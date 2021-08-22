#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QPushButton>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    mMainArea = std::make_unique<QScrollArea>();
    mMainArea->setWidgetResizable(true);
    mMainAreaWidget = std::make_unique<QWidget>();
    setCentralWidget(mMainArea.get());
    mMainArea->setWidget(mMainAreaWidget.get());
    mAreaLayout = std::make_unique<QVBoxLayout>();
    mMainAreaWidget->setLayout(mAreaLayout.get());
    for (int i = 0; i < 10; ++i) {
        ToolBoxItem *t = new ToolBoxItem();
        mAreaLayout->addWidget(t);
        QPushButton *b = new QPushButton(QString::number(i));
        QPushButton *bb = new QPushButton(QString::number(i));
        t->AppendWidget(b, 30);
        t->AppendWidget(bb, 60);
    }
    mAreaLayout->addStretch();
    mAreaLayout->setSpacing(0);
    mAreaLayout->setMargin(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

