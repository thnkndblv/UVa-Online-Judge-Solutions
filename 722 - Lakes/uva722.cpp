#include "stdio.h"
#include "string.h"

char buff[ 1003 ];
char grid[ 1003 ][ 1003 ];
int q[ 100005 ];
int mov[][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int main(int argc, char const *argv[])
{
    int ntc;
    int r, c;

    sscanf( gets(buff), "%d", &ntc );
    gets( buff );

    while ( ntc-- )
    {
        sscanf( gets(buff), "%d %d", &r, &c );

        int R = 0;
        while ( gets( grid[ R ] ) && strcmp(grid[R],"") != 0 ) R++;

        int C = strlen( grid[ 0 ] );

        int ans = 1;
        int head = 0, tail = 0;
        q[ tail++ ] = r-1;
        q[ tail++ ] = c-1;
        grid[r-1][c-1] = '1';
        while ( head < tail )
        {
            int ra = q[ head++ ];
            int ca = q[ head++ ];

            for (int k = 0; k < 4; k++)
            {
                int nr = ra + mov[k][0];
                int nc = ca + mov[k][1];

                if ( nr < 0 || nr >= R ) continue;
                if ( nc < 0 || nc >= C ) continue;
                if ( grid[nr][nc] == '1' ) continue;
                grid[nr][nc] = '1';
                ans++;
                q[ tail++ ] = nr;
                q[ tail++ ] = nc;
            }
        }

        printf("%d\n", ans);

        if ( ntc ) printf("\n");
    }

    return 0;
}