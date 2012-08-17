#include <stdio.h>
#include <utility>
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;

#define mp make_pair
#define X first
#define Y second

typedef pair<int,int> Point;

Point p[ 20 ];
char name[ 20 ];

int cross(Point &O, Point &A, Point &B)
{
    return (A.X-O.X)*(B.Y-O.Y)-(A.Y-O.Y)*(B.X-O.X);
}

bool isInside(Point &A, Point &B, Point &C, Point &D)
{
    return abs(cross(A, B, C)) == abs(cross(A,B,D)) + abs(cross(B,C,D)) + abs(cross(C,A,D));
}

int main()
{
    int n;
    
    while ( scanf("%d\n",&n), n )
    {
        for (int i=0; i<n; i++)
            scanf("%c %d %d\n",name+i,&p[i].X,&p[i].Y);
        
        double maxArea = 0.0;
        string ans = "ABC";
        for (int i=0; i<n; i++)
            for (int j=i+1; j<n; j++)
                for (int k=j+1; k<n; k++)
                {
                    double area = fabs( 0.5 * cross( p[i], p[j], p[k] ) );
                    bool ok = true;
                    for (int x=0; x<n; x++)
                        if (x!=i && x!=j && x!=k)
                            ok = ok && (!isInside( p[i], p[j], p[k], p[x] ));
                    
                    if ( ok && area > maxArea )
                    {
                        maxArea = area;
                        ans = "";
                        ans += name[i];
                        ans += name[j];
                        ans += name[k];
                    }
                }
        
        cout << ans << endl;
    }
    
    return 0;
}