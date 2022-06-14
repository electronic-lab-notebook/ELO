#include "eloadmin.h"
#include "./ui_eloadmin.h"

ELOAdmin::ELOAdmin(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ELOAdmin)
{
    ui->setupUi(this);

    // GitCom
    gitCommunication = new gitCom(this);

    // user
    activeUser = new user();

    // enable actions
    ui->actionchange_password->setEnabled(false);

    // init TemponaryDirs
    AdminDir = nullptr;

    ui->tabWidget->setEnabled(false);
}

ELOAdmin::~ELOAdmin()
{
    delete gitCommunication;
    delete activeUser;
    if (AdminDir != nullptr)
        delete AdminDir;
    delete ui;
}


void ELOAdmin::on_actionquit_triggered()
{
    QApplication::quit();
}

void ELOAdmin::on_actionchange_password_triggered()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Old password required"), tr("Old password"), QLineEdit::Password, "", &ok);
    if (ok) {
        if(activeUser->tryPassword(activeUser->getKeyFile(), text.toUtf8())) {
            bool ok2, ok3;
            QString text2 = QInputDialog::getText(this, tr("New password required"), tr("new password"), QLineEdit::Password, "", &ok2);
            QString text3 = QInputDialog::getText(this, tr("New password required"), tr("repeat new password"), QLineEdit::Password, "", &ok3);
            if(ok2 && ok3) {
                if(text2 == text3) {
                     // change the password
                     // get place to save the new user file
                    QString fileName = QFileDialog::getSaveFileName(this, tr("Where to save the new user file?"), QDir::homePath());
                     //changing the password
                    activeUser->changePassword(fileName, text2.toUtf8());
                    QMessageBox::information(this, tr("Password changed"), tr("Your Password is changed now."));
                } else {
                    // password repetition not successfull
                    QMessageBox::critical(this, tr("Verification failed"), tr("The new passwords were not the same. Aborting!"));
                }
            }
        } else {
            QMessageBox::critical(this, tr("wrong password"), tr("The entered password is wrong. Aborting!"));
        }
    }
}

void ELOAdmin::on_actionLoad_keyfile_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("UserFile"), QDir::homePath(), tr("All files (*)"));

    if(!fileName.isEmpty()) { // file selected
        // ask for the password
        bool ok;
        QString text = QInputDialog::getText(this, tr("Password required"), tr("Password"), QLineEdit::Password, "", &ok);
        if (ok) {
            // password dialog successfull
            if(activeUser->tryPassword(fileName, text.toUtf8())) { // check the password
                // open the file and read
                AdminDir = new QTemporaryDir();
                activeUser->setConfigSavePath(AdminDir->path());
                activeUser->loadUserFile(fileName, text.toUtf8());
                gitCommunication->getInfo(activeUser);
                ui->statusbar->showMessage(tr("user loaded succesfully"),2000);
                initAdminRepos();
            } else { // wrong password
                QMessageBox::critical(this, tr("wrong password"), tr("The entered password is wrong. Aborting!"));
            }
        }
    } else { //no file selected
        ui->statusbar->showMessage(tr("error loading user"),2000);
    }
}

void ELOAdmin::initAdminRepos()
{
    QJsonObject repos = activeUser->getRepoPermissions();
    QStringList keys = repos.keys();
    if (!keys.contains("gitolite-admin") || !keys.contains("ELO-admin")) {
        ui->statusbar->showMessage(tr("Error: loaded user has no admin permissions. Aborting!"));
        return;
    }
    gitCommunication->setWorkingDir(AdminDir->path());
    gitCommunication->doTheClone(activeUser, "gitolite-admin");
    gitCommunication->doTheClone(activeUser, "ELO-admin");
    ui->tabWidget->setEnabled(true);
    ui->actionchange_password->setEnabled(true);
    readUserFiles();
    readUserGroups();
    readRepos();
}

void ELOAdmin::readUserFiles()
{
    QDir dir(AdminDir->path() + QDir::separator() + "ELO-admin");
    QStringList files = dir.entryList(QDir::Files, QDir::Name | QDir::IgnoreCase);
    userList.clear();
    foreach (QString s, files) {
        if (s != "README") {
            QFile f(AdminDir->path() + QDir::separator() + "ELO-admin" + QDir::separator() + s);
            if (f.open(QIODevice::ReadOnly)) {
                user *u = new user();
                u->readUserFile(f.readAll());
                userList.append(u);
            }
        }
    }

    ui->userComboBox->clear();
    foreach (user *u, userList) {
        ui->userComboBox->addItem(u->getName());
    }
}

void ELOAdmin::on_userComboBox_currentIndexChanged(int index)
{
    user *u = userList.at(index);
    ui->usernameEdit->setText(u->getUserName());
    ui->fullNameEdit->setText(u->getName());
    ui->eMailEdit->setText(u->getEMail());
    ui->serverEdit->setText(u->getServer());
    ui->passwordEdit->setText(u->getWebPassword());
    ui->additionalInformationEdit->setPlainText(u->getAdditionalInformation());
}

void ELOAdmin::on_userSaveButton_clicked()
{
    user *u = userList.at((ui->userComboBox->currentIndex()));
    u->setName(ui->fullNameEdit->text());
    u->setEMail(ui->eMailEdit->text());
    u->setServer(ui->serverEdit->text());
    u->setWebPassword(ui->passwordEdit->text());
    u->setAdditionalInformation(ui->additionalInformationEdit->toPlainText());
    u->setConfigSavePath(AdminDir->path() + QDir::separator() + "ELO-admin");
    u->saveUserFileAsPlainText();
    gitCommunication->doTheCommit(activeUser, "update of " + ui->usernameEdit->text(), "ELO-admin");
}


void ELOAdmin::on_exportUserFileButton_clicked()
{
    QMessageBox::StandardButton btn = QMessageBox::question(this, tr("Set password?"), tr("Should a password for the file be set?"));
    QString pw;
    if (btn == QMessageBox::Yes) {
        bool ok;
        QString pw1 = QInputDialog::getText(this, tr("Password"), tr("Enter a password!"), QLineEdit::Normal, QString(), &ok);
        if (!ok)
            return;

        QString pw2 = QInputDialog::getText(this, tr("Password confirmation"), tr("Enter a password antoher time for confirmation!"), QLineEdit::Normal, QString(), &ok);
        if (!ok)
            return;

        if (pw1 != pw2) {
            QMessageBox::warning(this, tr("Confirmation failed!"), tr("The entered passwords were not the same! Aborting"));
            return;
        }
        pw = pw1;
    }

    QString fileName = QFileDialog::getSaveFileName(this, tr("Save user file"), QDir::homePath(), tr("ELO user files (*.elouser"));

    if (fileName.isEmpty())
        return;
    if (!fileName.endsWith(".elouser"))
        fileName = fileName + ".elouser";
    user *u = userList.at((ui->userComboBox->currentIndex()));
    u->saveUserFile(fileName, pw.toUtf8());
}

void ELOAdmin::on_userCreateButton_clicked()
{
    QString username = QInputDialog::getText(this, tr("set username"), tr("What is the users name?"));
    if (username.isEmpty()) {
        return;
    }

    // generating a key pair
    ssh_key privkey = ssh_key_new();
    ssh_key pubkey = ssh_key_new();

    int ret = ssh_pki_generate(SSH_KEYTYPE_RSA, 4096, &privkey);
    if(ret != SSH_OK) {
        return;
    }

    ssh_pki_export_privkey_to_pubkey(privkey, &pubkey);

    // export key pair
    QTemporaryFile privatKey;
    privatKey.open();
    QTemporaryFile publicKey;
    publicKey.open();
    ssh_pki_export_privkey_file(privkey, NULL, NULL, NULL, privatKey.fileName().toLocal8Bit());
    ssh_pki_export_pubkey_file(pubkey, publicKey.fileName().toLocal8Bit());

    // start creating user
    ui->fullNameEdit->clear();
    ui->eMailEdit->clear();
    ui->serverEdit->clear();
    ui->additionalInformationEdit->setPlainText("{}");

    user *u  = new user();
    u->setUserName(username);

    // read keyfiles
    privatKey.seek(0);
    u->setPrivateKey(QString(privatKey.readAll()));

    publicKey.seek(0);
    u->setPublicKey(QString(publicKey.readAll()));

    // add to userComboBox
    ui->userComboBox->addItem(username);
    userList.append(u);
    ui->userComboBox->setCurrentIndex(ui->userComboBox->count()-1);

    // save the new file
    u->setConfigSavePath(AdminDir->path() + QDir::separator() + "ELO-admin");
    u->saveUserFileAsPlainText();

    QFile f(AdminDir->path() + QDir::separator() + "gitolite-admin" + QDir::separator() + "keydir" + QDir::separator() + "ELO" + QDir::separator() + u->getUserName().remove("_") + ".pub");
    if (f.open(QIODevice::WriteOnly)) {
        f.write(u->getPublicKey());
        f.close();
    }

    gitCommunication->doTheCommit(activeUser, "add user " + u->getUserName(), "ELO-admin");
    gitCommunication->doTheCommit(activeUser, "add keyfile of " + u->getUserName(), "gitolite-admin");

    readUserGroups();
    readRepos();
}

void ELOAdmin::readUserGroups()
{
    userGroupList.clear();
    QRegularExpression userGroupExpression("\\s*(@[^\\s]+)\\s*=\\s*(.+)");
    QFile f(AdminDir->path() + QDir::separator() + "gitolite-admin" + QDir::separator() + "conf" + QDir::separator() + "ELO.conf");
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream in(&f);
        in.setEncoding(QStringConverter::Utf8);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QRegularExpressionMatch userGroupMatch = userGroupExpression.match(line);
            if (userGroupMatch.hasMatch()) {
                userGroup *ug = new userGroup(userGroupMatch.captured(1));
                userGroupList.append(ug);

                foreach (user *u, userList) {
                    ug->appendNoMember(u->getUserName().remove("_"));
                }

                foreach (QString s, userGroupMatch.captured(2).split(QRegularExpression("\\s+"), Qt::SkipEmptyParts)) {
                    ug->appendMember(s);
                }
            }
        }

        ui->userGroupComboBox->clear();
        foreach (userGroup *ug, userGroupList) {
            ui->userGroupComboBox->addItem(ug->getName());
        }
    }
}

void ELOAdmin::readRepos()
{
    repoList.clear();

    QRegularExpression repoExpression("\\s*repo\\s*([^\\s]+)");
    QRegularExpression ruleRExpression("\\s*R\\s*=\\s*(.+)");
    QRegularExpression ruleRWExpression("\\s*RW\\+\\s*=\\s*(.+)");

    QFile f(AdminDir->path() + QDir::separator() + "gitolite-admin" + QDir::separator() + "conf" + QDir::separator() + "ELO.conf");
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream in(&f);
        in.setEncoding(QStringConverter::Utf8);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QRegularExpressionMatch repoMatch = repoExpression.match(line);
            if (repoMatch.hasMatch()) {
                repo *r = new repo(repoMatch.captured(1));

                foreach (user *u, userList) {
                    r->appendNoAccess(u->getUserName().remove("_"));
                }
                foreach (userGroup *ug, userGroupList) {
                    r->appendNoAccess(ug->getName());
                }

                while (!line.trimmed().isEmpty()) {
                    QRegularExpressionMatch ruleRMatch = ruleRExpression.match(line);
                    if (ruleRMatch.hasMatch()) {
                        r->appendR(ruleRMatch.captured(1));
                    }

                    QRegularExpressionMatch ruleRWMatch = ruleRWExpression.match(line);
                    if (ruleRWMatch.hasMatch()) {
                        r->appendRW(ruleRWMatch.captured(1));
                    }
                    line = in.readLine();
                }
                repoList.append(r);
            }
        }
    }

    ui->repoComboBox->clear();
    std::sort(repoList.begin(), repoList.end());
    foreach (repo *r, repoList) {
        ui->repoComboBox->addItem(r->getName());
    }
}

void ELOAdmin::closeEvent(QCloseEvent *e)
{
    if (ui->actionchange_password->isEnabled()) {
        gitCommunication->doThePush(activeUser, "ELO-admin");
        gitCommunication->doThePush(activeUser, "gitolite-admin");
    }
    gitCommunication->setClose(true);
    QMainWindow::closeEvent(e);
}

void ELOAdmin::on_repoComboBox_currentIndexChanged(int index)
{
    if (index < 0)
        return;
    ui->repoNoAccessList->clear();
    ui->repoReadAccessList->clear();
    ui->repoWriteAccessList->clear();

    repo *r = repoList.at(index);

    ui->repoNoAccessList->addItems(r->getNoAccess());
    ui->repoNoAccessList->sortItems();
    ui->repoReadAccessList->addItems(r->getAccessR());
    ui->repoReadAccessList->sortItems();
    ui->repoWriteAccessList->addItems(r->getAccessRW());
    ui->repoWriteAccessList->sortItems();
}

void ELOAdmin::on_getWriteAccessButton_clicked()
{
    QListWidgetItem *item = ui->repoNoAccessList->currentItem();
    if (item) {
        QString userName = item->text();
        int index = ui->repoComboBox->currentIndex();
        repo *r = repoList.at(index);
        r->appendRW(userName);
        on_repoComboBox_currentIndexChanged(index);
    }
}

void ELOAdmin::on_removeWriteAcccessButton_clicked()
{
    QListWidgetItem *item = ui->repoWriteAccessList->currentItem();
    if (item) {
        QString userName = item->text();
        int index = ui->repoComboBox->currentIndex();
        repo *r = repoList.at(index);
        r->removeRW(userName);
        on_repoComboBox_currentIndexChanged(index);
    }
}

void ELOAdmin::on_getReadAccessButton_clicked()
{
    QListWidgetItem *item = ui->repoNoAccessList->currentItem();
    if (item) {
        QString userName = item->text();
        int index = ui->repoComboBox->currentIndex();
        repo *r = repoList.at(index);
        r->appendR(userName);
        on_repoComboBox_currentIndexChanged(index);
    }
}

void ELOAdmin::on_removeReadAccessButton_clicked()
{
    QListWidgetItem *item = ui->repoReadAccessList->currentItem();
    if (item) {
        QString userName = item->text();
        int index = ui->repoComboBox->currentIndex();
        repo *r = repoList.at(index);
        r->removeR(userName);
        on_repoComboBox_currentIndexChanged(index);
    }
}

void ELOAdmin::on_repoSaveButton_clicked()
{
    saveELOConf();
}

void ELOAdmin::saveELOConf()
{
    QFile f(AdminDir->path() + QDir::separator() + "gitolite-admin" + QDir::separator() + "conf" + QDir::separator() + "ELO.conf");
    if (f.open(QIODevice::WriteOnly)) {
        QTextStream out(&f);
        out.setEncoding(QStringConverter::Utf8);
        // write user groups -- ToDo
        foreach (userGroup *ug, userGroupList) {
            out << ug->getName() << " = " << ug->getMembers().join(" ") << Qt::endl;
        }

        // write repos
        foreach (repo *r, repoList) {
            out << Qt::endl;
            out << "repo " << r->getName() << Qt::endl;
            foreach (QString u, r->getAccessR()) {
                out << "\tR = " << u << Qt::endl;
            }
            foreach (QString u, r->getAccessRW()) {
                out << "\tRW+ = " << u << Qt::endl;
            }
            out << Qt::endl;
        }
        out.flush();
        f.close();
    }
    gitCommunication->doTheCommit(activeUser, "update repo and user groups", "gitolite-admin");
    ui->statusbar->showMessage("User group and repo config saved");
}

void ELOAdmin::on_repoCreateButton_clicked()
{
    QString repoName = QInputDialog::getText(this, tr("set repo name"), tr("What is the name of the new repo (connot be changed afterwards)?"));
    if (repoName.isEmpty())
        return;

    // create the repo
    repo *r = new repo(repoName);
    repoList.append(r);

    foreach (user *u, userList) {
        r->appendNoAccess(u->getUserName().remove("_"));
    }

    r->appendRW("@eloAdmin");
    ui->repoComboBox->addItem(repoName);
    ui->repoComboBox->setCurrentIndex(ui->repoComboBox->count() - 1);
    saveELOConf();
    gitCommunication->doTheCommit(activeUser, "add repo " + repoName, "gitolite-admin");
    gitCommunication->doThePush(activeUser, "gitolite-admin");

    gitCommunication->doTheClone(activeUser, repoName);
    gitCommunication->doInitialCommit(activeUser, repoName);
    gitCommunication->doThePush(activeUser, repoName);
}

void ELOAdmin::on_userGroupComboBox_currentIndexChanged(int index)
{
    if (index < 0)
        return;
    ui->userGroupNoMemberList->clear();
    ui->userGroupMemberList->clear();

    userGroup *ug = userGroupList.at(index);

    ui->userGroupNoMemberList->addItems(ug->getNoMembers());
    ui->userGroupMemberList->addItems(ug->getMembers());
}

void ELOAdmin::on_usergroupSaveButton_clicked()
{
    saveELOConf();
}

void ELOAdmin::on_userGroupSetMemberButton_clicked()
{
    QListWidgetItem *item = ui->userGroupNoMemberList->currentItem();
    if (item) {
        QString userName = item->text();
        int index = ui->userGroupComboBox->currentIndex();
        userGroup *ug = userGroupList.at(index);
        ug->appendMember(userName);
        on_userGroupComboBox_currentIndexChanged(index);
    }
}

void ELOAdmin::on_userGroupUnsetMemberButton_clicked()
{
    QListWidgetItem *item = ui->userGroupMemberList->currentItem();
    if (item) {
        QString userName = item->text();
        int index = ui->userGroupComboBox->currentIndex();
        userGroup *ug = userGroupList.at(index);
        ug->appendNoMember(userName);
        on_userGroupComboBox_currentIndexChanged(index);
    }
}

void ELOAdmin::on_userGroupCreateButton_clicked()
{
    QString userGroupName = QInputDialog::getText(this, tr("set user group name"), tr("What is the name of the new user group (connot be changed afterwards)?"));
    if (userGroupName.isEmpty())
        return;

    // create the repo
    if (!userGroupName.startsWith("@"))
        userGroupName = "@" + userGroupName;
    userGroup *ug = new userGroup(userGroupName);
    userGroupList.append(ug);

    foreach (user *u, userList) {
        ug->appendNoMember(u->getUserName().remove("_"));
    }

    ui->userGroupComboBox->addItem(userGroupName);
    ui->userGroupComboBox->setCurrentIndex(ui->userGroupComboBox->count() - 1);
    saveELOConf();
    gitCommunication->doTheCommit(activeUser, "add user group " + userGroupName, "gitolite-admin");

    readRepos();
}
