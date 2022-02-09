#pragma once

#include<iostream>
#include<assert.h>

using namespace std;

namespace zwr
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		/////
		//迭代器
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		const_iterator begin() const 
		{
			return _str;
		}
		const_iterator end() const
		{
			return _str + _size;
		}
        /////
		//构造函数
		string(const char* str = "\0")
			:_size(strlen(str))
			,_capacity(_size)   //capacity不包括'\0'
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		/////
		//拷贝构造（传统写法）
		string(const string& s)
			:_size(s._size)
			,_capacity(_size)
		{
			_str = new char[strlen(s._str) + 1];
			strcpy(_str, s._str);
		}
		/////
		//opertator=（传统写法）
		string& operator=(const char* str)
		{
			delete[] _str;
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
			_size = strlen(str);
			_capacity = _size;
			return *this;
		}
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
				_size = s._size;
				_capacity = _size;
			}
			return *this;
		}
		/////
		//print
		char* print()
		{
			return _str;
		}
		//size
		size_t size()
		{
			return _size;
		}
		//capacity
		size_t capacity()
		{
			return _capacity;
		}
		//swap
		void swap(string s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}
		//operator[]
		char& operator[](int pos)
		{
			assert(pos <= _size);
			return _str[pos];
		}
		//const operator[]
		const char& operator[](int pos) const 
		{
			assert(pos <= _size);
			return _str[pos];
		}
		/////
		//reserve
		void reserve(size_t new_capacity)
		{
			if (new_capacity > _capacity)
			{
				char* tmp = new char[new_capacity + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
				_capacity = new_capacity;
			}
		}
		//resize
		void resize(size_t new_size, char ch = '\0')
		{
			if (new_size < _size)
			{
				_str[new_size] = '\0';
				_size = new_size;
			}
			else
			{
				if (new_size > _capacity)
				{
					reserve(new_size);
				}
				while (_size != new_size)
				{
					_str[_size++] = ch;
				}
				_str[_size] = '\0';
			}
		}
		//push_back
		void push_back(char ch)
		{
			if (_size == _capacity)
			{
				int new_capacity = (_capacity == 0 ? 4 : 2 * _capacity);
				reserve(new_capacity);
			}
			_str[_size++] = ch;
			_str[_size] = '\0';
		}

		//append
		void append(const char* str)
		{
			int new_size = _size + strlen(str);
			if (new_size > _capacity)
			{
				reserve(new_size);
			}
			strcpy(_str + _size, str);
			_size = new_size;
		}
		//operator+=
		string& operator+=(const string& s)
		{
			append(s._str);
			return *this;
		}
		string& operator+=(const char* s)
		{
			append(s);
			return* this;
		}
		string& operator+=(char ch)
		{
			push_back(ch);
		}
		/////
		//insert
		string& insert(size_t pos, const char ch)
		{
			if (_size == _capacity)
			{
				int new_capacity = (_capacity == 0 ? 4 : 2 * _capacity);
				reserve(new_capacity);
			}
			size_t end = _size + 1;
			while (end >= pos + 1)
			{
				_str[end] = _str[end - 1];
				end--;
			}
			_str[end] = ch;
			_size++;
			return *this;
		}
		string& insert(size_t pos, const char* str)
		{
			int len = strlen(str);
			if (len == 0)
			{
				return *this;
			}
			if (len + _size > _capacity)
			{
				reserve(len + _size);
			}
			size_t end = _size + len;
			while (end >= pos + len)
			{
				_str[end] = _str[end - len];
				end--;
			}
			for (size_t i = 0; i < end; i++)
			{
				_str[pos + i] = str[i];
			}
			_size += len;
			return* this;
		}
		string& insert(size_t pos, const string& s)
		{
			insert(pos, s._str);
		}
		//erase
		string& erase(size_t pos = 0, size_t len = npos)
		{
			assert(pos >= 0);
			if (len == npos || len+pos > _size)
			{
				_str[pos] = '\0';
				return *this;
			}
			else
			{

			}
		}
		//c_str
		char* c_str()
		{
			return _str;
		}
		//clear
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
		//析构函数
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}


	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos = -1;
	};

	//operator +
	//operator <<
	//operator >>
	//getline
	//operator>
	//operator==
	//operator<
	//opertator>=
	//operator<=
	//operator!=
	void StringTest1()
	{
		string s1("hello world");
		cout << s1.print() << endl;
		string s2(s1);
		cout << s2.print() << endl;
		string s3 = "hello";
		cout << s3.print() << endl;
		s3 = s1;
		cout << s3.print() << endl;
	}

	class Data
	{
	public:
		Data(int year, int month, int day)
			:_year(year)
			,_month(month)
			,_day(day)
		{}
		
	private:
		int _year;
		int _month;
		int _day;
		static const int npos = -1;
	};
	const int Data::npos = -1;

	void StaticTest()
	{
		Data a1(1,1,1);
		//cout << 
	}
}
