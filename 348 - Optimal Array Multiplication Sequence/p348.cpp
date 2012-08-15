#include <stdio.h>
#include <memory.h>

int d[ 15 ];
int dp[ 15 ][ 15 ];
int prev[ 15 ][ 15 ];

int solve(int a, int b)
{
    int &ret = dp[a][b];
    if ( ret != -1 ) return ret;
    if ( a == b ) return ret = 0;
    for (int k=a; k<b; k++)
    {
        int cost = d[ a-1 ] * d[ k ] * d[ b ] + solve( a, k ) + solve( k+1, b );
        if ( ret==-1 || cost < ret )
        {
            ret = cost;
            prev[ a ][ b ] = k;
        }
    }
    return ret;
}

void path(int a, int b)
{
    if ( a == b ) printf("A%d",a);
    else
    {
        printf("(");
        path( a, prev[ a ][ b ] );
        printf(" x ");
        path( prev[ a ][ b ]+1, b );
        printf(")");
    }
}

int main()
{
    int n;
    int kase = 1;
    
    while ( scanf("%d",&n), n )
    {
        for (int i=0; i<n; i++) scanf("%d %d",d+i,d+i+1);
        memset( dp, -1, sizeof dp );
        solve( 1, n );
        printf("Case %d: ",kase++);
        path(1, n);
        printf("\n");
    }
    
    return 0;
}