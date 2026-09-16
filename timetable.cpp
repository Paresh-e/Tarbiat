#include "timetable.h"
#include "globaldata.h"
#include "QMessageBox"
#include "ui_timetable.h"
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QPrinter>
#include <QPainter>
#include <QTextDocument>
#include <QFileDialog>
#include <QRandomGenerator>
#include <QDateTime>
#include<math.h>
#include<algorithm>

TimeTable::TimeTable(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TimeTable)

{
    if(!GlobalData::instance().isfull){
        QMessageBox::warning(this,"خطا","ایتدا تنظیمات مسابقه را مشخص کنید");
        this->close();
        return;
    }else{


        mySettings = new timeTableSettings;
        mySettings = &GlobalData::instance().TTS;
        MyGroups = new QMap<QString,QMap<int,CompetitionGroup>>;
        MyGroups = &GlobalData::instance().finalGroups;
        restTimes = new  QMap<QString, QPair<QTime, QTime>>;
        *restTimes = GlobalData::instance().TTS.getRestTimes();
        QTime start = mySettings->startCom;




        tatami_Names = new QVector<QString>;
        for(auto it = MyGroups->constBegin() ; it != MyGroups->constEnd() ; ++it){
            qDebug()<<it.key();
            if(!tatami_Names->contains(it.key())){

                tatami_Names->append(it.key());
            }
        }
        int tatami_number = mySettings->tatamiNumber;
        QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";
        for(int i = 0 ; i< tatami_number; i++){
            if(!tatami_Names->contains(alphabet[i])){
                tatami_Names->append(alphabet[i]);
            }
        }
        qDebug()<<"--------------------------------";
        for(int i = 0 ; i < tatami_Names->size() ; i++){

            qDebug()<<tatami_Names->at(i);
            Current_tatami_Time[tatami_Names->at(i)] = start;
        }
        qDebug()<<"--------------------------------";






    }
    ui->setupUi(this);

    populateTable();

    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

TimeTable::~TimeTable()
{
    delete ui;
}


void TimeTable::populateTable(){
    for(auto it = MyGroups->constBegin() ; it != MyGroups->constEnd() ; ++it){
        // QMap<int, CompetitionGroup> innerMap;
        QString Tatem = it.key();
        for(auto init = it.value().constBegin() ; init != it.value().constEnd() ; ++init){
            // qDebug()<<Tatem;
            GlobalData::instance().repe_Done=0;
            where_compGro_go(init.value(),Tatem,init.value().Space,init.value().matchDuration);
        }
    }
    int row = ui->tableWidget->rowCount();
    for(int i = 0 ; i< row ; i++){
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(i+1)));

    }

}
void TimeTable::where_compGro_go(const CompetitionGroup &c, QString tatmi,double space,double Durat)
{
    if(Current_tatami_Time.contains(tatmi)){


        QVector<QString> *parti = new QVector<QString>;
        if(c.entryType == EntryType::Team){
            for(auto& i : c.teams){
                parti->append(i.teamName);
            }
            GlobalData::instance().number_of_this_group_participant = parti->size();

            if(c.matchType == MatchType::Kata){
                putLable_Kata_Team(c);
                pop_Kata(*parti,tatmi,space,Durat);
            }
            else if(c.matchType == MatchType::Kumite){
                putLable_Kumi_Team(c);
                pop_Kumi(*parti,tatmi,space,Durat);
            }


        }
        else if (c.entryType == EntryType::Individual){
            for(auto& i : c.participants){
                parti->append(i.firstName + " " + i.lastName);
            }
            GlobalData::instance().number_of_this_group_participant = parti->size();

            if(c.matchType == MatchType::Kata){
                putLable_Kata_Indivi(c);

                pop_Kata(*parti,tatmi,space,Durat);
            }
            else if(c.matchType == MatchType::Kumite){
                putLable_Kumi_Indivi(c);

                pop_Kumi(*parti,tatmi,space,Durat);
            }

        }
    }else{
        qDebug()<<tatmi << " is not in the there" ;
    }

}


void TimeTable::putLable_Kata_Team(const CompetitionGroup &c)
{
    int row = ui->tableWidget->rowCount();
    set_Item(groupDescription(c),row,1);



}

void TimeTable::putLable_Kata_Indivi(const CompetitionGroup &c)
{
    int row = ui->tableWidget->rowCount();
    set_Item(groupDescription(c),row,1);

}

void TimeTable::putLable_Kumi_Team(const CompetitionGroup &c)
{
    int row = ui->tableWidget->rowCount();
    set_Item(groupDescription(c),row,1);
}

void TimeTable::putLable_Kumi_Indivi(const CompetitionGroup &c)
{
    int row = ui->tableWidget->rowCount();
    set_Item(groupDescription(c),row,1);
}

int needed_players(int n){
    int temp = 1 ;
    while(temp<n){
        temp*=2;
    }
    return temp - n;
}

void TimeTable::pop_Kumi(QVector<QString>& p , QString tatami, double space, double Durat){
    // qDebug()<<this;
    // for(int i = 0 ; i < p.size();i++){
    //     qDebug()<<p[i];
    // }
    if(p.size() <= 0 ){


        return;
    }else if ( p.size() == 1 ){
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(p[0]));
        ui->tableWidget->setItem(row,3,new QTableWidgetItem("----"));
        QPair<QString , QTime> temp = finad_tatmi(tatami,Durat);
        QTime start = temp.second;
        QTime end = start.addSecs(60*Durat);
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
        ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
        QString tatami_name = temp.first;
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
        QTime& currentTime = Current_tatami_Time[tatami_name];
        currentTime = end.addSecs(space*60);



        return ;
    }
    else{
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(p.begin(),p.end(),g);
        int n_Byes = needed_players(p.size());
        // qDebug()<<n_Byes;
        for(int i = 0 ; i < n_Byes ; i++){
            p.push_front("BYE");
        }
        int row = ui->tableWidget->rowCount();
        QVector<QString> ByeShode;
        QVector<QString> *next_round = new QVector<QString>;
        int j = 0 ;
        int i = p.size();
        while(n_Byes>0){
            QString p1 = p[j];
            QString p2 = p[i-j-1];
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(p1));
            ui->tableWidget->setItem(row,3 , new QTableWidgetItem(p2));
            // QPair<QString , QTime> temp = finad_tatmi(tatami,Durat);
            // QTime start = temp.second;
            // QTime end = start.addSecs(60*Durat);
            // ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
            // ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
            // QString tatami_name = temp.first;
            // ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
            // QTime& currentTime = Current_tatami_Time[tatami_name];
            // currentTime = end.addSecs(space*60);


            j++;
            n_Byes--;
            ByeShode.append(p2);
            row+=1;
        }
        // for(int i = 0 ; i < p.size();i++){
        //     qDebug()<<p[i];
        // }
        for(int i = 0 ; i<ByeShode.size();i++){
            p.pop_front();
            p.pop_back();
        }
        for (int var = 0; var < ByeShode.size(); ++var) {
            next_round->append(ByeShode[var]);
        }

        int k = 0 ;
        for(int i = 0 ; i < p.size() / 2 ; i++,k++){

            QString p1 = p[k];
            QString p2 = p[++k];
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(p1));
            ui->tableWidget->setItem(row,3 , new QTableWidgetItem(p2));
            QPair<QString , QTime> temp = finad_tatmi(tatami,Durat);
            QTime start = temp.second;
            QTime end = start.addSecs(60*Durat);
            ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
            ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
            QString tatami_name = temp.first;
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
            QTime& currentTime = Current_tatami_Time[tatami_name];
            currentTime = end.addSecs(space*60);

            next_round->append(QString("winner of %1 row").arg(row+1));



            row+=1;
        }
        nextRound(*next_round,tatami,space,Durat);


    }

}

void TimeTable::pop_Kata(QVector<QString>& p , QString tatami, double space, double Durat){
    int row = ui->tableWidget->rowCount();
    for(int i = 0 ; i < p.size() ; i++){

        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row,2,new QTableWidgetItem(p[i]));

        QPair<QString , QTime> temp = finad_tatmi(tatami,Durat);
        QTime start = temp.second;
        QTime end = start.addSecs(60*Durat);
        ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
        ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
        QString tatami_name = temp.first;
        ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
        QTime& currentTime = Current_tatami_Time[tatami_name];
        currentTime = end.addSecs(space*60);

        row++;
    }



}


int R_max(int n) {
    if (n <= 1) return 0;           // n=0 یا 1 -> هیچ شانس‌مجددی
    int k = static_cast<int>(std::ceil(std::log2(n)));
    return 2 * (k - 1);
}
void TimeTable::nextRound(QVector<QString>& nr,QString tatami, double space, double Durat)
{
    // qDebug()<<this;
    // for(int i = 0 ; i < nr.size() ; i++){
    //     qDebug()<<nr[i];
    // }
    QVector<QString> *nextround = new  QVector<QString>;
    int row = ui->tableWidget->rowCount();

    if(nr.size()<=2){
        if(nr.size() == 2){

            if(mySettings->repeCharge ){
                if(GlobalData::instance().repe_Done == 1){
                    return;
                }

                if(mySettings->beforeFinal ){



                    if(GlobalData::instance().repe_Done != 1){
                        QVector<QString> * repe = new QVector<QString>;
                        int n = R_max(GlobalData::instance().number_of_this_group_participant);
                        for(int i = 0 ; i < n ;i++){
                            repe->append("RC");
                        }
                        GlobalData::instance().repe_Done = 1 ;
                        pop_Kumi(*repe,tatami,space,Durat);
                    }
                    ui->tableWidget->insertRow(row);
                    QString p1 = nr[0];
                    QString p2 = nr[1];
                    ui->tableWidget->setItem(row,2,new QTableWidgetItem(p1));
                    ui->tableWidget->setItem(row,3 , new QTableWidgetItem(p2));
                    QTime start = finad_tatmi(tatami,Durat).second;
                    QTime end = start.addSecs(60*Durat);
                    ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
                    ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
                    QString tatami_name = finad_tatmi(tatami,Durat).first;
                    ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
                    QTime& currentTime = Current_tatami_Time[tatami_name];
                    currentTime = end.addSecs(space*60);
                }
                else{
                    ui->tableWidget->insertRow(row);
                    QString p1 = nr[0];
                    QString p2 = nr[1];
                    ui->tableWidget->setItem(row,2,new QTableWidgetItem(p1));
                    ui->tableWidget->setItem(row,3 , new QTableWidgetItem(p2));
                    QTime start = finad_tatmi(tatami,Durat).second;
                    QTime end = start.addSecs(60*Durat);
                    ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
                    ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
                    QString tatami_name = finad_tatmi(tatami,Durat).first;
                    ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
                    QTime& currentTime = Current_tatami_Time[tatami_name];
                    currentTime = end.addSecs(space*60);

                    if(GlobalData::instance().repe_Done != 1){
                        QVector<QString> * repe = new QVector<QString>;
                        int n = R_max(GlobalData::instance().number_of_this_group_participant);
                        for(int i = 0 ; i < n ;i++){
                            repe->append("RC");
                        }
                        GlobalData::instance().repe_Done = 1 ;
                        pop_Kumi(*repe,tatami,space,Durat);
                    }

                }

            }

            else{
                    ui->tableWidget->insertRow(row);
                    QString p1 = nr[0];
                    QString p2 = nr[1];
                    ui->tableWidget->setItem(row,2,new QTableWidgetItem(p1));
                    ui->tableWidget->setItem(row,3 , new QTableWidgetItem(p2));
                    QTime start = finad_tatmi(tatami,Durat).second;
                    QTime end = start.addSecs(60*Durat);
                    ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
                    ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
                    QString tatami_name = finad_tatmi(tatami,Durat).first;
                    ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
                    QTime& currentTime = Current_tatami_Time[tatami_name];
                    currentTime = end.addSecs(space*60);
                }
        }
        return;
    }
    else{
        int j = 0 ;
        for(int i = 0 ; i < nr.size()/2 ; i++){




            QString p1 = nr[j++];
            QString p2 = nr[j++];
            ui->tableWidget->insertRow(row);
            ui->tableWidget->setItem(row,2,new QTableWidgetItem(p1));
            ui->tableWidget->setItem(row,3 , new QTableWidgetItem(p2));
            QTime start = finad_tatmi(tatami,Durat).second;
            QTime end = start.addSecs(60*Durat);
            ui->tableWidget->setItem(row,5,new QTableWidgetItem(start.toString("hh:mm")));
            ui->tableWidget->setItem(row,6,new QTableWidgetItem(end.toString("hh:mm")));
            QString tatami_name = finad_tatmi(tatami,Durat).first;
            ui->tableWidget->setItem(row,4,new QTableWidgetItem(tatami_name));
            QTime& currentTime = Current_tatami_Time[tatami_name];
            currentTime = end.addSecs(space*60);


            nextround->append(QString("winner of %1 row").arg(row+1));
            row+=1;


        }
        delete &nr;
        nextRound(*nextround,tatami, space,Durat);
    }
}

QString TimeTable::groupDescription(const CompetitionGroup &group) const
{
    QString groupLabel = QString("Group:%1|%2|%3|%4|MatchDuration:%5")
    .arg(group.ageCategory)
        .arg(group.weightCategory)
        .arg(group.gender == Gender::Male ? "Male" : "Female")
        .arg(group.matchType == MatchType::Kata ? "Kata" : "Kumite")
        .arg(group.matchDuration);
    return groupLabel;
}


void TimeTable::set_Item(QString a, int row, int co)
{
    ui->tableWidget->insertRow(row);
    ui->tableWidget->setItem(row,co,new QTableWidgetItem(a));
}

QPair<QString,QTime>  TimeTable::finad_tatmi(QString a,double duration)
{
    qDebug()<<a;
    QTime& currentTime = Current_tatami_Time[a];
    QString name = a;
    if(a.startsWith("Z") && mySettings->tatamiNumber>=2){
        QTime temp_time ;
        QString temp_name ;
        for(auto it=Current_tatami_Time.constBegin();it!=Current_tatami_Time.constEnd();++it){
            if(it.key().startsWith("Z")){
                continue;
            }


            for(auto j=Current_tatami_Time.constBegin();j!=Current_tatami_Time.constEnd();++j){
                if(j.key().startsWith("Z") || j.key()==it.key()){
                    continue;
                }
                qDebug()<<j.key()<<":"<<j.value().toString("hh:mm")<<" | "<<it.key()<<":"<<it.value();
                if(j.value()<=it.value()){
                    temp_time = j.value();
                    temp_name = j.key();
                }
            }

        }

        currentTime = temp_time;
        name = temp_name;
    }else if(a.startsWith("Z")&& mySettings->tatamiNumber<2){
        currentTime = Current_tatami_Time["A"];
        name = "A";
    }
    qDebug()<<name << currentTime.toString("hh:mm");



    for (auto it = restTimes->begin(); it != restTimes->end(); ++it) {
        QTime start = it.value().first;
        QTime end = it.value().second;

        if (currentTime >= start && currentTime < end) {
            int breakRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(breakRow);
            ui->tableWidget->setItem(breakRow, 0, new QTableWidgetItem(it.key()));
            ui->tableWidget->setItem(breakRow, 4, new QTableWidgetItem(start.toString("hh:mm")));
            ui->tableWidget->setItem(breakRow, 1, new QTableWidgetItem("<< زمان استراحت >> " ));
            ui->tableWidget->setItem(breakRow, 5, new QTableWidgetItem(end.toString("hh:mm")));
            currentTime = end;
        }
        else if (currentTime.addSecs(duration*60) >= start && currentTime.addSecs(duration*60) <end ){
            int breakRow = ui->tableWidget->rowCount();
            ui->tableWidget->insertRow(breakRow);
            ui->tableWidget->setItem(breakRow, 0, new QTableWidgetItem(it.key()));
            ui->tableWidget->setItem(breakRow, 4, new QTableWidgetItem(start.toString("hh:mm")));
            ui->tableWidget->setItem(breakRow, 1, new QTableWidgetItem("<< زمان استراحت >> " ));
            ui->tableWidget->setItem(breakRow, 5, new QTableWidgetItem(end.toString("hh:mm")));
            currentTime = end;
        }
    }
    return QPair(name,currentTime);


}






void printTableToPdf(QTableWidget* table, const QString& fileName) {
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QPainter painter;
    if (!painter.begin(&printer)) {
        qWarning("Failed to begin painting on printer.");
        return;
    }

    painter.setFont(QFont("Arial", 10));

    QRect pageRect = printer.pageRect(QPrinter::DevicePixel).toRect();
    int margin = 300;
    QRect drawRect = pageRect.adjusted(margin, margin, -margin, -margin);

    int currentY = drawRect.top();
    int rowHeight = 300;
    // از عرض واقعی ستون‌ها استفاده کنید
    // اگر بخواهید عرض هر ستون متفاوت باشد، باید یک آرایه از عرض ستون‌ها بسازید
    // و هنگام ترسیم از آن استفاده کنید. فعلا برای سادگی، تقسیم یکنواخت می‌کنیم.
    int totalTableWidth = 0;
    for(int col = 0; col < table->columnCount(); ++col) {
        totalTableWidth += table->columnWidth(col);
    }
    // نسبت‌های عرض ستون‌ها را محاسبه کنید
    QVector<double> columnWidthRatios;
    for(int col = 0; col < table->columnCount(); ++col) {
        columnWidthRatios.append(static_cast<double>(table->columnWidth(col)) / totalTableWidth);
    }


    // ترسیم هدرها
    painter.save();
    painter.setPen(Qt::black);
    painter.setBrush(QBrush(QColor("#D3D3D3")));

    int currentX = drawRect.left();
    for (int col = 0; col < table->columnCount(); ++col) {
        int actualColumnWidth = static_cast<int>(drawRect.width() * columnWidthRatios[col]);
        QRect headerRect(currentX, currentY, actualColumnWidth, rowHeight);
        painter.drawRect(headerRect);
        painter.drawText(headerRect, Qt::AlignCenter, table->horizontalHeaderItem(col)->text());
        currentX += actualColumnWidth;
    }
    painter.restore();
    currentY += rowHeight;

    // ترسیم محتویات جدول
    for (int row = 0; row < table->rowCount(); ++row) {
        if (currentY + rowHeight > drawRect.bottom()) {
            printer.newPage();
            currentY = drawRect.top();

            // هدرها را در صفحه جدید هم ترسیم کنید
            painter.save();
            painter.setPen(Qt::black);
            painter.setBrush(QBrush(QColor("#D3D3D3")));
            currentX = drawRect.left();
            for (int col = 0; col < table->columnCount(); ++col) {
                int actualColumnWidth = static_cast<int>(drawRect.width() * columnWidthRatios[col]);
                QRect headerRect(currentX, currentY, actualColumnWidth, rowHeight);
                painter.drawRect(headerRect);
                painter.drawText(headerRect, Qt::AlignCenter, table->horizontalHeaderItem(col)->text());
                currentX += actualColumnWidth;
            }
            painter.restore();
            currentY += rowHeight;
        }

        currentX = drawRect.left();
        for (int col = 0; col < table->columnCount(); ++col) {
            int actualColumnWidth = static_cast<int>(drawRect.width() * columnWidthRatios[col]);
            QRect cellRect(currentX, currentY, actualColumnWidth, rowHeight);
            painter.drawRect(cellRect);
            QTableWidgetItem* item = table->item(row, col);
            if (item) {
                painter.drawText(cellRect, Qt::AlignCenter, item->text());
            }
            currentX += actualColumnWidth;
        }
        currentY += rowHeight;
    }

    painter.end();
}
void TimeTable::on_pushButton_clicked()
{
    // باز کردن QFileDialog برای انتخاب مسیر ذخیره فایل
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "ذخیره فایل PDF", // عنوان دیالوگ
                                                    "output_table.pdf", // نام پیش‌فرض فایل
                                                    "فایل‌های PDF (*.pdf);;همه فایل‌ها (*)"); // فیلتر فایل‌ها

    if (!fileName.isEmpty()) { // اگر کاربر کنسل نکرد و یک نام فایل انتخاب کرد
        printTableToPdf(ui->tableWidget, fileName);
        QMessageBox::information(this, "موفقیت", "فایل PDF با موفقیت ذخیره شد!");
    } else {
        QMessageBox::warning(this, "عملیات لغو شد", "عملیات ذخیره PDF توسط کاربر لغو شد.");
    }
}

