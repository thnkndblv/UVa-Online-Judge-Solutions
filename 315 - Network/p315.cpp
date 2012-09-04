#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <memory.h>
#include <algorithm>
#include <set>

using namespace std;

int N;
bool g[ 102 ][ 102 ];

set< int > artPoint;
int dfsNum[ 102 ], num; // "num" must be 1 at the begin
int dfs(int u, int p)
{
    int leastAncestor = dfsNum[ u ] = num++;
    for (int v=1; v<=N; v++) if ( g[u][v] && v != p )
    {
        if ( dfsNum[v] == 0 )
        {
            int rec = dfs( v, u );
            if ( dfsNum[u]==1 && dfsNum[v]>2 ) artPoint.insert( u );
            if ( dfsNum[u]!=1 && rec >= dfsNum[u] ) artPoint.insert( u );
            leastAncestor = min( leastAncestor, rec );
        }
        else
        {
            leastAncestor = min( leastAncestor, dfsNum[ v ] );
        }
    }
    return leastAncestor;
}

int main()
{
    string line;
    int u, v;
    
    while ( scanf("%d\n",&N), N )
    {
        memset( g, 0, sizeof g );
        while ( getline(cin, line) )
        {
            istringstream in( line );
            in >> u;
            if ( u == 0 ) break;
            while ( in >> v )
            {
                g[u][v] = g[v][u] = true;
            }
        }
        
        artPoint.clear();
        num = 1;
        memset( dfsNum, 0, sizeof dfsNum );
        for (int i=1; i<=N; i++)
        {
            if ( dfsNum[i] == 0 ) dfs( i, -1 );
        }
        printf("%d\n",(int)artPoint.size());
    }
    
    return 0;
}
