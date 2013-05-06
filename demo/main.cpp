#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>

#include <libroxeetorrent/session.h>
#include <libroxeetorrent/root.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    new RoxeeTorrent::Session(QString::fromLatin1("RX"), 1, 0, 0, 0);
    new RoxeeTorrent::Root();

    return app.exec();
}
