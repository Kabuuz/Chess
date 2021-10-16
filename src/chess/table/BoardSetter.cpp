#include <mygame/chess/table/BoardSetter.hpp>
#include <algorithm>
#include <iostream>

namespace chess
{
namespace table
{

BoardSetter::BoardSetter() = default;

void BoardSetter::setBoard(Board& board, const std::vector<std::unique_ptr<figure::FigureBase>>& figures)
{
    for(const auto& figure : figures)
    {
        setFigureOnBoard(board, *figure);
    }
}

void BoardSetter::setFigureOnBoard(Board& board, const figure::FigureBase& figure)
{
    FigurePositions figurePositions;
    switch(figure.getColor())
    {
        case figure::FigureColor::White:
            figurePositions = getWhiteFigurePositions(figure.getType());
            break;
        case figure::FigureColor::Black:
            figurePositions = getBlackFigurePositions(figure.getType());
            break;
    }

    auto availablePositionIter = std::find_if(figurePositions.begin(),figurePositions.end(),[&board](const auto& position)
    {
        const auto& [rank, file] = position;
        return !(board.isFigurePresent(rank, file));
    });

    if(availablePositionIter != figurePositions.end())
    {
        const auto& [rank, file] = *availablePositionIter;
        board.setFigure(const_cast<figure::FigureBase*>(&figure), rank, file);
    }
    else
    {
        std::cout << "[ERR][BoardSetter] setFigureOnBoard : no available position" << std::endl;
        return;
    }
}

FigurePositions BoardSetter::getBlackFigurePositions(const figure::FigureType type)
{
    switch(type)
    {
        case figure::FigureType::Pawn:
            return getBlackPawnPositions();
            break;
        case figure::FigureType::Rook:
            return getBlackRookPositions();
            break;
        case figure::FigureType::Bishop:
            return getBlackBishopPositions();
            break;
        case figure::FigureType::Knight:
            return getBlackKnightPositions();
            break;
        case figure::FigureType::Queen:
            return getBlackQueenPositions();
            break;
        case figure::FigureType::King:
            return getBlackKingPositions();
            break;
    }

    return {};
}

FigurePositions BoardSetter::getWhiteFigurePositions(const figure::FigureType type)
{
    switch(type)
    {
        case figure::FigureType::Pawn:
            return getWhitePawnPositions();
            break;
        case figure::FigureType::Rook:
            return getWhiteRookPositions();
            break;
        case figure::FigureType::Bishop:
            return getWhiteBishopPositions();
            break;
        case figure::FigureType::Knight:
            return getWhiteKnightPositions();
            break;
        case figure::FigureType::Queen:
            return getWhiteQueenPositions();
            break;
        case figure::FigureType::King:
            return getWhiteKingPositions();
            break;
    }

    return {};
}

FigurePositions BoardSetter::getBlackPawnPositions()
{
    FigurePositions positions;
    for(File file='a'; file<MINIMAL_FILE+BOARD_WIDTH; file++)
    {
        positions.push_back({7,file});
    }
    return positions;
}

FigurePositions BoardSetter::getBlackRookPositions()
{
    return {{8,'a'},{8,'h'}};
}

FigurePositions BoardSetter::getBlackBishopPositions()
{
    return {{8,'c'},{8,'f'}};
}

FigurePositions BoardSetter::getBlackKnightPositions()
{
    return {{8,'b'},{8,'g'}};
}

FigurePositions BoardSetter::getBlackQueenPositions()
{
    return {{8,'d'}};
}

FigurePositions BoardSetter::getBlackKingPositions()
{
    return {{8,'e'}};
}

FigurePositions BoardSetter::getWhitePawnPositions()
{
    FigurePositions positions;
    for(File file='a'; file<MINIMAL_FILE+BOARD_WIDTH; file++)
    {
        positions.push_back({2,file});
    }
    return positions;
}

FigurePositions BoardSetter::getWhiteRookPositions()
{
    return {{1,'a'},{1,'h'}};
}

FigurePositions BoardSetter::getWhiteBishopPositions()
{
    return {{1,'c'},{1,'f'}};
}

FigurePositions BoardSetter::getWhiteKnightPositions()
{
    return {{1,'b'},{1,'g'}};
}

FigurePositions BoardSetter::getWhiteQueenPositions()
{
    return {{1,'d'}};
}

FigurePositions BoardSetter::getWhiteKingPositions()
{
    return {{1,'e'}};
}

}  // namespace table
}  // namespace chess
