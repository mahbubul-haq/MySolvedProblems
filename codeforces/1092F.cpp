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

class SegmentTree{
    vector<multiset<int> > st;
    vi ara;
    int n;

    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}

    void build(int node,int L,int R){
        if(L==R){
            st[node].insert(ara[L]);
        }
        else{
            build(left(node),L,(L+R)/2);
            build(right(node),(L+R)/2+1,R);
            st[node].insert(st[left(node)].begin(),st[left(node)].end());
            st[node].insert(st[right(node)].begin(),st[right(node)].end());
        }

    }

public:
    SegmentTree(vi _ara){
        ara=_ara;
        n=ara.size();
        st.assign(4*n,multiset<int>());
        build(1,0,n-1);
    }
};

int n;
int ara[200001];
vector<vi> AdjLst;
ll ansarr[200001];
ll ans;

ll dfs1(int u,ll layer,int parent){
    ans+=layer*ara[u];

    for(auto v:AdjLst[u]){
        if(parent!=v){
            ansarr[u]+=dfs1(v,layer+1,u);
        }
    }
    return ansarr[u]+=ara[u];
}

void dfs2(int u,int parent,ll cur){
    for(auto v:AdjLst[u]){
        if(v!=parent){
            ll temp=cur-ansarr[v]+(ansarr[1]-ansarr[v]);
            ans=max(ans,temp);
            dfs2(v,u,temp);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    AdjLst.assign(n+1,vi());
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    for(int i=0;i<n-1;i++){
        int u,v; cin>>u>>v;
        AdjLst[u].pb(v);
        AdjLst[v].pb(u);
    }

    dfs1(1,0,-1);
    dfs2(1,-1,ans);
    cout<<ans<<endl;

    return 0;
}
