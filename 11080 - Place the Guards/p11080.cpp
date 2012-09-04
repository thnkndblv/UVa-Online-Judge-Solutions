#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <queue>

using namespace std;

int N, M;
bool g[ 202 ][ 202 ];
int color[ 202 ];
int xd[ 2 ];

bool bfs(int s)
{
    bool ok = true;
    queue<int> q;
    q.push( s );
    color[ s ] = 0;
    xd[ 0 ] = xd[ 1 ] = 0;
    while ( !q.empty() )
    {
        int v = q.front(); q.pop();
        xd[ color[ v ] ]++;
        for (int i=0; i<N; i++)
        {
            if ( g[v][i] )
            {
                if ( color[ i ] == -1 )
                {
                    color[ i ] = color[ v ] ? 0 : 1;
                    q.push( i );
                }
                else if ( color[ i ] == color[ v ] ) ok = false;
            }
        }
    }
    return ok;
}

int main()
{
    int test;
    int u, v;
    
    scanf("%d",&test);
    while ( test-- )
    {
        scanf("%d %d",&N,&M);
        memset( g, 0, sizeof g );
        for (int i=0; i<M; i++)
        {
            scanf("%d %d",&u,&v);
            g[u][v] = g[v][u] = true;
        }
        
        memset( color, -1, sizeof color );
        bool ok = true;
        int ans = 0;
        for (int i=0; i<N; i++)
        {
            if ( color[i] == -1 )
            {
                if ( bfs( i ) )
                {
                    ans += max(min( xd[0], xd[1] ), 1);
                }
                else ok = false;
            }
        }
        if ( ok ) printf("%d\n",ans);
        else puts("-1");
    }
    
    return 0;
}
