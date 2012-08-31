#include <stdio.h>
#include <memory.h>
#include <set>
#include <utility>
#include <algorithm>

using namespace std;

#define forit(i, a) for ( __typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )

int R, C, M, N;
bool water[ 105 ][ 105 ];
bool seen[ 105 ][ 105 ];
set< pair< int, int > > mov;

int ans[2];
void dfs(int r, int c)
{
    seen[r][c] = true;
    int cnt = 0;
    forit(it, mov)
    {
        int nr = r + it->first;
        int nc = c + it->second;
        if ( nr>=0 && nr<R && nc>=0 && nc<C && !water[nr][nc]  )
        {
            cnt++;
            if ( !seen[nr][nc] ) dfs( nr, nc );
        }
    }
    ans[ cnt%2 ]++;
}

int main()
{
    int test;
    int W;
    int r, c;
    
    scanf("%d",&test);
    for (int cs=1; cs<=test; cs++)
    {
        scanf("%d %d %d %d",&R, &C, &M, &N);
        
        scanf("%d",&W);
        memset( water, 0, sizeof water );
        for (int i=0; i<W; i++)
        {
            scanf("%d %d",&r,&c);
            water[r][c] = true;
        }
        
        mov.clear();
        for (int k=0; k<2; k++)
        {
            for (int dr=-1; dr<=1; dr++)
                for (int dc=-1; dc<=1; dc++)
                    if ( dr && dc )
                        mov.insert( make_pair(dr*M, dc*N) );
            swap( M, N );
        }
        
        memset( seen, 0, sizeof seen );
        ans[0] = ans[1] = 0;
        dfs( 0, 0 );
        
        printf("Case %d: %d %d\n",cs,ans[0],ans[1]);
    }
    
    return 0;
}