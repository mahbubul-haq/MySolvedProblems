import java.math.BigInteger;
import java.util.*;

public class Main{

	static BigInteger one=BigInteger.ONE;
	static int n;
	static BigInteger ii,lcm;

	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		int t=sc.nextInt();

		for(int i=1;i<=t;i++){
			System.out.print("Case "+i+": ");
			
			n=sc.nextInt();

			lcm=one;
			

			for(int j=1;j<=n;j++){
			
				ii=sc.nextBigInteger();

				lcm=lcm.multiply(ii).divide(lcm.gcd(ii));

			}
			System.out.println(lcm); System.gc();
		}
	}
}
