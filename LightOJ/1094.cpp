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

vector<vii> AdjLst;
ll maxi=-1;
int idx=-1;
vector<bool> visited;

void dfs1(int id,ll cost){
    visited[id]=true;

    int siz=AdjLst[id].size();
    bool flag=false;
    for(int i=0;i<siz;i++){
        int v=AdjLst[id][i].first;
        if(!visited[v]){

            dfs1(v,AdjLst[id][i].second+cost);
            flag=true;

        }
    }
    if(!flag){
        if(maxi<cost){
            idx=id;
            maxi=cost;
        }
    }

}

ll dfs2(int u,ll cost){
    visited[u]=true;
    int siz=AdjLst[u].size();
    ll temp=cost;
    for(int i=0;i<siz;i++){
        pii v=AdjLst[u][i];

        if(!visited[v.first]){
            temp=max(temp,dfs2(v.first,cost+v.second));
        }

    }
    return temp;
}


int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; scanf("%d",&T);
    for(int cas=0;cas<T;cas++){
        int n; scanf("%d",&n);
        AdjLst.assign(n,vii());
        visited.assign(n,false);

        for(int i=0;i<n-1;i++){
            int u,v,k; scanf("%d%d%d",&u,&v,&k);
            AdjLst[u].pb(pii(v,k));
            AdjLst[v].pb(pii(u,k));

        }
        maxi=-1;
        idx=-1;

        dfs1(0,0);
        visited.assign(n,false);


        printf("Case %d: %lld\n",cas+1,dfs2(idx,0));
    }

    return 0;
}
