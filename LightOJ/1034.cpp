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
#define MAX 4e18
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

vector< vi > AdjLst;
vi toposort;
vector<bool> visited;

void dfs(int u){

    int siz=AdjLst[u].size();
    visited[u]=true;

    ff(i,0,siz-1){
        int v=AdjLst[u][i];
        if(!visited[v]){
            visited[v]=true;
            dfs(v);
        }
    }
    toposort.push_back(u);

}

void dfs1(int u){

    int siz=AdjLst[u].size();
    visited[u]=true;

    ff(i,0,siz-1){
        int v=AdjLst[u][i];
        if(!visited[v]){
            visited[v]=true;
            dfs1(v);
        }
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;

    ff(i,1,T){
        int n,m; cin>>n>>m;

        AdjLst.assign(n+1,vi());
        visited.assign(n+1,false);

        ff(j,1,m){
            int u,v; cin>>u>>v;
            AdjLst[u].pb(v);
        }

        ff(j,1,n){
            if(!visited[j]){

                dfs(j);
            }
        }

        visited.assign(n+1,false);

        int siz=toposort.size();
        int cnt=0;
        fb(j,siz-1,0){
            if(!visited[toposort[j]]){
                cnt++;
                dfs1(toposort[j]);
            }
        }

        cout<<"Case "<<i<<": "<<cnt<<endl;

        toposort.clear();
    }

    return 0;
}

