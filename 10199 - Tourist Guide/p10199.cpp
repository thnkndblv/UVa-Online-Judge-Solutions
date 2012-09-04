#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <memory.h>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int N, M;
vector< string > name;
map< string, int > id;
int g[ 102 ][ 102 ];

set< string > artPoints;
int dfsNum[ 102 ], num;
int dfs(int u, int p)
{
    int leastAncestor = dfsNum[ u ] = num++;
    
    for (int v=0; v<N; v++) if ( g[u][v] && v != p )
    {
        if ( dfsNum[ v ] == 0 )
        {
            int rec = dfs( v, u );
            if ( dfsNum[u]==1 && dfsNum[v]>2 ) artPoints.insert( name[ u ] );
            if ( dfsNum[u]!=1 && rec >= dfsNum[u] ) artPoints.insert( name[ u ] );
            leastAncestor = min( leastAncestor, rec );
        }
        else
        {
            leastAncestor = min( leastAncestor, dfsNum[v] );
        }
    }
    
    return leastAncestor;
}

int main()
{
    string s, t;
    int u, v;
    int cs = 0;
    
    while ( scanf("%d",&N), N )
    {
        // Graph Construction
        id.clear();
        name.clear();
        for (int i=0; i<N; i++)
        {
            cin >> s;
            id[ s ] = name.size();
            name.push_back( s );
        }
        
        scanf("%d",&M);
        memset( g, 0, sizeof g );
        for (int i=0; i<M; i++)
        {
            cin >> s >> t;
            u = id[s];
            v = id[t];
            g[u][v] = g[v][u] = true;
        }
        
        artPoints.clear();
        memset( dfsNum, 0, sizeof dfsNum );
        for (int i=0; i<N; i++)
            if ( dfsNum[i] == 0 )
            {
                num = 1;
                dfs( i, -1 );
            }
        
        if ( cs++ ) puts(""); // Line between test cases
        
        printf("City map #%d: %d camera(s) found\n",cs,(int)artPoints.size());
        for ( set<string>::iterator it = artPoints.begin(); it != artPoints.end(); it++ )
            printf("%s\n",it->c_str());
    }
    
    return 0;
}
