#include "encrypt.h"

unsigned char* RC4::rightKey( string& key ) //tworzenie jednorazowego klucza i zwrocenie w postaci stringu
{
   
    unsigned char* S = new unsigned char[N];
    for( int i = 0; i < N; i++ ) {
        S[i] = i;//generujemy tablice pomocnicza, identycznosciowa
    }
    //mieszanie permutacji z bajtami klucza
    for( int i = 0 , j = 0; i < N; i++ )//tworzenie klucza jednorazowego pseudlosowego
    {
        j = ( j + S[i] + key[i % key.length( )] ) % N;
        swap( S[i] , S[j] );
    }
    return S;
}
RC4::RC4( string key )//konstruktor ktory wygeneruje nam nowy klucz
{
    S = rightKey( key );
}

unsigned char RC4::random_gen( ) //wykonuje pseudolosow¹ generacje ktor¹ wykorzystamy do operacji xor i zaszyfrowania tekstu oryginalnego
{

    static int i = 0;
    static int j = 0;
    i = ( i + 1 ) % N;
    j = ( j + S[i] ) % N;
    swap( S[i] , S[j] );
    return S[( S[i] + S[j] ) % N];

}
string RC4::encrypt( string plain ) {

    int size = plain.length( );
    string result = plain;// aby dlugosc tekstu oryginalnego i zaszyfrowanego byla taka sama, poŸniej i tak nadpiszemy result 
    //szyfruje tekst
    for( int i = 0; i < size; i++ ) {
        result[i] = plain[i] ^ random_gen( );//wykonujemy operacje XOR na tekscie oryginalnym i strumieniu szyfrujacym
    }
    return result;
}

string RC4::readFile( ) //czytanie tekstu oryginalnego z pliku tekstowego
{
    fstream plik;
    string temp;
    string plain;
    plik.open( "plaintext.txt" , ios::in );
    if( plik.bad( ) ) {
        cerr << "You can't open this file - plaintext.txt" << endl;
        return "";
    }

    while( !plik.eof( ) ) {
        getline( plik , temp );//czyta stringi wierszami
        plain += temp;//
    }

    plik.close( );
    return plain;
}

void RC4::saveFile( string& result ) //zapisywanie zaszyfrowanego tekstu do pliku
{
    fstream plik;
    plik.open( "result.txt" , ios::out );
    if( plik.bad( ) ) {
        cerr << "You can't open this file - result.txt" << endl;
        return;
    }
    plik << result;

    plik.close( );
}



