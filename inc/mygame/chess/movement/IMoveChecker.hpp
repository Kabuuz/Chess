#ifndef MYGAME_CHESS_MOVEMENT_IMOVECHECKER_HPP
#define MYGAME_CHESS_MOVEMENT_IMOVECHECKER_HPP

#include <memory>
#include <mygame/chess/movement/fwd.hpp>
#include <mygame/chess/table/File.hpp>
#include <mygame/chess/table/Rank.hpp>
#include <utility>
#include <vector>

namespace chess
{
namespace movement
{
using Position = std::pair<table::Rank, table::File>;

class IMoveChecker
{
public:
    virtual std::vector<Position> getAvailablePositions(const Position& actualPosition) const = 0;
    virtual IMoveCheckerPtr clone() const = 0;

    virtual ~IMoveChecker() = default;
};
}  // namespace movement
}  // namespace chess

#endif  // MYGAME_CHESS_MOVEMENT_IMOVECHECKER_HPP
