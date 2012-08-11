#include <iostream>
#include <string>
#include <sstream>
#include <memory.h>
#include <algorithm>

using namespace std;

string line;
int n;
int square[ 102 ][ 102 ];
int cnt[ 102 ];
int mov[][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int r, int c, int color)
{
    if ( square[r][c] != color ) return 0;
    int ret = 1;
    square[r][c] = -1;
    for (int k=0; k<4; k++)
    {
        int nr = r + mov[k][0];
        int nc = c + mov[k][1];
        if ( nr>=1 && nr<=n && nc>=1 && nc<=n )
            ret += dfs( nr, nc, color );
    }
    return ret;
}

int main()
{
    int r, c;
    
    while ( cin >> n, n )
    {
        cin.ignore();
        memset( square, 0, sizeof square );
        for (int i=1; i<n; i++)
        {
            getline( cin, line );
            istringstream in( line );
            while (in >> r >> c)
            {
                square[ r ][ c ] = i;
            }
        }
        memset( cnt, 0, sizeof cnt );
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if ( square[i][j] != -1 )
                    cnt[ square[i][j] ] = dfs(i, j, square[i][j]);
        
        if ( count( cnt, cnt+n, n ) != n ) cout << "wrong" << endl;
        else cout << "good" << endl;
    }
    
    return 0;
}
