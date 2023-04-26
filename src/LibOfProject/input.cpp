#include <string>

bool CheckingTheInput(std ::string str, unsigned int k)//строка и количество символов которые нужно учитывать
{
    if (str.length()<=k)
        return 1;
    else
        return 0;
}