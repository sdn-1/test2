#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QLabel>
#include <QSpinBox>
#include <QFontComboBox>
#include <QPushButton>
#include "newwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QLabel *fLabCurFile;
    QProgressBar *progressBar;
    QSpinBox *spinFontSize;
    QFontComboBox *comboFont;
    QPushButton *button;

    void iniUI();
    void iniSingalSlots();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton *btn = new QPushButton(); //此处定义btn是为了在函数中改变btn的名称
    void ToggleWindow();
    newWindow *new_window;
    bool flag;

private slots:
    void on_actFontBold_triggered(bool checked);

    void on_textEdit_copyAvailable(bool b);

    void on_textEdit_selectionChanged();

    void on_spinBoxFontSize_valueChanged(int aFontSize);  //改变字体大小的SpinBox
    void on_comboFont_currentIndexChanged(const QString &arg1);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
