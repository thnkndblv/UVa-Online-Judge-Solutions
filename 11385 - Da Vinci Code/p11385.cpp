#include <stdio.h>
#include <ctype.h>
#include <memory.h>

int fib[ 50 ];
int code[ 50 ];
char str[ 200 ];
char ans[ 200 ];

void put(char c, int p)
{
    int i = 0;
    while ( p != fib[i] ) i++;
    ans[ i ] = c;
}

int main()
{
    int T;
    int n;
    
    fib[ 0 ] = 1;
    fib[ 1 ] = 2;
    for (int i=2; i<50; i++) fib[i] = fib[i-1] + fib[i-2];
    
    scanf("%d",&T);
    while ( T-- )
    {
        scanf("%d",&n);
        for (int i=0; i<n; i++) scanf("%d",code+i);
        gets( str );
        gets( str );
        memset( ans, 0, sizeof ans );
        for (int i=0, j=0; str[i]; i++)
        {
            if ( j >= n ) break;
            if ( isupper( str[i] ) ) put( str[ i ], code[j++] );
        }
        for (int i=49, j=0; i>=0; i--)
        {
            if ( isupper( ans[i] ) ) j = 1;
            else if ( j ) ans[i] = ' ';
        }
        puts(ans);
    }
    
    return 0;
}
