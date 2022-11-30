#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include "profileentity.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EditDialog(int userID, QWidget *parent = nullptr);
    ~EditDialog();
    QString readContent();

signals:
    void transmit(QString txt);

private slots:
    void on_pushButton_2_clicked();

    void on_Save_clicked();

    void on_textEdit_textChanged();

    void on_Cancel_clicked();

private:
    Ui::EditDialog *ui;
    int userID;
};

#endif // EDITDIALOG_H
