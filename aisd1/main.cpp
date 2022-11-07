#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
/* конструктор с параметрами: начальную степень многочлена;
• оператор [] для чтения коэффициента при заданной степени (обеспечить корректное поведение при любой неотрицательной степени);
 метод set для установки коэффициента при заданной степени (обеспечить корректное поведение в случае нулевого значения коэффициента и при любой неотрицательной степени);
• операторы сложения и вычитания многочленов;
 ооператор умножения многочлена на скаляр (обеспечить коммутативность);
вычисление значения многочлена при указанном значении х.
*/
class Equalization
{

public:
    double epsilon = 0.1;
    struct list {
        double degree;
        double coefficent;
        list* next;
    } *head;
    int count = 0;
    Equalization(double coefficent, double degree) {
        if (coefficent != 0) {
            this->head = new list;
            this->head->degree = degree;
            this->head->coefficent = coefficent;
            this->head->next = NULL; // это последний узел списка
            count = 1;
        }
    }
    ~Equalization() {
        list* p;
        count = 0;
        while (p = head)
        {
            head = p->next;
            delete p;
        }
    }
    list* GetHead() { return head; }
    void SetHead(list* head) { this->head = head; }
    bool DetectOldDegree(double coefficent, double degree) {
        list* FunctionHead = GetHead();
        while (FunctionHead) {
            if (FunctionHead->degree == degree) {
                FunctionHead->coefficent = FunctionHead->coefficent + coefficent;
                std::cout << "\nСтепени " << FunctionHead->degree << " просуммирован  коэффицент на " << coefficent << endl;
                return true;
            }
            FunctionHead = FunctionHead->next;
        }
        return false;
    }

    void Set(double coefficent, double degree)
    {
        if (!DetectOldDegree(coefficent, degree))
        {
            if (coefficent != 0) {
                list* pointer;
                pointer = new list;
                pointer->coefficent = coefficent;
                pointer->degree = degree;
                pointer->next = this->head;
                this->head = pointer;
                count++;
            }
        }

    }

    int DeleteElement(double degree)//1x1+2x2+3x3   2
    {
        int NowCount = 0;
        list* FunctionHead = GetHead();
        list* pred = FunctionHead;
        while (NowCount < count)
        {
            if (FunctionHead->degree == degree)
            {
                if (NowCount == 0)
                {
                    SetHead(FunctionHead->next);

                }
                else if (NowCount == count - 1)
                {
                    pred->next = nullptr;
                }
                else {
                    pred->next = FunctionHead->next;
                }
                delete FunctionHead;
                count--;
                return 1;
            }
            pred = FunctionHead;
            FunctionHead = FunctionHead->next;
            NowCount++;
        }
        return 0;
    }

    void Derivative() {
        list* FunctionHead = GetHead();
        cout << "\nНаша производная: ";
        bool FirstStart = true;
        while (FunctionHead) {
            if (!FirstStart) {

                if (FunctionHead->coefficent * FunctionHead->degree > 0) cout << "+";
            }
            cout << FunctionHead->coefficent * FunctionHead->degree;
            if (FunctionHead->degree != 1) {
                cout << "x^" << FunctionHead->degree - 1;
            }
            FirstStart = false;
            FunctionHead = FunctionHead->next;
        }

    }

    void Multiplication(double value) {
        list* FunctionHead = GetHead();
        while (FunctionHead) {
            FunctionHead->coefficent = FunctionHead->coefficent * value;
            FunctionHead = FunctionHead->next;
        }
        cout << "\nСкалярное произведение высчитано...\n";
    }
    void Calculation(double x) {
        list* FunctionHead = GetHead();
        double sum = 0;
        while (FunctionHead) {
            sum += FunctionHead->coefficent * pow(x, FunctionHead->degree);
            FunctionHead = FunctionHead->next;
        }
        cout << "При x=" << x << " значение последовательности равно " << sum << endl;
    }
