#include <QApplication>

#include "statisticbesttime.h"
#include "game.h"
#include "database.h"

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    DataBase db;
    db.connect();

    game = new Game();
    game->show();
    //game->showFullScreen();
    game->displayMainMenu();
    return a.exec();
}
