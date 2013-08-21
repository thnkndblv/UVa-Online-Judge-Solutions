#include "cstdio"
#include "cstring"

char buff[ 1003 ];
int dp[ 1003 ][ 1003 ];
int mov[ 1003 ][ 1003 ];
int run(int le, int ri)
{
    if ( dp[ le ][ ri ] != -1 ) return dp[ le ][ ri ];
    int &ret = dp[ le ][ ri ];

    if ( le >= ri ) return ret = 0;
    if ( buff[le] == buff[ri] )
    {
        mov[le][ri] = 0;
        ret = run( le+1, ri-1 );
    }
    else
    {
        int rle = 1 + run( le+1, ri );
        int rri = 1 + run( le, ri-1 );

        if ( rle <= rri )
        {
            mov[le][ri] = 1;
            ret = rle;
        }
        else
        {
            mov[le][ri] = 2;
            ret = rri;
        }
    }

    return ret;
}

void path(int le, int ri)
{
    if ( le > ri ) return;
    if ( le == ri )
    {
        printf("%c", buff[ le ]);
    }
    else
    {
        if ( mov[le][ri] == 0 )
        {
            printf("%c", buff[le]);
            path( le+1, ri-1 );
            printf("%c", buff[le]);
        }
        else if ( mov[le][ri] == 1 )
        {
            printf("%c", buff[le]);
            path( le+1, ri );
            printf("%c", buff[le]);
        }
        else
        {
            printf("%c", buff[ri]);
            path( le, ri-1 );
            printf("%c", buff[ri]);
        }
    }
}

int main(int argc, char const *argv[])
{
    while ( gets( buff ) )
    {
        int n = strlen( buff );

        memset( dp, -1, sizeof dp );
        printf("%d ", run( 0, n-1 ));
        path( 0, n-1 );
        printf("\n");
    }

    return 0;
}