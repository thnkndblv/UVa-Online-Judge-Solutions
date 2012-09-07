#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int,int> ii;

vector< ii > frac;

bool cmp(ii a, ii b)
{
    return a.first*b.second < b.first*a.second;
}

int gcd(int a, int b)
{
    return b == 0 ? a : gcd( b, a % b );
}

int main()
{
    int n, k;
    
    while ( scanf("%d %d",&n,&k) == 2 )
    {
        frac.clear();
        for (int den=1; den<=n; den++)
            for (int num=1; num<=den; num++)
                if ( gcd( num, den ) == 1 )
                    frac.pb( mp( num, den ) );
        sort( frac.begin(), frac.end(), cmp );
        printf("%d/%d\n",frac[k-1].first,frac[k-1].second);
    }
    
    return 0;
}
