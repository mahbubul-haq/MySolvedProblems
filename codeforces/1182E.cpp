#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         1000000000
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

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
template<class T> ll power(T a,int b){
    ll po=1; while(b--) po*=a; return po;
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

ll n1,c;
ll f[4];

ll dp[10];
ll F[3];

ll bigmod(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%MOD;
        a=(a*a)%MOD;
        b>>=1;
    }
    return res;
}

ll rec(int n){
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=(bigmod(c,2*n-6)*rec(n-1)%MOD)*(rec(n-2)*rec(n-3)%MOD)%MOD;
}

void multiply(ll mata[3][3],ll matb[3][3]){
    ll res[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res[i][j]=0;
            for(int k=0;k<3;k++){
                res[i][j]=(res[i][j]+mata[i][k]*matb[k][j]%(MOD-1))%(MOD-1);
            }
        }
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++)
            mata[i][j]=res[i][j];
    }
}

ll power(ll mata[3][3],ll n){
    ll mul[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    while(n){
        if(n&1)
            multiply(mul,mata);
        multiply(mata,mata);
        n>>=1;
    }
    return (mul[0][0]*F[2]%(MOD-1)+mul[0][1]*F[1]%(MOD-1)+mul[0][2]*F[0]%(MOD-1))%(MOD-1);
}

int main()
{
    //FI;FO;
    FastIO;

    cin>>n1;

    mem(dp,-1);
    for(int i=0;i<3;i++) {
        cin>>f[i+1];
        dp[i+1]=f[i+1];
    }
    cin>>c;

    if(n1<7){
        cout<<rec(n1)<<endl;
    }
    else{
        ll ans=1;
        F[0]=6,F[1]=11,F[2]=20;
        ll mat[3][3]={{1,1,1},{1,0,0},{0,1,0}};
        //cout<<power(mat,n1-4-2)<<endl;
        ans=(ans*bigmod(c,power(mat,n1-4-2)))%MOD;

        ll matb[3][3]={{1,1,1},{1,0,0},{0,1,0}};
        F[0]=1,F[1]=1,F[2]=2;
        ans=(ans*bigmod(f[1],power(matb,n1-4-2)))%MOD;

        ll matc[3][3]={{1,1,1},{1,0,0},{0,1,0}};
        F[0]=1,F[1]=2,F[2]=3;
        ans=(ans*bigmod(f[2],power(matc,n1-4-2)))%MOD;

        ll matd[3][3]={{1,1,1},{1,0,0},{0,1,0}};
        F[0]=1,F[1]=2,F[2]=4;
        ans=(ans*bigmod(f[3],power(matd,n1-4-2)))%MOD;

        ans=(ans*bigmod(bigmod(c,MOD-2),n1))%MOD;
        cout<<ans<<endl;
    }

    return 0;
}
