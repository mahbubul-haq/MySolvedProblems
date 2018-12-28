#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
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

vvii AdjLst;
vector<bool> visited;
int n;
vi cost;
vii ans;

int dfs1(int u){
    visited[u]=true;
    int siz=AdjLst[u].size();
    int temp=0;

    for(int i=0;i<siz;i++){
        pii v=AdjLst[u][i];
        if(!visited[v.first]){
            temp=max(temp,v.second+dfs1(v.first));
        }
    }

    return cost[u]=temp;

}

void dfs2(int u,int precost){
    visited[u]=true;
    int siz=AdjLst[u].size();
    int temp=0,tempmin=0;

    for(int i=0;i<siz;i++){
        pii v=AdjLst[u][i];

        if(!visited[v.first]){
            if(v.second+cost[v.first]>temp){
                tempmin=temp;
                temp=v.second+cost[v.first];
            }
            else if(v.second+cost[v.first]>tempmin){
                tempmin=v.second+cost[v.first];
            }
        }
    }

   /// cout<<temp<<" "<<tempmin<<" "<<precost<<" "<<u<<endl;

    ans.pb(pii(u,max(temp,precost)));

    for(int i=0;i<siz;i++){

        pii v=AdjLst[u][i];
        if(!visited[v.first]){

            if(temp==v.second+cost[v.first]){
                dfs2(v.first,max(tempmin,precost)+v.second);
            }
            else dfs2(v.first,max(temp,precost)+v.second);
        }

    }


}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;
    for(int cas=0;cas<T;cas++){
        scanf("%d",&n);
       // cout<<"N"<<n<<endl;
        AdjLst.assign(n,vii());

        for(int i=1;i<n;i++){
            int u,v,w; scanf("%d %d %d",&u,&v,&w);
            AdjLst[u].pb(pii(v,w));
            AdjLst[v].pb(pii(u,w));
        }
        visited.assign(n,false);
        cost.assign(n,0);

        dfs1(0);
        visited.assign(n,false);

        dfs2(0,0);

        sortv(ans);
        printf("Case %d:\n",cas+1);
        for(int i=0;i<n;i++){
            ///cout<<ans[i].first<<" "<<ans[i].second<<endl;
            printf("%d\n",ans[i].second);
        }
        ans.clear();


    }

    return 0;
}
