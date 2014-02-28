
 SOFTWARE DESIGN & ANALYSIS 3 PROJECT 1
 PROFESSOR WEISS HUNTER COLLEGE
 WILLIAM WIDMER 
 

// From the assignment.pdf

OVERVIEW
The purpose of this project is to give you practice indesigning and implementing classes, and using existing templates classes. You will design and implement a class to present polynomials and perform polynomial multiplication... The main program will read a sequence of polynomial definitions and operations from a file, create polynomials, and perform the specific operations.

INPUT AND OUTPUT
A vector of a most 100 Polynomials will be created. The main program wil read input from a text file whose name is specified on the command line. Each line of the fille will be in one of the following four formats:

1: k: c1 e1 c2 e2...cn en
  k is the place within the vector where this polynomial will be stored. Whitespace separates each term.
  ex: 3 : 6 5 -4 3 -2 1 2 0

2: n = m*k
  This input means that the nth position in the vector will contain the product of Polynomials m and k.

3: eval n(6)
  Evaluates the nth Polynomial where x = 6
  
4: show n
  Display the nth Polynomial
