#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

char str[ 15 ];
long long a[ 9 ];
long long b[ 9 ];

int main()
{
    while ( gets( str ) )
    {
        int len = strlen( str );
        for (int i=0; i<9; i++) a[ i ] = 0LL, b[ i ] = (1LL << 60);
        sort( str, str+len );
        do {
            if ( str[0] != '0' )
            {
                long long n;
                sscanf(str,"%lld",&n);
                a[ n % 9LL ] = max( a[ n % 9LL ], n );
                b[ n % 9LL ] = min( b[ n % 9LL ], n );
            }
        } while ( next_permutation( str, str+len ) );
        int best = 0;
        for (int i=0; i<9; i++) if ( a[i]-b[i] > a[best]-b[best] ) best = i;
        printf("%lld - %lld = %lld = 9 * %lld\n",a[best],b[best],a[best]-b[best],(a[best]-b[best])/9LL);
    }
    
    return 0;
}
