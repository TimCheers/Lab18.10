#include "Money.h"
#include "FileWork.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    system("chcp 1251>nul");
    Money sum;
    char FN[30];
    int ch = 1;
    int a=-1;
    while (ch !=0)
    {
        cout << "\n-----------------------------------------------------------------------\n";
        cout << "Введите номер команды:\n0) Выход\t\t\t1) Создать файл\n2) Распечатать файл\t\t3) Удалить эллемент по номеру\n4) Добавить эллемент\t\t5) Изменить элемент\n"<<endl;
        cout << "\n-----------------------------------------------------------------------\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nВведите название файла: ";
            cin >> FN;
            makeF(FN);
            break;
        case 2:
            cout << "\nВведите название файла: ";
            cin >> FN;
            PrintF(FN);
            break;
        case 3:
            cout << "\nВведите название файла: ";
            cin >> FN;
            DelByN(FN);
            break;
        case 4:
            cout << "\nВведите название файла: ";
            cin >> FN;
            a = AddMid(FN);
            if (a != 0)
            {
                AddEnd(FN, a);
            }
            break;
        case 5:
            cout << "\nВведите название файла: ";
            cin >> FN;
            changeOBJ(FN);
            break;
        case 0:
            cout << "\n==================================   Программа остановлена   ==================================\n\n\n\n";
        default:
            cout << "Ошибка!\n";
            break;
        }
    }
}
