//============================================================================
// Name        : tokenizer.cpp
// Author      : William Widmer
// Version     : 1.0?
// Description : 
//============================================================================
#include <iostream>
#include "tokenizer.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>   // for isalpha(), isalnum(), isdigit()
 

using namespace std; 
                                                                         
Tokenizer::Tokenizer(string str)                                                       
    : input_str(str), cur_pos(0)
{                                                                              
    separators.insert(' ');
}
 

Token Tokenizer::next_token()
{
    Token ret(ENDTOK, "", 0); // the default token is the ENDTOK
    size_t last;
 
    if (has_more_token()) { // cur_pos is at next non-separator char
        last = cur_pos++;   // hence, input_str[last] is a non-separator
        switch (input_str[last]) {
            case '+': case '-': case '*': case '/': case '=': case ':':
                ret.type = OPERATOR;
                ret.value = input_str[last];
                break;
            case '(': case ')': case '[': case ']': case '{': case '}':
                ret.type = DELIM;
                ret.value = input_str[last];
                break;            
            
            default:
                if (isdigit(input_str[last])) {
                    // scanning for NUMBER
                    move_through_digits();
                    if (input_str[cur_pos] == '.') {
                        cur_pos++;
                        move_through_digits();
                    }
                    ret.type  = NUMBER;
                    ret.value = input_str.substr(last, cur_pos-last);
                } else if (input_str[last] == '.') {
                    move_through_digits();
                    if (cur_pos == last+1) { // there was a '.' but no digit
                        ret.type = ERRTOK;
                        ret.value = input_str[last];
                    } else {
                        ret.type  = NUMBER;
                        ret.value = input_str.substr(last, cur_pos-last);
                    }
                } else if (isalpha(input_str[last]) || input_str[last] == '_') {
                    // sanning for IDENT, can start with alpha or _
                    while ( cur_pos < input_str.length() &&
                            (isalnum(input_str[cur_pos]) ||
                            input_str[cur_pos] == '_') )
                        cur_pos++;
                    ret.type  = CMD;
                    ret.value = input_str.substr(last, cur_pos-last);
                } else {
                    // unrecognized character, just an error token here
                    ret.type = ERRTOK;
                    ret.value = input_str[last];
                }
                break;       
        } // end switch()
    } // end if (has more token())
    return ret;
}
 
/*
	take all tokens and place into a vector for convienence. 
*/
vector<Token> Tokenizer::tokenize()
{
    vector<Token> ret;
    Token tok;
    while (has_more_token()) {
        tok = next_token();
        ret.push_back(tok);
    }
    return ret;
}
 

void Tokenizer::set_input(string str)
{
    input_str = str;
    restart();
}
 
/*
   returns true if there's more token down the stream from the current pos
   false otherwise
   cur_pos is moved to the first non-separator character or to the end of input
 */
bool Tokenizer::has_more_token()
{
    while (cur_pos < input_str.length() &&
            separators.find(input_str[cur_pos]) != separators.end()) {
        cur_pos++;
    }
    return (cur_pos < input_str.length());
}
 
/* 
	keep increasing cur_pos until the end of input_str or a non-digit is seen
 */
void Tokenizer::move_through_digits()
{
    while (cur_pos < input_str.length() && isdigit(input_str[cur_pos]))
        cur_pos++;
}
 
/*
   restart from the beginning
 */
void Tokenizer::restart()
{
    cur_pos = 0;
}

