#include "NewtonGregory.h"

#include <stdexcept>
#include <iostream>
#include <iomanip>
#include <cmath>

std::vector<std::vector<double>> NewtonGregory::DifferenceTable(const std::vector<double>& fValues)
{
	/*
	Construit la table des differences descendantes

	La table est une structure triangulaire :
		table[k][i] = Δ^k f_i

	Exemple pour 5 valeurs :
		table[0] = [f_0, f_1, f_2, f_3, f_4]      (5 éléments)
		table[1] = [Δf_0, Δf_1, Δf_2, Δf_3]       (4 éléments)
		table[2] = [Δ²f_0, Δ²f_1, Δ²f_2]          (3 éléments)
		table[3] = [Δ³f_0, Δ³f_1]                 (2 éléments)
		table[4] = [Δ⁴f_0]                        (1 élément)
	
	*/

	int n = static_cast<int>(fValues.size());

	// creer un vecteur table contenant n lignes.
	std::vector<std::vector<double>> table(n);
	
	// Ordre 0 : les valeurs elles - mêmes(Δ⁰f_i = f_i)
	table[0] = fValues;

	for (int k = 0; k < n; ++k)
	{
		int rowSize = n - k;
		table[k].resize(rowSize);

		// Ordres superieurs : Δ ^ k f_i = Δ ^ (k - 1) f_(i + 1) - Δ ^ (k - 1) f_i
		for (int i = 0; i < rowSize; ++i)
		{
			table[k][i] = table[k - 1][i + 1] - table[k - 1][i];
		}
	}

	return table;
}

double NewtonGregory::BinomialS(double s, int k)
{
	// coefficient binomial généralisé C(s, k) = s(s - 1)...(s - k + 1) / k!
	// formule incrémentale : C(s, k) = C(s, k-1) * (s - k + 1) / k

	if (k == 0)
	{
		return 1.0;
	}

	double result = 1.0;

	for (int j = 0; j < k; j++)
	{
		// Multiplie par(s - j) / (j + 1) à chaque étape
		// Cela calcule s / 1 * (s - 1) / 2 * (s - 2) / 3 * ... * (s - k + 1) / k
		result *= (s - j) / (j + 1);
	}

	return result;
}

std::pair<double, double> NewtonGregory::Interpolate(const std::vector<double>& xPoints, const std::vector<double>& fValues, double x, int degree)
{
	if (xPoints.size() != fValues.size())
	{
		throw std::invalid_argument("xPoints et fValues doivent avoir la meme taille.");
	}

	if (xPoints.size() < 2)
	{
		throw std::invalid_argument("Il faut au moins 2 points.");
	}

	if (!AreEquallySpaced(xPoints))
	{
		throw std::invalid_argument("Les points xPoints doivent etre equidistants.");
	}

	int maxDegree = static_cast<int>(xPoints.size()) - 1;

	if (degree < 0 || degree > maxDegree)
	{
		throw std::invalid_argument("Le degre demande est invalide.");
	}

	double h = xPoints[1] - xPoints[0];
	double x0 = xPoints[0];
	double s = (x - x0) / h; // Variable réduite

	// Etape 1 : Construire la table de différences
	std::vector<std::vector<double>> table = DifferenceTable(fValues);

	// Etape 2 : Calculer P_n(x) = Σ C(s, k) * Δ ^ k f_0
	double result = 0.0;
	for (int k = 0; k <= degree; ++k)
	{
		result += BinomialS(s, k) * table[k][0];
	}

	double errorEstimate = 0.0;

	// Etape 3 : Estimer l'erreur par le terme suivant (si on a assez de données)
	// Le terme suivant existe seulement si degree + 1 <= maxDegree
	if (degree + 1 <= maxDegree)
	{
		errorEstimate = std::abs(BinomialS(s, degree + 1) * table[degree + 1][0]);
	}

	return { result, errorEstimate };
}

bool NewtonGregory::AreEquallySpaced(const std::vector<double>& xPoints, double tolerance)
{
	if (xPoints.size() < 2)
	{
		return true;
	}

	double h = xPoints[1] - xPoints[0];

	for (size_t i = 1; i < xPoints.size() - 1; ++i)
	{
		double currentStep = xPoints[i + 1] - xPoints[i];

		if (std::abs(currentStep - h) > tolerance)
		{
			return false;
		}
	}

	return true;
}

void NewtonGregory::PrintDifferenceTable(const std::vector<std::vector<double>>& table)
{
	std::cout << "Table des differences :" << std::endl;

	for (size_t k = 0; k < table.size(); ++k)
	{
		std::cout << "Delta^" << k << " f : ";

		for (size_t i = 0; i < table[k].size(); ++i)
		{
			std::cout << std::fixed << std::setprecision(6) << table[k][i] << "  ";
		}

		std::cout << std::endl;
	}
}
