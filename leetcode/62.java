import java.math.BigInteger;

class Solution {
    public int uniquePaths(int m, int n) {
        
        BigInteger M=BigInteger.ONE;
        n--;
        m--;
        
        int maxi= (n>m)? n:m;
        int mini=(n>m)? m:n;
        
        for(int i=maxi+1;i<=n+m;i++)
            M=M.multiply(BigInteger.valueOf(i));
        
        for(int i=1;i<=mini;i++)
            M=M.divide(BigInteger.valueOf(i));
        
        return M.intValue();    
        
    }
}
