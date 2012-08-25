#include <stdio.h>
#include <math.h>

int fib[ 18 ];

int dp[ 1003 ];

int main()
{
    fib[ 0 ] = 0;
    fib[ 1 ] = 1;
    for (int i=2; i<18; i++) fib[i] = fib[i-1] + fib[i-2];
    for (int i=1; i<=1000; i++)
    {
        dp[ i ] = 0;
        for (int j=0; j<16 && fib[j]<=i; j++)
        {
            if ( fabs(1.6*i - (fib[j+1] + dp[ i-fib[j] ])) < fabs( 1.6*i - dp[i] ) )
                dp[ i ] = fib[j+1] + dp[ i-fib[j] ];
        }
    }
    
    int n;
    while ( scanf("%d",&n), n )
    {
        printf("%.2lf\n",fabs( 1.6*n - dp[n] ));
    }
    
    return 0;
}