#include "settings.h"

using std::cout;
using std::string;

void settings(std::vector<int>& defaultSettings)// вектор произвольного типа, принимает вектор с оригиналами переменных, которые будет необходимо изменить 
{
	bool isSettings = true;
	char userInput;
	
	while (isSettings) 
	{
		cout << "Вы находитесь в разделе 'НАСТРОЙКИ'\n" + string(20, '*') + "\nВыберите," <<
			"что хотите изменить : \n1 - максимальное кол - во игровых спичек\n" <<
			"2 - максимально допустимое кол-во спичек взятых за раз\n3 - выйти в меню";

		userInput = _getch();
		auto diffrenceOne = [&defaultSettings]() {if (defaultSettings[0] == 100) { return 200; } else return 100; };
		auto diffrenceTwo = [&defaultSettings]() {if (defaultSettings[1] == 10) { return 20; } else return 10; };

		switch (userInput)
		{
		case '1': system("CLS"); cout << "Текущее значение параметра: " << defaultSettings[0] << "\nЧтобы изменить его на " 
			<< diffrenceOne() << " нажмите 'y', чтобы снова перейти в раздел 'НАСТРОЙКИ' нажмите любую другую кнопку\n"; ;

			char changeSettingsOne;
			changeSettingsOne = _getch();
			switch (changeSettingsOne)
			{
			case 'y': system("CLS"); defaultSettings[0] = diffrenceOne(); cout << "значение успешно изменено на: " << defaultSettings[0] << "\n";
				 _getch(); break;

			default: system("CLS");
				break;
			}
			break;

		case '2': system("CLS"); cout << "Текущее значение параметра: " << defaultSettings[1] << "\nЧтобы изменить его на "
			<< diffrenceTwo() << " нажмите 'y', чтобы снова перейти в раздел 'НАСТРОЙКИ' нажмите любую другую кнопку\n";
			
			char changeSettingsTwo;
			changeSettingsTwo = _getch();
			switch (changeSettingsTwo)
			{
			case 'y': system("cls");  defaultSettings[1] = diffrenceTwo(); cout << "значение успешно изменено на: " << defaultSettings[1] << "\n";
				  _getch(); break;

			default: system("cls");
				break;
			}
			break;

		case '3':
			return;

		default:
			break;
		}
		system("CLS");
	}
}