#ifndef REGISTRATIONFORM_H
#define REGISTRATIONFORM_H

#include <QWidget>
#include "competitiongroupmanager.h"
#include "registrationmanager.h"
#include <QDialog>

namespace Ui {
class RegistrationForm;
}

class RegistrationForm : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationForm(QWidget *parent = nullptr);
    ~RegistrationForm();


private slots:
    void onGroupChanged(int index);

    void onRegisterClicked();



private:
    Ui::RegistrationForm *ui;
    CompetitionGroupManager manager;


    void updateGroupList();
    void clearForm();
};
QString toStringComp(const CompetitionGroup& c);


#endif // REGISTRATIONFORM_H
