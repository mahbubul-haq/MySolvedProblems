#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <random>
#include <chrono>
#include <tuple>
#include <sstream>
#include <climits>
#include <bitset>
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
#define MOD                         998244353
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

int main() {
    //FI;//FO;
    FastIO; //timeInit;

    int n, nn;
    cin >> n;

    if (n < 4) {
        string ans;
        for (int i = 1; i <= n; i++) {
            cout << "? " << i << " " << i << endl << flush;
            char c;
            cin >> c;
            ans += c;
        }
        cout << "! " << ans << endl;
    }
    else {
        cout << "? " << 1 << " " << n / 2 << endl << flush;
        map<string, int> one[n / 2], two[n / 2];
        nn = n / 2;
        for (int i = 1; i <= nn * (nn + 1) / 2; i++) {
            string now; cin >> now;
            bug(now);
            if (now == "-")
                exit(0);
            sort(all(now));
            one[siz(now) - 1][now]++;
        }
        cout << "? " << 1 << " " << n / 2 - 1 << endl << flush;
        nn = n / 2 - 1;
        for (int i = 1; i <= nn * (nn + 1) / 2; i++) {
            string now; cin >> now;
            bug(now);
            if (now == "-")
                exit(0);
            sort(all(now));
            two[siz(now) - 1][now]++;
        }

        string ans;
        unordered_map<char, int> cnt;

        for (int l = 1; l < n / 2; l++) {
            for (auto &x : one[l - 1]) {
                if (one[l - 1][x.ff] != two[l - 1][x.ff]) {
                    unordered_map<char, int> cntt;
                    for (int i = 0; i < l; i++)
                        cntt[x.ff[i]]++;
                    for (int i = 0; i < l; i++) {
                        if (cnt[x.ff[i]] != cntt[x.ff[i]]) {
                            ans += x.ff[i];
                            cnt[x.ff[i]]++;
                            break;
                        }
                    }
                    break;
                }
            }
        }

        auto x = *one[n / 2 - 1].begin();
        unordered_map<char, int> cntt;
        for (auto &xx : x.ff) {
            cntt[xx]++;
        }
        for (int i = 0; i < n / 2; i++) {
            if (cnt[x.ff[i]] != cntt[x.ff[i]]) {
                ans += x.ff[i];
                break;
            }
        }

        reverse(all(ans));
        int tot[n + 1][26];
        mem(tot, 0);

        int cnt1[26], cnt2[n / 2 + 1][26], cnt3[26];
        mem(cnt1, 0), mem(cnt2, 0), mem(cnt3, 0);
        for (int i = 1; i <= n / 2; i++) {
            for (int j = 0; j < 26; j++) {
                if (j == ans[i - 1] - 'a') {
                    cnt2[i][j] = cnt2[i - 1][j] + 1;
                }
                else cnt2[i][j] = cnt2[i - 1][j];
            }
        }

        cout << "? " << 1 << " " << n << endl << flush;
        for (int i = 1; i <= n * (n + 1) / 2; i++) {
            string now;
            cin >> now;
            bug(now);
            if (now == "-")
                exit(0);
            if (siz(now) == 1) {
                cnt1[now[0] - 'a']++;
            }

            for (int j = 0; j < siz(now); j++) {
                tot[siz(now)][now[j] - 'a']++;
            }
        }

        string ans1;

        for (int pos = n; pos > n / 2; pos--) {
            for (int i = 0; i < 26; i++) {
                int temp = tot[n - pos + 2][i] - tot[n - pos + 1][i] + cnt2[n - pos + 1][i];
                if (cnt1[i] > temp) {
                    ans1 += (char)(i + 'a');
                    cnt1[i]--;
                    break;
                }
            }
            if (n & 1 and pos == n / 2 + 2)
                break;
        }

        if (n & 1) {
            for (int i = 0; i < 26; i++)
                if (cnt1[i] - cnt2[n / 2][i] > 0) {
                    ans1 += (char)(i + 'a');
                    break;
                }
        }

        reverse(all(ans1));
        ans += ans1;
        cout << "! " << ans << endl;
    }

    //timeTaken;
    return 0;
}
