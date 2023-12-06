#ifndef PATIENTEDITVIEW_H
#define PATIENTEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <idatabase.h>
namespace Ui {
class PatientEditView;
}

class PatientEditView : public QWidget
{
    Q_OBJECT

public:
    explicit PatientEditView(QWidget *parent = nullptr,int index=0);
    ~PatientEditView();

private slots:
    void on_btSave_clicked();

    void on_btCancel_clicked();

signals:
    void goPreviousView();
private:
    Ui::PatientEditView *ui;
    QDataWidgetMapper *dataMapper;  //数据映射

};

#endif // PATIENTEDITVIEW_H
