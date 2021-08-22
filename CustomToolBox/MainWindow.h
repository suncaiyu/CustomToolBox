#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollArea>
#include <QVBoxLayout>

#include "ToolBoxItem.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<ToolBoxItem> mToolBox;
    std::unique_ptr<QScrollArea> mMainArea;
    std::unique_ptr<QWidget> mMainAreaWidget;
    std::unique_ptr<QVBoxLayout> mAreaLayout;
};
#endif // MAINWINDOW_H
