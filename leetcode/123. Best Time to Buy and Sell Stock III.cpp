class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, n = prices.size(), suff[n + 1];
        
        if (n < 2)
            return 0;
        
        memset(suff, 0, sizeof suff);
        int maxi = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suff[i + 1] = max(suff[i + 2], maxi - prices[i]);
            maxi = max(maxi, prices[i]);
        }
        
        ans = max(ans, suff[1]);
        
        maxi = prices[0];
        for (int i = 1; i < n - 1; i++) {
            int now = prices[i] - maxi;
            ans = max(ans, now + suff[i + 2]);
            maxi = min(maxi, prices[i]);
        }
        return ans;
    }
};
