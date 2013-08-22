#include "stdio.h"
#include "memory.h"

char buff[ 1003 ];

char board[ 15 ][ 15 ];

bool black[ 15 ][ 15 ];
bool white[ 15 ][ 15 ];

// Flood Fill
int mov[][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int q[ 1003 ];
void fill(int r, int c, bool seen[15][15])
{
    char color = board[r][c];
    seen[r][c] = true;
    int head = 0, tail = 0;
    q[ tail++ ] = r;
    q[ tail++ ] = c;

    while ( head < tail )
    {
        int ra = q[ head++ ];
        int ca = q[ head++ ];
        for (int k = 0; k < 4; k++)
        {
            int nr = ra + mov[k][0];
            int nc = ca + mov[k][1];
            if ( nr < 0 || nr >= 9 ) continue;
            if ( nc < 0 || nc >= 9 ) continue;
            if ( board[nr][nc] != '.' && board[nr][nc]!=color ) continue;
            if ( seen[nr][nc] ) continue;
            seen[nr][nc] = true;
            q[ tail++ ] = nr;
            q[ tail++ ] = nc;
        }
    }
}

int main(int argc, char const *argv[])
{
    int ntc;

    sscanf(gets(buff),"%d",&ntc);
    while ( ntc-- )
    {
        for (int i = 0; i < 9; i++) gets( board[ i ] );

        memset( black, 0, sizeof black );
        memset( white, 0, sizeof white );

        // Black
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if ( board[i][j] == 'X' )
                    fill( i, j, black );
                else if ( board[i][j] == 'O' )
                    fill( i, j, white );

        int blackCount = 0, whiteCount = 0;

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if ( black[i][j] && !white[i][j] ) blackCount++;
                else if ( !black[i][j] && white[i][j] ) whiteCount++;

        printf("Black %d White %d\n", blackCount, whiteCount);
    }

    return 0;
}