#include "sortgroups.h"

#include "globaldata.h"
#include "ui_sortgroups.h"
#include <QRegularExpressionValidator>
#include <QRegularExpression>
#include <QComboBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QStandardItem>
#include <QMessageBox>

SortGroups::SortGroups(QWidget *parent,int tattami)
    : QDialog(parent)
    , ui(new Ui::SortGroups)
    , manager(QCoreApplication::applicationDirPath() + "/groups.json")
{
    GlobalData::instance().empty_finalGroups();
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    tatami = new QVector<QComboBox*>;
    order = new QVector<QComboBox *>;

    manager.load();
    const auto& groups = manager.getGroups();
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";
    for (int i = 0; i < groups.size(); ++i) {
        const auto& g = groups[i];
        ui->tableWidget->insertRow(i);
        QString gender = g.gender == Gender::Male ? "Male" : "Female";
        QString matchType = g.matchType == MatchType::Kata ? "Kata" : "Kumite";
        QString entryType = g.entryType == EntryType::Team ? "Team" : "Individual";
        QString title = g.ageCategory+"|"
                        +g.weightCategory+"|"
                        +gender+"|"
                        +matchType+"|"
                        +entryType+"|"
                        +QString::number(g.teamSize);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(title));



//         QComboBox* tatamiButton = new QComboBox(this);

//         tatamiButton->addItem("None...");
//         for(int j = 0 ; j < tattami;j++){
//              tatamiButton->addItem(alphabet[j]);
//         }
//         ui->tableWidget->setCellWidget(i, 1, tatamiButton);
       

        QComboBox* tatamiButton = new QComboBox(this);
        QStandardItemModel * model = new QStandardItemModel(tatamiButton);
        QStandardItem * item = new QStandardItem("None...");
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
        item->setData(Qt::Checked,Qt::CheckStateRole);
        model->appendRow(item);
         for (int j = 0; j < tattami; j++) {
            QStandardItem * item = new QStandardItem(alphabet[j]);
            item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
            item->setData(Qt::Unchecked,Qt::CheckStateRole);
            model->appendRow(item);
        }
        tatamiButton->setModel(model);
        tatamiButton->setEditable(false);
        ui->tableWidget->setCellWidget(i, 1, tatamiButton);





        QComboBox * comboBox_Order = new QComboBox(this);
        comboBox_Order->addItem("None...");
        for(int k = 1 ; k <= groups.size();k++){
            comboBox_Order->addItem(QString::number(k));

        }
        ui->tableWidget->setCellWidget(i,2,comboBox_Order);

        tatami->append(tatamiButton);
        order->append(comboBox_Order);

    }
    ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

SortGroups::~SortGroups()
{
    delete ui;
}






void SortGroups::on_pushButton_clicked()
{



    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Are You Sure ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        int k = 1 ;
        QMap<QString,QMap<int,CompetitionGroup>>  Holders;

        const auto& groups = manager.getGroups();
         int L=  groups.size() + 1;
        for (int i = 0; i < groups.size(); ++i) {
            QString Tatemi_name = tatami->at(i)->currentText();
            int ord = order->at(i)->currentIndex();
             qDebug()<< Tatemi_name << ":"<<ord << groups[i].ageCategory;
            QMap<int,CompetitionGroup> temp;
            if(Tatemi_name == "None..."){
                if(ord == 0 ){
                    temp[ord] = groups[i];
                    QString Title = "ZZ"+ QString::number(k);
                    Holders[Title].insert(temp);
                    k++;
                }else{
                    temp[ord] = groups[i];
                    Holders["ZX"].insert(temp);
                }
            }else{
                if(ord == 0 ){
                    temp[L++] = groups[i];
                    Holders[Tatemi_name].insert(temp);
                }
                else{
                    temp[ord] = groups[i];
                    Holders[Tatemi_name].insert(temp);}
                 }

        }


        GlobalData::instance().SetGroups(Holders);
        GlobalData::instance().Describefinal();
        if(GlobalData::instance().finalGroups.size() == 0 ){
            QMessageBox::warning(this,"Error", "دوباره امتحان کنید");

        }
        this->close();
    }


}

