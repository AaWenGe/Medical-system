#ifndef MEDICATIONEDITVIEW_H
#define MEDICATIONEDITVIEW_H

#include <QWidget>

namespace Ui {
class MedicationEditView;
}

class MedicationEditView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicationEditView(QWidget *parent = nullptr);
    ~MedicationEditView();

private:
    Ui::MedicationEditView *ui;
};

#endif // MEDICATIONEDITVIEW_H
