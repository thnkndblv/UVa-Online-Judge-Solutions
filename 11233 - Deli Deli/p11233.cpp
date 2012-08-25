#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string,string> irr;

string v = "aeiou";
bool isVowel(char c)
{
    for (int i=0; i<v.length(); i++)
        if ( v[i] == c )
            return true;
    return false;
}

bool isConsonant(char c)
{
    return isalpha( c ) && !isVowel( c );
}

int main()
{
    int L, N;
    string a, b;
    
    cin >> L >> N;
    for (int i=0; i<L; i++)
    {
        cin >> a >> b;
        irr[ a ] = b;
    }
    
    for (int i=0; i<N; i++)
    {
        cin >> a;
        int len = a.length();
        if ( irr.find( a ) != irr.end() )
            a = irr[a];
        else if ( a[len-1]=='y' && isConsonant( a[len-2] ) ) a = a.substr(0, len-1) + "ies";
        else if ( a.substr(len-1)=="o" || a.substr(len-1)=="s" || a.substr(len-1)=="x" || a.substr(len-2)=="ch" || a.substr(len-2)=="sh" ) a += "es";
        else a += "s";
        
        cout << a << endl;
    }
    
    return 0;
}
