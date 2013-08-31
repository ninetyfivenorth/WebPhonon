#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Phonon/AudioOutput>
#include <Phonon/MediaObject>
#include <QFileDialog>
#include <Phonon/BackendCapabilities>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Phonon::AudioOutput *sndout=new Phonon::AudioOutput(Phonon::VideoCategory,this);
    med=new Phonon::MediaObject(this);
    Phonon::createPath(med,ui->VideoWidget);
    Phonon::createPath(med,sndout);
    ui->seekSlider->setMediaObject(med);
    ui->volumeSlider->setAudioOutput(sndout);
    ui->lineEdit->hide();

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionLocal_File_triggered()
{
    QString fname=QFileDialog::getOpenFileName(this,tr("Choose Files"));
    med->setCurrentSource(Phonon::MediaSource(QUrl(fname)));
}


void MainWindow::on_actionHttp_Stream_triggered()
{
    ui->lineEdit->show();
    QString uname;
    uname.insert(0,ui->lineEdit->text());
    med->setCurrentSource(Phonon::MediaSource(QUrl(uname)));
}

void MainWindow::on_actionPlay_triggered()
{
    med->play();
    ui->lineEdit->hide();
}

void MainWindow::on_actionPause_triggered()
{
    if(med->state()==Phonon::PlayingState)
    med->pause();
    else
        med->play();
}

void MainWindow::on_actionStop_triggered()
{
    med->clearQueue();
    med->stop();



}

void MainWindow::on_actionFull_Screen_triggered()
{

   if(ui->VideoWidget->isFullScreen()==false)
   {
        ui->VideoWidget->setFullScreen(true);

   }
   else
   {

      ui->VideoWidget->setFullScreen(false);
   }


}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}
