//============================================================================
// Name        : main.cpp
// Author      : William Widmer
// Version     : 1.0
// Description : Main function to act as a driver for Polynomial class and
//               Tokenizer class. Accepts a filename as input from command
//               line then interprets the file through the use of the
//               Tokenizer. Prints out all results to command line / ostream.
//============================================================================


#include <fstream>
#include <iostream>
#include "polynomial.h"
#include <vector>
#include <cstdlib>
#include "tokenizer.h"
using namespace std;

int main()
{ 
  cout << "CSci 335 : Project one. Please input a filepath" << endl;
  string input;			
  ifstream file;
  vector<Polynomial> poly;
  Tokenizer tok;
  std::string line;
  vector<Token> tokens;
    
  while(cin){
    cin >> input;
    file.open(input.c_str());
    if(!file.is_open()){
      cout << "Error opening file. Exiting..." << endl;
      break;
    } 

    /* I kept running into a 'request for member xy which is of 
     * non-class type vector' so I bit the bullet and added this for loop 
     * to make the file compile (and work!). Adds many 0x^0s.;  
     */    
    for(int i=0;i<100;i++){
      Polynomial p;
      poly.push_back(p);
    }

    // while we have lines in the input tokenize the line and run some commands we know
    while(std::getline(file, line)){
      tok.set_input(line);
      tokens = tok.tokenize();
      if(tokens[0].type == NUMBER){
	int a,b,c;
	Polynomial temp;
	if(tokens[1].value == ":"){
	  // First type specified in project, a: e1 d1, e2 d2, ..., en dn
	  for(int i=2;i<tokens.size();i=i+2){
	    a = std::atoi(tokens[i].value.c_str());
	    b = std::atoi(tokens[i+1].value.c_str());
	    temp.set(a,b);
	  }  	  
	  c = std::atoi(tokens[0].value.c_str());
	  poly[c]=temp;
	  cout << poly[c];
	  cout << endl;
	  cout << "Has been added to the array in the " << c <<"th position" << endl;
	  
	} else if(tokens[1].value == "="){
	  // Second type. a = b*c
	  Polynomial temp;
	  a = std::atoi(tokens[2].value.c_str());
	  b = std::atoi(tokens[4].value.c_str());	  
	  c = std::atoi(tokens[0].value.c_str());
	  temp = poly[a];
	  temp * poly[b];
	  poly[c] = temp;
	  cout << "The polynomials at position " << a << " & " << b << " have been multiplied to produce:" << endl;	  
	  cout << temp;
	  cout << endl;
	  cout << "and placed into position "<< c <<" in the array." << endl;
	}			  
      } else if(tokens[0].type == CMD)
	{
	  int a,b;
	  if(tokens[0].value == "show"){	  
	    // Third type. show(n)
	    a = std::atoi(tokens[1].value.c_str());
	    cout <<"Showing the polynomial in the "<< a << "th position of the array:"<< endl;
	    cout << poly[a];
	    cout << endl;
	  } else if(tokens[0].value== "eval"){	
	    // Fourth type of input. eval x(n)
	    a = std::atoi(tokens[2].value.c_str());
	    b = std::atoi(tokens[3].value.c_str());
	    cout <<"Evaluating the "<< a <<"th position of the array by taking x = "<< b <<endl;
	    cout << poly[a](b);
	    cout << endl;
	  }
	}			
    }		
    break;	
  } 
  
  return 0;
}
