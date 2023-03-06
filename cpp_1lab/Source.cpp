#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const vector<double> readCoefs()
{
	vector<double> coefs;
	double buff;

	ifstream fin("input.txt");
	for (int i = 0; i < 3; i++)
	{
		fin >> buff;
		coefs.push_back(buff);
	}
	fin.close();

	return coefs;
}

const double findDiscriminant(const vector<double>& coefs)
{	
	return coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
}

bool checkForRoots(const double& discriminant)
{
	return discriminant >= 0;
}

const vector<double> findRoots(const double& a, const double& b, const double& c, const double& discriminant)
{
	vector<double> roots;
	if (discriminant == 0)
	{
		roots.push_back(b * b / (2 * a));
		return roots;
	}
	else if (a == 0)
	{
		roots.push_back(-c/b);
		return roots;
	}
	else
	{
		roots.push_back((-b - sqrt(discriminant)) / (2 * a));
		roots.push_back((-b + sqrt(discriminant)) / (2 * a));
		return roots;
	}
}

void writeRoots(const vector<double>& roots)
{
	ofstream fout("output.txt");
	for (int i = 0; i < roots.size(); i++)
		fout << roots[i] << " ";
	fout.close();
}

void writeMessage()
{
	ofstream fout("output.txt");
	fout << "No roots in real numbers";
	fout.close();
}

int main()
{
	const vector<double> coefs = readCoefs();
	const double discriminant = findDiscriminant(coefs);
	if (checkForRoots(discriminant))
	{
		const vector<double> roots = findRoots(coefs[0], coefs[1], coefs[2], discriminant);
		writeRoots(roots);
	}
	else
		writeMessage();

	return 0;
}