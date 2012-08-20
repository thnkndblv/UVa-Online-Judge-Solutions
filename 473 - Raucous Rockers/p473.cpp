#include <stdio.h>
#include <memory.h>
#include <algorithm>

using namespace std;

int N, T, M;
int dp[ 1<<23 ];
int *song;
int solve(int n, int t, int m)
{
    int &ret = dp[ n*(T+1)*(M+1) + t*(M+1) + m ];
    
    if ( ret != -1 ) return ret;
    if ( n == 0 ) return ret = 0;
    if ( m == 0 ) return ret = 0;
    ret = solve( n-1, t, m );
    if ( song[n] <= t ) ret = max( ret, 1 + solve( n-1, t-song[n], m ) );
    ret = max( ret, solve( n, T, m-1 ) );
    
    return ret;
}

int main()
{
    int test;
    
    scanf("%d",&test);
    while ( test-- )
    {
        scanf("%d %d %d",&N,&T,&M);
        
        song = new int[ N+1 ];
        for (int i=1; i<=N; i++) scanf("%d,",song+i);
        
        memset( dp, -1, sizeof dp );
        printf("%d\n",solve( N, T, M ));
        
        delete song;
        if ( test ) puts("");
    }
    
    return 0;
}
