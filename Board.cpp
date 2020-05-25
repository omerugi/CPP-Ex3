//
// Created by omerugi on 24/05/2020.
//

#include <string>
#include <vector>
#include <stdexcept>
#include "Soldier.hpp"
#include "Board.hpp"

using namespace WarGame;

Soldier *&Board::operator[](std::pair<int, int> location) {
    return board[location.first][location.second];
}

Soldier *Board::operator[](std::pair<int, int> location) const {
    return nullptr;
}

void Board::move(uint player_number, std::pair<int, int> source, Board::MoveDIR direction) {

}

bool Board::has_soldiers(uint player_number) const {

    for (const auto & i : board) {
        for (auto j : i) {
            if(j != nullptr && j->player == player_number)
                return true;
        }
    }
    return false;
}
