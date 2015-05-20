#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_typeText_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void fillList();
    void createTypeImg();
    void findType(QString type, double *ptr);
};

#endif // MAINWINDOW_H
