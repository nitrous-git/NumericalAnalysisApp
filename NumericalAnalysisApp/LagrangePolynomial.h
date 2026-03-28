#pragma once // include only once 
#include <vector>

class LagrangePolynomial
{
    public:
        // xPoints : le tableau des abscisses
        // i : l’indice du polynôme de base
        // x : le point ou on veut évaluer 
        // & -on passe le tableau par référence, on ne copie pas tout le tableau, plus efficace
        // const -la fonction a le droit de lire le tableau, mais pas de le modifier
        static double Basis(const std::vector<double>& xPoints, int i, double x);

        // Calcule P_n(x) par la formule de Lagrange
        // Implémente la formule :
        // P_n(x) = Σ_{ i = 0 }^ {n} f_i · π_i(x)
        static double Interpolate(const std::vector<double>& xPoints, const std::vector<double>& yPoints, double x);
};