#ifndef MASTERVIEW_H
#define MASTERVIEW_H
#include <QDebug>
#include <QWidget>
#include <loginview.h>
#include <doctorview.h>
#include <departmentview.h>
#include <patienteditview.h>
#include <patientview.h>
#include <welcomeview.h>
#include <doctoreditview.h>
#include <visitview.h>
#include <visiteditview.h>
#include <medicationview.h>
#include <medicationeditview.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MasterView; }
QT_END_NAMESPACE

class MasterView : public QWidget
{
    Q_OBJECT

public:
    MasterView(QWidget *parent = nullptr);
    ~MasterView();

public slots:
    void goLoginView();
    void goWelcomeView();
    void goDoctorView();
    void goDepartmentView();
    void goPatientView();
    void goPatientEditView(int rowNo);
    void goPreviousView();
    void goDoctoreditview();
    void goVisitview();
    void goVisiteditview();
    void goMedicationview ();
    void goMedicationeditview();
private slots:
    void on_btBack_clicked();

    void on_stackedWidget_currentChanged(int arg1);

    void on_btLogout_clicked();

private:
    void pushWidgetToStackView(QWidget* widget);

    Ui::MasterView *ui;

    LoginView *loginView;
    PatientEditView *patientEditView;
    DoctorView *doctorView;
    DepartmentView *departmentView;
    WelcomeView *welcomeView;
    PatientView *patientView;
    doctorEditView doctoreditview;
    VisitView visitview;
    VisitEditView visiteditview;
    MedicationView medicationview;
    MedicationEditView medicationeditview;

};
#endif // MASTERVIEW_H
