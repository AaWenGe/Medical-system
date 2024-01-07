#ifndef DEPARTMENTEDITVIEW_H
#define DEPARTMENTEDITVIEW_H

#include <QWidget>

namespace Ui {
class departmentEditView;
}

class departmentEditView : public QWidget
{
    Q_OBJECT

public:
    explicit departmentEditView(QWidget *parent = nullptr);
    ~departmentEditView();

private:
    Ui::departmentEditView *ui;
};

#endif // DEPARTMENTEDITVIEW_H
