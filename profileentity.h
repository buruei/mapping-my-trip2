#ifndef PROFILEENTITY_H
#define PROFILEENTITY_H

#include <QString>
#include <QBitArray>

class ProfileEntity
{
public:
    ProfileEntity();
    ProfileEntity(int userID, QString Name, int Gender, QString Tagline, QString fileName, QString Location, QString createTime);

    int getuserID() const;
    QString getName() const;
    QString getLocation() const;
    QString getTagline() const;
    int getGender() const;
    const QString &getFileName() const;
    QString getCreateTime() const;
    QString getRealGender() const;
    void newName(QString);
    void newLocation(QString);
    void newTagline(QString);
    void newGender(int);
    void newfileName(QString);

private:
    int userID;
    QString Name;
    int Gender;
    QString Tagline;
    QString fileName;
    QString Location;
    QString createTime;
};

#endif // PROFILEENTITY_H
