#ifndef GITOLITECONF_H
#define GITOLITECONF_H

#include <QString>
#include <QStringList>

class repo {
public:
    repo(QString name) { repoName = name; }

    void appendNoAccess(QString username) { noAccess.append(username); }
    void appendR(QString username) { accessR.append(username); noAccess.removeOne(username); }
    void appendRW(QString username) { accessRW.append(username); noAccess.removeOne(username); }
    void removeR(QString username) { accessR.removeOne(username); noAccess.append(username); }
    void removeRW(QString username) { accessRW.removeOne(username); noAccess.append(username); }

    QString getName() { return repoName; }
    QStringList getNoAccess() { return noAccess; }
    QStringList getAccessR() { return accessR; }
    QStringList getAccessRW() { return accessRW; }

    bool operator<(const repo &r) const {
        return (this->repoName < r.repoName);
    }

private:
    QString repoName;
    QStringList accessR;
    QStringList accessRW;
    QStringList noAccess;
};

class userGroup {
public:
    userGroup(QString name) { groupName = name; }
    void appendNoMember(QString username) { noMembers.append(username); members.removeOne(username); }
    void appendMember(QString username) { members.append(username); noMembers.removeOne(username); }

    QString getName() { return groupName; }
    QStringList getMembers() { return members; }
    QStringList getNoMembers() { return noMembers; }

private:
    QString groupName;
    QStringList members;
    QStringList noMembers;
};

#endif // GITOLITECONF_H
