#ifndef MEDICATIONVIEW_H
#define MEDICATIONVIEW_H

#include <QWidget>
#include <idatabase.h>

namespace Ui {
class MedicationView;
}

class MedicationView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicationView(QWidget *parent = nullptr);
    ~MedicationView();

private slots:
    void on_btAdd_clicked();
    void on_btChange_clicked();

    void on_btDelete_clicked();

    void on_btSrearch_clicked();

signals:
    void goMedicationEditView();

private:
    Ui::MedicationView *ui;
};

#endif // MEDICATIONVIEW_H
