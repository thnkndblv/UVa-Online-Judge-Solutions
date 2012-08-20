#include <stdio.h>
#include <memory.h>

int N, K, M;
long long dp[55][55];

long long solve(int n, int k)
{
    long long &ret = dp[n][k];
    if ( ret != -1LL ) return ret;
    if ( n == 0 && k == 0 ) return ret = 1LL;
    if ( n == 0 ) return ret = 0LL;
    if ( k == 0 ) return ret = 0LL;
    ret = 0LL;
    for (int i=1; i<=M; i++)
    {
        if ( n-i < 0 ) break;
        ret += solve( n-i, k-1 );
    }
    return ret;
}

int main()
{
    
    while (scanf("%d %d %d",&N,&K,&M) == 3)
    {
        memset( dp, -1, sizeof dp );
        printf("%lld\n",solve( N, K ));
    }
    
    return 0;
}
