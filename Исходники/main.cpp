#include "shifr.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shifr w;
    w.show();
    return a.exec();
}
