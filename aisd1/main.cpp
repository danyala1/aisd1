#include <stdio.h>
#include <iostream>
#include "Header.h"

using namespace std;
/* ����������� � �����������: ��������� ������� ����������;
� �������� [] ��� ������ ������������ ��� �������� ������� (���������� ���������� ��������� ��� ����� ��������������� �������);
 ����� set ��� ��������� ������������ ��� �������� ������� (���������� ���������� ��������� � ������ �������� �������� ������������ � ��� ����� ��������������� �������);
� ��������� �������� � ��������� �����������;
 ��������� ��������� ���������� �� ������ (���������� ���������������);
���������� �������� ���������� ��� ��������� �������� �.
*/


int main() {
    try
    {
        double coefficent, degree;
        int choice;
        setlocale(LC_ALL, "RUS");
        cout << "��������� ���� �� ������, ������� ���������� ������� ��������: " << endl;
        cin >> coefficent;
        cout << "������� ��� �������: " << endl;
        cin >> degree;
        Equalization A(coefficent, degree);
        bool flag = true;
        while (flag) {
            A.DeleteElement(0);
            cout << A;
            cout << "�������� ��������:\n1)�������� ����� �������\n2)�������� �� ������\n3)��������� �\n4)����� �����������\n5)����� � ������ �����������\n6)������� �� ���� ������ ���������\n7)��������������� ����������\n8)������� �������\n9)�����\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "������� ���������� ������ ��������: " << endl;
                cin >> coefficent;
                cout << "������� ��� �������: " << endl;
                cin >> degree;
                A.Set(coefficent, degree);
            }
            else if (choice == 2) {
                cout << "������� �������� �� ������� ������ ��������: " << endl;
                cin >> degree;
                A.Multiplication(degree);
            }
            else if (choice == 3) {
                cout << "������� �������� �: " << endl;
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
                    cout << "�������� ���������� �������� ������ ����������: ";
                    cin >> coefficent;
                    cout << "�������� ������� �������� ������ ����������: ";
                    cin >> degree;
                    B.Set(coefficent, degree);
                    cout << "�������� ��� ���� ������� � ����������? \n1)��\n2)���";
                    cin >> choice;
                } while (choice == 1);
                if (SumOperation) A + B;
                else A - B;
            }
            else if (choice == 7) {
                cout << "�������� ������� �������� ������� �����������: ";
                cin >> degree;
                A[degree];
            }
            else if (choice == 8) {
                cout << "�������� ������� �������� ������� �������: ";
                cin >> degree;
                if (A.DeleteElement(degree) == 0) cout << "��� ������ �������� :(" << endl;
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
