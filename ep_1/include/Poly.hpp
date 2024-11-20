#ifndef POLY_HPP
#define POLY_HPP
#include <iostream>

using namespace std;
typedef struct pNode
{
    int coef;
    int exp;
    struct pNode *link;
} pNode;

typedef struct Poly
{
    pNode *head;
}Poly;

struct Compare {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.first < b.first;
    }
};

class Polynominal
{
public:
    Poly* Init_poly(Poly *p);
    void Print_Poly(Poly *p);
    Poly *Poly_Multi(Poly *p, int coef, int exp);
    Poly *Poly_Add(Poly *result, Poly *q);
    Poly *Poly_Poly_Multi(Poly *q, Poly *p);
    Poly *Poly_Insert(Poly *q, int coef, int exp);
};
#endif //POLY_HPP
