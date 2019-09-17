#include "kaastring.h"
using namespace std;

KAAString ksglob;
int intKAAString = 0;
char* temp;

KAAString::KAAString(int sze)
{
	value=new char[size=sze];
	value=(char*)"";
}

char* KAAString::getValue()
{return value;}

int KAAString::getSize()
{return size;}

KAAString::KAAString(KAAString& kaaarg)
{	
	value=new char[size=kaaarg.getSize()];
	char* tmp=kaaarg.getValue();
	strcpy(value,tmp);
}

KAAString::KAAString(const char* cstr)
{
	if(!cstr)
	{
		size=0;
		value=(char*)"";
	}
	else
	{
		size=strlen(cstr);
		value=new char[size+1];
		strcpy(value,cstr);
	}
}

KAAString::KAAString(char c)
{
	value=new char[2];
	size=1;
	value[0]=c;
}

KAAString& KAAString::operator=(KAAString& s)
{
	value=new char[size=s.getSize()];
	char* svalue=s.getValue();
	strcpy(value,svalue);
	return *this;
}

KAAString& KAAString::operator=(char c)
{
	delete[] value;
	value=new char[2];
	size=1;
	value[0]=c;
	return *this;
}

KAAString& KAAString::operator=(const char* cstr)
{
	if(!cstr)
	{
		size=0;
		delete[] value;
		value=0;
	}
	else
	{
		size=strlen(cstr);
		delete[] value;
		value=new char[size+1];
		strcpy(value,cstr);
	}
	return *this;
}

KAAString& operator+(KAAString& s,const char* cstr)
{
	
	
	ksglob.size=s.size+strlen(cstr);
	ksglob.value=new char[ksglob.size+1];
	
	strcpy(ksglob.value,s.value);
	strcat(ksglob.value,cstr);	
	return ksglob;
}

KAAString& operator+(KAAString& s1,KAAString& s2)
{
	ksglob.size=s1.size+s2.size;
	ksglob.value=new char[ksglob.size+1];	
	strcpy(ksglob.value,s1.value);
	strcat(ksglob.value,s2.value);	
	return ksglob;
}

KAAString& operator+(KAAString& s,char c)
{
	ksglob.size=s.size+1;
	ksglob.value=new char[ksglob.size+1];	
	strcpy(ksglob.value,s.value);	
	ksglob.value[ksglob.size-1]=c;
	ksglob.value[ksglob.size] = '\0';
	return ksglob;
}

KAAString& KAAString::operator+=(char c)
{
    char* tmpBuf = new char[size+1];
    strcpy(tmpBuf,value);
    tmpBuf[size] = c;
    tmpBuf[size+1] = '\0';
    size++;
    value = new char [size];
    strcpy(value,tmpBuf);
}

KAAString& KAAString::operator+=(KAAString& s)
{
    strcat(value,s.value);
    size+=s.size;
}

KAAString& KAAString::operator+=(char* cstr)
{
    strcat(value,cstr);
    size+=strlen(cstr);
}

ostream& operator<<(ostream& stream,KAAString& s)
{
	stream << s.value;
	return stream;
}

istream& operator>>(istream& stream,KAAString& s)
{
	delete[] s.value;	
	s.value=new char[256];
	stream.getline(s.value,256);
	s.size=strlen(s.value);
	return stream;
} 

bool KAAString::operator==(KAAString& s)
{
    if(!strcmp(value,s.value))
        return true;
    else 
        return false;
}

bool KAAString::operator!=(KAAString& s)
{
    if(!strcmp(value,s.value))
        return false;
    else 
        return true;
}

bool KAAString::operator>(KAAString& s)
{
    if(size>s.size)
    {
        return true;
    }
    else 
        return false;
}

bool KAAString::operator<(KAAString& s)
{
    if(size<s.size)
    {
        return true;
    }
    else 
        return false;
}

bool KAAString::operator>=(KAAString& s)
{
    if(size>=s.size)
    {
        return true;
    }
    else 
        return false;
}

bool KAAString::operator<=(KAAString& s)
{
    if(size<=s.size)
    {
        return true;
    }
    else 
        return false;
}

char KAAString::operator[](int index)
{
    return value[index];
}

int KAAString::toInt()
{
    intKAAString = 0;
    for(int i=0;i<size;i++)
    {
        if((value[i]<0x30) || (value[i] > 0x39))
            return false;
    }
    int mul = 1;
    int n = 0;
    int num = 0;
    for(int i=size;i>0;i--)
    {
        n=0;
        mul = 1;
        while(n!=i-1)
        {
            mul*=10;
            n++;
        }
        num = value[size-i] - 0x30;
        intKAAString+=mul*(num);
    }
    return(intKAAString);  
}

double KAAString::toDouble()
{
    int i = 0;
    int div = 0;
    int dr = 0;
    char ch;
    char* chs = new char[size];
    char* chd = new char[size];
    strcpy(chs,"");
    strcpy(chd,"");
    while((value[i]!='.') && (i != size+1))
    {
        ch = value[i];
        chs[i] = ch;
        i++;
    }
    chs[i]='\0';
    int k = 0;
    i++;
    while(i!=size+1)
    {
        ch = value[i];
        chd[k] = ch;
        k++;
        i++;
    }
    chd[k]='\0';
    KAAString st(chs);
    div = st.toInt();
    KAAString stds(chd);
    dr = stds.toInt();
    int n = 0,mul = 1;
    while(n!=strlen(chd))
        {
            mul*=10;
            n++;
        }
    double muld = mul;
    double d = dr/muld;
    d+=div;
    return d;
}

void KAAString::allocateExtraSpace(int nChars)
{
    delete[] value;
    value = new char[nChars];
    size = 0;
    nAllocated = nChars;
}

int KAAString::find(const char* pattern)
{
    if((!pattern))
        return -1;
    else
        if(!strlen(pattern))
            return -1;
        else
            if(strlen(pattern)>size)
                return -1;
    char* iterst = new char[strlen(pattern)];
    for(int i = 0;i<=(size-strlen(pattern));i++)
    {
        int iit = i;
        for(int k = 0;k<strlen(pattern);k++)
        {
            iterst[k]=value[iit];
            iit++;
        }
        iterst[iit]='\0';
        if(!strcmp(iterst,pattern))
            return i;
    }
    return -1;
}

int KAAString::find(KAAString& s)
{
    return find(s.value);
}

int KAAString::find(char c)
{
    if((!c))
        return -1;
    for(int i = 0;i<=size;i++)
    {
        if(value[i] == c)
            return i;
    }
    return -1;
}

bool KAAString::contains(const char* pattern)
{
    int ind = find(pattern);
    if (ind == -1)
        return false;
    else
        return true;
}

bool KAAString::contains(KAAString& s)
{
    
    if (find(s) == -1)
        return false;
    else
        return true;
}

bool KAAString::contains(char c)
{
    if (find(c) == -1)
        return false;
    else
        return true;
}

bool KAAString::erase(const char* pattern)
{
    int i = 0;
    if(!pattern)
        return false;
    else
        if(!strlen(pattern))
            return false;
        else
            if(strlen(pattern)>size)
                return false;    
    int ind = find(pattern);
    if(ind == -1)
        return false;
    temp = new char[size - strlen(pattern)];
    for(i = 0;i<ind;i++)
    {
        temp[i] = value[i];
    }
    ind += strlen(pattern);
    if(!(ind>=size))
    {
        for(int k = ind;k<size;k++,i++)
        {
            temp[i] = value[k];
        }
    }
    temp[i] = '\0';
    delete[] value;
    value = new char[strlen(temp)+1];
    size = strlen(temp);
    strcpy(value,temp);
    return true;
}

bool KAAString::erase(KAAString& s)
{
    int i = 0;
    if(!s.value)
        return false;
    else
        if(!strlen(s.value))
            return false;
        else
            if(strlen(s.value)>size)
                return false;    
    int ind = find(s.value);
    if(ind == -1)
        return false;
    char* erased = new char[size - strlen(s.value)];
    for(i = 0;i<ind;i++)
    {
        erased[i] = value[i];
    }
    ind += strlen(s.value);
    int k = 0;
    if(!(ind>=size))
    {
        for(k = ind;k<size;k++)
        {
            erased[i] = value[k];
            i++;
        }
    }
    erased[i] = '\0';
    delete[] value;
    value = new char[strlen(erased)+1];
    size = strlen(erased);
    strcpy(value,erased);
    return true;
}

KAAString& KAAString::substring(int iBegin, int iEnd)
{
    if(iBegin>=iEnd||iBegin<0||iEnd<0)
    {
        ksglob.value = new char[1];
        ksglob.value[0] = '\0';
        ksglob.size = 0;
        return ksglob;
    }
    int iNewlen = iEnd - iBegin + 1;
    ksglob.value = new char[iNewlen];
    int k = 0;
    for(int i = iBegin;i<=iEnd;i++)
    {
        ksglob.value[k] = value[i];
        k++;
    }
    ksglob.value[k] = '\0';
    return ksglob;
}

bool KAAString::getExtraLine(istream& stream)
{
    if(nAllocated)
    {
        delete[] value;	
	value=new char[nAllocated];
	stream.getline(value,nAllocated);
	size=strlen(value);
        return true;
    }
    return false;
}