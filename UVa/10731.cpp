/*
Strongly Connected Components are the answers.
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
vi dfs_num,dfs_low,Stack;
vector<bool> visited;
int n,times;
 
void tarjan_SCC(int u){
    dfs_low[u]=dfs_num[u]=++times;
    visited[u]=true;
    int siz=AdjLst[u].size();
    Stack.pb(u);
 
    ff(i,0,siz-1){
        int v=AdjLst[u][i];
        if(dfs_num[v]==-1) tarjan_SCC(v);
        if(visited[v]) dfs_low[u]=min(dfs_low[v],dfs_low[u]);
    }
 
    if(dfs_low[u]==dfs_num[u]){
        vi temp;
 
        while(true){
            int v=Stack.back(); Stack.pop_back();visited[v]=false;
            temp.pb(v);
            if(u==v) break;
        }
 
        SCC.pb(temp);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
    int i=1;
 
    while(cin>>n&&n!=0){
 
        if(i!=1) cout<<endl;
        i++;
 
        map<char,int> myMap;
        map<int,char> map1;
 
        char ch;
        int cnt=0;
        AdjLst.assign(27,vi());
 
        ff(j,1,n){
            vi tempvec;
 
            ff(k,1,5){
                cin>>ch;
                //cout<<ch<<"d";
                if(myMap[ch]==0){
                    myMap[ch]=++cnt;
                    map1[cnt]=ch;
                }
                tempvec.pb(myMap[ch]);
            }
            cin>>ch; if(myMap[ch]==0){
                myMap[ch]=++cnt;
                map1[cnt]=ch;
            }
            //cout<<ch<<"d"<<endl;
 
            ff(k,0,4){
                if(tempvec[k]!=myMap[ch]) AdjLst[myMap[ch]].pb(tempvec[k]);
            }
        }
 
        dfs_num.assign(cnt+1,-1);
        dfs_low.assign(cnt+1,0); visited.assign(cnt+1,false);
        times=0;
 
      // cout<<cnt<<endl;
        ///cout<<'?'<<endl;
 
        ff(j,1,cnt){
            if(dfs_num[j]==-1){
                tarjan_SCC(j);
            }
        }
 
      //  cout<<"??"<<endl;
 
 
        int siz=SCC.size();
 
        vector<vector<char> > finalSCC;
 
        ff(j,0,siz-1){
            vector<char> tem;
 
            int s=SCC[j].size();
 
            ff(k,0,s-1){
                tem.pb(map1[SCC[j][k]]);
            }
            sort(tem.begin(),tem.end());
            finalSCC.pb(tem);
        }
 
        sort(finalSCC.begin(),finalSCC.end());
 
        ff(j,0,siz-1){
            int s=finalSCC[j].size();
 
            ff(k,0,s-2){
                cout<<finalSCC[j][k]<<" ";
            }
            cout<<finalSCC[j][s-1]<<endl;
        }
 
        SCC.clear();
        Stack.clear();
 
    }
 
    return 0;
}
