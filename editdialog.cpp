#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(int userID, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog),
    userID(userID)
{
    ui->setupUi(this);
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_textEdit_textChanged()
{
    readContent();
}

QString EditDialog::readContent()
{
    return ui->textEdit->toPlainText();
}

void EditDialog::on_Save_clicked()
{
    emit transmit(ui->textEdit->toPlainText());
}


void EditDialog::on_Cancel_clicked()
{
    emit close();
}

