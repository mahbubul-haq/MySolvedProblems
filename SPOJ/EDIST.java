import java.util.Scanner;

public class Main {

    static int [][]dp=new int[2001][2001];
    static Scanner sc=new Scanner(System.in);
    static String a,b;

    public static void main(String[] args) {

        int t;
        t=sc.nextInt();
        while(t>0){
            t--;
            a=sc.next();
            b=sc.next();
            int n=a.length();
            int m=b.length();

            for(int i=0;i<=m;i++)
                dp[i][0]=i;
            for(int i=0;i<=n;i++)
                dp[0][i]=i;
            for(int i=0;i<m;i++)
                for(int j=0;j<n;j++){
                    if(b.charAt(i)==a.charAt(j))
                        dp[i+1][j+1]=dp[i][j];
                    else{
                        dp[i+1][j+1]=1+Integer.min(dp[i+1][j],Integer.min(dp[i][j],dp[i][j+1]));
                    }
                }


            System.out.println(dp[m][n]);

        }

    }
}
