#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
/* ����������� � �����������: ��������� ������� ����������;
� �������� [] ��� ������ ������������ ��� �������� ������� (���������� ���������� ��������� ��� ����� ��������������� �������);
 ����� set ��� ��������� ������������ ��� �������� ������� (���������� ���������� ��������� � ������ �������� �������� ������������ � ��� ����� ��������������� �������);
� ��������� �������� � ��������� �����������;
 ��������� ��������� ���������� �� ������ (���������� ���������������);
���������� �������� ���������� ��� ��������� �������� �.
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
            this->head->next = NULL; // ��� ��������� ���� ������
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
                std::cout << "\n������� " << FunctionHead->degree << " �������������  ���������� �� " << coefficent << endl;
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
        cout << "\n���� �����������: ";
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
        cout << "\n��������� ������������ ���������...\n";
    }
    void Calculation(double x) {
        list* FunctionHead = GetHead();
        double sum = 0;
        while (FunctionHead) {
            sum += FunctionHead->coefficent * pow(x, FunctionHead->degree);
            FunctionHead = FunctionHead->next;
        }
        cout << "��� x=" << x << " �������� ������������������ ����� " << sum << endl;
    }

    bool operator==(Equalization& src)
    {
        list* FunctionHead = GetHead();
        list* StartHeadB = src.head;
        int SearchSuccesesful = 0;
        if (count != src.count) return false;
        while (src.head) {
            while (FunctionHead) {

                //          ||degree1|  -   |degree2||   <  |epsilon|
                if (abs(abs(FunctionHead->degree) - abs(src.head->degree)) <= abs(epsilon) &&
                    abs(abs(FunctionHead->coefficent) - abs(src.head->coefficent)) <= abs(epsilon)) SearchSuccesesful++;
                FunctionHead = FunctionHead->next;
            }
            src.head = src.head->next;
        }
        src.head = StartHeadB;

        if (SearchSuccesesful == count) return true;
        else return false;

    }

    void operator -(Equalization& src)
    {
        list* FunctionHead = GetHead();
        list* StartHeadB = src.head;
        bool SearchSuccesesful;
        while (src.head) {
            SearchSuccesesful = false;
            while (FunctionHead) {
                if (FunctionHead->degree == src.head->degree)
                {
                    SearchSuccesesful = true;
                    FunctionHead->coefficent -= src.head->coefficent;

                    break;
                }
                FunctionHead = FunctionHead->next;
            }
            if (!SearchSuccesesful)
            {
                Set(src.head->coefficent * (-1), src.head->degree);
            }
            src.head = src.head->next;
        }
        src.head = StartHeadB;
    }

    void operator +(Equalization& src)
    {
        list* FunctionHead = GetHead();
        list* StartHeadB = src.head;
        bool SearchSuccesesful;
        while (src.head) {
            SearchSuccesesful = false;
            while (FunctionHead) {
                if (FunctionHead->degree == src.head->degree)
                {
                    SearchSuccesesful = true;
                    FunctionHead->coefficent += src.head->coefficent;
                    if (FunctionHead->coefficent == 0) count--;
                }
                FunctionHead = FunctionHead->next;
            }
            if (!SearchSuccesesful)
            {
                Set(src.head->coefficent, src.head->degree);
            }
            src.head = src.head->next;
        }
        src.head = StartHeadB;
    }

    int operator[](double degree)
    {
        list* FunctionHead = GetHead();
        while (FunctionHead) {
            if (FunctionHead->degree == degree)
            {
                double coefficent;
                cout << "������� ����� ���������� ������� " << FunctionHead->degree << ": ";
                cin >> coefficent;
                if (coefficent != 0) {
                    FunctionHead->coefficent = coefficent;
                }
                else { cout << "������ �������� �� ����"; }
                return 0;
            }
            FunctionHead = FunctionHead->next;
        }
        cout << "��� ����� ������� :( \n";
        return 0;
    }
