#ifndef VISITVIEW_H
#define VISITVIEW_H

#include <QWidget>

namespace Ui {
class VisitView;
}

class VisitView : public QWidget
{
    Q_OBJECT

public:
    explicit VisitView(QWidget *parent = nullptr);
    ~VisitView();

private:
    Ui::VisitView *ui;
};

#endif // VISITVIEW_H
