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
#define gt(i, x)                    get<i>(x)
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
#define tii                         tuple<int, int>
#define tiii                        tuple<int, int, int>
#define tiiii                       tuple<int, int, int, int>
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

int dirx[] = {-1, 1, 0, 0};
int diry[] = {0, 0, -1, 1};

int main() {
    //FI;FO;
    //FastIO; //timeInit;

    int l, r, c;
    while (cin >> l >> r >> c and (r | l | c)) {
        vector<vector<vb> > vis(l, vector<vb> (r, vb(c, false)));
        tiii start, dest;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                string temp;
                cin >> temp;
                for (int k = 0; k < c; k++) {
                    if (temp[k] == 'S') {
                        start = mt(i, j, k);
                    }
                    else if (temp[k] == 'E') {
                        dest = mt(i, j, k);
                    }
                    else if (temp[k] == '#') {
                        vis[i][j][k] = true;
                    }
                }
            }
        }

        int ans = INT_MAX;
        queue<tiiii> q;
        q.push(mt(0, gt(0,start), gt(1, start), gt(2, start)));
        vis[gt(0, start)][gt(1, start)][gt(2, start)] = true;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            if (mt(gt(1, x), gt(2, x), gt(3, x)) == dest) {
                ans = gt(0, x);
                break;
            }
            for (int i = 0; i < 4; i++) {
                int tox = gt(2, x) + diry[i];
                int toy = gt(3, x) + dirx[i];
                if (tox >= 0 and tox < r and toy >= 0 and toy < c and !vis[gt(1, x)][tox][toy]) {
                    q.push({gt(0, x) + 1, gt(1, x), tox, toy});
                    vis[gt(1, x)][tox][toy] = true;
                }
            }
            for (int i = -1; i < 2; i += 2) {
                int toi = gt(1, x) + i;
                if (toi >= 0 and toi < l and !vis[toi][gt(2, x)][gt(3, x)]) {
                    q.push({gt(0, x) + 1, toi, gt(2, x), gt(3, x)});
                    vis[toi][gt(2, x)][gt(3, x)] = true;
                }
            }
        }

        if (ans == INT_MAX) {
            cout << "Trapped!" << endl;
        }
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }

    //timeTaken;
    return 0;
}