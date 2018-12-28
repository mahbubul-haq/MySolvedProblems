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

map<int,int> myMap;
vector< vi > AdjLst;
vector<bool> visited,visited1;
int n,m,id,maxi;

void dfs1(int u,int dist){
    int siz=AdjLst[u].size();


    visited1[u]=true;
    for(int i=0;i<siz;i++){
        int v=AdjLst[u][i];

        if(!visited1[v]){
            dfs1(v,dist+1);
        }
    }

    if(dist>maxi){
        maxi=dist;
        id=u;
    }
}


int dfs(int u){
    visited[u]=true;
    int siz=AdjLst[u].size();
    int temp=0;

    for(int i=0;i<siz;i++){
        int v=AdjLst[u][i];
        if(!visited[v]){
            temp=max(dfs(v)+1,temp);
        }
    }
    myMap[temp]=u;
    return temp;


}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;

    AdjLst.assign(n+1,vi());
    visited.assign(n+1,false);

    for(int i=0;i<m;i++){
        int u,v; cin>>u>>v;
        AdjLst[u].pb(v);
        AdjLst[v].pb(u);
    }

    if(n==1){
        cout<<0<<endl;
        return 0;
    }

    vii CC;

    int CCcount=0;

    for(int i=1;i<=n;i++){
        if(!visited[i]){
            visited1.assign(n+1,false);
            maxi=-1;
            dfs1(i,0);

            myMap.clear();
            int dim=dfs(id);

            CC.pb(pii(dim,myMap[dim/2]));
        }
    }

    sortv(CC);
    int siz=CC.size();

    if(CC.size()==1){
        cout<<CC[0].first<<endl;
    }
    else{
        int dim1=CC[siz-1].first,dim2=CC[siz-2].first,dim3=0;

        if(dim2&1){
            dim2=dim2/2+1;
        }
        else dim2=dim2/2;
        dim2++;

        if(siz>=3){
            dim3=CC[siz-3].first;
        }

        if(dim3&1){
            dim3=dim3/2+1;
        }
        else dim3/=2;
        dim3++;

        if(dim1==0){
            if(n>2) cout<<2<<endl;
            else cout<<1<<endl;
        }
        else if(dim1&1){
            cout<<max(dim1,max(dim1/2+dim2+1,dim2+dim3))<<endl;
        }
        else cout<<max(max(dim1,dim1/2+dim2),dim3+dim2)<<endl;

        for(int i=0;i<siz-1;i++){
            cout<<CC[siz-1].second<<" "<<CC[i].second<<endl;
        }

    }


    return 0;
}
