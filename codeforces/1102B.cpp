#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define MOD 998244353
#define EPS 1e17
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e18
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

ostream& operator<<(ostream &os,const pll &a){
    os<<a.first<<" "<<a.second;
}

pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k; cin>>n>>k;

    int ara[n+1];
    for(int i=1;i<=n;i++) cin>>ara[i];

    vector< vector<bool> > AdjLst;
    AdjLst.assign(5001,vector<bool>());
    for(int i=1;i<=5000;i++) AdjLst[i].assign(5001,false);

        vi ans;

    for(int i=1;i<=k;i++){
        AdjLst[ara[i]][i]=true;
        ara[i]=i;
    }

    for(int i=k+1;i<=n;i++){
        bool flag=false;
        for(int j=1;j<=k;j++){
            if(AdjLst[ara[i]][j]==false){
                AdjLst[ara[i]][j]=true;
                ara[i]=j;
                flag=true;
                break;
            }
        }

        if(!flag){
            cout<<"NO"<<endl;
            return 0;
        }

    }

    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++) cout<<ara[i]<<" ";
    cout<<endl;

    return 0;
}
