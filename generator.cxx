#include <iostream>
#include <ctime>
#include <random>
#include <iomanip>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */



int main(int argc, char *argv[])
{
    std::string w1, w2;

    std::uniform_int_distribution<int> dist1 ( 97, 122 ); //klasa szablonowa
    std::mt19937 gen ( time ( NULL ) ); //generator pseudolosowy Mersenne Twister 32bit
    int n = 100000;
    for( int i = 0; i < n; i++ )
    {
        w1+=(char)dist1(gen);
        w1+=(char)dist1(gen);
        w1+=(char)dist1(gen);
        w1+=(char)dist1(gen);
        w2+=(char)dist1(gen);
        w2+=(char)dist1(gen);
        w2+=(char)dist1(gen);
        w2+=(char)dist1(gen);
        std::cout << w1 << "\n";
        std::cout << w2 << "\n";
        w1 = "";
        w2 = "";
    }
 
    return 0;
} 