#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>

#include <input.h>
#include <play.h>
#include <rules.h>
#include <settings.h>

void ShowMenuMessage()
{
    std ::cout << "Для того, чтобы играть, введите 1\n"
                  "Для того, чтобы ознакомиться с правилами, введите 2\n"
                  "Для того, чтобы настроить игру введите 3\n"
                  "Для того, чтобы выключить приложение, введите 4\n";
}

void TryAgainMsg()
{
    std::cout << "Введено ошибочное значение, попробуйте снова\n";
}

char SelectMode(std ::string& str)
{
    bool flag = CheckingTheInput(str, 1);
    if (flag)
        return str[0];
    return '0';
}

int main()
{
    std ::string str = "";
    char menuflag = '0';
    std::vector<int> settingsVec = {100, 10};
    while (1) {
        system("clear");
        ShowMenuMessage();
        std::getline(std::cin, str);
        menuflag = SelectMode(str);
        switch (menuflag) {
        case '1':
            Play(settingsVec);
            str = "";
            break;
        case '2':
            Rules();
            break;
        case '3':
            settings(settingsVec);
            break;
        case '4':
            return 0;
            break;
        default:
            TryAgainMsg();
        }
    }
}
