#ifndef MEDICATIONEDITVIEW_H
#define MEDICATIONEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <idatabase.h>
namespace Ui {
class MedicationEditView;
}

class MedicationEditView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicationEditView(QWidget *parent = nullptr,int index=0);
    ~MedicationEditView();

private slots:
    void on_btSave_clicked();

    void on_btCancel_clicked();
signals:
    void goPreviousView();
private:
    Ui::MedicationEditView *ui;
    QDataWidgetMapper *dataMapper;  //数据映射
};

#endif // MEDICATIONEDITVIEW_H
