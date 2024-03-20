#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "Bag.h"
#include "CheckRules.h"
#include "Observable.h"
#include "directoryBrick/Brick.h"
#include "CommonData.h"
class Game: public Observable
{

private:
    CheckRules rules;
    Board board;
    Bag bag;
    std::unique_ptr<Brick> currentBrick;//pointeur intelligent
    State state;
    std::vector<Position> listOfCurrentPositions;


public:
    Game();


    std::vector<Position> convertStartPositionsBrickToPositionsBoard(const std::vector<Position> & positionsTrue, Position gap);
    bool inBoard(const std::vector<Position> & positionsTrue);
    Position addGap(const Position& p, Position gap);
    bool hasCollisions(const std::vector<Position> & positionsInBoard);
    std::vector<Position> posWithoutOldPos(const std::vector<Position> & newPositionsInBoard);

    void translate(Direction d);
    void rotate(Rotation sens);
    void nextShape();
    void paintStartedBrick();

    const Board& getBoard() const { return board; }
    State getState() const { return state; }


    void setState(State newState) { state = newState; }

};

#endif // GAME_H
