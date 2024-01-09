#ifndef DOCTOREDITVIEW_H
#define DOCTOREDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <idatabase.h>
namespace Ui {
class doctorEditView;
}

class DoctorEditView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorEditView(QWidget *parent = nullptr,int index=0);
    ~DoctorEditView();

private slots:
    void on_btSave_clicked();
    void on_btCancel_clicked();

signals:
    void goPreviousView();
private:
    Ui::doctorEditView *ui;
    QDataWidgetMapper *dataMapper;  //数据映射
};


#endif // DOCTOREDITVIEW_H
