#ifndef _MYSTRING
#define _MYSTRING

class MyString { 
	char* buffer; 
	int length;
public: 
	MyString():length(0)
	{

	}
	void setbuffer(char* s) { buffer = s; length = strlen(s); } 
	char& operator[ ] (const int index) { return buffer[index]; }
	int size( ) { return length; }
}; 

#endif