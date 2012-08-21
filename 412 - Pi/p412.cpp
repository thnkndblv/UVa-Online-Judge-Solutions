#include <stdio.h>
#include <math.h>

int a[ 55 ];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd( b, a % b );
}

int main()
{
    int n;
    
    while ( scanf("%d",&n), n )
    {
        for (int i=0; i<n; i++) scanf("%d",a+i);
        int den = n * (n-1) / 2;
        int num = 0;
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                if ( gcd( a[i], a[j] ) == 1 )
                    num++;
        if ( num == 0 ) puts("No estimate for this data set.");
        else printf("%.6lf\n",sqrt( 6.0 * den / num ));
    }
    
    return 0;
}
