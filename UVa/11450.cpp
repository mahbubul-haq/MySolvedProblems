#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
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

int dp[21][201];
int m,c;
vector< vi > AdjLst;

int ret(int id,int val){
    if(id==c+1){
        if(val<=m) return val;
        else return -500;
    }

    if(dp[id][val]!=-1) return dp[id][val];

    int siz=AdjLst[id].size();
    int val1=0;

    for(int i=0;i<siz;i++){
        if(val+AdjLst[id][i]<=m) {
            val1 = max(val1, ret(id + 1, val+AdjLst[id][i]));
        }
    }

    return dp[id][val]=val1;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin>>t;

    while(t--){
        cin>>m>>c;
        mem(dp,-1);
        AdjLst.assign(c+1,vi());

        for(int i=0;i<c;i++){
            int k;cin>>k;

            for(int j=0;j<k;j++){
                int price; cin>>price; AdjLst[i+1].pb(price);
            }
        }

        if(ret(1,0)>0){
            cout<<ret(1,0)<<endl;
        }else cout<<"no solution"<<endl;


    }

    return 0;
}
