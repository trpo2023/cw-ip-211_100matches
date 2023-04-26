#include <stdlib.h>
#include <iostream>
#include <string>

#include <input.h>
#include <play.h>
#include <rules.h>
#include <settings.h>

void ShowMenuMessage()
{
    std::cout << "Для того, чтобы играть, введите 1\n"
                 "Для того, чтобы ознакомиться с правилами, введите 2\n"
                 "Для того, чтобы настроить игру введите 3\n"
                 "Для того, чтобы выключить приложение, введите 4\n";
}

void TryAgainMsg()
{
    std::cout << "Введено ошибочное значение, попробуйте снова\n";
}

unsigned char SelectMode(std ::string str)
{
    if (CheckingTheInput(str, 1))
        return str[0];
    return '0';
}


int main()
{
    std ::string str = "";
    unsigned char menuflag = '0';
    std::vector<int> settingsVec = {100, 10};
    while (1) {
        system("clear");
        ShowMenuMessage();
        std ::cin >> str;
        SelectMode(str);
        switch (menuflag) {
        case '1':
            play(settingsVec);
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
