#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <stdio.h>
#include <memory.h>

using namespace std;

#define pb push_back

vector< string > name;
map< string, int > id;

int g[102][102];
bool f[ 102 ];

int main()
{
    int N, M;
    string s, t;
    int cs = 1;
    
    while ( cin >> N )
    {
        name.clear();
        id.clear();
        memset( g, 0, sizeof g );
        memset( f, 0, sizeof f );
        for (int i=0; i<N; i++)
        {
            cin >> s;
            id[ s ] = name.size();
            name.pb( s );
        }
        cin >> M;
        for (int i=0; i<M; i++)
        {
            cin >> s >> t;
            int u = id[s];
            int v = id[t];
            g[ v ][ u ] = true;
        }
        int cnt = name.size();
        fill( f, f+cnt, true );
        queue< int > ans;
        while ( cnt )
        {
            for (int i=0; i<name.size(); i++)
            {
                if ( f[i] && count( g[i], g[i]+name.size(), true )==0 )
                {
                    f[i] = false;
                    ans.push( i );
                    cnt--;
                    for (int j=0; j<name.size(); j++)
                    {
                        g[j][i] = false;
                    }
                    break;
                }
            }
        }
        printf("Case #%d: Dilbert should drink beverages in this order:",cs++);
        while ( !ans.empty() )
        {
            cout << " " << name[ans.front()];
            ans.pop();
        }
        cout << "." << endl << endl;
    }
    
    return 0;
}
