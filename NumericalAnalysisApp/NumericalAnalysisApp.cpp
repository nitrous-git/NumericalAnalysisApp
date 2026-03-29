// NumericalAnalysisApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip> // Pour contrôler l’affichage des nombres

#include "LagrangePolynomial.h"
#include "NewtonGregory.h"

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

        // ----------------------------------------------------------
        // Newton Gregory Difference finies (descendantes)
        // Interpolation de sin(x)

       // Donnees : points equidistants
        //std::vector<double> xData = { 0.1, 0.5, 0.9, 1.3, 1.7 };
        //std::vector<double> fData = { 0.09983, 0.47943, 0.78333, 0.96356, 0.99166 };

        //double xEval = 0.8;

        //// Construire et afficher la table des differences
        //std::vector<std::vector<double>> table = NewtonGregory::DifferenceTable(fData);
        //NewtonGregory::PrintDifferenceTable(table);

        //std::cout << std::endl;
        //std::cout << "Evaluation en x = " << xEval << std::endl;
        //std::cout << std::endl;

        //double exactValue = std::sin(xEval);

        //for (int degree = 1; degree <= static_cast<int>(xData.size()) - 1; ++degree)
        //{
        //    std::pair<double, double> result =
        //        NewtonGregory::Interpolate(xData, fData, xEval, degree);

        //    double interpolatedValue = result.first;
        //    double estimatedError = result.second;
        //    double realError = std::abs(exactValue - interpolatedValue);

        //    std::cout << "Degre " << degree << " : " << std::endl;
        //    std::cout << "  P_" << degree << "(" << xEval << ") = "
        //        << std::fixed << std::setprecision(6)
        //        << interpolatedValue << std::endl;

        //    std::cout << "  Erreur reelle = "
        //        << std::fixed << std::setprecision(6)
        //        << realError << std::endl;

        //    if (degree < static_cast<int>(xData.size()) - 1)
        //    {
        //        std::cout << "  Erreur estimee = "
        //            << std::fixed << std::setprecision(6)
        //            << estimatedError << std::endl;
        //    }
        //    else
        //    {
        //        std::cout << "  Erreur estimee = non disponible (pas de terme suivant)"
        //            << std::endl;
        //    }

        //    std::cout << std::endl;
        //}
        // ----------------------------------------------------------
  


    }
    catch (const std::exception& ex)
    {
        std::cout << "Erreur : " << ex.what() << std::endl;
        return 1;
    }

    return 0;
}