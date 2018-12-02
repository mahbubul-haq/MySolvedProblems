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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n,k; cin>>n>>k;
    map<int,int>myMap;
    int a[n+1];
    int b[n+1];
    int cnt=0;

    vector<vi> AdjLst(k+1,vi());


    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++) cin>>b[i];


    for(int i=1;i<=n;i++){
        AdjLst[a[i]].pb(b[i]);
    }
    vi ans;

    for(int i=1;i<=k;i++){
        if(AdjLst[i].size()==0){
            cnt++;
        }
        else{
            sort(AdjLst[i].begin(),AdjLst[i].end());
            int siz=AdjLst[i].size();

            for(int ii=0;ii<siz-1;ii++){
                ans.pb(AdjLst[i][ii]);
            }
        }
    }
    sort(ans.begin(),ans.end());

    ll output=0;

    for(int i=0;i<cnt;i++){
        output+=ans[i];
    }
    cout<<output<<endl;

    return 0;
}
