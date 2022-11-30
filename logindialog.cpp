#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"

#include <QDebug>
#include <QMessageBox>

#include "dbhelper.h"

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QPixmap pix(":/tourists.png");
    ui->label_tourist->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio));
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_registerButton_clicked()
{
    RegisterDialog dialog;
    int result = dialog.exec();
    if(result==QDialog::DialogCode::Accepted) {
        ui->userNameLineEdit->setText(dialog.getUserName());
        ui->passwordLineEdit->setText(dialog.getPassword());
    }
}

void LoginDialog::on_loginButton_clicked()
{
    DBHelper helper;
    helper.open();
    int userId = helper.checkUser(ui->userNameLineEdit->text(), ui->passwordLineEdit->text());
    if(userId>=0) {
        map= new MapDialog(userId);
        map->show();
        hide();
    } else {
        QMessageBox::information(this, "Error", "Login failed");
    }
    helper.close();
}



