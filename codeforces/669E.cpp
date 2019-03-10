#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define PQ priority_queue
#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
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
void print(vector<T> vec){
    fof(i,0,vec.size()) cout<<vec[i].ff.ff<<" "<<vec[i].ff.ss<<" "<<vec[i].ss<<endl; cout<<endl;
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

#define LSOne(n) (n&(-n))

class FenwickTree{
    vector<map<int,int> > ft;
public:
    FenwickTree(vector<pair<pii,int> > vec){
        int n=vec.size();
        ft.resize(n+1);
        fof(i,0,n){
            pair<pii,int> x=vec[i];
            if(x.ff.ff==1) add(x.ff.ss,x.ss,1);
            else if(x.ff.ff==2) add(x.ff.ss,x.ss,-1);
            else{
                cout<<query(x.ff.ss,x.ss)<<endl;
            }
        }
    }

    void add(int id,int val,int add){
        for(;id<ft.size();id+=LSOne(id)){
            ft[id][val]+=add;
        }
    }

    int query(int b,int val){
        int sum=0;
        for(;b;b-=LSOne(b)){
            sum+=ft[b][val];
        }
        return sum;
    }
};

int main()
{
    //FI;FO;
    FASTIO;

    int n; cin>>n;

    vector< pair<pii,int> > query,sorted;
    map<int,int> mapp;
    vii vec;

    fof(i,0,n){
        int a,t,x;
        cin>>a>>t>>x;
        query.pb(mp(mp(a,t),x));
        vec.pb(mp(t,i+1));
    }

    sortv(vec);

    fof(i,0,n) mapp[vec[i].ff]=i+1;

    fof(i,0,n){
        sorted.pb(mp(mp(query[i].ff.ff,mapp[query[i].ff.ss]),query[i].ss));
    }

    FenwickTree ft(sorted);

    return 0;
}

