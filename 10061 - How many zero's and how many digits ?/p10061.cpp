#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
#include <limits.h>
#include <math.h>

using namespace std;

#define forit(i, a) for ( __typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )

#define MAXPRIME 30
vector< int > primo;
void sieve()
{
    for (int i=2; i<MAXPRIME; i++)
    {
        primo.push_back( i );
        for (int j=2; j<i; j++)
            if ( i % j == 0 )
            {
                primo.pop_back();
                break;
            }
    }
}

void factoriza(int n, map<int,int> &f)
{
    for (int i=0; i<primo.size(); i++)
    {
        if ( n == 1 ) break;
        while ( n % primo[i] == 0 )
        {
            f[ primo[i] ]++;
            n /= primo[i];
        }
    }
    if ( n != 1 ) f[ n ]++;
}

int count(int n, int f)
{
    int ret = 0;
    while ( n )
    {
        ret += n / f;
        n /= f;
    }
    return ret;
}

int main()
{
    sieve();

    int n, b;
    while ( scanf("%d %d",&n,&b) == 2 )
    {
        map<int,int> f;
        factoriza( b, f );
        
        int zeros = INT_MAX;
        forit(it,f)
        {
            zeros = min( zeros, count( n, it->first ) / it->second );
        }
        double digitos = 0.0;
        for (int i=1; i<=n; i++)
        {
            digitos += log( i ) / log( b );
        }
        //if ( n == 0 || n == 1 ) digitos = 1;
        printf("%d %d\n",zeros,(int)floor(digitos + 1e-9)+1);
    }
    
    return 0;
}
