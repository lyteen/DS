#include <iostream>
#include "Poly.hpp"

int main() 
{
    Polynominal polynominal;
    Poly *p = nullptr;
    Poly *q = nullptr;
    Poly *n = nullptr;
    p = polynominal.Init_poly(p);

    q = polynominal.Init_poly(q);
    polynominal.Print_Poly(p);
    polynominal.Print_Poly(q);
    //n = Poly_Add(p, q);
    //q = Poly_Multi(p, 3, 3);
    n = polynominal.Poly_Poly_Multi(q, p);
    //Print_Poly(n);
    return 0;
}