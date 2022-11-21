#include <stdio.h>
#include <iostream>
#include "Header.h"

using namespace std;
/* конструктор с параметрами: начальную степень многочлена;
• оператор [] для чтения коэффициента при заданной степени (обеспечить корректное поведение при любой неотрицательной степени);
 метод set для установки коэффициента при заданной степени (обеспечить корректное поведение в случае нулевого значения коэффициента и при любой неотрицательной степени);
• операторы сложения и вычитания многочленов;
 ооператор умножения многочлена на скаляр (обеспечить коммутативность);
вычисление значения многочлена при указанном значении х.
*/


double CheckDouble()
{
    double number = 0;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Input correct value" << endl;
    }
    return number;
}

int CheckChoise()
{
    int number = 0;
    while (!(cin >> number) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Enter a number" << endl;
    }
    return number;
}

int main() {
    try
    {
        double coefficent, degree;
        int choice;
        setlocale(LC_ALL, "RUS");
        cout << "Многочлен пока не создан, введите коэффицент первого элемента: " << endl;
        coefficent = CheckDouble();
        cout << "Введите его степень: " << endl;
        degree = CheckDouble();
        Equalization A(coefficent, degree);
        bool flag = true;
        while (flag) {
            A.DeleteElement(0);
            cout << A;
            cout << "Выберите действие:\n1)Добавить новый элемент\n2)Умножить на скаляр\n3)Вычислить х\n4)Найти производную\n5)Сумма с другим многочленом\n6)Вычесть из него другой многочлен\n7)Отредактировать коэффицент\n8)Удалить элемент\n9)Выход\n";
            choice = CheckChoise();
            if (choice == 1)
            {
                cout << "Введите коэффицент нового элемента: " << endl;
                coefficent = CheckDouble();
                cout << "Введите его степень: " << endl;
                degree = CheckDouble();
                A.Set(coefficent, degree);
            }
            else if (choice == 2) {
                cout << "Введите значение на которое хотите умножить: " << endl;
                degree = CheckDouble();
                A.Multiplication(degree);
            }
            else if (choice == 3) {
                cout << "Введите значение х: " << endl;
                degree = CheckDouble();
                A.Calculation(degree);
            }
            else if (choice == 4) {
                A.Derivative();
            }
            else if (choice == 5 || choice == 6) {
                bool SumOperation = false;
                if (choice == 5) SumOperation = true;
                Equalization B(0, 0);
                do {
                    cout << "Выберите коэффицент элемента нового многочлена: ";
                    coefficent = CheckDouble();
                    cout << "Выберите степень элемента нового многочлена: ";
                    degree = CheckDouble();
                    B.Set(coefficent, degree);
                    cout << "Добавить еще один элемент к многочлену? \n1)Да\n2)Нет\n";
                    choice  = CheckChoise();
                } while (choice == 1);
                if (SumOperation) A + B;
                else A - B;
            }
            else if (choice == 7) {
                cout << "Выберите степень элемента который редактируем: ";
                degree = CheckDouble();
                A[degree];
            }
            else if (choice == 8) {
                cout << "Выберите степень элемента который удаляем: ";
                degree = CheckDouble();
                if (A.DeleteElement(degree) == 0) cout << "Нет такого элемента :(" << endl;
            }
            else if (choice == 9) {
                flag = false;
            }
            else {
                system("CLS");
            }

        }
    }
    catch (EClassException& err)
    {
        err.Print();
    }
}
