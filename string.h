#include <cstddef>
#include <iostream>

class string{

	public : //public methods

// Constructors
  
  string ();
  string(const string& str);
  string (const char* s);
	
//Getters

  inline int size (void) const; 
  inline char* c_str (void) const;
  inline int max_size(void) const;
  inline int length(void) const;


//Destructor

  ~string();


//Setters

	

//Operators

	friend string operator+ (const string& A, char B);
	string& operator= (const string& A);
	string& operator= (char c);
  string& operator= (const char* s);

  
//Public Methods

  void clear (void);
  void resize(int n,char c);
  void resize(int n);
  bool empty(void) const;

  protected :  //Protected Methods

//Attributes
 

  int size_; // length of the String
  char* tab; // tab of char (represents the string)
  int capacity_; // tab size (room currently allocated)
  static const int Sizemax = 100; //maximum possible tab room

};


//Getters' definitions


inline int string::size () const {
  return size_;
}

inline int string::length() const{
  return size_;  
}

inline char* string::c_str () const {
	return tab;
}

inline int string::max_size() const{
  return Sizemax;
}



//Setters' definitions


