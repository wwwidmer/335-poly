//============================================================================
// Name        : main.cpp
// Author      : William Widmer
// Version     : 1.0
// Description : Main function to act as a driver for Polynomial class and Tokenizer class. Accepts a filename as input from command line then interprets the file through the use of the Tokenizer. Prints out all results to command line.
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
  /*  string input;			
  ifstream file;
  vector<Polynomial> poly[100];
  Tokenizer tok;
    
  while(cin){
    cin >> input;
    file.open(input.c_str());
    if(!file.is_open()){
      cout << "Error opening file. Exiting..." << endl;
      break;
    } 
    std::string line;
    vector<Token> tokens;
    while(std::getline(file, line)){
      tok.set_input(line);
      tokens = tok.tokenize();
      if(tokens[0].type == NUMBER){
	int c;
	Polynomial temp;
	c=std::atoi(tokens[0].value.c_str());
	if(tokens[1].value == ":"){
	  int a,b,c;
	  for(int i=2;i<tokens.size();i=i+2){
	    a = std::atoi(tokens[i].value.c_str());
	    b = std::atoi(tokens[i+1].value.c_str());	
	    temp.set(a,b);
	  }  
	  // cast c to integer
	  // poly[c] = temp;	  
	  cout << temp;
	  cout << "Has been added to the array in the nth position" << endl;
	  
	} else if(tokens[1].value == "="){
	  Polynomial temp;
	  int a,b;
	  a = std::atoi(tokens[2].value.c_str());
	  b = std::atoi(tokens[3].value.c_str());
	  // temp = poly[a]*poly[b];
	  // poly[tokens[0].value] = temp;
	  cout << temp;
	  cout << "The polynomials at position x, y have been multiplied to produce." << endl;
	  cout << "and placed into position n in the array." << endl;
	}			  
      } else if(tokens[0].type == CMD)
	{
	  if(tokens[0].value == "show"){
	    // cout <<  poly[std::atoi(tokens[1].value.c_str())];
	    cout <<"Showing the polynomial in the nth position of the array:"<<endl;
	  } else if(tokens[0].value== "eval"){
	    // poly[tokens[1]].eval(tokens[2]);
	    cout <<"Evaluating the nth position of the array by taking x = "<<endl;
	  }
	}			
    }		
    break;	
    } */
  Polynomial p(1,2);
  Polynomial c;
  c.set(1,2);
  c.set(5,4);
  p.set(2,3);
  p*c;
  cout << p;
  
  return 0;
}
