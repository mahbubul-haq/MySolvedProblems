#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF              1000000000000000000
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
#define vvll                        vector<vll>
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
bool check(ll N,int pos){  return (bool) (N&(1LL<<pos));}

///=======================================template=======================================///

int maxn=250000;

int left(int node){return (node<<1);}
int right(int node) {
    return ((node << 1) + 1);
}
int mid(int l, int r) {
    return ((l + r)/2);
}

class data{
public:
    ll asum;
    int atimes;
    ll bsum;
    int btimes;
    ll c;
    bool isC;
    ll sum;
    data(){
        asum=atimes=bsum=0;
        btimes=c=sum=0;
        isC=false;
    }
};

vector<data> st;

void push(int node,int l,int r){
    if(st[node].isC){
        if(l<r) {
            st[left(node)].asum = st[left(node)].bsum = 0;
            st[left(node)].atimes = st[left(node)].btimes = 0;
            st[right(node)].asum = st[right(node)].bsum = 0;
            st[right(node)].atimes = st[right(node)].btimes = 0;
            st[left(node)].isC = st[right(node)].isC = true;
            st[left(node)].c = st[right(node)].c = st[node].c;
        }
        st[node].sum=(r-l+1)*st[node].c;
    }

    ll k=(r-l+1);
    //fap(st[node].atimes);
    //fap(st[node].asum);
    st[node].sum+= k * st[node].asum + st[node].atimes * ((k + 1)* k) / 2;
    st[node].sum+= k * st[node].bsum + st[node].btimes * ((k+1)*k) / 2;
    if(l<r) {
        st[left(node)].asum += st[node].asum;
        st[left(node)].atimes += st[node].atimes;
        st[left(node)].btimes += st[node].btimes;
        st[right(node)].atimes += st[node].atimes;
        st[right(node)].btimes += st[node].btimes;
        int m = mid(l, r);
        if (st[node].atimes > 0)
            st[right(node)].asum += (st[node].asum + (m - l + 1) * st[node].atimes);
        st[right(node)].bsum += st[node].bsum;

        if (st[node].btimes > 0)
            st[left(node)].bsum += (st[node].bsum + (r - m) * st[node].btimes);
    }

    st[node].asum=st[node].atimes=0;
    st[node].bsum=st[node].btimes=0;
    st[node].c=0;
    st[node].isC=false;
   // cout<<node<<" "<<l<<" "<<r<<" "<<st[node].sum<<endl;
}

void updateA(int node, int l, int r, int i, int j){
    push(node, l, r);
    if(l>j or r<i or l>r)
        return;
    int m = mid(l,r);
    if(l>=i and r<=j){
        st[node].atimes++;
        st[node].asum+= l-i;
        //cout<<l<<" "<<r<<" "<<st[node].sum<<endl;
        return;
    }
    updateA(left(node), l, m, i, j);
    updateA(right(node), m+1, r, i, j);
    push(left(node),l,m);
    push(right(node),m+1,r);
    st[node].sum=st[left(node)].sum+st[right(node)].sum;
   // cout<<l<<"~"<<r<<" "<<st[node].sum<<endl;
}

void updateB(int node, int l, int r, int i, int j ){
    push(node,l,r);
    if(l>j or r<i or l>r)
        return;
    int m=mid(l,r);
    if(l>=i and r<=j){
        st[node].btimes++;
        st[node].bsum+=j-r;
        //cout<<l<<"B"<<r<<" "<<st[node].bsum<<endl;
        return;
    }
    updateB(left(node), l, m, i, j);
    updateB(right(node), m+1, r, i, j);
    push(left(node),l,m);
    push(right(node),m+1,r);
    st[node].sum=st[left(node)].sum + st[right(node)].sum;
  //  cout<<l<<"B-"<<r<<" "<<st[node].sum<<endl;
}//

void updateC(int node, int l, int r, int i, int j, int val){
    push(node, l, r);
    if(l>j or r<i or l>r)
        return;
    int m=mid(l,r);
    if(l >= i and r <= j){
        st[node].isC = true;
        st[node].c = val;
        st[node].asum = st[node].bsum = 0;
        st[node].atimes = st[node].btimes = 0;
        return ;
    }
    updateC(left(node),l,m,i,j,val);
    updateC(right(node),m+1,r,i,j,val);
    push(left(node), l, m);
    push(right(node), m + 1, r);
    st[node].sum = st[left(node)].sum + st[right(node)].sum;
}

ll query(int node, int l, int r, int i, int j){
    push(node, l, r);
    if(l>j or r<i or l>r)
        return 0;
    if(l >= i and r <= j){
        return st[node].sum;
    }
    ll val=query(left(node),l,mid(l,r),i,j);
    ll val1=query(right(node), mid(l,r)+1,r,i,j);
    return (val1+val);

}

int main()
{
    //FI;//FO;
    //FastIO;//timeInit;

    int t; cin>>t;
    for(int tc = 1; tc <= t; tc++){
        //printf("Case %d:\n", tc);
        cout<<"Case "<<tc<<":"<<endl;
        int n;
        //sfi(n);
        cin>>n;

        st.assign(4* maxn+5, data());

        while(n--){
            //scanf("%*c");
            //scanf("%*c");
            char type;
            int l, r;
           // scanf("%c %d %d", &type, &l, &r);
           cin>>type>>l>>r;
            l--,r--;

            if(type=='C'){
                int x; cin>>x;
                updateC(1, 0, maxn - 1, l, r, x);
            }
            else if(type=='A'){
                updateA(1, 0, maxn - 1, l, r);
            }
            else if(type=='B'){
                updateB(1, 0, maxn - 1, l, r);
            }
            else{
                cout<<query(1, 0, maxn - 1, l, r)<<endl;
            }
        }
    }

    //timeTaken;
    return 0;
}
