#ifndef CODE_H
#define CODE_H

#define N 256
#include <iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;

class RC4 {

    unsigned char* S;
    static unsigned char* rightKey( string& key );//generuje nam wlasciwy klucz

public:
    RC4( std::string key );//konstruktor 
    unsigned char random_gen( );//pseudolosowa generacja
    string encrypt( std::string plain );//zaszyfrowanie tekstu
    string readFile( );//czytanie z pliku
    void saveFile( std::string& plaintext );//zapisywanie do pliku
   
};


#endif