#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define endl                        "\n"
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         1e18
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define timeTaken                   endd=clock();cout<<(double)(endd-beginn)/CLOCKS_PER_SEC*1000<<endl
#define timeInit                    clock_t beginn=clock(),endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vpll                        vector<pll>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator
*/

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

//template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

vll fact,factinv;

ll bigmod(ll a,int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po =po* a%MOD;
        a =a*a%MOD;
        b >>= 1;
    }
    return po;
}

ll nCr(int i,int j){
    return (fact[i]*factinv[i-j]%MOD)*factinv[j]%MOD;
}

void z_func(string &text,vi &Z){
    int n=siz(text);
    Z.resize(n);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r)
            Z[i]=min(Z[i-l],r-i+1);
        while(i+Z[i]<n and text[Z[i]]==text[i+Z[i]])
            Z[i]++;
        if(i+Z[i]-1>r)
            l=i,r=i+Z[i]-1;
    }
}

void solve(){

    int n,q;
    cin>>n>>q;
    string s;
    cin>>s;
    vll cnt2(n+1);
    vll ans(n+1);
    for(int i=0;i<n;i++){
        string sub=s.substr(i,n-i);
        //reverse(sub.begin(),sub.end());
        vi Z;
        z_func(sub,Z);
        vi cnt(n+1);
        for(auto v:Z){
            cnt[0]++;
            cnt[v+1]--;
        }

        //cnt[0]++;

        for(int j=1;j<=n;j++){
            cnt[j]+=cnt[j-1];
            cnt2[cnt[j]]++;
        }

        ans[1]+=n-i;
    }

    ///for(int j=n-1;j>0;j--)
       // cnt2[j]-=cnt2[j+1];


    //for(int i=1;i<=n;i++)
        //cout<<cnt2[i]<<" ";cout<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            ans[j+1]+=(cnt2[i]*nCr(i,j))%MOD;
            ans[j+1]%=MOD;
        }
    }

    while(q--){
        int k; cin>>k;
        if(k>n) cout<<0<<endl;
        else
            cout<<ans[k]<<endl;
    }
}

int main()
{
    //FI;//FO;
    //FastIO;//timeInit;
    fact.resize(5001),factinv.resize(5001);
    fact[0]=1;
    for(int i=1;i<=5000;i++){
        fact[i]=fact[i-1]*i%MOD;
    }

    factinv[5000]=bigmod(fact[5000],MOD-2);
    for(int i=5000-1;i>=0;i--)
        factinv[i]=factinv[i+1]*(i+1)%MOD;

    int t; cin>>t;
    while(t--)
        solve();

    //timeTaken;
    return 0;
}
