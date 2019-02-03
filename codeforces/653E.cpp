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
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
//#define FIFO
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(x,y) for(int i=x;i<(int)y;i++)
#define fob(x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
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
set<int> remaining;
map<pii, bool> forbidden;

void dfs(int u){

    vi ans;
   remaining.erase(u);

    auto it=remaining.begin();

    while(it!=remaining.end()){
        int mini=min(u,*it);
        int maxi=max(u,*it);

        if(!forbidden[pii(mini,maxi)]){
            ans.pb(*it);
        }

        it++;
    }

    for(int i=0;i<ans.size();i++) remaining.erase(ans[i]);

    for(int i=0;i<ans.size();i++) dfs(ans[i]);
}

int main()
{
#ifdef FIFO
    FI;
    FO;
#endif
    FASTIO;

    int n,m,k;

    cin>>n>>m>>k;
    int d=n-1;

    for(int i=2;i<=n;i++) remaining.insert(i);

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        pii x=mp(min(u,v),max(u,v));

        forbidden[x]=true;
        if(x.first==1) d--;
    }


    int cc=0;

    for(int i=2;i<=n;i++){
        if(remaining.find(i)!=remaining.end()){
            pii x=mp(1,i);
            if(!forbidden[x]){
                dfs(i);
                cc++;
            }
        }
    }

    if(!remaining.empty()){
        cout<<"impossible"<<endl;
        return 0;
    }
    if(cc>k||d<k){
        cout<<"impossible"<<endl;
        return 0;
    }

    cout<<"possible"<<endl;

    return 0;
}
