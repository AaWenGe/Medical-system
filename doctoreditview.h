#ifndef DOCTOREDITVIEW_H
#define DOCTOREDITVIEW_H

#include <QWidget>

namespace Ui {
class doctorEditView;
}

class DoctorEditView : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorEditView(QWidget *parent = nullptr);
    ~DoctorEditView();

private:
    Ui::doctorEditView *ui;
};


#endif // DOCTOREDITVIEW_H
