#include "play.h"

void play(const std::vector<int>& settings)
{
    Player first(true, "Player one");
    Player second(false, "Player two");
    int matchesRemaining = settings[0];
    bool isGame = true;
    int decMatches = 0;
    while (isGame) {
        system("clear");
        std::cout << "������ ��������: " << matchesRemaining << "\n";
        if (first.isMove)
            std::cout << "������ �����:" << first._name << " \n";
        else
            std::cout << "������ �����:" << second._name << " \n";
        std::cout << "������� �������� ���-�� ������ [" << 1 << "-"
                  << settings[1] << "]\n";
        do {
            std::cin >> decMatches;
            if (TestDec(settings, decMatches)) {
                if (takeAway(matchesRemaining, decMatches)) {
                    matchesRemaining -= decMatches;
                    if (first.isMove) {
                        first.isMove = false;
                        second.isMove = true;
                    } else {
                        first.isMove = true;
                        second.isMove = false;
                    }
                    break;
                } else
                    std::cout << "� ��� ��� " << decMatches << " ������!\n";
            } else
                std::cout << "�������� ����!\n";
        } while (true);
        if (matchesRemaining == 0) {
            system("clear");
            if (first.isMove)
                std::cout << "����� " << second._name << " �������!";
            else
                std::cout << "����� " << first._name << " �������!";
            isGame = false;
        }
    }
}
bool takeAway(int& matchesCount, int dec)
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
