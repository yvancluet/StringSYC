#include "string.h"


//Constructors

string::string (){ //Default constructor
	size_ = 0;
	capacity_ = 0;
	tab = nullptr;
}

string::string (const string& str){ //copy constructor
	
	size_ = str.size();
	capacity_ = str.capacity();	
	tab = new char[capacity_+1];	
	char* str_tab = str.c_str();	
	for (int i = 0 ; i<(size_+1) ; i++){
		tab[i] = str_tab[i];
	}
}

//Public Methods

void string::clear (void){
	tab[0] = '\0';
	size_ = 0;
}

//Protected Methods

//Operators

string operator+ (string&& lhs, const char* rhs){
  return lhs + string(rhs);
}
 
string& string::operator= (char c){
	
  if(capacity_ < 1){
    delete[] tab;
    tab = new char[2];
    capacity_ = 1;
    size_ = 1;
  }
  
  tab[0] = c;
  tab[1] = '\0';
    
  return *this;
}

string operator+ (const string& A, char B){
	
  char* chaineA = A.c_str();
  
  int a = A.size();
  int sumsize = a + 1;
	
  if (sumsize > A.Sizemax){
    sumsize = A.Sizemax;
    std::cout << "String's length exceeds maximum capacity"  << std::endl;
  }
  
  char* sumchaine = new char[sumsize+1];
	
  for (int i =0; i<a; i++){
    sumchaine[i]=chaineA[i];
  }
	
  sumchaine[a]=B;
  sumchaine[sumsize] = '\0';
  return string(sumchaine);

}

