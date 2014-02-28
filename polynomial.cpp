//============================================================================
// Name        : Polynomial.cpp
// Author      : William Widmer
// Version     : 1
// Description : Polynomial class implementation. 
//============================================================================


#include <iostream>
#include <math.h>
#include "polynomial.h"
#include <list>
using namespace std;


Polynomial::Polynomial() // default constructor, zero polynomial 0x^0 
{
  Term zero;
  zero.coefficient=0;
  zero.degree=0;
  t.push_front(zero);
}
Polynomial::Polynomial(const Polynomial& p) // Copy Constructor
{
  list<Term> tt = p.t;
  for (list<Term>::iterator it = tt.begin(); it != tt.end(); ++it)
    {
      set((*it).coefficient, (*it).degree);
    }   
}	
Polynomial::Polynomial(int x, int y) // Constructor for cx^e
{
  Term xy;
  xy.coefficient=x;
  xy.degree=y;
  if(t.empty()){
    t.push_front(xy);
  } 
}

Polynomial::~Polynomial() // Clear memory and didn't do.
{   
}

// Comparison function for sorting.
bool compare(Term a, Term b){  
  return a.degree > b.degree;
}

void Polynomial::simplify(){
  // This works best if the list is sorted... So call another sort just in case.
  t.sort(compare);  
  list<Term>::iterator it = t.begin();  
  list<Term>::iterator i = t.begin();
  i++;  
  while(i!=t.end()){
    if( (*it).degree == (*i).degree && (*i).degree != 0){
      (*it).coefficient+=(*i).coefficient;
      it=t.erase(it);
      i++;
      continue;      
    }   
     it++;
     i++;
  }
}
  


/* Function to set an exponent and coefficient. Iterates 
 * to find an appropriate position to place the new Term xy. 
 * If the List of terms is empty xy becomes the first element.
 */
void Polynomial::set(int x, int y)
{
  Term xy;
  xy.coefficient=x;
  xy.degree=y;
  if(!t.empty()){
    if(y > t.back().degree){
      t.push_back(xy);
    } else {
      for (list<Term>::iterator it = t.begin(); it != t.end(); ++it)
	{
	  if((*it).degree > xy.degree){	
	    t.insert(it,xy);
	    break;
	  } 
	} 
    }
  } else {
    t.push_front(xy);
  }
  t.sort(compare);  
  simplify();
}
	

/*
 * Operator overloads for (), *, =, and <<
 */
	
double Polynomial::operator()(double x){
  double sum=0;	
  for (list<Term>::iterator it = t.begin(); it != t.end(); ++it)
    {
      double xdeg = pow(x,(*it).degree);
      sum += (*it).coefficient*xdeg;
    }  
  return sum;  
}	


Polynomial& Polynomial::operator*(const Polynomial& r){
  list<Term> tt = r.t;
  list<Term> temp_list;
  for (list<Term>::iterator it = tt.begin(); it != tt.end(); ++it){
    for(list<Term>::iterator it2 = t.begin(); it2 != t.end(); ++it2){
      Term temp;
      temp.degree=(*it).degree+(*it2).degree;
      temp.coefficient=(*it).coefficient*(*it2).coefficient;
      temp_list.push_front(temp);
    }
  }
  temp_list.sort(compare);
  t=temp_list;  
  simplify();
}

Polynomial& Polynomial::operator=(const Polynomial& r){  
  list<Term> tt = r.t;
  t.clear();
  for (list<Term>::iterator it = tt.begin(); it != tt.end(); ++it)
    {
      set((*it).coefficient, (*it).degree);
    }   
}
  

std::ostream& operator<< (std::ostream& o, const Polynomial& p){  
  list<Term> t = p.t;
  list<Term>::iterator i = t.end();
  list<Term>::iterator it;
  --i;
  for (it = t.begin(); it != t.end(); ++it)
    {
      if(!(*it).coefficient == 0){
       	o << (*it).coefficient << "x";
	if(1 < (*it).degree || 0 == (*it).degree){
	  o << "^" << (*it).degree;
	}
	if(!(it==i)){
	 o << " + ";
	}
      }
    }
}

