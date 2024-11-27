#include <iostream>
#include <queue>
#include "Poly.hpp"

using namespace std;

Poly* Polynominal::Poly_Insert(Poly *p, int coef, int exp)
{
    if(!p->head) 
    {
        p->head->coef = coef;
        p->head->exp = exp;
        p->head->link = nullptr;
        return p;
    }
    pNode *pa = p->head;
    pNode *prev = nullptr;
    prev = pa;
    while(pa)
    {
        if(!pa->link)
        {
            pNode *temp = new pNode;
            temp->coef = coef;
            temp->exp = exp;
            temp->link = nullptr;
            prev->link = temp;
            break;
        }
        if(exp > pa->exp)
        {
            pNode *temp = new pNode;
            temp->coef = coef;
            temp->exp = exp;
            temp->link = pa;
            prev->link = temp;
            break;
        }
        else{
            prev = pa;
            pa = pa->link;
        }
    }
    return p;
}

Poly* Polynominal::Init_poly(Poly *p)
{
    p = new Poly;
    pNode* last_node = nullptr;
    pNode* temp = nullptr;
    int poly_num;
    cout << "Input number of poly:" << "\n";
    cin >> poly_num;
    /*
    TODO:
        1.Check the exp isnt already input 
    */
    priority_queue<pair<int, int>, vector<std::pair<int, int>>, Compare> pq;
    int coef, exp;
    for(int j = 0; j < poly_num; j++)
    {
        cout << "Input coef:" << "\n";
        cin >> coef;
        cout << "Input exp:" << "\n";
        cin >> exp;
        pq.push({exp, coef});
    }
    for(int i = 0; i < poly_num; i++)
    {   
        temp = new pNode;
        temp->exp = pq.top().first;
        temp->coef = pq.top().second;
        temp->link = nullptr;
        if (i == 0)
        {
            p->head = temp;
        } else {
            last_node->link = temp;
        }
        last_node = temp;
        pq.pop();
    }
    return p;
}
void Polynominal::Print_Poly(Poly *p)
{   
    pNode* temp = p->head;
    while(temp)
    {
        cout << temp->coef << "x^" << temp->exp;
        temp = temp->link;
        if (temp) cout << "+";
    }
    cout << "\n";
    return;
}
/*
TODO:
    1.How optimized and explain the poly_multiple?
*/
Poly *Polynominal::Poly_Multi(Poly *p, int coef, int exp)
{
    Poly *ployni = new Poly;
    ployni->head = nullptr;  // Initialize the head of the new polynomial to null

    pNode *poly_node = nullptr;  // Pointer to the current node in ployni
    pNode *last = p->head;       // Pointer to the current node in the input polynomial

    while(last)
    {   
        pNode *temp = new pNode;
        temp->coef = coef * last->coef;
        temp->exp = exp + last->exp;
        temp->link = nullptr;  // Set the link of the new node to nullptr

        if(ployni->head == nullptr) {
            // First node in the new polynomial
            ployni->head = temp;
            poly_node = temp;
        } else {
            // Link the new node to the last node in the list
            poly_node->link = temp;
            poly_node = poly_node->link;  // Move to the new last node
        }

        last = last->link;  // Move to the next node in the input polynomial
    }

    return ployni;
}
Poly *Polynominal::Poly_Add(Poly *result, Poly *q)
{

   if(!result) return q;

   pNode *pa = result->head;pNode *pb = q->head;
   pNode *prev = new pNode;
   prev = result->head;
   while (pa && pb)
   {
        if (pa->exp == pb->exp)
        {
            pa->coef = pa->coef + pa->coef;
            prev = pa;
            pa = pa->link;
            pb = pb->link;
        }
        else if(pa->exp < pb->exp)
        {
            pNode *temp = new pNode;
            /*
            instead of pa_current_node to pb_current_node;
            init temp same pa_current_node insert pa_current_node next node
            */
            temp->coef = pa->coef;
            temp->exp = pa->exp;
            temp->link = pa->link;
            prev->coef = pb->coef;
            prev->exp = pb->exp;
            pb = pb->link;
            prev->link = temp;
            pa = temp;
            prev = prev->link; 
        } else 
        {
            prev = pa;
            pa = pa->link;
            if(!pa)
            {
                while(pb)
                {
                    pNode *temp = new pNode;
                    temp->coef = pb->coef;
                    temp->exp = pb->exp;
                    pb = pb->link;
                    temp->link = nullptr;
                    prev->link = temp;
                    prev = prev->link;
                }
            }
        }
   }
   return result;
}

Poly *Polynominal::Poly_Poly_Multi(Poly *q, Poly *p)
{
    if(!(q || p)) return nullptr;
    pNode *qa = q->head;
    Poly *result = nullptr;
    Poly *temp = nullptr;
    int coef, exp;
    while(qa)
    {
        coef = qa->coef;
        exp = qa->exp;
        temp = Poly_Multi(p, coef, exp);
        result = Poly_Add(result, temp);
        Print_Poly(result);
        qa = qa->link;
    }
    return result;
}