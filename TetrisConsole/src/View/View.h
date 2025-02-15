#ifndef VIEW_H
#define VIEW_H



#include "../Model/Game.h"
class View
{
public:
    View();
    void displayBoard(const Board& board);
    void displayInfosGame(Game& game);
    void displayMessage(std::string message);
    void displayState(Game& game);
    void displayCommand();

private :
    void displayScore(Game& game);
    void displayNbLigneComplete(Game& game);
    void displayNiveau(Game& game);

};

#endif // VIEW_H
