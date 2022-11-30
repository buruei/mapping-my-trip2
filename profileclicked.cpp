#include "profileclicked.h"

ProfileClicked::ProfileClicked(int userID, QWidget* parent, Qt::WindowFlags f)
    : QLabel(parent),
      userID(userID)
{
    dialog = new ProfileDialog(userID);
    connect(dialog,&ProfileDialog::transmit,this,&ProfileClicked::update);
}

ProfileClicked::~ProfileClicked() {}

void ProfileClicked::mousePressEvent(QMouseEvent* event) {
    dialog -> setWindowTitle("Profile");
    dialog -> setModal(true);
    dialog -> exec();
    emit clicked();
}

void ProfileClicked::update(QString txt)
{
    emit transmit(txt);
}
