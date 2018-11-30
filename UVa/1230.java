import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main( String [] args) {

       Scanner scanner=new Scanner(System.in);

       int n; n=scanner.nextInt();

       for(int i=0;i<n;i++){

          BigInteger x=scanner.nextBigInteger();
          BigInteger y=scanner.nextBigInteger();
          BigInteger m=scanner.nextBigInteger();

           System.out.println(x.modPow(y,m));

       }
       scanner.nextInt();

    }

}
