#include <iostream>
#include <rules.h>
#include <settings.h>
#include <stdlib.h>

void MenuMessage(unsigned char& menuflag)
{
    std ::cout << "Для того, чтобы играть, введите 1\n"
                  "Для того, чтобы ознакомиться с правилами, введите 2\n"
                  "Для того, чтобы настроить игру введите 3\n"
                  "Для того, чтобы выключить приложение, введите 4\n";
    std ::cin >> menuflag;
}

void TryAgainMsg()
{
    std ::cout << "Введено ошибочное значение, попробуйте снова\n";
}

int main()
{
    unsigned char menuflag;
    std::vector<int> settingsVec = {100, 10}; // значения настроек по умолчанию
    while (1) {
        MenuMessage(menuflag);
        system("clear");
        switch (menuflag) {
        case '1':
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
