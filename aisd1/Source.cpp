#include "Header.h"
#include <stdio.h>
#include <iostream>


using namespace std;
Equalization::Equalization(double coefficent, double degree) {
        if (coefficent != 0) {
            this->head = new list;
            this->head->degree = degree;
            this->head->coefficent = coefficent;
            this->head->next = NULL;
            count = 1;
        }
    }
Equalization:: ~Equalization() {
        list* p;
        count = 0;
        while (p = head)
        {
            head = p->next;
            delete p;
        }
 }

list* Equalization::GetHead()
{
    return head;
}

    void Equalization::SetHead(list* head) { this->head = head; }

    bool Equalization::DetectOldDegree(double coefficent, double degree) {
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

    void Equalization::Set(double coefficent, double degree)
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

    int Equalization::DeleteElement(double degree)
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

    void  Equalization::Derivative() {
        list* FunctionHead = GetHead();
        
        while (FunctionHead)
        {
            FunctionHead -> coefficent = FunctionHead -> coefficent * FunctionHead->degree;
            FunctionHead -> degree--;
            FunctionHead = FunctionHead->next;

        }
        

    }

    void Equalization::Multiplication(double value) {
        list* FunctionHead = GetHead();
        while (FunctionHead) {
            FunctionHead->coefficent = FunctionHead->coefficent * value;
            FunctionHead = FunctionHead->next;
        }
        cout << "\nСкалярное произведение высчитано...\n";
    }

    void Equalization::Calculation(double x) {
        list* FunctionHead = GetHead();
        double sum = 0;
        while (FunctionHead) {
            sum += FunctionHead->coefficent * pow(x, FunctionHead->degree);
            FunctionHead = FunctionHead->next;
        }
        cout << "При x=" << x << " значение последовательности равно " << sum << endl;
    }

    void Equalization:: operator -(Equalization& src)
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

    void  Equalization:: operator +(Equalization& src)
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

    int Equalization:: operator[](double degree)
    {
        list* FunctionHead = GetHead();
        while (FunctionHead) {
            if (FunctionHead->degree == degree)
            {
                double coefficent;
                cout << "Введите новый коэффицент степени " << FunctionHead->degree << ": ";
                cin >> coefficent;
                if (coefficent != 0) {
                    FunctionHead->coefficent = coefficent;
                }
                else { cout << "Нельзя поменять на ноль"; }
                return 0;
            }
            FunctionHead = FunctionHead->next;
        }
        cout << "Нет такой степени :( \n";
        return 0;
    }


    ostream& operator<<(ostream& os, Equalization obj)
{
    bool FirstStart = true;
    cout << "\nНаша последовательность: ";
    while (obj.head) {
        if (obj.head->coefficent == 0)
        {
            obj.DeleteElement(obj.head->degree);
            FirstStart = true;
        }
        if (!FirstStart && obj.head->coefficent > 0) cout << "+";
        if (obj.head->coefficent != 1) cout << obj.head->coefficent;
        if (obj.head->degree != 0) cout << "x";
        else cout << obj.head->coefficent;
        if (obj.head->degree < 0) { cout << "^(" << obj.head->degree << ")"; }
        else if (obj.head->degree != 1 && obj.head->degree != 0) cout << "^" << obj.head->degree;

        obj.head = obj.head->next;
        FirstStart = false;
    }
    cout << "\n";
    return os;
}
EClassException::EClassException(const char* err) {
        strncpy_s(_err, err, 255);
        _err[255] = 0;
    }
    void EClassException:: Print()
    {
        std::cout << _err << std::endl;
    }
