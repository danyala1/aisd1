#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
/* конструктор с параметрами: начальную степень многочлена;
Х оператор [] дл€ чтени€ коэффициента при заданной степени (обеспечить корректное поведение при любой неотрицательной степени);
 метод set дл€ установки коэффициента при заданной степени (обеспечить корректное поведение в случае нулевого значени€ коэффициента и при любой неотрицательной степени);
Х операторы сложени€ и вычитани€ многочленов;
 ооператор умножени€ многочлена на скал€р (обеспечить коммутативность);
вычисление значени€ многочлена при указанном значении х.
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
                std::cout << "\n—тепени " << FunctionHead->degree << " просуммирован  коэффицент на " << coefficent << endl;
                return true;
            }
            FunctionHead = FunctionHead->next;
        }
        return false;
    }