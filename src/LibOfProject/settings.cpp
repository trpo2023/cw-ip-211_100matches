#include <algorithm>
#include <iostream>
#include <unistd.h>
#include <vector>

using std::cout;
using std::string;

void FirstSettingsMessage(const unsigned int currentSettings);
void SecondSettingsMessage(const unsigned int currentSettings);

int CheckInput(std::string userInput);
void ResetSettings(std::vector<int>& defaultSettings);
void ShowMenu();

class InputHandler {
public:
    bool ChangeFirstSettings(
            std::vector<int>& defaultSettings, const unsigned int userInput);
    bool ChangeSecondSettings(
            std::vector<int>& defaultSettings, const unsigned int userInput);
};

bool InputHandler::ChangeFirstSettings(
        std::vector<int>& defaultSettings, const unsigned int userInput)
{
    if (userInput <= 200 && userInput > 50) { // Ok
        defaultSettings[0] = userInput;
        return true;
    }
    return false; // Wrong input
}

bool InputHandler::ChangeSecondSettings(
        std::vector<int>& defaultSettings, const unsigned int userInput)
{
    if (userInput <= 20 && userInput > 5) { // Ok
        defaultSettings[1] = userInput;
        return true;
    }
    return false; // Wrong input
}

void settings(std::vector<int>& defaultSettings)
{
    bool isSettings = true;
    string userInput = "";
    InputHandler userInputHandler;
    while (isSettings) {
        ShowMenu();

        int userChangingSettings;
        std::cin >> userInput;
        std::cin.ignore(256, '\n');
        int result = CheckInput(userInput);

        switch (result) {
        case 1:
            FirstSettingsMessage(defaultSettings[0]);
            std::cin >> userChangingSettings;
            if (!userInputHandler.ChangeFirstSettings(
                        defaultSettings, userChangingSettings)) {
                std::cout << "Введен НЕВЕРНЫЙ диапазон!\n";
                std::cin.clear();
                sleep(1);
            }
            break;
        case 2:
            SecondSettingsMessage(defaultSettings[1]);
            std::cin >> userChangingSettings;
            if (!userInputHandler.ChangeSecondSettings(
                        defaultSettings, userChangingSettings)) {
                std::cout << "Введен НЕВЕРНЫЙ диапазон!\n";
                std::cin.clear();
                sleep(1);
            }
            break;
        case 3:
            ResetSettings(defaultSettings);
            std::cout << "Все настройки были возвращены\n";
            sleep(1);
            break;

        case 4:
            return; // back to menu
        default:
            break;
        }
    }
}

void FirstSettingsMessage(const unsigned int currentSettings)
{
    system("clear");
    std::cout << "Текущее значение параметра: " << currentSettings
              << "\nВы можете изменить его в пределах от [50-200],\n"
              << "Введите число в допустимом диапазоне, либо введите число вне "
                 "диапазона для выхода в меню...\n";
}

void SecondSettingsMessage(const unsigned int currentSettings)
{
    system("clear");
    std::cout << "Текущее значение параметра " << currentSettings
              << "\nВы можете изменить его в пределах от [5-20],\n"
              << "Введите число в допустимом диапазоне, либо введите число вне "
                 "диапазона для выхода в меню...\n";
}

int CheckInput(std::string userInput)
{
    std::transform(
            userInput.begin(), userInput.end(), userInput.begin(), [](char c) {
                return tolower(c);
            });
    if (userInput == "first")
        return 1;
    else if (userInput == "second")
        return 2;
    else if (userInput == "reset")
        return 3;
    else if (userInput == "exit")
        return 4;
    return 0;
}

void ResetSettings(std::vector<int>& defaultSettings)
{
    defaultSettings[0] = 100;
    defaultSettings[1] = 10;
}

void ShowMenu()
{
    system("clear");

    cout << "Вы находитесь в разделе 'Настройки'\n"
         << "\nЧтобы изменить кол-во игровых спичек, введите команду "
            "'first'"
         << "\nЧтобы изменить макс. допустимое кол-во спичек для взятия за "
            "ход введите команду 'second'"
         << "\nЧтобы вернуть настройки в исходное положение введите "
            "команду 'reset'"
         << "\nВыйти в меню - команда 'exit'\n";
}