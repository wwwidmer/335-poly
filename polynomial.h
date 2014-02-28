//============================================================================
// Name        : Polynomial.h
// Author      : William Widmer 
// Version     : 1
// Description : Polynomial class header file
//============================================================================

using namespace std;
#include <ostream>
#include <list>

#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

/* 
 * Term in the form of (coefficient x ^ degree)
 */
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
  double operator()(double x);
  Polynomial& operator*(const Polynomial& r);
  ~Polynomial();
  void simplify();
  void set(int x, int y);
  friend std::ostream& operator<< (std::ostream& o, const Polynomial& p);
};	

	


#endif
	
	
