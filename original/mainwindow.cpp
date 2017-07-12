#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myField = new field;
    grView = ui->graphicsView;
    grView->setScene(myField);
    grView->scale(0.002,0.002);

    connect(myField, SIGNAL(putDataTypeInLabel(QString)),ui->labelOfPointType_2,SLOT(setText(QString)));
    connect(myField, SIGNAL(putHeightInSpinBox(double)),ui->SpinBoxHeight,SLOT(setValue(double)));
    connect(myField, SIGNAL(putDateInDateBox(QDate)),ui->dateEdit,SLOT(setDate(QDate)));
    connect(myField, SIGNAL(putTimeInTimeBox(QTime)),ui->timeEdit,SLOT(setTime(QTime)));
    connect(myField, SIGNAL(putLatitudeInLineEdit(QString)),ui->lineEditOfLatitude,SLOT(setText(QString)));
    connect(myField, SIGNAL(putLongitudeInLineEdit(QString)),ui->lineEditOfLongitude,SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_Plus ||
            event->key() == Qt::Key_plusminus)
    {
        grView->scale(1.5,1.5);
    }
    if(event->key() == Qt::Key_Minus)
    {
        grView->scale(0.75,0.75);
    }
}

void MainWindow::on_action_triggered()
{
    QFileDialog * d = new QFileDialog;
    QString tmp = d->getOpenFileName(this,tr("Открыть трек"),
                                     "", tr("KML track(*.kml)"));
        if(tmp == "") return;
    QFile *f = new QFile;
    f->setFileName(tmp);
    //if(myField->getTrackList()->size() == 0)
    {
        MyTrack * track = new MyTrack(f,myField);
        myField->setCurTrack(track);
        track->setDataType("Track");
        myField->getTrackList()->push_back(track);
        //track->setTrackPos();
        myField->addTrackToScene();
        for(int i = 0; i < myField->getTrackList()->size(); i++)
        {
            if(myField->getTrackList()->at(i)->getStorage()->getSize() > 1)
                myField->getTrackList()->at(i)->setTrackPos();
        }
        for(int i = 0; i < myField->getTrackList()->size(); i++)
        {
            if(myField->getTrackList()->at(i)->getStorage()->getSize() == 1)
            {
                myField->getTrackList()->at(i)->setTrackPos();
            }
        }
    }

}

void MainWindow::on_action_2_triggered()
{
    if(!myField->getTrackList()->isEmpty())
    {
        QFileDialog * d = new QFileDialog;
        QString tmp = d->getSaveFileName(this,tr("Сохранить трек"),
                                         "", tr("KML track(*.kml)"));
        if(tmp == "") return;
        QFile *f = new QFile;
        f->setFileName(tmp);
        myField->getTrackList()->at(0)->saveInFile(f);
    }
    else qDebug() << "ERROR: try to save empty file";
}

void MainWindow::on_colorCheckBox_clicked(bool checked)
{
    if(checked)
    {
        myField->getTrackList()->at(0)->setColorByHeight();
    }
    else
    {
        myField->getTrackList()->at(0)->setColor(Qt::green);
    }
}



void MainWindow::on_action_3_triggered()
{
    QMessageBox *pmbx = new QMessageBox;
    pmbx->about(this,"О программе","Задание для курсовой работы <<Графический редактор GPS треков формата KML>>\n"
                                   "Подготовил Ермак Андрей, УГАТУ, ПРО-209, 2015");
    //int n = pmbx->exec();
    delete pmbx;
}

void MainWindow::on_action_4_triggered()
{
    QMessageBox *pmbx = new QMessageBox;
    pmbx->about(this,"Функциональность","Программа обладает базовой функциональностью работы "
                                        "с GPS треками и GPS точками");
    //int n = pmbx->exec();
    delete pmbx;
}

void MainWindow::on_lineEditOfLatitude_editingFinished()
{
    if(!myField->getTrackList()->isEmpty())
    {
        QString tmp = ui->lineEditOfLatitude->text();
        QString str = "";
        for(int i=0; i<tmp.size(); ++i)
        {
            if(tmp[i] == '.') continue;
            str.append(tmp[i]);
        }
        //qDebug() << str.toInt();
        myField->getTrackList()->at(0)->getStorage()->
                getCurrentObject()->getData()->setLatitude(str.toDouble());
        myField->getTrackList()->at(0)->getStorage()->
                getCurrentObject()->getData()->
                setPos(myField->getTrackList()->at(0)->getStorage()->
                       getCurrentObject()->getData()->scenePos().x(),str.toDouble()-MyPoint::y_max);
    }
}

void MainWindow::on_lineEditOfLongitude_editingFinished()
{
    if(!myField->getTrackList()->isEmpty())
    {
        QString tmp = ui->lineEditOfLongitude->text();
        QString str = "";
        for(int i=0; i<tmp.size(); ++i)
        {
            if(tmp[i] == '.') continue;
            str.append(tmp[i]);
        }
        //qDebug() << str.toInt();
        myField->getTrackList()->at(0)->getStorage()->
                getCurrentObject()->getData()->setLongitude(str.toDouble());
        myField->getTrackList()->at(0)->getStorage()->
                getCurrentObject()->getData()->
                setPos(str.toDouble()-MyPoint::x_max,myField->getTrackList()->at(0)->getStorage()->
                       getCurrentObject()->getData()->scenePos().y());
    }
}

void MainWindow::on_dateEdit_editingFinished()
{
    if(!myField->getTrackList()->isEmpty())
    {
        myField->getTrackList()->at(0)->getStorage()->
                getCurrentObject()->getData()->setDateByQDate(ui->dateEdit->date());
    }
}

void MainWindow::on_timeEdit_editingFinished()
{
    if(!myField->getTrackList()->isEmpty())
    {
        myField->getTrackList()->at(0)->getStorage()->
                getCurrentObject()->getData()->setTimeByQTime(ui->timeEdit->time());
    }
}

void MainWindow::on_SpinBoxHeight_editingFinished()
{
    if(!myField->getTrackList()->isEmpty())
    {
        myField->getTrackList()->at(0)->getStorage()->
                getCurrentObject()->getData()->setHeightBySpinBox(ui->SpinBoxHeight->value()*100);
        myField->getTrackList()->at(0)->computeMinMaxHeight();
        myField->getTrackList()->at(0)->setColorByHeight();
    }
}

void MainWindow::on_action_9_triggered()
{
    myField->addTrackPoint = true;
}

void MainWindow::on_action_11_triggered()
{
    myField->clear();
    myField->getTrackList()->clear();
    myField->setCurTrack(NULL);
}
