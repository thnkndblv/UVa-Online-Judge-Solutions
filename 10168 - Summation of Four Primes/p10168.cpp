#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back

#define MAXPRIME 10000100
bitset< MAXPRIME > criba;
vector< int > primo;
void sieve()
{
    criba.set();
    criba[ 0 ] = 0;
    criba[ 1 ] = 0;
    for (int i=2; i<MAXPRIME; i++)
    {
        if ( criba[i] )
        {
            primo.pb( i );
            for (int j=i<<1; j<MAXPRIME; j+=i)
                criba[j] = 0;
        }
    }
}

bool func(int n, int k)
{
    if ( k == 1 )
    {
        if ( criba[ n ] )
        {
            printf("%d",n);
            return true;
        }
        else return false;
    }
    for (int i = (int)(upper_bound(primo.begin(), primo.end(), n) - primo.begin()); i>=0; i--)
    {
        if ( primo[ i ] > n ) continue;
        if ( func( n-primo[i], k-1 ) )
        {
            printf(" %d%s",primo[i],k==4?"\n":"");
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    
    sieve();
    
    while ( scanf("%d",&n) == 1 )
    {
        if ( !func( n, 4 ) ) puts("Impossible.");
    }
    
    return 0;
}