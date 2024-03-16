#ifndef BOARD_H
#define BOARD_H

#include "CommonData.h"
#include <vector>
#include "Position.h"
#include <memory>
#include <map>
#include "directoryBrick/Brick.h"
class Board
{
private :
    int height;
    int width;
    std::vector<std::vector<CaseType>> board;
    static std::map<const std::type_info*, CaseType> brickTypeToCaseType;


public:
    Board();
    Board(int height, int width);

    bool inBoard(Position pos);
    std::vector<int> getCompleteLines();//va retourner les lines completes
    void removeCompletesLines(std::vector<int> linesList);//va supprimer les lignes complete, ce qui
    //veut dire de faire un decallage des brique en glissant tt les blacks du dessus vers le bas

    void insert(Position p, std::unique_ptr<Brick> b);
    void deleteOldBrick(Position p);

    CaseType getType(Position p);
    const int getHeight() const;;
    const int getWidth() const;
    const std::vector<std::vector<CaseType>>& getBoard() const;

    void setHeight(int newHeight);;
    void setWidth(int newWidth);;



};

#endif // BOARD_H
