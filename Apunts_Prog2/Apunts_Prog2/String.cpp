#include "String.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>




void String::Alloc(unsigned int new_memory)
{  
	in_size = new_memory;
	ch_word = new char[in_size];

}

//------------------------------------

//Constructors

//------------------------------------

String::String()
{
	Alloc(1);
	Clear();

}

/*String::String(const char* c)
{   // Más uno por el '\0'
	Alloc(strlen(c) + 1);
	strcpy_s(ch_word, in_size , c);
}*/


String::String(const String& c)
{
	Alloc(strlen(c.ch_word) + 1);
	strcpy_s(ch_word, in_size, c.ch_word);
}


String::String(const char* format,...)
{
	in_size = 0;

	if (format != NULL)
	{
		static char tmp[100];
		static va_list  ap;

		va_start(ap, format);
		int res = vsprintf_s(tmp, 100, format, ap);
		va_end(ap);

		if (res > 0)
		{
			Alloc(res + 1);
			strcpy_s(ch_word, in_size, tmp);
		}
	}
	
	if (in_size == 0)
	{
		Alloc(1);
		Clear();
	}
}

//-------------------------------------------------------
//Operators
//-------------------------------------------------------

bool String:: operator ==(const char* c)const
{
	assert(c != NULL);
	return strcmp(ch_word, c) == 0;
}

bool String:: operator ==(const String& c)const
{
	return strcmp(ch_word, c.ch_word) == 0;
}

bool String:: operator !=(const char* c)const
{
	return strcmp(ch_word, c) != 0;
}

bool String:: operator !=(const String& c)const
{
	return strcmp(ch_word, c.ch_word) != 0;
}

const String& String:: operator=(const char* c)
{
	if (c != NULL)
	{
		if (strlen(c) + 1 > in_size)
		{
			delete[] ch_word;
			Alloc(strlen(c) + 1);
		}
		else
		{
			Clear();
		}

		strcpy_s(ch_word, in_size, c);

	}
	else
	{
		Clear();
	}
	return(*this);
}


const String& String::operator=(const String& c)
{
	if (strlen(c.ch_word) + 1 > in_size)
	{
		delete[] ch_word;
		Alloc(strlen(c.ch_word) + 1);

	}
	else
	{
		Clear();
	}

	strcpy_s(ch_word, in_size, c.ch_word);

	return (*this);
}


const String& String:: operator+=(const char* c)
{
	if (c != NULL)
	{
		unsigned int need_memory = strlen(ch_word) + strlen(c) + 1;

		if (need_memory > in_size)
		{
			char* tmp = ch_word;
			Alloc(need_memory);
			strcpy_s(ch_word, in_size, tmp);
			delete[] tmp;
		}

		strcat_s(ch_word, in_size, c);

	}

	return (*this);
}

const String& String:: operator+=(const String& c)
{
	unsigned int need_memory = strlen(ch_word) + strlen(c.ch_word) + 1;

	if (need_memory > in_size)
	{
		char* tmp = ch_word;
		Alloc(need_memory);
		strcpy_s(ch_word, in_size, tmp);
		delete[] tmp;
	}

	strcat_s(ch_word, in_size, c.ch_word);

	return (*this);

}


//----------------------------------------------------
//Others Methods
//----------------------------------------------------

unsigned int String::Length()const
{
	return strlen(ch_word);
}

unsigned int String::Capacity()const
{
	//return(sizeof(ch_word) / sizeof(char));
	return in_size;
}

void String::Clear()
{
	ch_word[0] = '\0';
}

