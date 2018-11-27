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

int AdjLst[20][20];
ll dp[1<<19][19];
int n,m,k;
ll ara[20];

ll max_sat(int mask,int id){

    if(id!=-1)
        if(dp[mask][id]!=-1) return dp[mask][id];

    int cnt=0;
    ff(i,0,n-1){
        if(check(mask,i)) cnt++;
    }
    if(cnt>=m) return dp[mask][id]=0;
    ll val=0;
    ff(i,0,n-1){
        if(!check(mask,i)){

            int tempmask=Set(mask,i);

            if(id==-1)
                val=max(val,ara[i]+max_sat(tempmask,i));
            else{
                val=max(val,ara[i]+AdjLst[id][i]+max_sat(tempmask,i));
            }


        }
    }

    if(id==-1) return val;
    else return dp[mask][id]=val;



}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    mem(dp,-1);


    cin>>n>>m>>k;


    ff(i,0,n-1) cin>>ara[i];

    ff(i,1,k){
        int u,v,w;
        cin>>u>>v>>w;
        u--,v--;
        AdjLst[u][v]=w;
    }

    int mask=0;

    cout<<max_sat(mask,-1)<<endl;

    return 0;
}
