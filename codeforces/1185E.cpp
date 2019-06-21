#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         1000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vpll                        vector<pll>

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator
*/

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b){
    ll po=1;
    while(b){
        if(b&1)
            po*=a;
        a*=a;
        b>>=1;
    }
    return po;
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

int dirx[]={-1,1,0,0};
int diry[]={0,0,1,-1};

class data{
public:
    bool First;
    pii start,end;
};

int main()
{
    //FI;//FO;
    FastIO;

    int t ; cin>>t;

    while(t--){
        int n,m; cin>>n>>m;

        char mat[n+1][m+1],mata[n+1][m+1];
        vector<data> vec(26);
        for(int i=0;i<26;i++) {
            vec[i].First = false;
            vec[i].start=mp(-1,-1);
            vec[i].end=mp(-1,-1);
        }
        pii taken;
        int cnt=-1;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) {
                cin >> mat[i][j];
                mata[i][j]='.';
                if(mat[i][j]!='.'){
                    int val=mat[i][j]-'a';
                    if(vec[val].First){
                        vec[val].end=mp(i,j);
                    }
                    else{
                        
                        vec[val].start=vec[val].end=mp(i,j);
                        if(cnt<val)
                        {
                            taken=mp(i,j);
                            cnt=val;
                        }
                        vec[val].First=true;
                    }
                }

            }
        }

        int lastidx=-1;
        for(int i=25;i>=0;i--){
            if(vec[i].First)
            {
                lastidx=i;
                break;
            }
        }
        //fap(lastidx);

        if(lastidx==-1){
            cout<<"YES"<<endl;
            cout<<0<<endl;
        }
        else{
            vector<pair<pii,pii > > ans;
            bool flag=true;
            for(int i=0;i<=lastidx;i++){
                if(!vec[i].First){
                    mata[taken.ff][taken.ss]=(char)('a'+i);
                    ans.pb(mp(taken,taken));
                }
                else if(vec[i].end.ff==vec[i].start.ff or
                vec[i].end.ss==vec[i].start.ss){

                    if(vec[i].start.ss==vec[i].end.ss){
                        for(int j=vec[i].start.ff;j<=vec[i].end.ff;j++){
                            mata[j][vec[i].start.ss]=(char)('a'+i);
                        }
                    }
                    else{
                        for(int j=vec[i].start.ss;j<=vec[i].end.ss;j++){
                            mata[vec[i].start.ff][j]=(char)('a'+i);
                        }
                    }

                    ans.pb(mp(vec[i].start,vec[i].end));

                }
                else{
                    flag=false;
                }
            }

            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(mata[i][j]!=mat[i][j]){
                        flag=false;
                    }
                }
            }

            if(flag){
                cout<<"YES"<<endl;
                cout<< siz(ans)<<endl;
                for(auto v:ans){
                    cout<<v.ff.ff<<" "<<v.ff.ss<<" "<<v.ss.ff<<" "<<v.ss.ss<<endl;
                }
            } else{
                cout<<"NO"<<endl;
            }
        }

    }

    return 0;
}
