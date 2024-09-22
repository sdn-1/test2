#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::iniUI()
{
    fLabCurFile = new QLabel;
    fLabCurFile->setMidLineWidth(150);
    fLabCurFile->setText("当前文件:");
    ui->statusbar->addWidget(fLabCurFile);

    progressBar = new QProgressBar;
    progressBar->setMinimum(5);
    progressBar->setMaximum(50);
    progressBar->setValue(ui->textEdit->font().pointSize());
    ui->statusbar->addWidget(progressBar);

    spinFontSize = new QSpinBox;
    spinFontSize->setMinimum(5);
    spinFontSize->setMaximum(50);
    ui->toolBar->addWidget(new QLabel("字体大小:"));
    ui->toolBar->addWidget(spinFontSize);

    comboFont = new QFontComboBox;
    ui->toolBar->addWidget(new QLabel("字体"));
    ui->toolBar->addWidget(comboFont);
}

void MainWindow::iniSingalSlots()
{
    connect(spinFontSize,SIGNAL(valueChanged(int)),
           this,SLOT(on_spinBoxFontSize_valueChanged(int)));
    connect(comboFont,SIGNAL(currentIndexChanged(const QString&)),
            this,SLOT(on_comboFont_currentIndexChanged(const QString&)));

}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
    iniSingalSlots();
    setCentralWidget(ui->textEdit);

    btn->setParent(this);
    ui->toolBar->addWidget(btn);
    btn->setText("个人ID");

    connect(btn,&QPushButton::clicked,this,&MainWindow::ToggleWindow);
    //可以在这里加上一个新窗口的关闭按键和Toggle中的else的联系？？
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ToggleWindow()
{
    if(flag){
        new_window = new newWindow();
        new_window->resize(400,200);
        new_window->show();
        new_window->setAttribute(Qt::WA_DeleteOnClose);
        flag = 0;
        // btn->setText("关闭");
    }
    else{
        new_window->close();
        flag = 1;
        btn->setText("个人ID");
    }
}

void MainWindow::on_actFontBold_triggered(bool checked)
{
    QTextCharFormat fmt;
    // fmt=ui->textEdit->currentCharFormat();
    if(checked)
        fmt.setFontWeight(QFont::Bold);
    else
        fmt.setFontWeight(QFont::Normal);
    ui->textEdit->mergeCurrentCharFormat(fmt);
}


void MainWindow::on_textEdit_copyAvailable(bool b)
{
    ui->actcut->setEnabled(b);
    ui->actCopy->setEnabled(b);
    ui->actPaste->setEnabled(ui->textEdit->canPaste());
}


void MainWindow::on_textEdit_selectionChanged()
{
    QTextCharFormat fmt;
    fmt=ui->textEdit->currentCharFormat();
    ui->actFontItalic->setChecked(fmt.fontItalic());
    ui->actFontBold->setChecked(fmt.font().bold());
    ui->actFontWordunder->setChecked(fmt.fontUnderline());
}

void MainWindow::on_spinBoxFontSize_valueChanged(int aFontSize)
{

}

void MainWindow::on_comboFont_currentIndexChanged(const QString &arg1)
{

}

