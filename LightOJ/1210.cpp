/*

find Strongly connected components(SCCs)
now find the number of SCCs that has no indegree(X) and the number of SCCs that has no outdegree(Y)
ans=max(X,Y);

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

vector< vi > AdjLst,SCC;
int n,dfs_times;
vi dfs_num,dfs_low,Stack,inWhichSCC;
vector<bool> visited,indegree,outdegree;
int SCCcount=0;




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

    int T; scanf("%d",&T);

    ff(ii,1,T) {
        int m;
        scanf("%d%d",&n,&m);
        AdjLst.assign(n + 1, vi());

        ff(i, 1, m) {
            int u,v;
            scanf("%d%d",&u,&v);
            AdjLst[u].pb(v);
        }

        dfs_num.assign(n + 1, -1);
        dfs_low.assign(n + 1, 0);
        visited.assign(n + 1, false);
        inWhichSCC.assign(n + 1, -1);

        dfs_times = 0;


        SCCcount=0;
        SCC.clear(); Stack.clear();
        ff(i, 1, n) {
            if (dfs_num[i] == -1) tarjan_SCC(i);
        }

        int siz = SCC.size();

        if (siz == 1) {
            cout << "Case "<<ii<<": "<<0<< endl;
            continue;
        }

        indegree.assign(siz, false);
        outdegree.assign(siz, false);

        ff(i, 0, siz - 1) {
            int s = SCC[i].size();

            ff(j, 0, s - 1) {
                int temp = SCC[i][j];
                int ss = AdjLst[temp].size();

                ff(k, 0, ss - 1) {

                    int v = AdjLst[temp][k];
                    if (inWhichSCC[temp] != inWhichSCC[v]) {
                        outdegree[inWhichSCC[temp]] = true;
                        indegree[inWhichSCC[v]] = true;
                    }
                }

            }
        }

        int incnt = 0, outcnt = 0;

       // vi indzero, outzero;

        ff(i, 0, siz - 1) {
            if (!indegree[i]) {
                incnt++;
               // indzero.pb(i);
            }
            if (!outdegree[i]) {
                outcnt++;
               // outzero.pb(i);
            }
        }

        cout << "Case "<<ii<<": "<<max(incnt, outcnt) << endl;

        /*int coveredind = 0, coveredoutd = outcnt;
        bool flag = false;

        while (true) {


            if (coveredind == incnt && coveredoutd == 0) {
                break;
            }


            if (coveredind == incnt && coveredoutd != 0) {
                cout << SCC[outzero[coveredoutd - 1]][0] << " " << SCC[0][0] << endl;
                coveredoutd--;
            } else if (coveredoutd == 0 && coveredind != incnt) {
                cout << SCC[siz - 1][0] << " " << SCC[indzero[coveredind]][0] << endl;
                coveredind++;
            } else {


                cout << SCC[outzero[coveredoutd - 1]][0] << " " << SCC[indzero[coveredind]][0] << endl;
                coveredind++;
                coveredoutd--;

            }*/


    }


    return 0;
}
