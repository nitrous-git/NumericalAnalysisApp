// NumericalAnalysisApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // Pour contrôler l’affichage des nombres

#include "LagrangePolynomial.h"

int main()
{
    try
    {
        // ----------------------------------------------------------
        // Polynome de Lagrange 
        // Interpolation de sin(x) avec 3 points
        std::vector<double> xData = { 0.1, 0.5, 0.9 };
        std::vector<double> yData = { 0.09983, 0.47943, 0.78333 };

        // Point d’evaluation, on veut calculer P_2(0.8)
        double xEval = 0.8;

        double pX = LagrangePolynomial::Interpolate(xData, yData, xEval);
        double exact_value = std::sin(xEval);
        double error = std::abs(exact_value - pX);

        // std::fixed : afficher les nombres en decimal fixe (enelever les 0)
        // std::setprecision(6) : afficher 6 chiffres apres la virgule
        std::cout << std::fixed << std::setprecision(6);
        std::cout << "P_2(" << xEval << ") = " << pX << std::endl;
        std::cout << "sin(" << xEval << ") = " << exact_value << std::endl;
        std::cout << "Erreur = " << error << std::endl;
        // ----------------------------------------------------------







    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}