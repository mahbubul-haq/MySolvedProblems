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
#define INF 1e9
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define debugx(x) cout<<"WTH! "<<x<<endl
#define debug(x,y) cout<<x<<" "<<y<<endl

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
int n,s,w;
vector<vi> AdjLst;
vi dp;
bool flag=false;

int ret(int line){
    if(line>=n+1) return 0;

    if(dp[line]!=-1){
        return dp[line];
    }
    int temps=s;

    int cnt=0;
    bool taken[101]; mem(taken,false);

    int val=INT_MAX;

    temps--;
    for(int i=0;i<(int)AdjLst[line].size();i++){
        if(!taken[AdjLst[line][i]]){
                taken[AdjLst[line][i]]=true;
                temps--;
                cnt++;
            }
    }

    if(temps<0){
            flag=true; return 0;
    }

   ff(i,line+1,n+2){

       val=min(val,cnt+ret(i));

       temps--;
       for(int j=0;j<(int )AdjLst[i].size();j++){
            if(!taken[AdjLst[i][j]]){
                taken[AdjLst[i][j]]=true;
                temps--;
                cnt++;
            }
       }

       if(temps<0){
            break;
       }

   }

   return dp[line]=val;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;


    ff(cas,1,T){

        cout<<"Case "<<cas<<": ";


         cin>>n>>s>>w;
          dp.assign(n+5,-1);
        AdjLst.assign(n+5,vi());
        flag=false;

        ff(i,1,w){
            int k; cin>>k;
            ff(j,1,k){
                int u;cin>>u;
                AdjLst[u].pb(i);
            }
        }

        int x=ret(1);
        if(flag) cout<<"-1"<<endl;
        else cout<<x<<endl;
       // if(ret) cout<<ret(1)<<endl;


    }

    return 0;
}
