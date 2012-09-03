#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector< string > str;

bool g[ 26 ][ 26 ];
bool f[26];

void buildG(int a, int b, int k)
{
    for (; a <= b && k >= str[a].size(); a++);
    if ( a >= b ) return;
    int i = a;
    int j = a;
    for (; j<=b; j++)
    {
        if ( str[i][k] != str[j][k] )
        {
            g[ str[i][k]-'A' ][ str[j][k]-'A' ] = true;
            f[ str[i][k]-'A' ] = true;
            f[ str[j][k]-'A' ] = true;
            buildG( i, j-1, k+1 );
            i = j;
        }
    }
    buildG( i, j-1, k+1 );
}

int main()
{
    string wd;
    
    while ( cin >> wd, wd != "#" )
    {
        str.push_back( wd );
    }
    
    buildG( 0, str.size() - 1, 0 );
    
    int cnt = count( f, f+26, true );
    
    stack< char > ans;
    while ( cnt )
    {
        for (int i=0; i<26; i++)
        {
            if ( f[i] && count( g[i], g[i]+26, true ) == 0 )
            {
                ans.push( 'A' + i );
                f[i] = false;
                cnt--;
                for (int j=0; j<26; j++) g[j][i] = false;
            }
        }
    }
    while ( !ans.empty() )
    {
        printf("%c",ans.top());
        ans.pop();
    }
    puts("");
    
    return 0;
}
