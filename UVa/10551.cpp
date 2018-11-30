import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main( String [] args) {

        Scanner scanner = new Scanner(System.in);

        while(true){
            BigInteger b=scanner.nextBigInteger();

            if(b.intValue()==0) return;

            BigInteger p=new BigInteger(scanner.next(),b.intValue());
            BigInteger m=new BigInteger(scanner.next(),b.intValue());

            BigInteger ans=p.mod(m);

            System.out.println(ans.toString(b.intValue()));

        }

    }

}
