#include  "Cipher.h"

using namespace std;

std::string modAlphaTable::encrypt(const std::string& open_text) // шифрование
{
    string tabl = open_text;
    int dl, nstrok, index, x;
    dl = open_text.length(); // введенный текст
    nstrok = (dl - 1) / key1 + 1; // количество столбцов
    x = 0;
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < dl) {
                tabl[x] = open_text[index-1];
                x++;
            }
        }
    }
    return tabl;
}

std::string modAlphaTable::decrypt(const std::string& cipher_text) // расшифрование
{
    string tabl = cipher_text;
    int dl, nstrok, index, x;
    dl = cipher_text.length();
    nstrok = (dl - 1) / key1 + 1; // количество столбцов
    x = 0;
    for (int i = key1; i > 0; i--) { // столбцы
        for (int j = 0; j < nstrok; j++) { // строки
            index = i+key1*j;
            if (index-1 < dl) {
                tabl[index-1] = cipher_text[x];
                x++;
            }
        }
    }
    return tabl;
}
