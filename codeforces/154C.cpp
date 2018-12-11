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



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll cnt=0;

    int n,m; cin>>n>>m;

    vector<vi> AdjLst1(n,vi()),AdjLst2(n,vi());

    for(int i=0;i<n;i++) AdjLst1[i].pb(i);

    for(int i=0;i<m;i++){

        int u,v; cin>>u>>v;
        u--,v--;
        AdjLst1[u].pb(v);
        AdjLst1[v].pb(u);
        AdjLst2[u].pb(v);
        AdjLst2[v].pb(u);
    }

    for(int i=0;i<n;i++){
        sortv(AdjLst1[i]);
        sortv(AdjLst2[i]);
    }

    sortv(AdjLst1);
    sortv(AdjLst2);

    ll temp=1;

    for(int i=1;i<n;){

        bool flag=true;

        if(AdjLst1[i].size()==AdjLst1[i-1].size()){
            for(int j=0;j<AdjLst1[i].size();j++){
                if(AdjLst1[i][j]!=AdjLst1[i-1][j]){
                    flag=false;
                    break;
                }
            }
        }
        else flag=false;

        i++;

        if(flag) temp++;
        else{

            cnt+=((temp-1)*temp)/2;

            temp=1;

        }

        if(i==n){
            if(flag){
                cnt+=((temp-1)*temp)/2;
            }
        }

    }

    temp=1;

    for(int i=1;i<n;){

        bool flag=true;

        if(AdjLst2[i].size()==AdjLst2[i-1].size()){
            for(int j=0;j<AdjLst2[i].size();j++){
                if(AdjLst2[i][j]!=AdjLst2[i-1][j]){
                    flag=false;
                    break;
                }
            }
        }
        else flag=false;

        i++;

        if(flag) temp++;
        else{

            cnt+=((temp-1)*temp)/2;

            temp=1;

        }

        if(i==n){
            if(flag){
                cnt+=((temp-1)*temp)/2;
            }
        }

    }


    cout<<cnt<<endl;


    return 0;
}
