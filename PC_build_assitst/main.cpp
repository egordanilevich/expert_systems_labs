#include "pc_build_assist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PC_build_assist w;
    w.show();
    return a.exec();
}
