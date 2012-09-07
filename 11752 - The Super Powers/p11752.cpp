#include <stdio.h>
#include <limits.h>
#include <set>
#include <bitset>
#include <math.h>

using namespace std;

#define MAX (1<<16)
bitset< 100 > criba;
void sieve()
{
    criba.set();
    criba[ 0 ] = 0;
    criba[ 1 ] = 0;
    for (int i=2; i<100; i++)
    {
        for (int j=2; j<i; j++)
            if ( i % j == 0 )
                criba[ i ] = 0;
    }
}

set< unsigned long long > ans;

int main()
{
    sieve();
    ans.insert( 1ULL );
    for (int i=2; i<MAX; i++)
    {
        double lim = log10( ULLONG_MAX ) / log10( i );
        //printf("%d ^ %lf\n",i,lim);
        unsigned long long n = 1ULL;
        for (int j=1; j<lim; j++)
        {
            n *= i;
            if ( j > 1 && criba[j] == 0 ) ans.insert( n );
        }
    }
    
    for ( set< unsigned long long >::iterator it = ans.begin(); it != ans.end(); it++ ) printf("%llu\n",*it);
    
    return 0;
}
