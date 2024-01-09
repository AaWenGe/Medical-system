#ifndef VISITEDITVIEW_H
#define VISITEDITVIEW_H

#include <QWidget>
#include <QDataWidgetMapper>
#include <QSqlTableModel>
#include <idatabase.h>
namespace Ui {
class VisitEditView;
}

class VisitEditView : public QWidget
{
    Q_OBJECT

public:
    explicit VisitEditView(QWidget *parent = nullptr,int index=0);
    ~VisitEditView();

private slots:
    void on_btSave_clicked();

    void on_btCancel_clicked();
signals:
    void goPreviousView();
private:
    Ui::VisitEditView *ui;
    QDataWidgetMapper *dataMapper;  //数据映射
};

#endif // VISITEDITVIEW_H
