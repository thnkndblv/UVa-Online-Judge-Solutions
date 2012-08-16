#include <stdio.h>
#include <memory.h>
#include <limits.h>
#include <algorithm>

using namespace std;

#define oo INT_MAX

int a[ 255 ];
int s[ 255 ];
int dp[ 255 ][ 255 ];

int solve(int i, int j)
{
    if ( i >= j ) return 0;
    int &ret = dp[i][j];
    if ( ret != oo ) return ret;
    for (int k=i; k<=j; k++)
        ret = min( ret, solve(i,k-1) + (s[j]-s[i-1]-a[k]) + solve(k+1,j) );
    return ret;
}

int main()
{
    int n;
    
    while ( scanf("%d",&n) == 1 )
    {
        for (int i=1; i<=n; i++) scanf("%d",a+i);
        for (int i=1; i<=n; i++) s[i] = a[i] + s[i-1];
        for (int i=1; i<=n; i++) fill( dp[i]+1, dp[i]+n+1, oo );
        printf("%d\n",solve(1, n));
    }
    
    return 0;
}