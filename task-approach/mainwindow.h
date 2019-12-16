#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Task.h"
#include "Approach.h"
#include <vector>
#include <memory>
#include <QMainWindow>

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
    std::vector<std::shared_ptr<Task>> tasks;
    std::vector<std::shared_ptr<Approach>> approaches;

    void addTasks();
    void addApproaches();
    void calculate();
    void addResultToTable(Task &task, Approach &approach, bool isSolved);

private slots:
    void setSolveButtonEnabled();
    void on_pbSolve_clicked();
};
#endif // MAINWINDOW_H
