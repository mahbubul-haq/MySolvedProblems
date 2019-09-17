#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1, y1, x2, y2)            ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2))
#define dist3D(x1, y1, z1, x2, y2, z2)    ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2))
#define EPS                         1e-16
#define endl                        "\n"
#define FastIO                      ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt", "r", stdin)
#define FO                          freopen("out.txt", "w", stdout)
#define fap(x)                      cout << "WTH: " << x << endl
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
#define sfi(x)                      scanf("%d", &x)
#define sfii(x,y)                   scanf("%d %d", &x, &y)
#define sfiii(x,y,z)                scanf("%d %d %d", &x, &y, &z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(), v.end())
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

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;
typedef tree<int,null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> ordered_set;

//os.order_of_key(v): returns how many elements strictly less than v
//os.find_by_order(k - 1): returns kth smallest element's iterator
*/

template<class T> class compare {
public:
    bool operator() (pair<T, T> &x, pair<T, T> &y) {
        if (x.first == y.first) {
            return x.ss > y.ss;
        }
        return x.ff > y.ff;
    }
};

//template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
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

template<class T> pair<T, T> operator + (const pair<T, T> &a, const pair<T, T> &b) { return {a.ff + b.ff, a.ss + b.ss}; }
template<class T> pair<T, T> operator - (const pair<T, T> &a, const pair<T, T> &b) { return {a.ff - b.ff, a.ss - b.ss}; }
template<class T> pair<T, T> operator * (const pair<T, T> &a, const pair<T, T> &b) { return {a.ff * b.ff, a.ss * b.ss}; }
template<class T> pair<T, T> operator % (const pair<T, T> &a, const pair<T, T> &b) { return {a.ff % b.ff, a.ss % b.ss}; }
template<class T, class U> pair<T, T> operator + (const pair<T, T> &a, const U &b) { return {a.ff + b, a.ss + b}; }
template<class T, class U> pair<T, T> operator * (const pair<T, T> &a, const U &b) { return {a.ff * b, a.ss * b}; }

int Set(int N, int pos) { return N = N | (1 << pos); }
int reset(int N, int pos){ return N = N & ~ (1 << pos); }
bool check(ll N, int pos){ return (bool) (N & (1LL << pos)); }

///=======================================template=======================================///

int main() {
    //FI;//FO;
    FastIO;//timeInit;

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; tc++) {
        cout << "Case #" << tc << ": ";
        string s;
        cin >> s;

        reverse(s.begin(), s.end());

        int rem = 0;
        string one, two;

        for (int i = 0; i < siz(s); i++) {
            int now = s[i] - '0';

            if (now + rem == 10) {
                one += '5';
                two += '5';
                rem = 1;
            }
            else if(now + rem < 0) {
                one += '2';
                two += '7';
                rem = -1;
            }
            else {

                if (now + rem == 0) {
                    one += '0';
                    two += '0';
                    rem = 0;
                    continue;
                }

                now = now + rem;
                int jj = 0, jjj = 0;

                for (int j = 1; j <= max(now, 9); j++) {
                    jj = now - j;
                    if (j != 4 and jj != 4) {
                        jjj = j;
                        break;
                    }
                }

                if((jj == 0 or jjj == 0) and i != siz(s) - 1 ) {
                    now = jj + jjj + 10;
                    jj = now / 2;
                    jjj = now / 2 + (now & 1 ? 1 : 0);
                   // cout << jjj << " " << jj << endl;
                    one += (char) (jj + '0');
                    two += (char) (jjj + '0');
                    rem = -1;
                }
                else {
                    one += (char) (jj + '0');
                    two += (char) (jjj + '0');
                    rem = 0;
                }
            }
        }
       // cout << one << " " << two << endl;
        reverse(one.begin(), one.end());
        reverse(two.begin(), two.end());

        int i = 0;
        while (i < siz(one) and one[i] == '0')
            i++;
        for (int ii = i; ii < siz(one); ii++) {
            cout << one[ii];
        }
        cout << " ";

        i = 0;
        while (i < siz(two) and two[i] == '0')
            i++;
        for (int ii = i; ii < siz(two); ii++) {
            cout << two[ii];
        }
        cout << endl;

    }

    //timeTaken;
    return 0;
}
