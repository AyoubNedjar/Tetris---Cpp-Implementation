#include "Controller.h"
#include <iostream>

using namespace std;

Controller::Controller(Game& g, View v): game(g), view(v){};


/**
 * va etre executer quand rotate , translate vont etre excuter car ils auront notifier le controller et
 * ce dernier executera la methode update
 * @brief Controller::update
 */
void Controller::update(){

    view.displayInfosGame(game);
    view.displayBoard(game.getBoard());
    game.updateStateIfVictory();
}

/**
 * Ici il y aura le boucle de jeu
 * @brief Controller::start
 */
void Controller::start(){
    // string userInput;
    char userInput;
    std::cout<<"bienvenue voici le board ";
    view.displayBoard(game.getBoard());
    int i = 0;
    while (cin>>userInput && game.getState()==State::PLAYING){
        switch(userInput){
        case 's' :
            game.translateWithDropOrNot(Direction::DOWN, false);
            break;
        case 'q' :
            game.translateWithDropOrNot(Direction::LEFT, false);
            break;
        case 'd' :
            game.translateWithDropOrNot(Direction::RIGHT, false);
            break;
        case 'e' :
            game.rotate(Rotation::CLOCKWISE);
            break;
        case 'a' :
            game.rotate(Rotation::ANTI_CLOCKWISE);
            break;
        case 'w' :
            game.drop();
            break ;
        }
        if (game.getNbLigneComplete()>=10){
            *(game.getNiveau()) = (game.getNbLigneComplete()/10)+1 ;
        }
    }
    view.displayState(game);
}

