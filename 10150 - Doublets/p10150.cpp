#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory.h>
#include <queue>

using namespace std;

vector<string> dict;
map<string,int> pos;
int next[ 25200 ];
int main()
{
    string wd;
    while ( getline( cin, wd ), wd != "" )
    {
        pos[ wd ] = dict.size();
        dict.push_back( wd );
    }
    
    int f = 0;
    string s, t;
    while ( cin >> s >> t )
    {
        if ( f++ ) puts("");
        if ( pos.find( s ) == pos.end() )
        {
            puts("No solution.");
            continue;
        }
        if ( pos.find( t ) == pos.end() )
        {
            puts("No solution.");
            continue;
        }
        memset( next, -1, sizeof next );
        int ids = pos[ s ];
        int idt = pos[ t ];
        next[ idt ] = -2;
        queue< int > q;
        q.push( idt );
        while ( !q.empty() )
        {
            int u = q.front(); q.pop();
            string s = dict[ u ];
            for (int i=0; i<s.length(); i++)
                for (int c='a'; c<='z'; c++)
                {
                    string t = s;
                    t[ i ] = c;
                    if ( pos.find( t ) != pos.end() )
                    {
                        int v = pos[ t ];
                        if ( next[ v ] == -1 )
                        {
                            next[ v ] = u;
                            q.push( v );
                        }
                    }
                }
        }
        if ( next[ids] == -1 ) puts("No solution.");
        else
        {
            for (int i=ids; i!=-2; i=next[i]) cout << dict[ i ] << endl;
        }
    }
    
    return 0;
}