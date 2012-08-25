#include <stdio.h>
#include <bitset>
#include <vector>
#include <map>
#include <string.h>

using namespace std;

#define forit(i, a) for ( __typeof( a.rbegin() ) i = a.rbegin(); i != a.rend(); i++ )

#define MAXN 1024
bitset< MAXN > criba;
vector< int > fact[ MAXN ];
void sieve()
{
    criba.set();
    criba[0] = 0;
    criba[1] = 0;
    for (int i=2; i<MAXN; i++)
        if ( criba[ i ] )
        {
            fact[ i ].push_back( i );
            for (int j=i<<1; j<MAXN; j+=i)
            {
                criba[j] = 0;
                for (int k=j; k%i==0; k/=i)
                    fact[ j ].push_back( i );
            }
        }
}

int main()
{
    int test;
    int n;
    char str[ 25 ];
    
    sieve();
    
    scanf("%d",&test);
    for (int kase=1; kase<=test; kase++)
    {
        scanf("%d%s",&n,str);
        int k = strlen( str );
        map<int,int> f;
        for (int i=n; i>1; i-=k)
        {
            forit( it, fact[i] )
            {
                f[ *it ]++;
            }
        }
        unsigned long long cnt = 1LL;
        bool inf = false;
        forit( it, f )
        {
            cnt *= ( it->second + 1LL );
            if ( cnt > 1000000000000000000LL )
                inf = false;
        }
        if ( inf ) printf("Case %d: Infinity\n",kase);
        else printf("Case %d: %lld\n",kase,cnt);
    }
    
    return 0;
}
