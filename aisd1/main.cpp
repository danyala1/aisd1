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


int main() {
    try
    {
        double coefficent, degree;
        int choice;
        setlocale(LC_ALL, "RUS");
        cout << "Многочлен пока не создан, введите коэффицент первого элемента: " << endl;
        cin >> coefficent;
        cout << "Введите его степень: " << endl;
        cin >> degree;
        Equalization A(coefficent, degree);
        bool flag = true;
        while (flag) {
            A.DeleteElement(0);
            cout << A;
            cout << "Выберите действие:\n1)Добавить новый элемент\n2)Умножить на скаляр\n3)Вычислить х\n4)Найти производную\n5)Сумма с другим многочленом\n6)Вычесть из него другой многочлен\n7)Отредактировать коэффицент\n8)Удалить элемент\n9)Выход\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Введите коэффицент нового элемента: " << endl;
                cin >> coefficent;
                cout << "Введите его степень: " << endl;
                cin >> degree;
                A.Set(coefficent, degree);
            }
            else if (choice == 2) {
                cout << "Введите значение на которое хотите умножить: " << endl;
                cin >> degree;
                A.Multiplication(degree);
            }
            else if (choice == 3) {
                cout << "Введите значение х: " << endl;
                cin >> degree;
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
                    cin >> coefficent;
                    cout << "Выберите степень элемента нового многочлена: ";
                    cin >> degree;
                    B.Set(coefficent, degree);
                    cout << "Добавить еще один элемент к многочлену? \n1)Да\n2)Нет";
                    cin >> choice;
                } while (choice == 1);
                if (SumOperation) A + B;
                else A - B;
            }
            else if (choice == 7) {
                cout << "Выберите степень элемента который редактируем: ";
                cin >> degree;
                A[degree];
            }
            else if (choice == 8) {
                cout << "Выберите степень элемента который удаляем: ";
                cin >> degree;
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
