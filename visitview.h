#ifndef VISITVIEW_H
#define VISITVIEW_H

#include <QWidget>
#include <idatabase.h>

namespace Ui {
class VisitView;
}

class VisitView : public QWidget
{
    Q_OBJECT

public:
    explicit VisitView(QWidget *parent = nullptr);
    ~VisitView();

private slots:
    void on_btAdd_clicked();

    void on_btChange_clicked();

    void on_btDelete_clicked();

    void on_btSrearch_clicked();

signals:
    void goVisitEditView(int idx);

private:
    Ui::VisitView *ui;
};

#endif // VISITVIEW_H
