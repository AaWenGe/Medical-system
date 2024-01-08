#ifndef DOCTORVIEW_H
#define DOCTORVIEW_H

#include <QWidget>
#include <idatabase.h>

namespace Ui {
class DoctorView;
}

class DoctorView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorView(QWidget *parent = nullptr);
    ~DoctorView();

private slots:
    void on_btAdd_clicked();

    void on_btChange_clicked();

    void on_btDelete_clicked();

    void on_btSrearch_clicked();

signals:
    void goDoctorEditView();

private:
    Ui::DoctorView *ui;
};

#endif // DOCTORVIEW_H
