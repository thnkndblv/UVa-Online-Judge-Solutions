#include "stdio.h"
#include "memory.h"
#include "algorithm"

using namespace std;

char buff[ 1003 ];
int maze[ 303 ][ 303 ];

// Slash type1: /
// Representamos esto como:
//  *.**
//  .***
//  ***.
//  **.*
void slash1(int r, int c)
{
    maze[r+0][c+1] = -2;
    maze[r+1][c+0] = -2;
    maze[r+2][c+3] = -2;
    maze[r+3][c+2] = -2;
}

// Slash type2: /'
// Representamos esto como:
//  **.*
//  ***.
//  .***
//  *.**
void slash2(int r, int c)
{
    maze[r+0][c+2] = -2;
    maze[r+1][c+3] = -2;
    maze[r+2][c+0] = -2;
    maze[r+3][c+1] = -2;
}

// Flood Fill

int mov[][2] = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}}; // Movimimientos
int R, C;   // Dimensiones del grid
int Count, Longest; // Soluciones

void DFS(int r, int c, int pr, int pc, int tm)
{
    maze[ r ][ c ] = tm;
    for (int k = 0; k < 8; k++)
    {
        int nr = r + mov[ k ][ 0 ];
        int nc = c + mov[ k ][ 1 ];

        if ( nr < 0 || nr >= R ) continue;
        if ( nc < 0 || nc >= C ) continue;
        if ( nr == pr && nc == pc ) continue;
        if ( maze[nr][nc] == -1 ) continue;

        if ( maze[nr][nc] == -2 ) DFS( nr, nc, r, c, tm+1 );
        else if ( maze[nr][nc] < tm+1 )
        {
            Count++;
            Longest = max( Longest, (tm+1 - maze[nr][nc]) / 2 );
        }
    }
}

int main(int argc, char const *argv[])
{
    int w, h;
    int tc = 1;

    while ( sscanf(gets(buff), "%d %d", &w, &h), w || h )
    {
        memset( maze, -1, sizeof maze );
        for (int i = 0; i < h; i++)
        {
            gets( buff );
            for (int j = 0; j < w; j++)
            {
                if ( buff[j] == '/' ) slash1( i*4, j*4 );
                else slash2( i*4, j*4 );
            }
        }

        Count = 0;
        Longest = 0;
        R = 4 * h;
        C = 4 * w;
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if ( maze[ i ][ j ] == -2 )
                    DFS( i, j, -1, -1, 0 );

        printf("Maze #%d:\n", tc++);

        if ( Count == 0 ) printf("There are no cycles.\n");
        else printf("%d Cycles; the longest has length %d.\n", Count, Longest);
        
        printf("\n");
    }

    return 0;
}