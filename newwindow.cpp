#include "newwindow.h"
#include "ui_newwindow.h"

newWindow::newWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::newWindow)
{
    ui->setupUi(this);
}

newWindow::~newWindow()
{
    delete ui;
}
