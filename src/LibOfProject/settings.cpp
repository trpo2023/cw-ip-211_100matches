#include "settings.h"

using std::cout;
using std::string;

void settings(std::vector<int>& defaultSettings)
{
    bool isSettings = true;
    char userInput;

    while (isSettings) {
        cout << "Вы находитесь в разделе 'НАСТРОЙКИ'\n" + string(20, '*')
                        + "\nВыберите,"
             << "что хотите изменить : \n1 - максимальное кол - во игровых "
                "спичек\n"
             << "2 - максимально допустимое кол-во спичек взятых за раз\n3 - "
                "выйти в меню";

        userInput = _getch();
        unsigned int userSettingsInput = 0;

        switch (userInput) {
        case '1': // меняем первый параметр
            system("CLS");
            cout << "Текущее значение параметра: " << defaultSettings[0]
                 << "\nВы можете изменить его в пределах от [50-200], "
                 << "для этого нажмите 'y'.\nЧтобы снова перейти в раздел "
                    "'НАСТРОЙКИ' нажмите любую другую кнопку\n";

            char changeSettingsOne;
            changeSettingsOne = _getch();
            switch (changeSettingsOne) {
            case 'y':
                system("CLS");
                cout << "Введите число от 50 до 200 ->\n";
                std::cin >> userSettingsInput;
                if (userSettingsInput <= 200 && userSettingsInput >= 50) {
                    defaultSettings[0] = userSettingsInput;
                    cout << "значение успешно изменено на: "
                         << defaultSettings[0]
                         << // assert, проверить 50<=defaultSettings<=200
                            "\nДля продолжения нажмите любую кнопку...";
                } else
                    cout << "Введен неправильный диапазон!\n";
                _getch();
                break;

            default:
                system("CLS");
                break;
            }
            break;

        case '2': // меняем второй параметр
            system("CLS");
            cout << "Текущее значение параметра: " << defaultSettings[1]
                 << "\nВы можете изменить его в пределах от [5-20],"
                 << "для этого нажмите 'y'.\nчтобы снова перейти в раздел "
                    "'НАСТРОЙКИ' нажмите любую другую кнопку\n";

            char changeSettingsTwo;
            changeSettingsTwo = _getch();
            switch (changeSettingsTwo) {
            case 'y':
                system("cls");
                cout << "Введите число от 5 до 20 ->\n";
                std::cin >> userSettingsInput;
                if (userSettingsInput <= 20 && userSettingsInput >= 5) {
                    defaultSettings[1] = userSettingsInput;
                    cout << "значение успешно изменено на: "
                         << defaultSettings[1] << "\n"
                         << "\nДля продолжения нажмите любую кнопку...";
                } else
                    cout << "Введен неверный диапазон!\n";
                _getch();
                break;

            default:
                system("cls");
                break;
            }
            break;

        case '3':
            return; // выход в меню

        default:
            break;
        }
        system("CLS");
    }
}
