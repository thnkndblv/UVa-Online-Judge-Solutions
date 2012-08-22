#include <stdio.h>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int,int> ii;

vector< ii > mat[ 10000 ];

int main()
{
    int r, c;
    int a, b;
    
    while ( scanf("%d %d",&r,&c) == 2 )
    {
        queue< int > que;
        for (int i=1; i<=c; i++) mat[i].clear();
        for (int i=1; i<=r; i++)
        {
            scanf("%d",&a);
            while ( a-- )
            {
                scanf("%d",&b);
                que.push( b );
            }
            while ( !que.empty() )
            {
                scanf("%d",&b);
                mat[ que.front() ].push_back( make_pair( i, b ) );
                //printf( "(%d,%d) -> %d\n", i+1, que.front(), b );
                que.pop();
            }
        }
        printf("%d %d\n",c,r);
        for (int i=1; i<=c; i++)
        {
            printf("%d",(int)mat[i].size());
            for (int j=0; j<mat[i].size(); j++) printf(" %d",mat[i][j].first);
            printf("\n");
            for (int j=0; j<mat[i].size(); j++)
            {
                if ( j ) printf(" ");
                printf("%d",mat[i][j].second);
            }
            printf("\n");
        }
    }
    
    return 0;
}
