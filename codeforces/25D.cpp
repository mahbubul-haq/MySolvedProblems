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

vii cutRoads;

class UnionFindDS{
    vector<int> rank,parent,setSize;
    int numOfSets;
public:
    UnionFindDS(int N){
        rank.assign(N,0);setSize.assign(N,1); numOfSets=N;
        parent.assign(N,0); for(int i=0;i<N;i++) parent[i]=i;
    }
    int findSet(int i){ return (parent[i]==i)? i:(parent[i]=findSet(parent[i]));}
    bool isSameSet(int i,int j){ return findSet(i)==findSet(j); }
    void unionSet(int i,int j){
        if(!isSameSet(i,j)){
            numOfSets--;
            int x=findSet(i),y=findSet(j);
            if(rank[x]>rank[y]) parent[y]=x,setSize[x]+=setSize[y];
            else{
                parent[x]=y; setSize[y]+=setSize[x];
                if(rank[x]==rank[y]) rank[y]++;
            }
        }
        else{ cutRoads.pb(pii(i,j));}
    }
    int numOfDisjointSets(){ return numOfSets;}
    int sizeOfSet(int i){ return setSize[findSet(i)]; }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;

    UnionFindDS ufds(n);

    for(int i=1;i<n;i++){

        int u,v; cin>>u>>v;
        u--,v--;

        ufds.unionSet(u,v);
    }

    cout<<ufds.numOfDisjointSets()-1<<endl;

    for(int i=1;i<n;i++){

        if(!ufds.isSameSet(i,i-1)){
            ufds.unionSet(i,i-1);
            cout<<cutRoads.back().first+1<<" "<<cutRoads.back().second+1<<" "<<i<<" "<<i+1<<endl;
            cutRoads.pop_back();
        }

    }

    return 0;
}
