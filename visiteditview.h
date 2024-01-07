#ifndef VISITEDITVIEW_H
#define VISITEDITVIEW_H

#include <QWidget>

namespace Ui {
class VisitEditView;
}

class VisitEditView : public QWidget
{
    Q_OBJECT

public:
    explicit VisitEditView(QWidget *parent = nullptr);
    ~VisitEditView();

private:
    Ui::VisitEditView *ui;
};

#endif // VISITEDITVIEW_H
