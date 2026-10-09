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
#include <qlistwidget.h>

SortGroups::SortGroups(QWidget *parent,int tattami)
    : QDialog(parent)
    , ui(new Ui::SortGroups)
    , manager(QCoreApplication::applicationDirPath() + "/groups.json")
{
    GlobalData::instance().empty_finalGroups();
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    // tatami = new QVector<QComboBox*>;
    // order = new QVector<QComboBox *>;

    manager.load();
    const auto& groups = manager.getGroups();
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";


    // start page sort > making the tatemi into the table
    for ( int i = 0 ; i<tattami ; ++i){
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(alphabet[i]));
        // be ezay har tattami ye khat onsert misheh
        QListWidget * priorityList= new QListWidget();

        for(int j = 0 ; j< groups.size();j++){

            const auto& g = groups[j];
            QString gender = g.gender == Gender::Male ? "Male" : "Female";
            QString matchType = g.matchType == MatchType::Kata ? "Kata" : "Kumite";
            QString entryType = g.entryType == EntryType::Team ? "Team" : "Individual";
            QString title = g.ageCategory+"|"
                            +g.weightCategory+"|"
                            +gender+"|"
                            +matchType+"|"
                            +entryType+"|"
                            +QString::number(g.teamSize);
            QListWidgetItem *item =
                new QListWidgetItem(title);

            // title اصلی را نگه می‌داریم
            item->setData(Qt::UserRole, title);
            item->setFlags(
                item->flags() | Qt::ItemIsUserCheckable
                );
            item->setCheckState(Qt::Checked);

            priorityList->addItem(item);

            // ezafeh shodan har group , jeloy har tattami

        }
        connect(
            priorityList->model(),
            &QAbstractItemModel::rowsMoved,
            this,
            [this, priorityList]()
            {
                updatePriority(priorityList);
            }
            );
        connect(
            priorityList,
            &QListWidget::itemChanged,
            this,
            [this, priorityList](QListWidgetItem *item)
            {
                if (item->flags() & Qt::ItemIsUserCheckable)
                {
                    moveUncheckedToEnd(priorityList);
                }
            }
            );
        priorityList->setDragDropMode(QAbstractItemView::InternalMove);
        priorityList->setDefaultDropAction(Qt::MoveAction);

        ui->tableWidget->setCellWidget(i,1,priorityList);

        updatePriority(priorityList);

    }









//     for (int i = 0; i < groups.size(); ++i) {
//         const auto& g = groups[i];
//         ui->tableWidget->insertRow(i);
//         QString gender = g.gender == Gender::Male ? "Male" : "Female";
//         QString matchType = g.matchType == MatchType::Kata ? "Kata" : "Kumite";
//         QString entryType = g.entryType == EntryType::Team ? "Team" : "Individual";
//         QString title = g.ageCategory+"|"
//                         +g.weightCategory+"|"
//                         +gender+"|"
//                         +matchType+"|"
//                         +entryType+"|"
//                         +QString::number(g.teamSize);
//         ui->tableWidget->setItem(i,0,new QTableWidgetItem(title));



// //         QComboBox* tatamiButton = new QComboBox(this);

// //         tatamiButton->addItem("None...");
// //         for(int j = 0 ; j < tattami;j++){
// //              tatamiButton->addItem(alphabet[j]);
// //         }
// //         ui->tableWidget->setCellWidget(i, 1, tatamiButton);
       

//         QComboBox* tatamiButton = new QComboBox(this);
//         QStandardItemModel * model = new QStandardItemModel(tatamiButton);
//         QStandardItem * item = new QStandardItem("None...");
//         item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
//         item->setData(Qt::Checked,Qt::CheckStateRole);
//         model->appendRow(item);
//          for (int j = 0; j < tattami; j++) {
//             QStandardItem * item = new QStandardItem(alphabet[j]);
//             item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable);
//             item->setData(Qt::Unchecked,Qt::CheckStateRole);
//             model->appendRow(item);
//         }
//         tatamiButton->setModel(model);
//         tatamiButton->setEditable(false);
//         ui->tableWidget->setCellWidget(i, 1, tatamiButton);





//         QComboBox * comboBox_Order = new QComboBox(this);
//         comboBox_Order->addItem("None...");
//         for(int k = 1 ; k <= groups.size();k++){
//             comboBox_Order->addItem(QString::number(k));

//         }
//         ui->tableWidget->setCellWidget(i,2,comboBox_Order);

//         tatami->append(tatamiButton);
//         order->append(comboBox_Order);

//     }
//     ui->tableWidget->resizeColumnsToContents();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}
void SortGroups::updatePriority(QListWidget *priorityList)
{
    for (int i = 0; i < priorityList->count(); ++i)
    {
        QListWidgetItem *item =
            priorityList->item(i);

        // title اصلی
        QString title =
            item->data(Qt::UserRole).toString();

        // شماره جدید
        item->setText(
            QString("%1.        %2")
                .arg(i + 1)
                .arg(title)
            );
    }
}
SortGroups::~SortGroups()
{
    delete ui;
}

void SortGroups::moveUncheckedToEnd(QListWidget *priorityList)
{
    // ابتدا آیتم‌های بدون تیک را جمع‌آوری می‌کنیم
    QList<QListWidgetItem*> uncheckedItems;

    for (int i = 0; i < priorityList->count(); ++i)
    {
        QListWidgetItem *item = priorityList->item(i);

        if (item->checkState() == Qt::Unchecked)
        {
            uncheckedItems.append(item);
        }
    }

    // انتقال آیتم‌های بدون تیک به انتهای لیست
    for (QListWidgetItem *item : uncheckedItems)
    {
        int row = priorityList->row(item);

        priorityList->takeItem(row);
        priorityList->addItem(item);
    }

    // به‌روزرسانی شماره اولویت‌ها
    updatePriority(priorityList);
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

