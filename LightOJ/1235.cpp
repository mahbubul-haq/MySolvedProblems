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
#define sfl(x)                      scanf("%I64",&x);
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

int n,k;
int ara[20];
vvi vec;
bool flag;

void rec(int id,int val,int idx,int nn){
    if(val==k){
        flag=true;return;
    }
    if(id==nn+1) vec[idx].pb(val);
    else{
        if(val+ara[id]<=k)rec(id+1,val+ara[id],idx,nn);
        if(val+2*ara[id]<=k) rec(id+1,val+2*ara[id],idx,nn);
        rec(id+1,val,idx,nn);
    }
}

int main()
{
    //FI;FO;
    //FastIO;

    int t; sfi(t);

    fof(cas,1,t+1){
        printf("Case %d: ",cas);

        //cin>>n>>k;
        sfii(n,k);


        vec.assign(2,vi());

        fof(i,1,n+1) sfi(ara[i]);

        if(n==1 and (ara[1]==k or ara[1]*2==k)) {
            cout<<"Yes"<<endl;
            continue;
        }
        else if(n==1) {
            cout<<"No"<<endl;
            continue;
        }

        flag=false;

        rec(1,0,0,n/2);
        rec(n/2+1,0,1,n);

        sortv(vec[0]);
        sortv(vec[1]);

        if(!flag){
             for(int i=0;i<siz(vec[0]);i++){

                 int val=k-vec[0][i];

                 int l=0,r=vec[1].size()-1;

                 while(true){
                     int mid=(l+r)>>1;
                     if(l>=r){
                         if(vec[1][l]==val) flag=true;
                         break;
                     }
                     else if(vec[1][mid]<val) l=mid+1;
                     else if(vec[1][mid]>val) r=mid;
                     else {
                         flag=true;break;
                     }
                 }

                 if(flag) break;

             }
        }

        if(flag) printf("Yes\n");
        else printf("No\n");

    }

    return 0;
}
