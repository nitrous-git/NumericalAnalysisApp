// NumericalAnalysisApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "NumericalTests.h"

int main()
{
    try
    {
        NumericalTests::RunAll();
    }
    catch (const std::exception& ex)
    {
        std::cout << "Erreur : " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}