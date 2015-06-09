#ifndef STRING_CLASS
#define STRING_CLASS

#define TMP_STRING_SIZE	4096
#include <assert.h>


#include <string.h>
class String_Class
{
	//Atributs
private:

	char* word;
	unsigned int size;

public:

	//Constructors

	//Default Constructor
	String_Class(){ Alloc(1); word[0] = '\0'; }

	//Constructor copy char
	String_Class(const char *_string)
	{
		size = strlen(_string) + 1;
		word = new char[size];
		strcpy_s(word, size, _string);
	}
    
	//Constructor copy string
	String_Class(const String_Class& string)
	{
		Alloc(string.size);
		strcpy_s(word, size, string.word);
	}

	//Destructor
	~String_Class()
	{
		delete[]word;
	}

	//Operators
	
	//==
	bool operator == (const char* _string)const
	{
		return strcmp(_string, word) == 0;
	}

	bool operator == (const String_Class& _string)const
	{
		return strcmp(_string.word, word) == 0;
	}

	bool operator != (const char* _string)const
	{
		return strcmp(_string, word) != 0;
	}

	bool operator != (const String_Class& _string)const
	{
		return strcmp(_string.word, word) != 0;
	}

	const String_Class& operator =(const char* _string)
	{
		if (_string != NULL)
		{
			if (strlen(_string) + 1 > size)
			{
				delete[] word;
				Alloc(strlen(_string) + 1);
			}

			Clear();

			strcpy_s(word, size, _string);
		}

		else
		{
			word[0] = '\0';
			strcpy_s(word, size, _string);
		}
			return(*this);
		
	}
	
	const String_Class& operator =(const String_Class& _string)
	{
		if (_string.size > size)
		{
			delete[] word;
			Alloc(_string.size);
		}

		Clear();

		strcpy_s(word, size, _string.word);

		return(*this);
	}

	const String_Class& operator +=(const char* _string)
	{
		if (_string != NULL)
		{
			unsigned int length = strlen(_string) + Length() + 1;
			if (length > size)
			{
				char* tmp = word;
				Alloc(length);
				strcpy_s(word, size, tmp);
				delete tmp;
			}

			strcat_s(word, size, _string);

			return(*this);
		}
	}

	const String_Class& operator +=(const String_Class& _string)
	{
		
			unsigned int length = _string.size + Length();
			if (length > size)
			{
				char* tmp = word;
				Alloc(length);
				strcpy_s(word, size, tmp);
				delete tmp;
			}

			strcat_s(word, size, _string.word);

			return(*this);
    }
	
	//Prefix
	/*const String_Class& prefix(const char* _string)
	{

		unsigned int memory = strlen(_string) + Length() + 1;

		if (_string != NULL)
		{
			if (memory > size)
			{
				char* tmp = word;
				Alloc(memory);
				strcpy_s(word, size, _string);
				strcat_s(word, size, tmp);
				delete[] tmp;
			}
		}
		
		
		return(*this);

	}

	const String_Class& prefix(const String_Class& _string)
	{

		unsigned int memory = _string.size + Length();

		if (memory > size)
		{
			char* tmp = word;
			Alloc(memory);
			strcpy_s(word, size, _string.word);
			strcat_s(word, size, tmp);
			delete[] tmp;
		}
		
		return(*this);

	}*/



	const String_Class& Prefix(const char* _string_c)
	{

		char tmp[TMP_STRING_SIZE];
		strcpy_s(tmp, TMP_STRING_SIZE, _string_c);
		strcat_s(tmp, TMP_STRING_SIZE, word);
        
		unsigned int need_memory = strlen(tmp) + 1;
		if (need_memory > size)
		{
			delete[] word;
			Alloc(need_memory);
		}
		strcpy_s(word, size, tmp);

		return(*this);
	}

	const String_Class& Prefix(const String_Class& _string_c)
	{
	    
		char tmp[TMP_STRING_SIZE];
		strcpy_s(tmp, TMP_STRING_SIZE, _string_c.word);
		strcat_s(tmp, TMP_STRING_SIZE, word);

		unsigned int need_memory = strlen(tmp) + 1;
		if (need_memory > size)
		{
			delete[] word;
			Alloc(need_memory);
		}
		strcpy_s(word, size, tmp);

		return(*this);
	}

	//SWAP
	void SWAP(String_Class& a)
	{
		char* tmp = a.word;
		a.word = word;
		word = tmp;
	}

	void SWAP_C(char* a, char* b)
	{
		char* tmp = a;
		a = b;
		b = tmp;
	}


	//Trim
	void Trim()
	{
		int pos = 0;
		unsigned int start = 0;
		unsigned int end = Length() - 1;

		while (word[end] == ' ')
		{
			end--;
		}


		while (word[start] == ' ')
		{
			start++;
		}

		for (unsigned int i = 0, j = start; i <= end; i++, j++)
			word[i] = word[j];

		word[end - start + 1 ] = '\0';
	  	
	}
	
	//Find word in string
	unsigned int Find(const char* _string)//It is correct
	{
		unsigned int num_word = 0;

		if (_string == NULL)
		{
			return NULL;
		}

		else
		{
			int len = strlen(_string);
			for (unsigned int i = 0; i < Length(); i++)
			{
				if (word[i] == _string[0])
				{
					if (strncmp(_string, &word[i], len) == 0)
					{
						num_word++;
					}
				}

			}
		}

		return (num_word);

	}

	//Other methods
	void Clear()
	{
		word[0] = '\0';
	}

	unsigned int Length()const
	{
		return strlen(word);
	}

	unsigned int GetCapacity()const
	{
		return size;
	}

	char* GetString()const{ return word; }

private:

	void Alloc(unsigned int memory)
	{
		size = memory;
		word = new char[size];
	}

};
#endif