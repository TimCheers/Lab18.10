#pragma once
#include "Money.h"
#include <iostream>
#include <fstream>
using namespace std;
int makeKoll()
{
	int n = -1;
	while (n < 0)
	{
		cout << "������� ����� ��������: ";
		cin >> n;
		if (n < 0)
		{
			cout << "������!\n";
		}
	}
	return n;
}
void makeF(const char* Fname)
{
	fstream file(Fname, ios::out | ios::trunc);
	if (!file)
	{
		cout << "���������� ������� ����!\n";
	}
	else
	{
		Money tmp;
		int n = -1;
		while (n <= 0)
		{
			cout << "������� ����������� �������: ";
			cin >> n;
			if (n <= 0)
			{
				cout << "������!\n";
			}
		}
		for (int i = 0; i < n; i++)
		{
			cout << "������� " << i + 1 << " �����: ";
			cin >> tmp;
			file << tmp << endl;
		}
		file.close();
	}
}
void PrintF(const char* Fname)
{
	fstream file(Fname, ios::in);
	if (!file)
	{
		cout << "���������� ������� ����!\n";
	}
	else
	{
		Money tmp;
		bool f = 0;
		cout << "\n---------------------------------------------------------\n";
		cout << "\t\t\t" << Fname << "\t\t\t" << endl;
		while (file >> tmp)
		{
			f = 1;
			cout << tmp <<endl;
		}
		cout << "\n---------------------------------------------------------\n";
		if (f == 0)
		{
			cout << "���� ����!\n";
		}
		file.close();
	}
}
void DelByN(const char* Fname)
{
	fstream tmpF("tmpF", ios::out);
	fstream file(Fname, ios::in);
	if (!file)
	{
		cout << "���������� ������� ����!\n";
	}
	else
	{
		Money tmp;
		int i = 0;
		int n = makeKoll();
		bool f = 0;
		while (file >> tmp)
		{
			if (i != n)
			{
				tmpF << endl <<tmp;
			}
			else
			{
				f = 1;
			}
			i++;
			if (file.eof())
			{
				break;
			}
		}
		file.close();
		tmpF.close();
		remove(Fname);
		rename("tmpF", Fname);
		if (f == 0)
		{
			cout << "������ �������� ��������\n";
		}
	}
}
int AddMid(const char* Fname)
{
	fstream tmpF("tmpF", ios::out);
	fstream file(Fname, ios::in);
	if (!file)
	{
		cout << "���������� ������� ����!\n";
	}
	else
	{
		Money tmp,addObj;
		int i = 0;
		int n = makeKoll();
		bool f = 1;
		while (file >> tmp)
		{
			if (i == n)
			{
				cout << "������� ����������� �����: ";
				cin >> addObj;
				f = 0;
				tmpF << addObj << endl;
			}
			tmpF << tmp << endl;
			if (file.eof())
			{
				break;
			}
			i++;
		}
		file.close();
		tmpF.close();
		remove(Fname);
		rename("tmpF", Fname);
		if (f==1)
		{
			return n;
		}
		else
		{
			return 0;
		}
	}
}
void AddEnd(const char* Fname, int n)
{
	fstream file(Fname, ios::app);
	if (!file)
	{
		cout << "���������� ������� ����!\n";
	}
	else
	{
		Money addObj;
		cout << "������� ����������� �����: ";
		cin >> addObj;
		file << addObj << endl;
	}
}
void changeOBJ(const char* Fname)
{
	fstream tmpF("tmpF", ios::out);
	fstream file(Fname, ios::in);
	if (!file)
	{
		cout << "���������� ������� ����!\n";
	}
	else
	{
		Money tmp, addObj;
		int i = 0;
		int n = makeKoll();
		bool f = 1;
		while (file >> tmp)
		{
			if (i == n)
			{
				cout << "������� �����: ";
				cin >> addObj;
				f = 0;
				tmpF << addObj << endl;
			}
			else
			{
				tmpF << tmp << endl;
			}
			if (file.eof())
			{
				break;
			}
			i++;
		}
		file.close();
		tmpF.close();
		remove(Fname);
		rename("tmpF", Fname);
		if (f == 1)
		{
			cout << "������ ��������� ��������\n";
		}
	}
}
void DelByV(const char* Fname)
{
	fstream tmpF("tmpF", ios::out);
	fstream file(Fname, ios::in);
	if (!file)
	{
		cout << "���������� ������� ����!\n";
	}
	else
	{

	}
}