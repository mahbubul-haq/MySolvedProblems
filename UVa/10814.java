import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main( String [] args) {

       Scanner scanner=new Scanner(System.in);

       int n; n=scanner.nextInt();

       for(int i=0;i<n;i++){

           BigInteger p=scanner.nextBigInteger();
          // System.out.println(p);
           scanner.next();
           BigInteger q=scanner.nextBigInteger();
           //System.out.println(q);

           BigInteger gcd=p.gcd(q);

           System.out.println(p.divide(gcd)+ " / "+q.divide(gcd));

       }

    }

}
