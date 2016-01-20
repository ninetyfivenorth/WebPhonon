#ifndef ADDMOVIECASTDIALOG_H
#define ADDMOVIECASTDIALOG_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
namespace Ui {
class AddMovieCastDialog;
}

class AddMovieCastDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddMovieCastDialog(QWidget *parent = 0);
    ~AddMovieCastDialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddMovieCastDialog *ui;
    QSqlDatabase db;
    QSqlQuery *query;
    QSqlQueryModel *model1;
    QSqlQueryModel *model2;
    QString charecter,role;

    int actor_id,movie_id;
};

#endif // ADDMOVIECASTDIALOG_H