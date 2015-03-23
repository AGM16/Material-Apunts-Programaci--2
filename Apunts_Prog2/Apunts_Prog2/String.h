#ifndef STRING
#define STRING
#include <stdio.h>

class String
{
private:
	
	char* ch_word;
	unsigned int in_size;
	void Alloc(unsigned int new_memory);

public:
	//----------------------------
	//Constructors
	//----------------------------
	String();
	//String(const char* c);
	String(const char* format, ...);
	String(const String& c);

	~String(){
		if (ch_word != NULL){
			delete[] ch_word;
		}
	
	};

	//----------------------------
	//Operators
	//----------------------------

	bool operator == (const char* c)const;
	bool operator != (const char* c)const;

	bool operator ==(const String& c)const;
	bool operator !=(const String& c)const;

	const String& operator = (const char* c);

	const String& operator = (const String& c);

	const String& operator += (const char* c);

	const String& operator += (const String& c);


	//----------------------------
	//Others methods
	//----------------------------

	unsigned int Length()const;

	unsigned int Capacity()const;

	void Clear();

	const char* getString()const{
		return ch_word;
	}

};

#endif