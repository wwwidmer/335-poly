//============================================================================
// Name        : 
// Author      : 
// Version     :
// Copyright   : 
// Description : 
//============================================================================

using namespace std;
#include <ostream>
#include <list>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

struct Term
{
  int coefficient;
  int degree; 
};

class Polynomial
{
private:
  list<Term> t;
  
public:	
  Polynomial();
  Polynomial(const Polynomial& p); 
  Polynomial(int c, int e);		
  Polynomial& operator=(const Polynomial& r);
  Polynomial& operator*(const Polynomial& r);
  ~Polynomial();
  void set(int x, int y);
  double eval(double x);
  void print();	
  friend std::ostream& operator<< (std::ostream& o, const Polynomial& p);
};	

	


#endif
	
	
