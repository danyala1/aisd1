#include <stdio.h>
#include <iostream>

using namespace std;
struct list {
    double degree;
    double coefficent;
    list* next;
};
class Equalization
{
public:
    double epsilon = 0.1;
    
    list *head = nullptr;
    int count = 0;
    Equalization(double coefficent, double degree);
    ~Equalization();

    list* GetHead();

    void SetHead(list* head);

    bool DetectOldDegree(double coefficent, double degree);

    void Set(double coefficent, double degree);

    int DeleteElement(double degree);

    void Derivative();

    void Multiplication(double value);

    void Calculation(double x);

    bool operator==(Equalization& src);

    void operator -(Equalization& src);

    void operator +(Equalization& src);
       

    int operator[](double degree);

    friend ostream& operator<<(ostream& os, Equalization obj);
};


class EClassException
{
protected:
    char _err[256];
public:
    EClassException(const char* err);
    void Print();
};