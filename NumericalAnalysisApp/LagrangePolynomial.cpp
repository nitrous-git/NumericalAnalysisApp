#include "LagrangePolynomial.h"
#include <stdexcept> // library permet d’utiliser des erreurs

double LagrangePolynomial::Basis(const std::vector<double>& xPoints, int i, double x)
{
	// size() retourne un type spécial entier non signé (size_t)
	// Pour simplifier les boucles avec int, static_cast<int>
	int n = static_cast<int>(xPoints.size());

	// Calcule du i-ème polynôme de base de Lagrange π_i(x).
	// Implémente la formule :
	// π_i(x) = ∏_{ j≠i } (x - x_j) / (x_i - x_j)
	double result = 1.0;
	for (int j = 0; j < n; ++j)
	{
		if (j != i) 
		{
			double deno = xPoints[i] - xPoints[j];
			if (deno == 0.0)
			{	
				//division par zéro : impossible.
				throw std::runtime_error("Erreur : deux abscisses x_i sont identiques.");
			}

			result *= (x - xPoints[j]) / deno;
		}
	}

	return result;
}

double LagrangePolynomial::Interpolate(const std::vector<double>& xPoints, const std::vector<double>& yPoints, double x)
{
	if (xPoints.size() != yPoints.size())
	{
		throw std::runtime_error("Erreur : xPoints et yPoints doivent avoir la meme taille.");
	}

	int n = static_cast<int>(xPoints.size());

	// Formule de Lagrange
	// P_n(x) = Σ_{ i = 0 }^ {n} f_i · π_i(x)
	double result = 0.0;
	for (int i = 0; i < n; ++i)
	{
		result += yPoints[i] * Basis(xPoints, i, x);
	}

	return result;
}
