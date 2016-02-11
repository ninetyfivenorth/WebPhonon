#ifndef ADDMVDIALOG_H
#define ADDMVDIALOG_H

#include <QDialog>
#include <QFileDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlError>
namespace Ui {
class AddMVDialog;
}

class AddMVDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMVDialog(QWidget *parent = 0);
    ~AddMVDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddMVDialog *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlQueryModel *model;
    QString url;
    int music_id;
};

#endif // ADDMVDIALOG_H
