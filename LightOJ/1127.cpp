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
#define INF                         100000
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
template<class T> void print(vector<T> &vec){
    for(int i=0;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
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

ll ara[31];
int n,w;
vll firs,sec;

void rec(int id,ll val,int nn){
    if(id==nn+1) firs.pb(val);
    else{
        if(val+ara[id]<=w) rec(id+1,val+ara[id],nn);
        rec(id+1,val,nn);
    }
}

void rec1(int id,ll val,int nn){
    if(id==nn+1) sec.pb(val);
    else{
        if(val+ara[id]<=w) rec1(id+1,val+ara[id],nn);
        rec1(id+1,val,nn);
    }
}

int main()
{
    //FI;FO;
    FastIO;

    int t; cin>>t;

    fof(cas,1,t+1){
        cout<<"Case "<<cas<<": ";
        cin>>n>>w;

        firs.clear();sec.clear();
        for(int i=1;i<=n;i++) cin>>ara[i];

        if(n==1 and ara[1]<=w)cout<<2<<endl;
        else if(n==1 and ara[1]>w) cout<<1<<endl;
        else{

            rec(1,0,n/2);
            rec1(n/2+1,0,n);

            sortv(firs);
            sortv(sec);

            ll ans=0;

            //print(firs);
            //print(sec);
            for(int i=0;i<siz(firs);i++){
                ll val=w-firs[i];

                int mid,l=0,r=siz(sec);

                while(true){

                    if(l>=r) {
                        mid=l;
                        break;
                    }

                    mid=(l+r)>>1;
                    if(sec[mid]<=val){
                        l=mid+1;
                    }
                    else if(sec[mid]>val){
                        r=mid;
                    }
                }

                if(mid==siz(sec)) ans+=siz(sec);
                else if(sec[mid]>val){
                    ans+=mid;
                }
                else ans+=mid+1;

            }

            cout<<ans<<endl;

        }


    }

    return 0;
}
