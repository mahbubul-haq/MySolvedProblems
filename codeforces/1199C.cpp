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
#define INF                         1e18
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         998244353
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
#define timeTaken                   endd=clock();cout<<(double)(endd-beginn)/CLOCKS_PER_SEC*1000<<endl
#define timeInit                    clock_t beginn=clock(),endd
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
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
 
//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k-1): returns kth smallest element's iterator
 
 
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
 
int main()
{
    //FI;//FO;
    //FastIO;//timeInit;
 
    int n,I;
    cin>>n>>I;
    I*=8;
    ll K;
 
    if(I*1.0/n>30){
        cout<<0<<endl;
        return 0;
    }
    else{
        int l=1,r=1e9;
        while(l<=r){
            int mid=(l+r)/2;
            ll m=(ll)(ceil(log2(mid))+0.000005);
            if(n*m<=I)
                K=mid,l=mid+1;
            else r=mid-1;
 
        }
    }
 
    //cout<<K<<endl;
 
    int ara[n+1];
 
    set<int> st;
    ordered_set st1;
 
    for(int i=1;i<=n;i++)
        cin>>ara[i],st.insert(ara[i]);
    sort(ara+1,ara+n+1);
 
    ll disti=siz(st);
    disti=disti-K;
 
    //cout<<disti<<endl;
 
    //cout<<disti<< " "<<K<<endl;
 
    if(disti<=0){
        cout<<0<<endl;
        return 0;
    }
 
    int cnt=INT_MAX;
 
    int cnt1=0,cnt2=0;
    int val=ara[n];
    cnt1=1;
    int idx=n;
 
    while(cnt1<=disti){
        if(val==ara[idx])
            idx--;
        else{
            val=ara[idx];
            cnt1++;
        }
    }
    int left=1;
    idx++;
 
    //cout<<disti<<endl;
    //cout<<idx<<endl;
    for(cnt2=0;cnt2<=disti;cnt2++){
        cnt=min(cnt,n-idx+1+left-1);
 
        if(idx>n)
            break;
 
        int vall=ara[left];
        //cout<<left<<endl;
        while(left<=n and vall==ara[left])
            left++;
 
 
        vall=ara[idx];
        //cout<<idx<<endl;
        while(idx<=n and vall==ara[idx])
            idx++;
    }
 
    cout<<cnt<<endl;
 
    //timeTaken;
    return 0;
}
