#ifndef WELCOMEVIEW_H
#define WELCOMEVIEW_H

#include <QWidget>
#include <QDebug>
namespace Ui {
class WelcomeView;
}

class WelcomeView : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeView(QWidget *parent = nullptr);
    ~WelcomeView();

private slots:
    void on_btDepartment_clicked();

    void on_btDoctor_clicked();

    void on_btPatient_clicked();

    void on_btMedication_clicked();

    void on_btVisit_clicked();

signals:
    void goDepartmentView();
    void goDoctorView();
    void goPatientView();
    void goVisitView();
    void goMedicationView();

private:
    Ui::WelcomeView *ui;
};

#endif // WELCOMEVIEW_H
