#include "sortgroups.h"

#include "globaldata.h"
#include "qdatetimeedit.h"
#include "tattami.h"
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

SortGroups::SortGroups(QWidget *parent,int tattami,bool defaultTime)
    : QDialog(parent)
    , ui(new Ui::SortGroups)
    , manager(QCoreApplication::applicationDirPath() + "/groups.json")
{
    tatNum = tattami;
    GlobalData::instance().empty_finalGroups();
    ui->setupUi(this);
    ui->tableWidget->setRowCount(0);
    // tatami = new QVector<QComboBox*>;
    // order = new QVector<QComboBox *>;
    DefTime = defaultTime;
    manager.load();
    const auto& groups = manager.getGroups();
    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";



    ui->tableWidget->setColumnCount(3);

    ui->tableWidget->setHorizontalHeaderLabels({
        "Tatami",
        "Timeline",
        "Priority"
    });

    // اگر زمان پیش‌فرض داریم، ستون Timeline مخفی شود
    ui->tableWidget->setColumnHidden(1, defaultTime);





    // start page sort > making the tatemi into the table
    for ( int i = 0 ; i<tattami ; ++i){
        ui->tableWidget->insertRow(i);

        // =====================================
        // Column 0: Tatami title
        // =====================================

        QTableWidgetItem *item = new QTableWidgetItem(alphabet[i]);

        item->setTextAlignment(Qt::AlignCenter);

        QFont font = item->font();
        font.setBold(true);
        font.setPointSize(14);
        item->setFont(font);

        ui->tableWidget->setItem(i, 0, item);
        // be ezay har tattami ye khat onsert misheh


        // =====================================
        // Column 1: Timeline
        // =====================================

        if (!defaultTime)
        {
            QTimeEdit *timeEdit = new QTimeEdit(ui->tableWidget);

            timeEdit->setDisplayFormat("HH:mm");
            timeEdit->setTime(QTime(8, 0));

            ui->tableWidget->setCellWidget(i, 1, timeEdit);
        }




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
            item->setData(Qt::UserRole+1, j);
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

        ui->tableWidget->setCellWidget(i,2,priorityList);

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



void SortGroups::setDefTime(QTime T){
    DefaultTime = T;
}
void SortGroups::on_pushButton_clicked()
{

    QString alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXY";

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Are You Sure ?",
                                  QMessageBox::Yes | QMessageBox::No);
    QVector<Tattami> * Holder = new QVector<Tattami>;
    if (reply == QMessageBox::Yes) {

            Tattami * temp;
            QVector<CompetitionGroup> nons;



                for (int tatamiRow = 0;
                     tatamiRow < ui->tableWidget->rowCount();
                     ++tatamiRow)
                {
                    QString tatamiName =
                        ui->tableWidget->item(tatamiRow, 0)->text();
                    if(!DefTime){
                        QTimeEdit *timeEdit = qobject_cast<QTimeEdit*>(
                            ui->tableWidget->cellWidget(tatamiRow, 1)
                            );
                        if (timeEdit)
                        {
                            QTime time = timeEdit->time();
                            temp = new Tattami(tatamiName,time);
                            // qDebug() << time.toString("HH:mm");
                        }
                    }else{
                        temp = new Tattami(tatamiName,this->DefaultTime);
                    }
                    auto *priorityList = qobject_cast<QListWidget *>(
                        ui->tableWidget->cellWidget(tatamiRow, 2)
                        );

                    if (!priorityList)
                        continue;



                    for (int priority = 0;
                         priority < priorityList->count();
                         ++priority)
                    {
                        QListWidgetItem *item = priorityList->item(priority);


                        int groupIndex = item->data(Qt::UserRole+1).toInt();

                        if (groupIndex >= 0 && groupIndex < manager.getGroups().size()) {
                            CompetitionGroup& g = manager.getGroups()[groupIndex];

                            // حالا به تمام اطلاعات گروه دسترسی داری
                            qDebug() << g.ageCategory;
                            qDebug() << g.matchDuration;
                            qDebug() << g.Space;
                            qDebug() << g.participants.size();
                            qDebug() << g.teams.size();
                            // گروه‌های بدون تیک غیرفعال هستند
                            if (item->checkState() != Qt::Checked){
                                nons.append(g);
                            }else{
                                temp->set_Category(g);
                            }
                        }

                    }
                    for(auto& i : nons){
                        temp->set_Category(i);
                    }
                    nons.clear();
                }




            }



    this->close();

    }




