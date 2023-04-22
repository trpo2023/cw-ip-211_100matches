#pragma once
#include <iostream>
#include <vector>
// ƒолжен иметьс€ флаг, который указывает, кто делает ход
// Ќаличие переменной котора€ хранит текущее кол-во спичек, не принадлежащих
// игрокам доп. функции с выводом сообщений о статусе игры функци€ по уменьшению
// количества спичек в общем запасе и увеличению личного запаса игрока
void play(const std::vector<int>& settings);
bool takeAway(int& matchesCount, int dec);
bool TestDec(const std::vector<int>& settings, int dec);
struct Player {
    bool isMove;
    std::string _name;
    Player(bool move, std::string name) : isMove(move), _name(name)
    {
    }
};
