#include<iostream>
#ifndef STRING0_H
#define STRING0_H
using namespace std;

class my_string
{
    private:
        char* palabra;
        int tam;
    public:
        int size_t(const char* text);
        my_string(const char* str);
        my_string(const my_string & str);
        ~my_string();
        int size_str(my_string text);
        bool operator == (my_string & str);
        char & operator [](const int & i);
        my_string operator + (const my_string & str);
        my_string & operator =(const my_string & str);
        bool  operator <(const my_string & str);
        bool  operator >(const my_string & str);
        friend ostream & operator<<(ostream & os,  my_string & str)
        {
            return os<<str.palabra;
        }
        friend istream & operator>>(istream & is,  my_string & str)
        {
            return is>>str.palabra;
        }
};
#endif
