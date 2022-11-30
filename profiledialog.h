#ifndef PROFILEDIALOG_H
#define PROFILEDIALOG_H

#include <QDialog>
#include "profileentity.h"
#include "dbhelper.h"
#include <string.h>
#include "editdialog.h"
#include "clickablelabel.h"
#include <QFileDialog>

#include <QQuickItem>
#include <QMenu>
#include <QAction>
#include <QPixmap>
#include <QMessageBox>
#include <QString>
#include <QMouseEvent>
#include <QDebug>

namespace Ui {
class ProfileDialog;
}

class ProfileDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProfileDialog(int userID, QWidget *parent = nullptr);
    ~ProfileDialog();
    void update();
    void generate_profile();
    void update_name();
    void update_gender();
    void update_location();
    void update_tagline();

signals:
    void transmit(QString txt);

private slots:
    void on_pushButton_clicked();

private:
    QFont font;
    Ui::ProfileDialog *ui;
    int userID;
    DBHelper db;
    ProfileEntity Profile;
    QList<ClickableLabel*> profile_list;
};

#endif // PROFILEDIALOG_H
