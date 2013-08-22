#include "stdio.h"

char buff[ 1003 ];
char grid[ 102 ][ 102 ];
int q[ 100005 ];
int mov[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

int main(int argc, char const *argv[])
{
    int ntc;

    sscanf(gets(buff), "%d", &ntc);
    for (int tc=1; tc<=ntc; tc++)
    {
        int n;
        sscanf(gets(buff), "%d", &n);

        for (int i = 0; i < n; i++) gets( grid[ i ] );

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ( grid[i][j] == 'x' )
                {
                    ans++;

                    int head = 0, tail = 0;
                    q[ tail++ ] = i;
                    q[ tail++ ] = j;
                    grid[i][j] = '.';
                    while ( head < tail )
                    {
                        int ra = q[ head++ ];
                        int ca = q[ head++ ];

                        for (int k = 0; k < 4; k++)
                        {
                            int nr = ra + mov[k][0];
                            int nc = ca + mov[k][1];

                            if ( nr < 0 || nr >= n ) continue;
                            if ( nc < 0 || nc >= n ) continue;
                            if ( grid[nr][nc] == '.' ) continue;

                            grid[nr][nc] = '.';
                            q[ tail++ ] = nr;
                            q[ tail++ ] = nc;
                        }
                    }
                }

        printf("Case %d: %d\n", tc, ans);
    }

    return 0;
}