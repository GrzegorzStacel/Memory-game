#include <QApplication>
#include "statisticbesttime.h"
#include "game.h"

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    //game->showFullScreen();
    game->displayMainMenu();
    return a.exec();
}
