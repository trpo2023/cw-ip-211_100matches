
#include <iostream>
#include <string>

#include <input.h>
#include <play.h>

void Play(const std::vector<int>& settings)
{
    Player first(true, "Player one");
    Player second(false, "Player two");
    int matchesRemaining = settings[0];
    bool isGame = true;
    int decMatches = 0;
    std ::string str = "";
    while (isGame) {
        system("clear");
        std::cout << "Спичек осталось: " << matchesRemaining << "\n";
        if (first.isMove)
            std::cout << "Ходит игрок:" << first._name << " \n";
        else
            std::cout << "Ходит игрок:" << second._name << " \n";
        std::cout << "Выберите желаемое кол-во "
                     "спичек ["
                  << 1 << "-" << settings[1] << "]\n";
        do {
            std::getline(std::cin, str);
            decMatches = SelectQuantity(str);
            if (TestDec(settings, decMatches)) {
                if (TakeAway(matchesRemaining, decMatches)) {
                    matchesRemaining -= decMatches;
                    first.isMove = ChangeOfCourse(first.isMove);
                    second.isMove = ChangeOfCourse(second.isMove);
                    break;
                } else
                    std::cout << "У вас нет " << decMatches << " спичек!\n";
            } else
                std::cout << "Неверный "
                             "ввод\n";
        } while (true);
        if (matchesRemaining == 0) {
            system("clear");
            if (first.isMove)
                std::cout << "Игрок " << second._name << " победил!";
            else
                std::cout << "Игрок " << first._name << " победил!";
            isGame = false;
        }
    }
    std::cout << "\n";
    std ::cout << "Для того, чтобы выйти введите "
                  "что-нибудь\n";
    std::getline(std::cin, str);
}
bool TakeAway(int matchesCount, int dec)
{
    if (matchesCount >= dec)
        return true;
    else
        return false;
}
bool TestDec(const std::vector<int>& settings, int dec)
{
    if (dec <= settings[1] && dec > 0)
        return true;
    else
        return false;
}

int SelectQuantity(std ::string str)
{
    bool flag = CheckingTheInput(str, 2);
    if (flag)
        return std ::stoi(str);
    return -1;
}
bool ChangeOfCourse(bool x)
{
    if (x)
        return 0;
    return 1;
}