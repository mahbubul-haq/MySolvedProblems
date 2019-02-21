import java.util.Scanner;
import java.math.BigInteger;
import java.io.*;

public class Main {

    static int n,k;
    static BigInteger[][][] dp=new BigInteger[104][104][2];

    static BigInteger ret(int id,int k1,int isPos){
        if(!dp[id][k1][isPos].equals(BigInteger.valueOf(-1))) return dp[id][k1][isPos];
        if(id>=n-1){
            if(isPos==1){
                return BigInteger.valueOf(2);
            }
            else if(k1+1==k){
                return BigInteger.ONE;
            }
            else return BigInteger.ZERO;
        }

        BigInteger val1,val2;

        //System.out.println(k+" "+n+ " "+isPos);

        val1=ret(id+1,k1+1,Integer.max((k1+1)>=k?1:0,isPos));
        val2=ret(id+1,0,isPos);

        //BigInteger x=val1.add(val2);
        return dp[id][k1][isPos]=val1.add(val2);

    }

    public static void main(String[] args) throws Exception{

        Scanner sc=new Scanner(System.in);

        //File file=new File("inout.txt");
        //Scanner sc=new Scanner(file);

        try {
            while (sc.hasNextInt()) {
                n = sc.nextInt();
                k = sc.nextInt();

                if(n==1){
                    System.out.println(1);
                    continue;
                }

                //Arrays.fill(dp,BigInteger.valueOf(-1));

                for (int i = 0; i < 104; i++) {
                    for (int j = 0; j < 104; j++) {
                        for (int kk = 0; kk < 2; kk++) {
                            dp[i][j][kk] = BigInteger.valueOf(-1);
                        }
                    }
                }


                System.out.println(ret(1, 1, (k == 1) ? 1 : 0).add(ret(1, 0, 0)));

            }
        }
        finally {
            sc.close();
        }
    }
}
