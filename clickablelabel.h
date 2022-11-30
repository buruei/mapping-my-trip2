#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>
#include <Qt>
#include "editdialog.h"
#include <QMessageBox>


class ClickableLabel : public QLabel {
    Q_OBJECT

public:
    explicit ClickableLabel(int userID, QWidget* parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    ~ClickableLabel();
    QString Content();

signals:
    void clicked();
    void transmit(QString txt);

protected:
    void mousePressEvent(QMouseEvent* event);

private slots:
    void update(QString txt);

private:
    int userID;
    QString content;
    EditDialog *dlg;
};

#endif // CLICKABLELABEL_H
