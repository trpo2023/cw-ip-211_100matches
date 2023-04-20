#include <settings.h>

using std::cout;
using std::string;

void settings(std::vector<int>& defaultSettings)
{
    bool isSettings = true;
    char userInput;
    // char delay;

    while (isSettings) {
        cout << "Вы находитесь в разделе 'НАСТРОЙКИ'\n" + string(20, '*')
                        + "\nВыберите,"
             << "что хотите изменить : \n1 - максимальное кол - во игровых "
                "спичек\n"
             << "2 - максимально допустимое кол-во спичек взятых за раз\n3 - "
                "вернуть начальные настройки\n4 - выйти в меню\n";

        userInput = getchar();
        unsigned int userSettingsInput = 0;

        switch (userInput) {
        case '1': // меняем первый параметр
            system("clear");
            cout << "Текущее значение параметра: " << defaultSettings[0]
                 << "\nВы можете изменить его в пределах от [50-200], "
                 << "для этого нажмите 'y'.\nЧтобы снова перейти в раздел "
                    "'НАСТРОЙКИ' нажмите любую другую кнопку\n";

            char changeSettingsOne;
            std::cin >> changeSettingsOne;
            switch (changeSettingsOne) {
            case 'y':
                system("clear");
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
                // delay = getchar();
                break;

            default:
                system("clear");
                break;
            }
            break;

        case '2': // меняем второй параметр
            system("clear");
            cout << "Текущее значение параметра: " << defaultSettings[1]
                 << "\nВы можете изменить его в пределах от [5-20],"
                 << "для этого нажмите 'y'.\nчтобы снова перейти в раздел "
                    "'НАСТРОЙКИ' нажмите любую другую кнопку\n";

            char changeSettingsTwo;
            std::cin >> changeSettingsTwo;
            switch (changeSettingsTwo) {
            case 'y':
                system("clear");
                cout << "Введите число от 5 до 20 ->\n";
                std::cin >> userSettingsInput;
                if (userSettingsInput <= 20 && userSettingsInput >= 5) {
                    defaultSettings[1] = userSettingsInput;
                    cout << "значение успешно изменено на: "
                         << defaultSettings[1]
                         << "\nДля продолжения нажмите любую кнопку...";
                } else
                    cout << "Введен неверный диапазон!\n";
                // delay = getchar();
                break;

            default:
                system("clear");
                break;
            }
            break;

        case '3': // восстановить дефолтные значения
            system("clear");
            defaultSettings[0] = 100;
            defaultSettings[1] = 10;
            cout << "Все настройки были обнулены.\n";
            // delay = getchar();
            break;

        case '4':
            return; // выход в меню
        default:
            break;
        }
        system("clear");
    }
}
