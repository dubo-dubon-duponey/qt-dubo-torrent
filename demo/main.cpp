#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>

#include <libroxeetorrent/session.h>
#include <libroxeetorrent/root.h>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    RoxeeTorrent::Session * rLibTorrent = new RoxeeTorrent::Session(QString::fromLatin1("RX"), 1, 0, 0, 0);
    RoxeeTorrent::Root * rLibTorrentRoot = new RoxeeTorrent::Root();

    return app.exec();
}
