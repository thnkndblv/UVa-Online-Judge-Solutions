#include "stdio.h"
#include "memory.h"

char buff[ 1003 ];
char grid[ 15 ][ 15 ];
int dist[ 15 ][ 15 ];

int mov[][2] = {{-1,0},{0,1},{1,0},{0,-1}};

int get(char c)
{
    if ( c == 'N' ) return 0;
    if ( c == 'E' ) return 1;
    if ( c == 'S' ) return 2;
    return 3;
}

int main(int argc, char const *argv[])
{
    int R, C, c;

    while ( sscanf(gets(buff), "%d %d %d", &R, &C, &c), R || C || c )
    {
        for (int i = 1; i <= R; i++) gets( grid[ i ] + 1 );

        memset( dist, -1, sizeof dist );
        int r = 1, Count = 0;
        while ( r >= 1 && r <= R && c >= 1 && c <= C && dist[ r ][ c ] == -1 )
        {
            dist[ r ][ c ] = Count++;
            int k = get( grid[ r ][ c ] );

            r = r + mov[ k ][ 0 ];
            c = c + mov[ k ][ 1 ];
        }

        if ( r >= 1 && r <= R && c >= 1 && c <= C )
            printf("%d step(s) before a loop of %d step(s)\n", dist[r][c], Count - dist[r][c]);
        else printf("%d step(s) to exit\n", Count);
    }

    return 0;
}
