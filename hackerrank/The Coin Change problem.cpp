#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define vi vector<int>

vi coin;
ll dp[55][255];
int n,m;

ll isposs(int i,int amount)
{
	if(i>=m)
	{
		if(amount ==0)
			return 1;
		else return 0;
	}
	if(dp[i][amount]!=-1)
		return dp[i][amount];
	ll ret1=0,ret2=0;
	if(amount-coin[i]>=0) ret1=isposs(i,amount-coin[i]);
	ret2=isposs(i+1,amount);

	return dp[i][amount]=ret1+ret2;

}

int main()
{
    cin>>n>>m;
    memset(dp,-1,sizeof dp);

    for(int i=0;i<m;i++){
        int val; cin>>val;
        coin.pb(val);
    }

    cout<<isposs(0,n)<<endl;

	return 0;
}
