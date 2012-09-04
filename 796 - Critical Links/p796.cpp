#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;

#define pb push_back
#define forit(i, a) for ( __typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )

int N;
vector< set< int > > g;
 
set< pair< int, int > > ans;
vector< int > color;
vector< int > dfsNum;
int num;
int dfs(int u, int p)
{
    color[ u ] = 1;
    dfsNum[ u ] = num++;
    
    int leastAncestor = num;
    forit(v, g[u]) if ( *v != p )
    {
        if ( color[ *v ] == 0 )
        {
            int rec = dfs( *v, u );
            if ( rec > dfsNum[ u ] )
            {
                //printf("%d - %d\n",u,*v);
                if ( u > *v ) ans.insert( make_pair( *v, u ) );
                else ans.insert( make_pair( u, *v ) );
            }
            leastAncestor = min( leastAncestor, rec );
        }
        else leastAncestor = min( leastAncestor, dfsNum[ *v ] );
    }
    color[u] = 2;
    return leastAncestor;
}

int main()
{
    string line;
    int u, m, v;
    
    while ( cin >> N )
    {
        cin.ignore();
        g.resize( N );
        for (int i=0; i<N; i++) g[i].clear();
        for (int i=0; i<N; i++)
        {
            getline( cin, line );
            replace( line.begin(), line.end(), '(', ' ' );
            replace( line.begin(), line.end(), ')', ' ' );
            istringstream in( line );
            in >> u;
            in >> m;
            for (int j=0; j<m; j++)
            {
                in >> v;
                g[ u ].insert( v );
                g[ v ].insert( u );
            }
        }
        
        num = 1;
        ans.clear();
        color.resize( N );
        dfsNum.resize( N );
        for (int i=0; i<N; i++) color[i] = dfsNum[i] = 0;
        for (int i=0; i<N; i++)
        {
            if ( color[i] == 0 )
                dfs( i, -1 );
        }
        
        printf("%d critical links\n",(int)ans.size());
        forit(it, ans) printf("%d - %d\n",it->first,it->second);
        puts("");
    }
    
    return 0;
}