#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<"WTH: "<<x<<endl
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS 1e-12
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define ff first
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)
#define INF 100000
#define ld long double
#define ll long long
#define mem(x,y) memset(x,y,sizeof x)
#define mp make_pair
#define MOD 1000000007
#define PI acos(-1.0)
#define PQ priority_queue
#define pb push_back
#define pib pair<int,bool>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sfi(x) scanf("%d",&x)
#define sfii(x,y) scanf("%d%d",&x,&y)
#define sfiii(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define siz(x) (int)x.size()
#define sortv(v) sort(v.begin(),v.end())
#define ss second
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>

template<class T>
class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> &vec){
    fof(i,0,vec.size()) cout<<vec[i].ss<<" "; cout<<endl;
}
template<class T>
void print(set<T> &s){
    for(auto it: s) cout<<it<<" "; cout<<endl;
}

template<class T> pair<T,T> operator+(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff+b.ff,a.ss+b.ss}; }
template<class T> pair<T,T> operator-(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff-b.ff,a.ss-b.ss}; }
template<class T> pair<T,T> operator*(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff*b.ff,a.ss*b.ss}; }
template<class T> pair<T,T> operator%(const pair<T,T> &a,const pair<T,T> &b){ return {a.ff%b.ff,a.ss%b.ss}; }
template<class T,class U> pair<T,T> operator+(const pair<T,T> &a,const U &b){ return { a.ff+b,a.ss+b}; }
template<class T,class U> pair<T,T> operator*(const pair<T,T> &a,const U &b){ return { a.ff*b,a.ss*b}; }

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

///=======================================template=======================================///

int main()
{
    //FI;FO;
    FastIO;



    int n; cin>>n;
    vii ans;

    int ara[n+1][n+1];

    fof(i,1,n+1) fof(j,1,n+1) cin>>ara[i][j];


    int mpref[n+1][n+1];
    int wpref[n+1][n+1];
    int wprefid[n+1][n+1];

    deque<int> q;

    for(int i=1;i<=n;i++){
        q.pb(i);
        vii temp;

        for(int j=1;j<=n;j++){
            temp.pb(mp(ara[i][j],j));
        }

        sortv(temp);

        for(int j=0;j<n;j++){
            mpref[i][j+1]=temp[j].ss;
        }
    }

    for(int i=1;i<=n;i++){
        vii temp;

        for(int j=1;j<=n;j++){
            temp.pb(mp(ara[j][i],j));
        }

        sort(temp.rbegin(),temp.rend());

        for(int j=0;j<n;j++){
            wpref[i][j+1]=temp[j].ss;
            wprefid[i][temp[j].ss]=j+1;
        }
    }

    vi wfree(n+1,-1);

    while(!q.empty()){
        int m=q.front();

        for(int i=1;i<=n;i++){
            if(wfree[mpref[m][i]]==-1){
                wfree[mpref[m][i]]=m;
                q.pop_front();
                break;
            }
            else{
                int m1=wfree[mpref[m][i]];
                int id=wprefid[mpref[m][i]][m];
                int id1=wprefid[mpref[m][i]][m1];
                if(id<id1){
                    wfree[mpref[m][i]]=m;
                    q.pop_front();
                    q.pb(m1);
                    break;
                }
            }
        }

    }

    for(int i=1;i<=n;i++) ans.pb(mp(wfree[i],i));

    sortv(ans);

    print(ans);

    return 0;
}
