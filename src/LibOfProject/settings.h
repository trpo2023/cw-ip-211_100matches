#pragma once
#include <string>
#include <vector>

void settings(std::vector<int>& defaultSettings);
void FirstSettingsMessage(unsigned int currentSettings);
void SecondSettingsMessage(unsigned int currentSettings);

int CheckInput(std::string userInput);
void ResetSettings(std::vector<int>& defaultSettings);

class InputHandler {
public:
    bool ChangeFirstSettings(
            std::vector<int>& defaultSettings, unsigned int userInput);
    bool ChangeSecondSettings(
            std::vector<int>& defaultSettings, unsigned int userInput);
};
