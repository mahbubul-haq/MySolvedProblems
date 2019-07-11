#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define endl                        "\n"
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
Â
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

//template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
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

pll mod={1e9+7.01,1e9+9.01};
pll p={29,31};
vpll p_pow;
int sz;

void pow_calc(){
    p_pow.resize(1e6+5);
    p_pow[0]={1LL,1LL};
    for(int i=1;i<=1e6+1;i++)
        p_pow[i]=(p_pow[i-1]*p)%mod;
}

pll compute_hash(string pattern){
    pll hashvalue={0LL,0LL};
    for(int i=0;i<sz;i++){
        hashvalue=(hashvalue+p_pow[sz-i-1]*(pattern[i]-'a'+1))%mod;
    }
    return hashvalue;
}
vi ans;
void findPattern(string text,pll patternhash){
    int szz=siz(text);
    pll hash={0LL,0LL};
    for(int i=0;i<sz;i++){
        hash=(hash+p_pow[sz-i-1]*(text[i]-'a'+1))%mod;
    }
    if(hash==patternhash)
        ans.pb(1);
    for(int i=sz;i<szz;i++){
        hash=((hash+mod-(p_pow[sz-1]*(text[i-sz]-'a'+1))%mod)%mod)*p+(text[i]-'a'+1);
        hash=hash%mod;
        if(hash==patternhash)
            ans.pb(i-sz+2);
    }
}

int main()
{
    //FI;//FO;
    FastIO;
    //clock_t begin=clock(),endd;
    pow_calc();

    int t; cin>>t;
    int ii=0;
    while(t--){
        ans.clear();

        if(ii!=0)
            cout<<endl;
        ii++;

        string text,pattern;
        cin>>text>>pattern;

        if(siz(pattern)>siz(text)){
            cout<<"Not Found"<<endl;
            continue;
        }

        sz=siz(pattern);
        pll patternhash=compute_hash(pattern);
        findPattern(text,patternhash);

        if(siz(ans)){
            cout<< siz(ans)<<endl;
            for(auto v: ans)
                cout<<v<<" ";
            cout<<endl;
        }
        else cout<<"Not Found"<<endl;
        //cout<<endl;

    }

    //endd=clock();cout<<(double)(endd-begin)/CLOCKS_PER_SEC*1000<<endl;
    return 0;
}
