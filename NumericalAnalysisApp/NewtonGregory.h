#pragma once

#include <vector>
#include <utility> // pour utiliser std::pair
#include <string>

class NewtonGregory
{
    public :
        // Construit la table des differences avant
        static std::vector<std::vector<double>> DifferenceTable(const std::vector<double>& fValues);

        // Calcule le coefficient binomial generalise C(s, k)
        static double BinomialS(double s, int k);

        // Evalue le polynome de Newton Gregory avant et retourne aussi une estimation de l'erreur
        static std::pair<double, double> Interpolate(const std::vector<double>& xPoints, const std::vector<double>& fValues, double x, int degree);

        // Verifie si les x sont equidistants
        static bool AreEquallySpaced(const std::vector<double>& xPoints, double tolerance = 1e-9);


        // Pretty print
        static void PrintDifferenceTable(const std::vector<std::vector<double>>& table);
};

