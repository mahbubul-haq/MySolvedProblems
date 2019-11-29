#include <bits/stdc++.h>
using namespace std;
 
#define all(v)                      v.begin(), v.end()
#define Chrono                      chrono::steady_clock::now().time_since_epoch().count()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-15
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define ff                          first
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x, y, sizeof x)
#define mp                          make_pair
#define msi                         map<string, int>
#define mii                         map<int, int>
#define mis                         map<int, string>
#define MOD                         1000000007
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int, bool>
#define pii                         pair<int, int>
#define pll                         pair<ll, ll>
#define present(c, x)               ((c).find(x) != (c).end())
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define ss                          second
#define timeTaken                   endd = clock(); cout << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
#define timeInit                    clock_t beginn = clock(), endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string, int>
#define umii                        unordered_map<int, int>
#define umis                        unordered_map<int, string>
#define vb                          vector<bool>
#define vi                          vector<int>
#define vvi                         vector<vi>
#define vii                         vector<pii>
#define vvii                        vector<vii>
#define vll                         vector<ll>
#define vvll                        vector<vll>
#define vpll                        vector<pll>
#define bug(...)                    cerr << __PRETTY_FUNCTION__ << " - " << __LINE__ << " : (" << #__VA_ARGS__ << ") = ("; _Print(__VA_ARGS__);
template<class T> void _Print(T &&x) { cerr << x << ")" << endl; }
template<class T, class ...S> void _Print(T &&x, S &&...y) { cerr << x << ", "; _Print(y...); }
 
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;
 
//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
 
 
template<class T> class compare {
public:
    bool operator() (pair<T, T> &x, pair<T, T> &y) {
        if (x.first == y.first) {
            return x.ss > y.ss;
        }
        return x.ff > y.ff;
    }
};
 
template<class T> ostream &operator<<(ostream &os, const pair<T, T> &a) { return os << a.ff << " " << a.ss; }
ll power(ll a, int b) {
    ll po = 1;
    while (b) {
        if (b & 1)
            po *= a;
        a *= a;
        b >>= 1;
    }
    return po;
}
 
template<class T> pair<T, T> operator+(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff + b.ff, a.ss + b.ss}; }
template<class T> pair<T, T> operator-(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff - b.ff, a.ss - b.ss}; }
template<class T> pair<T, T> operator*(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff * b.ff, a.ss * b.ss}; }
template<class T> pair<T, T> operator%(const pair<T, T> &a, const pair<T, T> &b) { return {a.ff % b.ff, a.ss % b.ss}; }
template<class T, class U> pair<T, T> operator+(const pair<T, T> &a, const U &b) { return {a.ff + b, a.ss + b}; }
template<class T, class U> pair<T, T> operator*(const pair<T, T> &a, const U &b) { return {a.ff * b, a.ss * b}; }
 
int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(int N, int pos){ return (bool) (N & (1 << pos)); }
 
///=======================================template=======================================///
 
class Data{
public:
    int ans,sum,pref,suff;
};
 
class SegmentTree{
    int n;
    vi ara;
    vector< Data > st;
 
    int left(int node){ return (node<<1);}
    int right(int node){ return (node<<1)+1;}
 
    Data make_data(int val){
        Data temp;
        temp.suff=temp.pref=temp.ans=max(val,0);
        temp.sum=val;
        return temp;
    }
 
    Data combine( Data L,Data R){
        Data temp;
        temp.sum=L.sum+R.sum;
        temp.pref=max(L.pref,L.sum+R.pref);
        temp.suff=max(R.suff,R.sum+L.suff);
        temp.ans=max(max(L.ans,R.ans),L.suff+R.pref);
        return temp;
    }
 
    void build(int node,int L,int R){
        if(L==R){
            st[node]=make_data(ara[L]);
        }
        else{
            build(left(node),L,(L+R)/2);
            build(right(node),(L+R)/2+1,R);
 
            st[node]=combine(st[left(node)],st[right(node)]);
        }
    }
 
    Data query(int node,int L,int R,int i,int j){
        if(i>R||j<L) return make_data(0);
        if(L>=i&&R<=j) return st[node];
 
 
        Data lef=query(left(node),L,(L+R)>>1,i,j);
        Data rig=query(right(node),((L+R)>>1)+1,R,i,j);
 
        return combine(lef,rig);
    }
 
    void update(int node,int L,int R,int pos,int value){
        if(pos>R||pos<L) return;
        if(pos==L&&pos==R){
            st[node]=make_data(value);
            return;
        }
        update(left(node),L,(L+R)/2,pos,value);
        update(right(node),(L+R)/2+1,R,pos,value);
 
        st[node]=combine(st[left(node)],st[right(node)]);
    }
 
public:
    SegmentTree(vi _ara){
        ara=_ara;
        n=ara.size();
        st.assign(4*n+1,Data());
        build(1,0,n-1);
    }
    int pref(int i, int j) {return query(1, 0, n - 1, i, j).pref; }
    int tot(int i, int j) {return query(1, 0, n - 1, i, j).sum; }
    int query(int i,int j){ return query(1,0,n-1,i,j).ans;}
    void update(int pos,int value){ update(1,0,n-1,pos,value);}
};
 
int main() {
    //FI;//FO;
    FastIO; //timeInit;
 
    int n;
    cin >> n;
 
    set<int> l, r;
 
    vi ara(n, 0);
    SegmentTree st(ara);
 
    string s;
    cin >> s;
    int pos = 0, maxs = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        if (c == 'L') {
            pos--;
            pos = max(0, pos);
        }
        else if(c == 'R') {
            pos++;
            pos = min(n - 1, pos);
        }
        else if (c  == '(') {
            st.update(pos, -1);
        }
        else if (c == ')') {
            st.update(pos, 1);
        }
        else {
            char tem = s[pos];
            st.update(pos, 0);
        }
 
        int maxi = st.query(0, n - 1);
        int tot = st.tot(0, n - 1);
        int pref = st.pref(0, n - 1);
 
        if (tot == 0 and pref < 1)
            cout << maxi << " ";
        else cout << -1 <<" ";
    }
 
    //timeTaken;
    return 0;
}
