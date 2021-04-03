#pragma once
#include <iostream>
#include <fstream>
using namespace std;
class Money
{
public:
	Money();
	Money(unsigned long int R, unsigned int K);
	Money(const Money& other);
	~Money();
	Money& operator = (const Money& other);
	friend ostream& operator << (ostream& out, const Money& other);
	friend istream& operator >> (istream& in, Money& other);
	///////////////
	friend fstream& operator << (fstream& out, const Money& other);
	friend fstream& operator >> (fstream& in, Money& other);
private:
	unsigned long R;
	unsigned int K;
};