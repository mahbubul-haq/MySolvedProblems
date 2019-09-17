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

bool comp(pair<pii, bool> &a, pair<pii, bool> &b) {
    if (a.ff.ff == b.ff.ff) {
        

        if (a.ss == b.ss) {
             return a.ff.ss > b.ff.ss;
        }
        return (a.ss and !b.ss);

    }
    return a.ff.ff < b.ff.ff;
}

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {

        vector <pair< pii, bool > > XH;

        for (int i = 0; i < siz(buildings); i++) {
            XH.pb({{buildings[i][0], buildings[i][2]}, true});
            XH.pb({{buildings[i][1], buildings[i][2]}, false});
        }

        sort(XH.begin(), XH.end(), comp);

        int now = 0;
        vvi ans;

        multiset<int> mset;
        int last = -1;
        for (int i = 0; i < siz(XH); i++) {
            pair<pii, bool > data = XH[i];
            if (data.ss) {
                mset.insert(data.ff.ss);

                auto it = mset.end();
                it--;
                int H = *it;
                if (now < H) {
                    ans.emplace_back(vi(2));
                    ans.back()[0] = data.ff.ff;
                    ans.back()[1] = H;
                    now = H;
                }
            }
            else {
                mset.erase(mset.find(data.ff.ss));
                if (mset.empty()) {
                    //cout << data.ff.ss << endl;
                    if(!(last == data.ff.ff))
                        ans.emplace_back(vi(2));
                    
                    ans.back()[0] = data.ff.ff;
                    ans.back()[1] = 0;
                    now = 0;
                    last = data.ff.ff;
                }
                else {
                    auto it = mset.end();
                    it--;
                    int H = *it;
                    if (now > H) {
                        if (!(last == data.ff.ff))
                            ans.emplace_back(vi(2));
                        
                        ans.back()[0] = data.ff.ff;
                        ans.back()[1] = H;
                        now = H;
                        last = data.ff.ff;
                    }
                }
            }
        }

        /*
        /fap(1);
        set<vi> s;
        for (auto &v : ans) {
            s.insert(v);
            //cout << v[0] << v[1] << endl;
        }

        ans.clear();
        for (auto &v : s) {
            ans.pb(v);
        }*/

        return ans;

    }
};
