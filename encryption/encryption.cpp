#include "encrypt.h"

int main()
{
    string key = "crypto";
    RC4 cipher( key );
    string plain = cipher.readFile( );//otwiera plik i zapisuje dane do stringu - plaintext.txt
    string result = cipher.encrypt( plain );//szyfrujemy
    cout << result; //wypisujemy wynik
    cipher.saveFile( result );//zapisujemy do pliku

    return 0;
}