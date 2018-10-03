#ifndef string_h
#define string_h
#include <assert.h>
//Alexandru Cercel Mihai
class String {
private:
	unsigned int length = 0u;
	char *string = nullptr;


	void Allocate(unsigned int size) 
	{
		length = size;
		string = new char[length];
	}

	void Copy(const char* string)
	{
		for (int i = 0; i < length; ++i)this->string[i] = string[i];
	}

public:


	~String()
	{

		if (string != nullptr) 
		{	
		delete[] string;
		string = nullptr;
		Allocate(0);

		}
	}

	String()
	{
		Allocate(10);
	}
	String(const char* string)
	{
		assert(string);
		if (string != nullptr) {
			Allocate(CalLength(string));
			Copy(string);
		}
		else {
			Allocate(10);
		}
	}
	String(const String& string)
	{
		
		if (string.GetString() != nullptr)
		{
			Allocate(string.length);
			Copy(string.string);
		}
		else
		{
			Allocate(1);
		}
	}

public:
	
	//Methods
	char* GetString() const
	{
		return string;
	}
	int CalLength(const char* string) const
	{
		int string_length;
		for (string_length = 0; string[string_length] != '\0'; ++string_length);
		string_length++;
		return string_length;
	}
	//

	//Operators
	String& operator=(const char* string) 
	{
		Allocate(CalLength(string) + 1);
		Copy(string);
		return *this;
	}
	String& operator =(const String& string) 
	{
		Allocate(CalLength(string.GetString()));
		Copy(string.GetString());
		return *this;
	}


	
};
#endif // !1
