#include "eloadmin.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ELOAdmin w;
    w.show();
    return a.exec();
}
