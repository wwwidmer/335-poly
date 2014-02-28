//============================================================================
// Name        : tokenizer.h
// Author      : William Widmer
// Version     : 1?
// Description : Tokenizer class header file made during a previous class.
//               The tokenizer takes an input and seperates into many tokens
//               of different types to allow for easy input verification.
//============================================================================


#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>
#include <vector>
#include <set>


/*
 * Types of strings that can be found and used from an input.
 */
enum token_types_t{

    CMD,  // a sequence of alphanumeric characters and _, starting with alpha
    STRING, // sequence of characters between " ", no escape
    DELIM,  // {}()[]
    OPERATOR, // + - / * =
    COMMENT,  // # follows by any characters to the end of line/file
    NUMBER,   // a series of digits, or digits.digits, or .digits
    ENDTOK,   // end of string/file, no more token
    ERRTOK    // unrecognized token

};
/*
 * A token is some group of characters seperated by a " ". 
 */
struct Token{
	token_types_t type;
	std::string value;
	int ival;
	Token(token_types_t tt=ENDTOK, std::string val="", int iv=0)
		: type(tt), value(val), ival(iv){}
};

class Tokenizer{    
 	private:
 	std::string    input_str;  // the input string to be scanned
 	size_t         cur_pos;    // current position in the input string
 	std::set<char> separators; // set of separators
 	
 	void move_through_digits(); 
	public:
    	Tokenizer(std::string str="");
 
    	void set_input(std::string); 
    	void restart();            
 
	Token next_token();            
	std::vector<Token> tokenize(); 	
	bool has_more_token();        
};

#endif
