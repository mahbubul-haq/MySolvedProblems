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

///=======================================template=======================================///

#define  viii vector<pair<pii,int> >
#define piii pair<pii,int>

viii st;
vi ara;
int n;

int left(int node){ return (node<<1);}
int right(int node){ return (node<<1)|1;}

void update(int,int,int);
void build(vi &_ara){
    ara=_ara;
    n=siz(ara);
    st.assign(4*n+1,piii());
    update(1,0,n-1);
}

void update(int node,int L,int R){
    if(L==R){
        st[node].ff.ff=ara[L];
        st[node].ff.ss=ara[L];
        st[node].ss=1;
    }
    else{

        int mid=(L+R)>>1;

        update(left(node),L,mid);
        update(right(node),mid+1,R);

        st[node].ff.ff=min(st[left(node)].ff.ff,st[right(node)].ff.ff);
        st[node].ff.ss=__gcd(st[left(node)].ff.ss,st[right(node)].ff.ss);

        if(st[node].ff.ff==st[node].ff.ss){
            if(st[node].ff.ff==st[left(node)].ff.ff and st[node].ff.ff==st[right(node)].ff.ff){
                st[node].ss=st[left(node)].ss+st[right(node)].ss;
            }
            else if(st[node].ff.ff==st[left(node)].ff.ff){
                st[node].ss=st[left(node)].ss;
            }
            else st[node].ss=st[right(node)].ss;
        }
        else st[node].ss=0;

    }
}

piii query(int node,int L,int R,int i,int j){
    if(L>=i and R<=j){
        return st[node];
    }
    else if(j<L or i>R) return mp(mp(INT_MAX,0),0);
    else{
        int mid=(L+R)>>1;
        piii x=query(left(node),L,mid,i,j);
        piii y=query(right(node),mid+1,R,i,j);

        int mini=min(x.ff.ff,y.ff.ff);
        int gcd=__gcd(x.ff.ss,y.ff.ss);

        int cnt=0;
        if(gcd==mini){
            if(mini==x.ff.ff and mini==y.ff.ff){
                cnt=x.ss+y.ss;
            }
            else if(mini==y.ff.ff){
                cnt=y.ss;
            }
            else cnt=x.ss;
        }
        else cnt=0;

        return mp(mp(mini,gcd),cnt);
    }
}

int main()
{
    //FI;FO;
    FastIO;

    cin>>n;

    vi vec; for(int i=0;i<n;i++){
        vec.emplace_back();
        cin>>vec.back();
    }

    build(vec);

    int q; cin>>q;

    while(q--){
        int u,v; cin>>u>>v;
        u--,v--;
        cout<<(v-u+1-query(1,0,n-1,u,v).ss)<<endl;
    }

    return 0;
}
