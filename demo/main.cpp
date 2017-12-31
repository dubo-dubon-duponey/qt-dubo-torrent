#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>

#include <libdubotorrent/session.h>
#include <libdubotorrent/root.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    new DuboTorrent::Session(QString::fromLatin1("RX"), 1, 0, 0, 0);
    new DuboTorrent::Root();

    return app.exec();
}
