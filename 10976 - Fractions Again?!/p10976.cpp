#include <stdio.h>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int k;
    
    while ( scanf("%d",&k) == 1 )
    {
        int K = k*k;
        vector< pair< int, int > > ans;
        for (int i=1; i<=k; i++)
        {
            if ( K%i != 0 ) continue;
            int j = K / i;
            int x = j + k;
            int y = i + k;
            ans.push_back( make_pair( x, y ) );
        }
        printf("%d\n",(int)ans.size());
        for (int i=0; i<ans.size(); i++)
        {
            printf("1/%d = 1/%d + 1/%d\n",k,ans[i].first,ans[i].second);
        }
    }
    
    return 0;
}
