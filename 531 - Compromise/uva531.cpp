#include "cstdio"
#include "vector"
#include "string"
#include "sstream"
#include "cstring"
#include "algorithm"

using namespace std;

char buff[ 10004 ];

int dp[ 102 ][ 102 ];
int mov[ 102 ][ 102 ];

int main(int argc, char const *argv[])
{
    while ( gets( buff ) )
    {
        vector< string > a, b;

        while ( strcmp( buff, "#" ) != 0 )
        {
            stringstream ss( buff );
            string wd;
            while ( ss >> wd ) a.push_back( wd );
            gets( buff );
        }

        while ( gets( buff ) && strcmp( buff, "#" ) != 0 )
        {
            stringstream ss( buff );
            string wd;
            while ( ss >> wd ) b.push_back( wd );
        }

        reverse( a.begin(), a.end() );
        reverse( b.begin(), b.end() );

        int n = a.size();
        int m = b.size();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                mov[i][j] = 0;
                if ( a[ i-1 ] == b[ j-1 ] ) dp[ i ][ j ] = 1 + dp[ i-1 ][ j-1 ];
                else
                {
                    dp[ i ][ j ] = dp[ i-1 ][ j-1 ];
                    if ( dp[ i-1 ][ j ] > dp[ i ][ j ] )
                    {
                        dp[ i ][ j ] = dp[ i-1 ][ j ];
                        mov[i][j] = 1;
                    }
                    if ( dp[ i ][ j-1 ] > dp[ i ][ j ] )
                    {
                        dp[ i ][ j ] = dp[ i ][ j-1 ];
                        mov[i][j] = 2;
                    }
                }
            }

        int r = n, c = m;
        bool flag = false;
        while ( r && c )
        {
            if ( a[ r-1 ] == b[ c-1 ] )
            {
                if ( flag ) printf(" ");
                printf("%s", a[ r-1 ].c_str());
                flag = true;
            }

            if ( mov[r][c] == 0 ) r--, c--;
            if ( mov[r][c] == 1 ) r--;
            if ( mov[r][c] == 2 ) c--;
        }
        printf("\n");
    }

    return 0;
}
