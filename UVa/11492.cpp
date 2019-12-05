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
#define iii                         pair<int, pii>
#define iiii                        pair<pii, pii>
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
#define timeTaken                   endd = clock(); cerr << (double) (endd - beginn) / CLOCKS_PER_SEC * 1000 << endl
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

struct str {
    int f, l1, l2, len;
    str(int f, int l1, int l2, int len) {
        this->f = f;
        this->l1 = l1;
        this->l2 = l2;
        this->len = len;
    }
};

int main() {
    //FI;FO;
    //FastIO; //timeInit;

    int n;
    while (cin >> n and n) {
        umsi saves;
        int cnt = 1;
        string s, e;
        cin >> s >> e;
        int st, en;
        saves[s] = cnt++;
        st = cnt - 1;
        saves[e] = cnt++;
        en = cnt - 1;
        vector<vector<str> > words;
        words.eb();
        words.eb();
        words.eb();

        for (int i = 0; i < n; i++) {
            string l1, l2, wo;
            cin >> l1 >> l2 >> wo;
            if (!present(saves, l1)) {
                saves[l1] = cnt++;
                words.eb();
            }
            if (!present(saves, l2)) {
                saves[l2] = cnt++;
                words.eb();
            }

            str now(wo[0] - 'a', saves[l1], saves[l2], siz(wo));
            words[saves[l1]].eb(now);
            int temp = now.l1;
            now.l1 = now.l2;
            now.l2 = temp;
            words[saves[l2]].eb(now);
        }

        map<tiiii, int> dist;
        PQ<pair<int, tiiii>, vector<pair<int, tiiii> >, greater<pair<int, tiiii> > >pq;
        for (auto &x : words[st]) {
            pq.push({x.len, {x.f, x.l1, x.l2, x.len}});
            dist[{x.f, x.l1, x.l2, x.len}] = x.len;
        }

        int ans = INT_MAX;
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();

            int ds = x.ff, f = gt(0, x.ss), l1 = gt(1, x.ss), l2 = gt(2, x.ss), len = gt(3, x.ss);

            if (l1 == en or l2 == en) {
                ans = ds;
                break;
            }


            if (ds == dist[{f, l1, l2, len}]) {

                for (auto &xx : words[l1]) {
                    if(xx.f == f)
                        continue;
                    if (dist.find({xx.f, xx.l1, xx.l2, xx.len}) == dist.end() or dist[{xx.f, xx.l1, xx.l2, xx.len}] > ds + xx.len) {
                        dist[{xx.f, xx.l1, xx.l2, xx.len}] = ds + xx.len;
                        pq.push({ds + xx.len, {xx.f, xx.l1, xx.l2, xx.len}});
                    }
                }

                for (auto &xx : words[l2]) {
                    if(xx.f == f)
                        continue;
                    if (dist.find({xx.f, xx.l1, xx.l2, xx.len}) == dist.end() or dist[{xx.f, xx.l1, xx.l2, xx.len}] > ds + xx.len) {
                        dist[{xx.f, xx.l1, xx.l2, xx.len}] = ds + xx.len;
                        pq.push({ds + xx.len, {xx.f, xx.l1, xx.l2, xx.len}});
                    }
                }

            }

        }

        if (ans == INT_MAX) {
            cout << "impossivel" << endl;
        }
        else cout << ans << endl;


    }

    //timeTaken;
    return 0;
}
