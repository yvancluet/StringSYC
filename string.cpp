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

string::string (const char* s){ //Constructor from c-string
  char charac = s[0];
  int longueur = 0;
  while(charac != '\0'){
    longueur ++;
    charac = s[longueur];
  }
  if (longueur > Sizemax){
    longueur = Sizemax;
    std::cout << "String's length exceeds maximum capacity"  << std::endl;
  }
  size_ = longueur;
  capacity_ = longueur;
  tab = new char[longueur + 1];
  for(int i = 0 ; i < longueur ; i++){
    tab[i] = s[i];
  }
  tab[longueur] = '\0';
}


//Destructor

string::~string(){
  delete [] tab;
} 


//Public Methods

void string::clear (void){
	tab[0] = '\0';
	size_ = 0;
}

void string::resize (int n, char c){
  if(n > Sizemax){
    n = Sizemax;
    std::cout << "Requested length exceeds maximum capacity"  << std::endl;
  }
/*If n is greater than size and capacity, 
 * tab is replaced by an array of size n */
  if(n > size_){
    char* tab2 = new char[n+1];
    for(int i = 0 ; i < size_ ; i++){
      tab2[i] = tab[i];
    }
    delete[] tab;
    for(int i = size_ ; i < n ; i++){
      tab2[i] = c;
    }
    tab2[n] = '\0';
    size_ = n;
    capacity_ = n;
    tab = tab2;    
  }
  else{               
 /*If n is smaller than the current string length, 
the current value is shortened to its first n character, 
removing the characters beyond the nth*/
    tab[n] = '\0'; 
    size_ = n;
  }
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

/string& string::operator= (const char* s){
	
  if(tab != nullptr){
    delete [] tab;
  }
  size_ = string(s).length();
  if(size_ > 0){
    tab = new char [size_ + 1];
    for (int i = 0 ; i<=size_+1 ; i++){
      tab[i] = s[i];
    }
  }
  else{
    tab = nullptr;
  }
  return *this;
}


