#include "clickablelabel.h"

ClickableLabel::ClickableLabel(int userID, QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent),
    userID(userID)
{
    content = "";
    dlg = new EditDialog(userID, NULL);
    connect(dlg,&EditDialog::transmit,this,&ClickableLabel::update);
}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent* event) {
    dlg -> setModal(true);
    dlg -> setWindowTitle("Edit");
    dlg -> exec();
    content = dlg -> readContent();
    emit clicked();
}

QString ClickableLabel::Content(){
    return content;
}
void ClickableLabel::update(QString txt)
{
    dlg ->close();
    content = txt;
    QMessageBox::information(this,"Message","Successfully Saved");
    emit transmit(txt);
}
