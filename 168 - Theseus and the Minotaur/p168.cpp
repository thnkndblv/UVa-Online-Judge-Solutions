#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <vector>

using namespace std;

#define forit(i, a) for ( __typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )
#define pb push_back

vector< int > g[ 26 ];
int seen[ 26 ];

int main()
{
    string line;
    string x, y;
    char M, T;
    int k;
    
    while ( getline( cin, line ), line != "#" )
    {
        for (int i=0; i<26; i++) g[i].clear();
        memset( seen, 0, sizeof seen );
        istringstream in( line );
        getline( in, x, '.' );
        in >> M >> T >> k;
        in.clear();
        in.str( x + ';' );
        while ( getline( in, y, ';' ) )
        {
            int u = y[0] - 'A';
            for (int i=2; i<y.length(); i++)
            {
                int v = y[i] - 'A';
                g[u].pb( v );
            }
        }
        M -= 'A';
        T -= 'A';
        int cnt = 0;
        while ( !seen[ M ] )
        {
            seen[ T ]++;
            bool ok = false;
            forit(it, g[M])
            {
                int i = *it;
                if ( !seen[ i ] )
                {
                    seen[ T ]--;
                    T = M;
                    cnt++;
                    if ( cnt % k == 0 )
                    {
                        printf("%c ",T+'A');
                        seen[ T ]++;
                    }
                    M = i;
                    ok = true;
                    break;
                }
            }
            if ( !ok ) break;
        }
        printf("/%c\n",(char)(M+'A'));
    }
    
    return 0;
}