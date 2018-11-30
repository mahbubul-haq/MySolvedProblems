import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main( String [] args) {

        int n,f;
        Scanner scanner=new Scanner(System.in);
        int x=0;

        while(true){
            x++;
            n=scanner.nextInt();
            f=scanner.nextInt();

            if(f==0&&n==0 ) break;

            BigInteger totalcost= BigInteger.ZERO;

            for(int i=1;i<=n;i++){
                BigInteger v=scanner.nextBigInteger();
                totalcost=totalcost.add(v);
            }

            BigInteger ans=totalcost.divide(BigInteger.valueOf(f));
            System.out.println("Bill #"+x+" costs "+totalcost+": each friend should pay "+ans);
            System.out.println();

        }

    }

}
