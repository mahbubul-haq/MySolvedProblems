/*

First determine Strongly connected components(SCCs) of the graph.
then find the number of SCCs that have 0 indegree (X) and SCCs that have zero outdegree(Y)
ans=max(X,Y)
now to add (ans) number of edges...first make new graph with SCCs taken as node. and edges among them are new edges.
do topological sort.
then from start of topological sort cover all X and Y.
I have firstly added edges with all vertices with outdegree zero to vertices with indegree 0...if indegree 0 vertices are all have got edges
then I added edges with vertices having indegree. as I will have to add edge with vertices having outdegree.(this was the first loop. this 
loop will cover all outdegree 0 vertices)
then another loop to cover all indegree zero vertices.

*/

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

vector< vi > AdjLst,AdjLst1,SCC;
int n,dfs_times;
vi dfs_num,dfs_low,Stack,inWhichSCC,topsort;
vector<bool> visited,indegree,outdegree;
int SCCcount=0;

void dfs(int u){
    visited[u]=true;

    int siz=AdjLst1[u].size();

    ff(i,0,siz-1){
        int v=AdjLst1[u][i];

        if(!visited[v]) dfs(v);
    }
    topsort.pb(u);
}


void tarjan_SCC(int u){
    dfs_num[u]=dfs_low[u]=++dfs_times;
    visited[u]=true;
    Stack.pb(u);

    int siz=AdjLst[u].size();
    ff(i,0,siz-1){
        int v=AdjLst[u][i];

        if(dfs_num[v]==-1) tarjan_SCC(v);
        if(visited[v]) dfs_low[u]=min(dfs_low[v],dfs_low[u]);
    }

    if(dfs_low[u]==dfs_num[u]){
        vi tempvec;
        while(true){
            int v=Stack.back(); Stack.pop_back(); visited[v]=false;

            tempvec.pb(v);
            inWhichSCC[v]=SCCcount;

            if(u==v) break;
        }
        SCCcount++;
        SCC.pb(tempvec);
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    AdjLst.assign(n+1,vi());

    ff(i,1,n){
        int x; cin>>x;
        AdjLst[i].pb(x);
    }

    dfs_num.assign(n+1,-1);dfs_low.assign(n+1,0);
    visited.assign(n+1,false);
    inWhichSCC.assign(n+1,-1);

    dfs_times=0;

    ff(i,1,n){
        if(dfs_num[i]==-1) tarjan_SCC(i);
    }

   int siz=SCC.size();

    if(siz==1){
        cout<<0<<endl;
        return 0;
    }

    indegree.assign(siz,false);
    outdegree.assign(siz,false);

    AdjLst1.assign(siz,vi());


    ff(i,0,siz-1){
        int s=SCC[i].size();

        ff(j,0,s-1){
            int temp=SCC[i][j];
            int ss=AdjLst[temp].size();

            ff(k,0,ss-1){

                int v=AdjLst[temp][k];
                if(inWhichSCC[temp]!=inWhichSCC[v]){
                    outdegree[inWhichSCC[temp]]=true;
                    indegree[inWhichSCC[v]]=true;
                    AdjLst1[inWhichSCC[temp]].pb(inWhichSCC[v]);
                }
            }

        }
    }

    int incnt=0,outcnt=0;

    vi indzero,outzero;



    ff(i,0,siz-1){
        if(!indegree[i]) {
            incnt++;

        }
        if(!outdegree[i]) {
            outcnt++;
        }
    }

    visited.assign(siz,false);

    ff(i,0,siz-1) if(!visited[i]) dfs(i);

    cout<<max(incnt,outcnt)<<endl;

    ///cout<<SCC[topsort[0]][0]<<" "<<SCC[topsort[siz-1]][0]<<endl;
   // indegree[siz-1]=true;

    fb(i,siz-1,0){
        if(!outdegree[i]){
            bool flag=false;

            fb(j,i-1,0){
                if(!indegree[j]){
                    cout<<SCC[topsort[i]][0]<<" "<<SCC[topsort[j]][0]<<endl;
                    flag=true;
                    outdegree[i]=true;
                    indegree[j]=true;
                    break;
                }
            }

            if(!flag){
                fb(j,siz-1,i+1){
                    if(!indegree[j]){
                        cout<<SCC[topsort[i]][0]<<" "<<SCC[topsort[j]][0]<<endl;
                        flag=true;
                        outdegree[i]=true;
                        indegree[j]=true;
                        break;
                    }
                }
            }
            if(!flag){
                cout<<SCC[topsort[i]][0]<<" "<<SCC[topsort[i-1]][0]<<endl;
            }

        }
    }

    fb(i,siz-1,1){
        if(!indegree[i-1]){
            cout<<SCC[topsort[i]][0]<<" "<<SCC[topsort[i-1]][0]<<endl;
        }
    }


    return 0;
}
