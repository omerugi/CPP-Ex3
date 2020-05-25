//
// Created by omerugi on 24/05/2020.
//

#include <cassert>
#include "doctest.h"
#include "DemoGame.hpp"
#include "FootSoldier.hpp"
#include "FootCommander.hpp"

using namespace WarGame;

Board board(32, 32);
TEST_CASE("game 1"){
    assert(!board.has_soldiers(1));
    board[{0, 1}] = new FootSoldier(1);
    board[{0, 3}] = new FootCommander(1);
    board[{0, 5}] = new FootSoldier(1);
    assert(board.has_soldiers(1));

    assert(!board.has_soldiers(2));
    board[{7, 1}] = new FootSoldier(2);
    board[{7, 3}] = new FootCommander(2);
    board[{7, 5}] = new FootSoldier(2);
    assert(board.has_soldiers(2));

    for (int i = 0; i < 16; i++) {
        CHECK_NOTHROW(board.move(1, {0+i, 1}, Board::MoveDIR::Down));// FootSoldier of player 1 moves forward and attacks.
        CHECK_NOTHROW(board.move(2, {31-i, 1}, Board::MoveDIR::Up));    // FootSoldier of player 2 moves forward and attacks.
        CHECK_NOTHROW(board.move(1, {0+i, 3},Board::MoveDIR::Down));      // FootCommander of player 1 moves forward, and all soldiers of player 1 attack.
        CHECK_NOTHROW(board.move(2, {31-i, 3},Board::MoveDIR::Up));      // FootCommander of
        CHECK_NOTHROW(board.move(1, {0+i, 5}, Board::MoveDIR::Down));
        CHECK_NOTHROW(board.move(2, {31-i, 5}, Board::MoveDIR::Up));    // FootSoldier of player 2 moves forward and attacks.
	}
}
TEST_CASE("error"){
    CHECK_THROWS(board.move(2, {0, 1}, Board::MoveDIR::Down));
    CHECK_THROWS(board.move(2, {0, 2}, Board::MoveDIR::Down));

    CHECK_THROWS(board.move(2, {0, 2}, Board::MoveDIR::Up));
    CHECK_THROWS(board.move(2, {31, 5}, Board::MoveDIR::Down));

}
