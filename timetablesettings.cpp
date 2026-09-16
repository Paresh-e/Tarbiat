#include "timetablesettings.h"
#include "globaldata.h"
#include "sortgroups.h"
#include "ui_timetablesettings.h"
#include <QMessageBox>
timeTableSettings::timeTableSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::timeTableSettings)
{
    ui->setupUi(this);
    ui->TatamiNumberSpinBox->setMinimum(1);
    ui->checkBox->setVisible(false);

}

timeTableSettings::~timeTableSettings()
{
    delete ui;
}
void timeTableSettings::set_restTimes(QMap<QString,QPair<QTime, QTime>> T)
{
    currentRestTimes = T;
}
void timeTableSettings::on_AddBreak_clicked()
{
    QTime start = ui->BreakStartTimeEdit->time();
    QTime end = ui->BreakEndTimeEdit->time();
    QString breackTitle = ui->lineEdit->text();
    if (start >= end) {
        QMessageBox::warning(this, "خطا", "زمان شروع نمی‌تواند بعد از زمان پایان باشد.");
        return;
    }

    if (isTimeOverlap(start, end)) {
        QMessageBox::warning(this, "خطا", "بازه زمانی با زمان‌های استراحت قبلی تداخل دارد.");
        return;
    }
    if (breackTitle.isEmpty()){
        QMessageBox::warning(this, "خطا", "اسم تایم استراحت نمیتواند خالی باشد.");
        return;
    }
    QPair<QTime,QTime> times =qMakePair(start,end);

    currentRestTimes[breackTitle]= times;
    updateRestTimeList();
}
 QMap<QString,QPair<QTime, QTime>> timeTableSettings::getRestTimes() const {
    return currentRestTimes;
}
bool timeTableSettings::isTimeOverlap(const QTime &newStart, const QTime &newEnd) {
    for (const auto &existingPair : currentRestTimes) {
        QTime existingStart = existingPair.first;
        QTime existingEnd = existingPair.second;

        // Check for overlap
        if ((newStart < existingEnd && newEnd > existingStart)) {
            return true;
        }
    }
    return false;
}
void timeTableSettings::updateRestTimeList() {
    ui->restTimeList->clear();
    int j = 1 ;

    QMapIterator<QString, QPair<QTime, QTime>> i(currentRestTimes);
    while (i.hasNext()) {
        i.next();
        ui->restTimeList->addItem(QString("%1: | "+i.value().first.toString("hh:mm")+
                                          "-"+
                                          i.value().second.toString("hh:mm")+" | "+
                                          i.key())
                                      .arg(j++));
        }
    }

void timeTableSettings::on_DeleteBreakButton_clicked()
{
    if(ui->restTimeList->selectedItems().isEmpty()){
        QMessageBox::warning(this, "خطا", "لطفاً برای حذف یک زمان استراحت را انتخاب کنید.");
        return;
    }
    QString inputString = ui->restTimeList->currentItem()->text();
    QString result;
    int lastPipeIndex = inputString.lastIndexOf('|'); // پیدا کردن آخرینoccurrence کاراکتر '|'

     if (lastPipeIndex != -1) { // اگر '|' پیدا شد
         // از یک کاراکتر بعد از '|' تا انتهای رشته را برش می‌زنیم
         result = inputString.mid(lastPipeIndex + 1);
         result = result.trimmed(); // حذف فضاهای خالی اطراف (اگر وجود داشته باشد)
     }

     currentRestTimes.remove(result);
     updateRestTimeList();
}


void timeTableSettings::on_SaveButton_clicked()
{
    tatamiNumber = ui->TatamiNumberSpinBox->value();
    if(tatamiNumber <= 0 ){
        QMessageBox::warning(this,"تعداد تاتمی ها معتبر نیست " ,"خطا");
        return;
    }
    startCom = ui->StartTimeEdit->time();
    QTime eraliest(8,0);
    QTime latest(20,0);

    if(startCom <eraliest || startCom> latest){
        QMessageBox::warning(this, "خطا" , "زمان مسابقه باید بین 8 صبح تا 8 شب باشد" );
        return;
    }
    if(GlobalData::instance().finalGroups.isEmpty()){
        QMessageBox::warning(this,"خطا","ابتدا ترتیب گروه ها را مشخص کنید");
        return;
    }

    repeCharge = ui->repeCharCheackBox->isChecked();
    beforeFinal = ui->checkBox->isChecked();
    GlobalData::instance().SetSettings(*this);
    this->close();
}


void timeTableSettings::on_SortGroupBtn_clicked()
{
    SortGroups * form = new SortGroups(nullptr,ui->TatamiNumberSpinBox->value());
    form->show();

}





void timeTableSettings::on_repeCharCheackBox_stateChanged(int arg1)
{
    if(arg1 == 0 ){
        ui->checkBox->setChecked(false);
        ui->checkBox->setVisible(false);
    }else{
        ui->checkBox->setVisible(true);
    }
}

