#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define forit(a,i) for ( __typeof( a.begin() ) i = a.begin(); i != a.end(); i++ )

struct point {
    int x, y;
    point(){}
    point(int x, int y):x(x),y(y){}
    bool operator<(const point &p) const
    {
        return x<p.x || (x==p.x && y<p.y);
    }
};

int cross(const point &O, const point &A, const point &B)
{
    return (A.x-O.x)*(B.y-O.y)-(A.y-O.y)*(B.x-O.x);
}

vector<point> convexHull(vector<point> P)
{
    int n = P.size(), k = 0; vector< point > H( 2*n );
    
    // Sort points lexicographically
    sort( P.begin(), P.end() );
    
    // Build lower hull
    for (int i=0; i<n; i++) {
        while (k>=2 && cross(H[k-2],H[k-1],P[i])<=0) k--;
        H[k++] = P[i];
    }
    
    // Build upper hull
    for (int i=n-2, t=k+1; i>=0; i--) {
        while (k>=t && cross(H[k-2],H[k-1],P[i])<=0) k--;
        H[k++] = P[i];
    }
    
    H.resize( k );
    return H;
}

bool isInside(vector<point> &P, point p)
{
    if ( P.size() < 3 ) return false;
    for (int i=0; i<P.size()-1; i++)
    {
        int j = i + 1;
        int c = cross( P[i], P[j], p );
        int x = min( P[i].x, P[j].x );
        int X = max( P[i].x, P[j].x );
        int y = min( P[i].y, P[j].y );
        int Y = max( P[i].y, P[j].y );
        
        int d = x<=p.x&&p.x<=X&&y<=p.y&&p.y<=Y;
        if ( c < 0 )
            return false;
        else if ( c == 0 && d == 0 )
            return false;
    }
    return true;
}

int main()
{
    int c, r, o;
    int kase = 1;
    
    while ( scanf("%d %d %d",&c,&r,&o), c || r || o )
    {
        printf("Data set %d:\n",kase++);
        
        vector< point > cop;
        int x, y;
        for (int i=0; i<c; i++)
        {
            scanf("%d %d",&x,&y);
            cop.push_back( point(x, y) );
        }
        if ( cop.size() >= 3 ) cop = convexHull( cop );
        
        vector< point > robber;
        for (int i=0; i<r; i++)
        {
            scanf("%d %d",&x,&y);
            robber.push_back( point(x, y) );
        }
        if ( robber.size() >= 3 ) robber = convexHull( robber );
        
        for (int i=0; i<o; i++)
        {
            scanf("%d %d",&x,&y);
            bool safe = isInside( cop, point(x, y) );
            bool robbed = isInside( robber, point(x, y) );
            printf("     Citizen at (%d,%d) is %s.\n",x,y,safe?"safe":robbed?"robbed":"neither");
        }
        puts("");
    }
    
    return 0;
}
