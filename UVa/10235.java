import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main( String [] args) {

       Scanner scanner=new Scanner(System.in);

       int n;

       while(scanner.hasNext()) {
           n=scanner.nextInt();
           String str = new StringBuffer(String.valueOf(n)).reverse().toString();
           int x = (int) Integer.valueOf(str);

           BigInteger an = BigInteger.valueOf(n);
           BigInteger ax = BigInteger.valueOf(x);

           System.out.print(an + " is ");

           if (!an.isProbablePrime(20)) {
               System.out.println("not prime.");
           } else if (!an.equals(ax) && ax.isProbablePrime(10)) {
               System.out.println("emirp.");
           } else System.out.println("prime.");
       }

    }

}
