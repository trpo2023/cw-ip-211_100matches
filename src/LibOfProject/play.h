#pragma once
#include <string>
#include <vector>

void Play(const std::vector<int>& settings);
bool TakeAway(int matchesCount, int dec);
bool TestDec(const std::vector<int>& settings, int dec);
int SelectQuantity(std ::string str);
bool ChangeOfCourse(bool x);
struct Player {
    bool isMove;
    std::string _name;
    Player(bool move, std::string name) : isMove(move), _name(name)
    {
    }
};