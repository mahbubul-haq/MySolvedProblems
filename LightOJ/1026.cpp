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
#define INF 1e9
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
vii articulationBridges;
int times;
vi dfs_num,dfs_low,parent;
vector<bool> visited;



void articulationBridge(int u){
    dfs_low[u]=dfs_num[u]=++times;

    int siz=AdjLst[u].size();
    ff(i,0,siz-1){
        int v=AdjLst[u][i];
        if(!visited[v]){
            visited[v]=true;
            parent[v]=u;

            articulationBridge(v);

            if(dfs_low[v]>dfs_num[u]){
                    int maxu=max(u,v),minu=min(u,v);
                articulationBridges.pb(pii(minu,maxu));
            }
            dfs_low[u]=min(dfs_low[v],dfs_low[u]);


        }
        else{
            if(v!=parent[u]) dfs_low[u]=min(dfs_low[u],dfs_num[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T;
    scanf("%d",&T);
    //cin>>T;
    ff(i,1,T){

        int n;
        scanf("%d",&n);
       // cin>>n;
        AdjLst.assign(n,vi());
       // string s; getline(cin,s);
      //  cout<<n<<"33 "<<s<<endl;
        articulationBridges.clear();
        dfs_num.assign(n,INT_MAX);
        dfs_low.assign(n,INT_MAX);
        visited.assign(n,false);
        parent.assign(n,-1);
        times=0;

        ff(j,1,n){
            char ara[1000000];

            scanf(" %[^\n]",ara);
            string input;
           // getline(cin,input);
           input=ara;
           // cout<<input<<endl;
            stringstream cls(input);
            string temp;
            vector<string> ve;
            while(getline(cls,temp,' ')){
          //      cout<<temp<<" 222"<<endl;
                ve.pb(temp);
            }

            stringstream ss(ve[0]);
            int u; ss>>u;

            ff(k,2,(int)ve.size()-1){
                stringstream ss1(ve[k]);
                int v; ss1>>v;
                AdjLst[u].pb(v);
            }
        }

        ff(j,0,n-1){
            if(!visited[j]){
                visited[j]=true;

                articulationBridge(j);

            }
        }

        sort(articulationBridges.begin(),articulationBridges.end());

        cout<<"Case "<<i<<":"<<endl;
        int siz=articulationBridges.size();
        cout<<siz<<" critical links"<<endl;
        if(siz>0){
            ff(j,0,siz-1){
                int xx=articulationBridges[j].first,yy=articulationBridges[j].second;
                cout<<xx<<" - "<<yy<<endl;
            }
        }

    }

    return 0;
}
