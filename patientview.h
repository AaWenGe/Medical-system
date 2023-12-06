#ifndef PATIENTVIEW_H
#define PATIENTVIEW_H

#include <QWidget>
#include <idatabase.h>

namespace Ui {
class PatientView;
}

class PatientView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientView(QWidget *parent = nullptr);
    ~PatientView();

private slots:
    void on_btAdd_clicked();

    void on_btSrearch_clicked();

    void on_btDelete_clicked();

    void on_btChange_clicked();


signals:
    void goPatientEditView(int idx);

private:
    Ui::PatientView *ui;
};

#endif // PATIENTVIEW_H
