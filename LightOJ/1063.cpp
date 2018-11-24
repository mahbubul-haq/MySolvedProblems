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
vector<bool> artBridges,visited;
vi parent, dfs_num,dfs_low;
int times=0,numOfChildren=0,dfsRoot;

void artBridge(int u){
    dfs_num[u]=dfs_low[u]=++times;

    int siz=AdjLst[u].size();

    ff(i,0,siz-1){
        int v=AdjLst[u][i];
        if(!visited[v]){

            parent[v]=u;
            visited[v]=true;

            if(u==dfsRoot) numOfChildren++;

            artBridge(v);

            if(dfs_low[v]>=dfs_num[u]){
                artBridges[u]=true;
            }

            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(v!=parent[u]) dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin>>t;

    ff(i,1,t){
        int n,m;
        cin>>n>>m;
        AdjLst.assign(n+1,vi());

        ff(j,1,m){
            int u,v;
            cin>>u>>v;
            AdjLst[u].pb(v);
            AdjLst[v].pb(u);
        }
        times=0;numOfChildren=0;
        dfsRoot=1;
        parent.assign(n+1,-1);
        visited.assign(n+1,false);
        dfs_low.assign(n+1,INT_MAX);
        dfs_num.assign(n+1,INT_MAX);
        artBridges.assign(n+1,false);
        visited[1]=true;
        artBridge(1);

        artBridges[1]=(numOfChildren>1);
        int cnt=0;

      //  cout<<numOfChildren<<endl;

        ff(j,1,n) {
            if(artBridges[j]) {
                cnt++;
              //  cout<<j<<endl;
            }

        }

        cout<<"Case "<<i<<": "<<cnt<<endl;

    }

    return 0;
}
