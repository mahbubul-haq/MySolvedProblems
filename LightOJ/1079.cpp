#include <iostream>
#include <vector>
using namespace std;

int main(){

    int t; cin>>t;

    for(int i=1;i<=t;i++){
        cout<<"Case "<<i<<": ";

        double prob;
        int n,maxn=0; cin>>prob>>n;
        vector<pair<double,int> > vec;
        for(int j=1;j<=n;j++){
            int val;
            double probs;
            cin>>val>>probs;
            vec.push_back({probs,val});
            maxn+=vec[j-1].second;
        }

        double dp[n+1][maxn+1];
        for(int j=0;j<=n;j++){
            for(int k=0;k<=maxn;k++){
                dp[j][k]=1;
            }
        }
        dp[n][0]=0;

        for(int j=n-1;j>=0;j--){
            for(int k=0;k<=maxn;k++){
                dp[j][k]=dp[j+1][k];
                if(k-vec[j].second>=0){
                    dp[j][k]=min(dp[j][k],dp[j+1][k-vec[j].second]+(1-dp[j+1][k-vec[j].second])*vec[j].first);
                }
            }
        }

        int ans=0;
        for(int i=0;i<=maxn;i++){
            if(dp[0][i]<prob) ans=i;
        }
        cout<<ans<<endl;

    }

    return 0;
}
