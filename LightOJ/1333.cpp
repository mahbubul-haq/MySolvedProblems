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
#define INF                         100000
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
template<class T> void print(vector<T> &vec){
    for(int i=1;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
}
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

///=======================================template=======================================//
#define mod 1000000000

ll bigmod(ll a,int b){
    ll temp=1;
    a%=mod;

    while(b){
        if(b&1) temp=(temp*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return temp;
}

int main()
{
    //FI;FO;
    FastIO;

    int t; cin>>t;

    for(int i=0;i<t;i++){
        cout<<"Case "<<i+1<<": ";
        int m,n,k,b; cin>>m>>n>>k>>b;

        vii vec;

        for(int j=0;j<b;j++){
            int u,v; cin>>u>>v;
            vec.pb(mp(v,u));
        }

        sortv(vec);

        unordered_map<int,bool>mapp;
        int cnt=0;

        ll ans=1;
        int lastid=0;
        int lastcol=-1;
        for(int j=0;j<b;j++){
            if(lastcol==-1){
                lastcol=vec[j].ff;
                if(mapp[lastcol]==0){
                    cnt++;
                    mapp[lastcol]=1;
                }
                lastid=vec[j].ss;
                if(lastid>1){
                    ans=(((ans*k)%mod)*bigmod(k-1,lastid-1-1))%mod;
                }
            }
            else if(vec[j].ff==lastcol){
                if(vec[j].ss-lastid>1){
                    ans=(((ans*k)%mod)*bigmod(k-1,vec[j].ss-lastid-1-1))%mod;
                }
                lastcol=vec[j].ff;
                lastid=vec[j].ss;
                if(mapp[lastcol]==0){
                    cnt++;
                    mapp[lastcol]=1;
                }
            }
            else{
                if(m-lastid>0){
                    ans=(((ans*k)%mod)*bigmod(k-1,m-lastid-1))%mod;
                }

                lastcol=vec[j].ff;
                lastid=vec[j].ss;
                if(lastid>1){
                    ans=(((ans*k)%mod)*bigmod(k-1,lastid-1-1))%mod;
                }

                if(mapp[lastcol]==0){
                    cnt++;
                    mapp[lastcol]=1;
                }
            }
        }

        if(lastid!=0 and m-lastid>0){
            ans=(((ans*k)%mod)*bigmod(k-1,m-lastid-1))%mod;
        }

        ll temp=1;

        temp=(k*bigmod(k-1,m-1))%mod;
        if(n-cnt>0) {
            temp = bigmod(temp, n - cnt);
            ans = (ans * temp) % mod;

        }
        cout << ans << endl;

    }

    return 0;
}
