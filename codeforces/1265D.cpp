#include <bits/stdc++.h>
using namespace std;
 
#define all(v)                      v.begin(), v.end()
#define Chrono                      chrono::steady_clock::now().time_since_epoch().count()
#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-15
#define eb                          emplace_back
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
#define mt                          make_tuple
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
#define bug(...)                    cerr << __LINE__ << " : (" << #__VA_ARGS__ << ") = ("; _Print(__VA_ARGS__);
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
 
int main() {
    //FI;FO;
    //FastIO; //timeInit;
 
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = a +b + c + d;
 
    int ans[a + b + c + d + 5];
    int cnt[4];
    cnt[0]= a;
    cnt[1] = b, cnt[2] = c, cnt[3] = d;
 
    deque<int> dq;
    if (b) {
        dq.push_front(1);
        cnt[1]--;
    }
    else if (a)
        dq.push_front(0), cnt[0]--;
    else if (c)
        dq.push_front(2), cnt[2]--;
    else dq.push_front(3), cnt[3]--;
 
    bool l = true, r = true;
    while (l) {
        int v = dq.front();
        if (v == 0){
            if (cnt[v + 1]) {
                dq.push_front(1);
                cnt[1]--;
            }
            else
                l = false;
        }
        else if (v == 3) {
            if (cnt[v - 1]) {
                dq.push_front(2);
                cnt[2]--;
            }
            else
                l = false;
        }
        else {
            if (cnt[v - 1]) {
                dq.push_front(v - 1);
                cnt[v - 1]--;
            }
            else if (cnt[v + 1]) {
                dq.push_front(v + 1);
                cnt[v + 1]--;
            }
            else l = false;
        }
 
        if (siz(dq) >= n)
            break;
    }
 
    while (r) {
        int v = dq.back();
        if (v == 0){
            if (cnt[v + 1]) {
                dq.push_back(1);
                cnt[1]--;
            }
            else
                r = false;
        }
        else if (v == 3) {
            if (cnt[v - 1]) {
                dq.push_back(2);
                cnt[2]--;
            }
            else
                r = false;
        }
        else {
            if (cnt[v - 1]) {
                dq.push_back(v - 1);
                cnt[v - 1]--;
            }
            else if (cnt[v + 1]) {
                dq.push_back(v + 1);
                cnt[v + 1]--;
            }
            else r = false;
        }
 
        if (siz(dq) >= n)
            break;
    }
 
    if (siz(dq) >= n) {
        cout << "YES" << endl;
        while (!dq.empty()) {
            cout << dq.front() << " ";
            dq.pop_front();
        }
    }
    else cout << "NO" << endl;
 
    //timeTaken;
    return 0;
}
