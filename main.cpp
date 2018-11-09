#include <QApplication>
#include "statisticbesttime.h"
#include "game.h"
//#include "cards.h"
//#include "timer.h"

Game *game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->displayMainMenu();
    return a.exec();
}
