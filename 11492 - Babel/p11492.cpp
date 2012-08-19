#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <memory.h>

using namespace std;

#define pb push_back

struct edge
{
    int node, len;
    int initial;
    edge(){}
    edge(int node, string &s):node(node),len(s.length()),initial(s[0]-'a'){}
    edge(int node, int len, int initial):node(node),len(len),initial(initial){}
    bool operator<( const edge &E ) const
    {
        return len > E.len;
    }
};

map< string,int > id;
vector< edge > g[ 4003 ];
int dist[ 4003 ][ 27 ];

int main()
{
    int M;
    string S, T;
    string u, v, w;
    
    while ( cin >> M, M )
    {
        cin >> S >> T;
        id.clear();
        for (int i=0; i<M; i++)
        {
            cin >> u >> v >> w;
            if ( id.find( u ) == id.end() )
            {
                id[ u ] = id.size() - 1;
                g[ id.size() - 1 ].clear();
            }
            if ( id.find( v ) == id.end() )
            {
                id[ v ] = id.size() - 1;
                g[ id.size() - 1 ].clear();
            }
            int idu = id[ u ];
            int idv = id[ v ];
            g[ idu ].pb( edge( idv, w ) );
            g[ idv ].pb( edge( idu, w ) );
        }
        if ( id.find( S ) == id.end() )
        {
            puts("impossivel");
            continue;
        }
        if ( id.find( T ) == id.end() )
        {
            puts("impossivel");
            continue;
        }
        int ids = id[ S ];
        int idt = id[ T ];
        memset( dist, -1, sizeof dist );
        dist[ ids ][ 26 ] = 0;
        priority_queue< edge > pq;
        pq.push( edge( ids, 0, 26 ) );
        while ( !pq.empty() )
        {
            int u = pq.top().node;
            int du = pq.top().len;
            int iu = pq.top().initial;
            pq.pop();
            if ( du != dist[u][iu] ) continue;
            //cout << u << " " << du << " " << iu << endl;
            for (int i=0; i<g[u].size(); i++)
            {
                int v = g[u][i].node;
                int dv = g[u][i].len;
                int iv = g[u][i].initial;
                if ( iu == iv ) continue;
                if ( dist[v][iv]==-1 || du+dv<dist[v][iv] )
                {
                    dist[v][iv] = du + dv;
                    pq.push( edge( v, dist[v][iv], iv ) );
                }
            }
        }
        int best = -1;
        for (char c=0; c<27; c++)
            if ( dist[idt][c] != -1 )
            {
                if ( best==-1 || dist[idt][c]<best )
                    best = dist[idt][c];
            }
        if ( best == -1 ) puts("impossivel");
        else cout << best << endl;
    }
    
    return 0;
}