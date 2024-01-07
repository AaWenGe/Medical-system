#ifndef MEDICATIONVIEW_H
#define MEDICATIONVIEW_H

#include <QWidget>

namespace Ui {
class MedicationView;
}

class MedicationView : public QWidget
{
    Q_OBJECT

public:
    explicit MedicationView(QWidget *parent = nullptr);
    ~MedicationView();

private:
    Ui::MedicationView *ui;
};

#endif // MEDICATIONVIEW_H
