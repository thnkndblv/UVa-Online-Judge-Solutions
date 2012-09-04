#include <stdio.h>
#include <memory.h>
#include <queue>

using namespace std;

int N;
bool g[ 303 ][ 303 ];
int color[ 303 ];
bool bfs(int s)
{
    bool ret = true;
    queue< int > q;
    q.push( s );
    color[ s ] = 0;
    while ( !q.empty() )
    {
        int v = q.front(); q.pop();
        for (int i=1; i<=N; i++)
        {
            if ( g[v][i] )
            {
                if ( color[ i ] == -1 )
                {
                    color[ i ] = color[v] ? 0 : 1;
                    q.push( i );
                }
                else if ( color[i] == color[v] ) ret = false;
            }
        }
    }
    return ret;
}

int main()
{
    int u, v;
    
    while ( scanf("%d",&N), N )
    {
        memset( g, 0, sizeof g );
        while ( scanf("%d %d",&u,&v), u || v )
        {
            g[ u ][ v ] = g[ v ][ u ] = true;
        }
        bool ans = true;
        memset( color, -1, sizeof color );
        for (int i=1; i<=N; i++)
        {
            if ( color[ i ] == -1 )
            {
                ans = ans && bfs( i );
            }
        }
        puts( ans ? "YES" : "NO" );
    }
    
    return 0;
}
