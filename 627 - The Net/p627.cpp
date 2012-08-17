#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <memory.h>

using namespace std;

#define MAXN 303

string line;
vector< int > g[ MAXN ];
int dist[ MAXN ];
int prev[ MAXN ];

void path(int s, int t)
{
    if ( s == t ) printf("%d",s);
    else
    {
        path( s, prev[t] );
        printf(" %d",t);
    }
}

int main()
{
    int n, m;
    int s, t;
    
    while ( cin >> n )
    {
        cin.ignore();
        for (int i=0; i<n; i++)
        {
            getline( cin, line );
            replace( line.begin(), line.end(), '-', ' ' );
            replace( line.begin(), line.end(), ',', ' ' );
            
            istringstream in( line );
            int id, router;
            in >> id;
            g[ id ].clear();
            while ( in >> router ) g[ id ].push_back( router );
        }
        cin >> m;
        cout << "-----" << endl;
        for (int i=0; i<m; i++)
        {
            cin >> s >> t;
            memset( dist, -1, sizeof dist );
            memset( prev, -1, sizeof prev );
            queue< int > q;
            q.push( s );
            dist[ s ] = 0;
            prev[ s ] = -2;
            while ( !q.empty() )
            {
                int u = q.front(); q.pop();
                for (int i=0; i<g[u].size(); i++)
                {
                    if ( dist[ g[u][i] ] == -1 )
                    {
                        dist[ g[u][i] ] = dist[ u ] + 1;
                        prev[ g[u][i] ] = u;
                        q.push( g[u][i] );
                    }
                }
            }
            
            if ( dist[ t ] == -1 ) puts("connection impossible");
            else
            {
                path( s, t );
                puts("");
            }
        }
    }
    
    return 0;
}