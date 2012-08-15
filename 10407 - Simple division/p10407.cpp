#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

// Algoritmo de Euclides para calcular el GCD
int gcd(int a, int b)
{
    return b == 0 ? a : gcd( b, a%b );
}

int main()
{
    int n;
    
    while ( scanf("%d",&n), n )
    {
        // Leemos cada caso de entrada
        vector< int > a;
        do {
            a.push_back( n );
        } while (scanf("%d",&n), n);
        
        // Calculamos el GCD
        int ans = 0;
        for (int i=1; i<a.size(); i++)
            ans = gcd( a[0]-a[i], ans );
        
        // Imprimimos la solucion
        printf("%d\n",abs(ans));
    }
    
    return 0;
}
