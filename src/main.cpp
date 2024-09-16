#include <QApplication>
#include "view.h"

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    View v;
    v.setWindowTitle(QStringLiteral("Arrow Defense Game Qt/C++"));
    v.show();
    a.exec();
}
