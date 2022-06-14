#ifndef ELOADMIN_H
#define ELOADMIN_H

#include <QMainWindow>
#include <QStandardPaths>
#include <QInputDialog>
#include <QFileDialog>
#include <QTemporaryDir>
#include <QDebug>
#include <QTemporaryFile>
#include <QMessageBox>
#include <QRegularExpression>
#include <algorithm>

#ifdef __linux__
    #include <libssh/libssh.h>
#else
    #include "libssh/libssh.h"
#endif

#include "../ELO/user.h"
#include "../ELO/gitcom.h"

#include "gitoliteConf.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ELOAdmin; }
QT_END_NAMESPACE

class ELOAdmin : public QMainWindow
{
    Q_OBJECT

public:
    ELOAdmin(QWidget *parent = nullptr);
    ~ELOAdmin();

private slots:
    void on_actionquit_triggered();

    void on_actionchange_password_triggered();

    void on_actionLoad_keyfile_triggered();

    void initAdminRepos();

    void readUserFiles();

    void on_userComboBox_currentIndexChanged(int index);

    void on_userSaveButton_clicked();

    void on_exportUserFileButton_clicked();

    void on_userCreateButton_clicked();

    void readUserGroups();

    void readRepos();

    void on_repoComboBox_currentIndexChanged(int index);

    void on_getWriteAccessButton_clicked();

    void on_removeWriteAcccessButton_clicked();

    void on_getReadAccessButton_clicked();

    void on_removeReadAccessButton_clicked();

    void on_repoSaveButton_clicked();

    void saveELOConf();

    void on_repoCreateButton_clicked();

    void on_userGroupComboBox_currentIndexChanged(int index);

    void on_usergroupSaveButton_clicked();

    void on_userGroupSetMemberButton_clicked();

    void on_userGroupUnsetMemberButton_clicked();

    void on_userGroupCreateButton_clicked();

private:
    Ui::ELOAdmin *ui;

    user *activeUser;
    gitCom *gitCommunication;
    QTemporaryDir *AdminDir;
    QVector<user *> userList;
    QVector<userGroup *> userGroupList;
    QVector<repo *> repoList;


protected:
   void closeEvent(QCloseEvent* e) override;

};
#endif // ELOADMIN_H
