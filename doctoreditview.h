#ifndef DOCTOREDITVIEW_H
#define DOCTOREDITVIEW_H

#include <QWidget>

namespace Ui {
class doctorEditView;
}

class doctorEditView : public QWidget
{
    Q_OBJECT

public:
    explicit doctorEditView(QWidget *parent = nullptr);
    ~doctorEditView();

private:
    Ui::doctorEditView *ui;
};

#endif // DOCTOREDITVIEW_H
