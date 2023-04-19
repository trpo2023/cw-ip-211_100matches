#pragma once
#include <vector>
#include <Windows.h>
#include <conio.h>
#include <iostream>

//–еализовать пункт меню, в отдельном файле
//в этой функции(settings) пользователь сможет помен€ть принимаемые оригиналы переменных, которые объ€влены в main
//они будут передаватьс€ в main
//а после использоватьс€ в play

void settings(std::vector<int>& defaultSettings);