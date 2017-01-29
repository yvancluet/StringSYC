#include "string.h"
#include <iostream>

int main(){
  
//Creating Character Table
	char const * a = "Ceci"; 
	char const * b = " est une phrase.";

//Creating a string using the copy contructor	
	string A = string(a);
	std::cout << A.c_str() << std::endl;
	string B = string(b);
	string AB;
// +(string) operator test
	AB = A + B;
	std::cout << AB.c_str() << std::endl;
// +(char*) operator test
	AB = A + " est une phrase.";
	std::cout << AB.c_str() << std::endl;


	char const * c = "Patat";
	string C = string(c);
	char d='a';
	string Cd;
// +(char) operator test
	Cd = C + d;
	std::cout<<(Cd).c_str()<<std::endl;

  return 0;  
}
