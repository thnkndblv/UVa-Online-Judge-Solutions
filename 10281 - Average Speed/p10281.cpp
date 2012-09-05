#include <stdio.h>
#include <ctype.h>

char str[ 100 ];

int sec(int h, int m, int s)
{
    return (h * 60 + m) * 60 + s;
}

double hrs(double s)
{
    return s / 60.0 / 60.0;
}

int main()
{
    int hp, mp, sp, vp;
    int h, m, s, v;
    int p;
    double dist = 0;
    bool f = false;
    
    while ( gets( str ) )
    {
        for (int i=0; str[i]; i++) if ( !isdigit( str[i] ) ) str[i] = ' ';
        
        int p = sscanf(str,"%d %d %d %d",&h,&m,&s,&v);
        
        if ( f )
        {
            double t = hrs( sec(h,m,s) - sec(hp,mp,sp) );
            double d = vp * t;
            dist += d;
        }
        f = true;
        
        if ( p == 3 ) printf("%02d:%02d:%02d %.2lf km\n",h,m,s,dist);
        else vp = v;
        
        hp = h;
        mp = m;
        sp = s;
    }
    
    return 0;
}
