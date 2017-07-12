#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QFileDialog>
#include <QKeyEvent>
#include <QMessageBox>

#include "field.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void keyPressEvent(QKeyEvent * event);

    QGraphicsView * grView;
    field * myField;

private slots:
    void on_action_triggered();

    void on_colorCheckBox_clicked(bool checked);

    void on_action_2_triggered();

    void on_action_3_triggered();

    void on_action_4_triggered();

    void on_lineEditOfLatitude_editingFinished();

    void on_lineEditOfLongitude_editingFinished();

    void on_dateEdit_editingFinished();

    void on_timeEdit_editingFinished();

    void on_SpinBoxHeight_editingFinished();

    void on_action_9_triggered();

    void on_action_11_triggered();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
