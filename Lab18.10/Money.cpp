#include "Money.h"
#include <iostream>
#include <fstream>
using namespace std;
Money::Money()
{
	R = 0;
	K = 0;
}
Money::Money(unsigned long int R, unsigned int K)
{
	this->K = K;
	this->R = R;
}
Money::Money(const Money& other)
{
	this->K = other.K;
	this->R = other.R;
}
Money::~Money()
{
}
Money& Money:: operator = (const Money& other)
{
	this->K = other.K;
	this->R = other.R;
	return *this;
}
bool Money:: operator != (const Money& other)
{
	return !(this->R == other.R && this->K == other.K);
}
bool Money:: operator == (const Money& other)
{
	return this->R == other.R && this->K == other.K;
}
bool Money:: operator <= (const Money& other)
{
	return this->R <= other.R && this->K <= other.K;
}
Money Money :: operator -(const Money& other)
{
	Money tmp;
	int tmpK = 0, tmpR = 0;
	tmp.R = this->R - other.R;
	tmp.K = this->K - other.K;
	if (this->K < other.K)
	{
		tmp.R--;
		tmp.K = other.K - this->K;
	}
	return tmp;
}
ostream& operator << (ostream& out, const Money& other)
{
	return (out << other.R << '.' << other.K);
}
istream& operator >> (istream& in, Money& other)
{
	char ch;
	in >> other.R >> ch >> other.K;
	return in;
}
fstream& operator << (fstream& fout, const Money& other)
{
	fout << other.R << '.' << other.K;
	return fout;
}
fstream& operator >> (fstream& fin, Money& other)
{
	char ch='.';
	fin >> other.R >> ch >> other.K;
	return fin;
}