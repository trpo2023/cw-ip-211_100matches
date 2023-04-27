#include <input.h>
#include <string>

bool CheckingTheInput(
        std ::string str,
        unsigned int k) //строка и количество символов которые нужно учитывать
{
    std ::string cheak = "1234567890";
    unsigned int len = str.length();
    if (len <= k) {
        for (unsigned int i = 0; i < len; i++)
            if (cheak.find(str[i]) == std::string::npos)
                return 0;
        return 1;
    } else
        return 0;
}
