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
    for(int i=1;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
}
template<class T> ll power(T a,int b){
    ll po=1; while(b--) po*=a; return po;
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

///=======================================template=======================================//

const int sz=21;
int maxn;

class ST{
public:
    vi st,lazy;

    ST(){
        st.assign(8*maxn+1,0);
        lazy.assign(8*maxn+1,0);
    }

    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}

    void push(int node,int l,int r){
        if(lazy[node]){
            lazy[left(node)]=lazy[left(node)]^1;
            lazy[right(node)]=lazy[right(node)]^1;
            st[node]=r-l+1-st[node];
            lazy[node]=0;
        }
    }

    void update(int node,int l,int r,int i,int j){

        push(node,l,r);

        if(i>r or j<l) return;
        if(l>=i and r<=j){
            lazy[node]=1^lazy[node];
            push(node,l,r);
            return;
        }

        int mid=(l+r)>>1;
        update(left(node),l,mid,i,j);
        update(right(node),mid+1,r,i,j);

        st[node]=st[left(node)]+st[right(node)];
    }
    int query(int node,int l,int r,int i,int j){
        push(node,l,r);

        if(i>r or j<l) return 0;
        if(l>=i and r<=j){
            return st[node];
        }

        int mid=(l+r)>>1;
        int val=query(left(node),l,mid,i,j);
        int val2=query(right(node),mid+1,r,i,j);

        return val+val2;
    }
};

int main()
{
    //FI;FO;
    FastIO;

    cin>>maxn;

    vi vec(maxn);
    fof(i,0,maxn) cin>>vec[i];

    int m; cin>>m;

    ST st[sz];

    for(int i=0;i<maxn;i++){
        for(int j=0;j<sz;j++){
            if(1&(vec[i]>>j)){
                st[j].update(1,0,maxn-1,i,i);
            }
        }
    }

    while(m--){
        int t;
        cin>>t;
        if(t==1){
            int l,r; cin>>l>>r;
            l--,r--;
            ll ans=0;
            ll mult=1;

            for(int j=0;j<sz;j++){
                ans+=mult*st[j].query(1,0,maxn-1,l,r);
                mult*=2;
            }
            cout<<ans<<endl;
        }
        else{
            int l,r,x; cin>>l>>r>>x;
            l--,r--;
            for(int i=0;i<sz;i++){
                if(1&(x>>i)) st[i].update(1,0,maxn-1,l,r);
            }
        }
    }

    return 0;
}
