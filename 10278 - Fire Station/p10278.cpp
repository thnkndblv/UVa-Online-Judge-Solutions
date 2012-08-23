#include <stdio.h>
#include <vector>
#include <utility>
#include <memory.h>
#include <deque>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define forit(i, a) for ( __typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )

typedef pair<int,int> ii;

char str[ 100 ];
vector< ii > g[ 505 ];
int fireStation[ 105 ];

int dist[ 505 ];
void dijkstra(int s)
{
    memset( dist, -1, sizeof dist );
    dist[ s ] = 0;
    priority_queue< ii, deque<ii>, greater<ii> > pq;
    pq.push( mp( dist[s], s ) );
    while ( !pq.empty() )
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if ( d != dist[u] ) continue;
        forit(it, g[u])
        {
            int xd = it->first;
            int v = it->second;
            if ( dist[v]==-1 || dist[u]+xd < dist[v] )
            {
                dist[ v ] = dist[u] + xd;
                pq.push( mp( dist[v], v ) );
            }
        }
    }
}

int main()
{
    int test;
    int f, n;
    int u, v, w;
    
    scanf("%d",&test);
    while ( test-- )
    {
        scanf("%d %d",&f,&n); gets( str );
        n++;
        for (int i=0; i<n; i++) g[i].clear();
        for (int i=0; i<f; i++)
        {
            sscanf(gets(str),"%d\n",&fireStation[i]);
            g[0].push_back( mp( 0, fireStation[i] ) );
        }
        while ( gets(str) )
        {
            if ( sscanf(str,"%d %d %d",&u,&v,&w) != 3 ) break;
            g[ u ].pb( mp( w, v ) );
            g[ v ].pb( mp( w, u ) );
        }
        
        int best = INT_MAX;
        int ans = 1;
        for (int i=1; i<n; i++)
        {
            g[0].pb( mp( 0, i ) );
            dijkstra( 0 );
            int x = *max_element( dist, dist+n );
            if ( x < best )
            {
                best = x;
                ans = i;
            }
            g[0].pop_back();
        }
        printf("%d\n",ans);
        if ( test ) puts("");
    }
    
    return 0;
}
