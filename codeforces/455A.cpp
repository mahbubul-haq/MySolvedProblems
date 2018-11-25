#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<long,long>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 1000000007
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define MAX 4e18
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};
int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

int n;
vll ara;
ll dp[100005];
int cnt[100005];

ll ret(int id,int lasttaken){
    if(id>=n) return 0;

   // cout<<id<<" "<<dp[id]<<endl;

    if (lasttaken!=ara[id])
        if(dp[ara[id]]!=-1) return dp[ara[id]];


    ll val1,val2;

   /// cout<<lasttaken<<" "<<ara[id]<<" "<<id<<endl;

    if(lasttaken==ara[id])
    {
        ret(id+1,lasttaken);
    }
    else{
        ///int temp=lasttaken;
       // cout<<"Lt"<<lasttaken<<" ";
        val2=ret(id+1,lasttaken);
       // cout<<lasttaken<<endl;
        val1=ret(id+1,ara[id]+1)+(ll)cnt[ara[id]]*ara[id];

        return dp[ara[id]]=max(val1,val2);
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
    mem(dp,-1);

    ff(i,1,n){
        int x;
        cin>>x;
        cnt[x]++;

    }

    ff(i,1,100001) if(cnt[i]!=0) ara.pb((ll)i);

    n=(int)ara.size();

  //  cout<<n<<endl;


    cout<<ret(0,-1)<<endl;

    return 0;
}
