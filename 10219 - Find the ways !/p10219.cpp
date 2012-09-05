#include <stdio.h>
#include <math.h>

int C(int n, int k)
{
    //int ret = 1;
    double num = 0, den = 0;
    if ( n-k < k ) k = n - k;
    
    for (int i=1; i<=k; i++)
    {
        num += log10( n - k + i );
        den += log10( i );
        //ret = ret * (n - k + i) / i;
    }
    
    return (int)(floor(num-den+1e-9)+1);
}

int main()
{
    int n, k;
    
    while ( scanf("%d %d",&n,&k) == 2 )
    {
        printf("%d\n",C(n,k));  
    }
    
    return 0;
}
