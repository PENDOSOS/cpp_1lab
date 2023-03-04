#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<double> readCoefs()
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

double findDiscriminant(vector<double> coefs)
{	
	return coefs[1] * coefs[1] - 4 * coefs[0] * coefs[2];
}

bool checkForRoots(double discriminant)
{
	return discriminant >= 0;
}

vector<double> findRoots(double a, double b, double discriminant)
{
	vector<double> roots;
	if (discriminant == 0)
	{
		roots.push_back(b * b / (2 * a));
		return roots;
	}
	else
	{
		roots.push_back((-b - sqrt(discriminant)) / (2 * a));
		roots.push_back((-b + sqrt(discriminant)) / (2 * a));
		return roots;
	}
}

void writeRoots(vector<double> roots)
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
	vector<double> coefs;
	vector<double> roots;
	double discriminant;

	coefs = readCoefs();
	discriminant = findDiscriminant(coefs);
	if (checkForRoots(discriminant))
	{
		roots = findRoots(coefs[0], coefs[1], discriminant);
		writeRoots(roots);
	}
	else
		writeMessage();

	return 0;
}