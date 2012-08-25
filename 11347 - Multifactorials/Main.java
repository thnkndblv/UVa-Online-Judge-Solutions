import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.BigInteger;

class Main
{
    final int MAXN = 1024;
    BitSet criba = new BitSet( MAXN );
    List< Integer > primo = new ArrayList< Integer >();
    void sieve()
    {
        criba.set( 0, MAXN );
        criba.set( 0, false );
        criba.set( 1, false );
        for (int i=2; i<MAXN; i++)
            if ( criba.get(i) )
            {
                primo.add( i );
                for (int j=i<<1; j<MAXN; j+=i)
                    criba.set( j, false );
            }
    }
    
    void factoriza(int n, Map<Integer, Integer> f)
    {
        for (int i=0; i<primo.size(); i++)
        {
            if ( n == 1 ) break;
            int cnt = f.containsKey(primo.get(i)) ? f.get(primo.get(i)) : 0;
            while ( n % primo.get(i) == 0 )
            {
                n /= primo.get(i);
                cnt++;
            }
            if (cnt != 0) f.put( primo.get(i), cnt );
        }
        if ( n != 1 )
        {
            int cnt = f.containsKey( n ) ? f.get(n) : 0;
            cnt++;
            f.put( n, cnt );
        }
    }
    
    Main()
    {
        Scanner sc = new Scanner( System.in );
        sieve();
        
        int test = sc.nextInt();
        for (int caso=1; caso<=test; caso++)
        {
            String str = sc.next();
            int m = 0;
            for (int i=str.length()-1; i>=0; i--, m++)
                if ( str.charAt(i) != '!' ) break;
            int n = Integer.valueOf( str.substring( 0, str.length()-m ) );
            Map< Integer, Integer > f = new TreeMap< Integer, Integer >();
            for (int i=n; i>1; i-=m)
            {
                factoriza(i, f);
            }
            Iterator it = f.entrySet().iterator();
            BigInteger divisores = BigInteger.ONE;
            while ( it.hasNext() )
            {
                Map.Entry pair = (Map.Entry)it.next();
                //System.out.println( pair.getKey()+" ^ "+pair.getValue() );
                int e = Integer.parseInt(pair.getValue()+"");
                divisores = divisores.multiply( BigInteger.valueOf( e+1 ) );
            }
            if ( divisores.compareTo( BigInteger.TEN.pow(18) ) > 0 )
                System.out.println( "Case " + caso + ": Infinity" );
            else System.out.println( "Case " + caso + ": " + divisores );
        }
    }
    
    public static void main(String[] args)
    {
        new Main();
    }
}
