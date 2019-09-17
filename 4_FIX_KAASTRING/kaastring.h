#ifndef _KAA_STRING_H_
#define _KAA_STRING_H_
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
class KAAString
{
 public:
	KAAString(int sze);
	KAAString(KAAString& s);
	KAAString(const char* cstr = 0);
	KAAString(char c);
	KAAString& operator=(KAAString& s);
	KAAString& operator=(const char* cstr);
	KAAString& operator=(char c);
	friend KAAString& operator+(KAAString& s,const char* cstr);
	friend KAAString& operator+(KAAString& s1,KAAString& s2);
	friend KAAString& operator+(KAAString& s1,char c);
        KAAString& operator+=(char c);
        KAAString& operator+=(KAAString& s);
        KAAString& operator+=(char* cstr);
        bool operator==(KAAString& s);
        bool operator!=(KAAString& s);
        bool operator>(KAAString& s);
        bool operator>=(KAAString& s);
        bool operator<=(KAAString& s);
        bool operator<(KAAString& s);
        char operator[](int index);
	char* getValue();
	int getSize();
	friend ostream& operator<<(ostream& stream,KAAString& s);
	friend istream& operator>>(istream& stream,KAAString& s);
        void allocateExtraSpace(int nChars);
        bool getExtraLine(istream& stream);
        int toInt();
        double toDouble();
        int find(const char* pattern);
        int find(KAAString& s);
        int find(char c);
        bool contains(const char* pattern);
        bool contains(KAAString& s);
        bool contains(char c);
        bool erase(const char* pattern);
        bool erase(KAAString& s);
        KAAString& substring(int iBegin, int iEnd);
 protected:
	char* value;
	int size;
        int nAllocated;
};

#endif