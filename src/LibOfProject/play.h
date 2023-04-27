#pragma once
#include <string>
#include <vector>

void play(const std::vector<int>& settings);
bool takeAway(int matchesCount, int dec);
bool TestDec(const std::vector<int>& settings, int dec);
int SelectQuantity(std ::string str);
struct Player {
    bool isMove;
    std::string _name;
    Player(bool move, std::string name) : isMove(move), _name(name)
    {
    }
};
