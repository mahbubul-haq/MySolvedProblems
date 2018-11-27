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

vector< vi > AdjLst,SCC;
vi dfs_num,dfs_low,Stack;
vector<bool> visited;
int V,E,dfs_times;

void tarjan_SCC(int u){
    dfs_num[u]=dfs_low[u]=++dfs_times;
    int siz=AdjLst[u].size();

    visited[u]=true;
    Stack.push_back(u);

    for(int i=0;i<siz;i++){

        int v=AdjLst[u][i];

        if(dfs_num[v]==-1) tarjan_SCC(v);

        if(visited[v]) dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }

    if(dfs_num[u]==dfs_low[u]){
        vi tempvec;

        while(true){
            int v=Stack.back(); Stack.pop_back();
            visited[v]=false;

            tempvec.push_back(v);

            if(v==u) break;
        }

        SCC.push_back(tempvec);
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    int V,E; cin>>V;
    int ara[V+1];
    ff(i,1,V) cin>>ara[i];
    cin>>E;

    AdjLst.assign(V+1,vi());///vertices are numbered from 0 to V-1


    for(int i=0;i<E;i++){
        int u,v;
        cin>>u>>v;
        AdjLst[u].pb(v);///must be directed for SCC
    }

    dfs_num.assign(V+1,-1),dfs_low.assign(V+1,0),visited.assign(V+1,false);
    dfs_times=0;

    for(int i=1;i<=V;i++){
        if(dfs_num[i]==-1){
            tarjan_SCC(i);
        }
    }

    //cout<<"NumOfSCC: "<<SCC.size()<<endl;

    ll cnt=0;
    ll cnt1=1;

    for(int i=0;i<SCC.size();i++){

        int mini=INT_MAX;
        for(int j=0;j<SCC[i].size();j++){
            //cout<<SCC[i][j]<<" ";
            mini=min(mini,ara[SCC[i][j]]);
        }
        cnt+=mini;
        int cntt=0;
        for(int j=0;j<SCC[i].size();j++){
            if(ara[SCC[i][j]]==mini) cntt++;
        }
        cnt1=(cnt1*cntt)%MOD;

        //cout<<endl;

    }

    cout<<cnt<<" "<<cnt1<<endl;

    return 0;
}
