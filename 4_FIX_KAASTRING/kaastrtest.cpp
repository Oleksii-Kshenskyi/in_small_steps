#include "kaastring.h"
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    KAAString s("I can't feel @#$ my legs!");
    KAAString a("@#$ ");
    s.erase(a);
    cout << s << endl;    
}