#include "stdio.h"
#include "vector"
#include "string"
#include "algorithm"
#include "cstring"

using namespace std;

#define pb push_back

char buff[ 1003 ];
int q[ 100005 ];

int R, C;
char border;
vector< string > grid;
vector< bool > done[ 35 ];
vector< int > L;
int mov[][2] = {{0,1},{0,-1},{1,0},{-1,0}};

void flood(int r, int c, bool flag = false)
{
    int head = 0, tail = 0;
    q[ tail++ ] = r;
    q[ tail++ ] = c;
    q[ tail++ ] = 2;
    done[r][c] = true;
    while ( head < tail )
    {
        int ra = q[ head++ ];
        int ca = q[ head++ ];
        int da = q[ head++ ];

        for (int k = 0; k < 4; k++)
        {
            int nr = ra + mov[k][0];
            int nc = ca + mov[k][1];
            if ( nr < 0 || nr >= R ) continue;
            if ( nc < 0 || nc >= C ) continue;
            if ( done[nr][nc] ) continue;

            if ( flag )
            {
                if ( grid[nr][nc] == border ) continue;
                grid[nr][nc] = grid[r][c];
                done[nr][nc] = true;
                q[ tail++ ] = nr;
                q[ tail++ ] = nc;
                q[ tail++ ] = 0;
            }
            else
            {
                int nd = da - (grid[ra][ca] != grid[nr][nc]);
                if ( nd < 1 ) continue;

                done[nr][nc] = true;
                q[ tail++ ] = nr;
                q[ tail++ ] = nc;
                q[ tail++ ] = nd;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    while ( gets( buff ) )
    {
        grid.clear();
        L.clear();

        grid.pb("");
        L.pb( 0 );
        while ( buff[ 0 ] != '_' )
        {
            L.push_back( strlen( buff ) );
            grid.push_back( buff );
            grid.back() = " " + grid.back() + " ";
            gets( buff );
        }
        grid.pb( "" );
        L.pb( 0 );

        R = grid.size();
        C = 0;
        for (int i = 0; i < R; i++) C = max( C, (int)grid[i].length() );
        for (int i = 0; i < R; i++) grid[ i ] += string(C - grid[i].length(), ' ');
        for (int i = 0; i < R; i++) done[ i ].assign( C, false );

        flood( 0, 0 );

        border = 0;
        for (int i = 0; i < R && border == 0; i++)
            for (int j = 0; j < C && border == 0; j++)
                if ( grid[i][j] != ' ' )
                {
                    border = grid[i][j];
                }

        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                if ( !done[i][j] && grid[i][j] != ' ' && grid[i][j] != border )
                    flood( i, j, true );

        for (int i = 1; i < R-1; i++)
        {
            for (int j = 1; j <= L[i]; j++)
            {
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
        puts( buff );
    }

    return 0;
}
