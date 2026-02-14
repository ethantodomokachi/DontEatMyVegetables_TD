#include <iostream>
#include "main.h"
#include "Level.h"

int main()
{
    Level test("C:\\Users\\vince\\Documents\\GitHub\\DontEatMyVegetables_TD\\src\\Levels\\Level1.txt");

    test.GetMap();
    test.GetWave();
    test.NextWave();
    std::cout << std::endl;
    std::cout << std::endl;

    test.GetMap();
    test.GetWave();
    test.NextWave();
    std::cout << std::endl;
    std::cout << std::endl;

    test.GetMap();
    test.GetWave();
    test.NextWave();
    std::cout << std::endl; 
    std::cout << std::endl;

    return 0;
}