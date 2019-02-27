#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> vec){
    fof(i,0,vec.size()) cout<<vec[i]<<" "; cout<<endl;
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

#define K 25

class SparseTable{
    vector<vll> st;
    vi log;
public:
    SparseTable(vi ara){
        int n=ara.size();
        log.resize(n+5);
        log[1]=0;
        for(int i=2;i<=n;i++){
            log[i]=log[i/2]+1;
        }

        st.resize(n+5);

        fof(i,0,n){
            st[i].resize(K);
            st[i][0]=ara[i];
        }

        fof(j,1,K+1){
            for(int i=0;i+(1<<j)<=n;i++){
                st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
            }
        }
    }

    ll rmq(int L,int R){
        int j=log[R-L+1];
        return min(st[L][j],st[R-(1<<j)+1][j]);
    }

};

map<int,vector<int> > map1;
ll dp[100005];
int n;

ll ret(int id,int now1,int now2){
    if(id==n+1) return 0;
    if(dp[id]!=-1){
        return dp[id];
    }

    ll val1=abs(map1[id][0]-now1)+abs(map1[id][1]-now2)+ret(id+1,map1[id][0],map1[id][1]);
    ll val2=abs(map1[id][1]-now1)+abs(map1[id][0]-now2)+ret(id+1,map1[id][1],map1[id][0]);

    return dp[id]=min(val1,val2);
}

int main()
{
    //FI;FO;
    FASTIO;
    mem(dp,-1);

    cin>>n;

    fof(i,1,2*n+1){
        int x; cin>>x;
        map1[x].pb(i);
    }

    ll dis=0;
    int now=1;

    cout<<ret(1,1,1)<<endl;

    return 0;
}
