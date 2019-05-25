#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-10
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         100000
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

template<class T> class compare{
public:
    bool operator()(pair<T,T> &x,pair<T,T> &y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
template<class T> void print(vector<T> &vec){
    for(int i=1;i<siz(vec);i++) cout<<vec[i]<<" ";cout<<endl;
}
template<class T> void print(set<T> &s) {
    for(auto it: s) cout<<it<<" "; cout<<endl;
}
template<class T> void print(list<T> &lst) {
    for(auto it: lst) cout<<it<<" "; cout<<endl;
}
template<class T> ll power(T a,int b){
    ll po=1; while(b--) po*=a; return po;
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

///=======================================template=======================================//

int main()
{
    //FI;FO;
    FastIO;

    int t; cin>>t;

    while(t--){

        string s; cin>>s;

        bool flag=false;

        int last9=siz(s),last0=siz(s);
        for(int i=siz(s)-1;i>=0;i--) {
            if(s[i]!='9') break;
            else last9=i;
        }
        //string ans;
        bool f=false;
        int cnt1=0;
        for(int i=siz(s)-1;i>=0;i--) {
            if(s[i]!='0' and s[i]!='1') f=true;
            if(s[i]=='1') cnt1++;
        }
        if(siz(s)==1){
            cout<<s;
        }
        else if(!f) {
            if (cnt1 == 1) {
                for (int i = 0; i < siz(s) - 1; i++) {
                    cout << 9;
                }
            }
            else if (cnt1 == 2 and s[siz(s) - 1] == '1') cout << s;
            else {
                string ans;
                ans += '9';

                if(s[siz(s)-1]=='1') cnt1--;

                for (int i = siz(s) - 2; i >= 0; i--) {
                    if (s[i] == '1' and cnt1 == 2) {
                        ans += '0', cnt1 = 10000000;
                    } else {
                        if (cnt1 == 10000000 and s[i] == '1') ans += '1';
                        else if (cnt1 == 10000000) ans += '0';
                        else {
                            ans += '9';
                            if (s[i] == '1') cnt1--;
                        }
                    }
                }
                int i = siz(ans) - 1;
                while (ans[i] == '0')i--;

                for (; i >= 0; i--) {
                    cout << ans[i];
                }

            }
        }
        else {
            bool fff=false;
            for (int i = 0; i < siz(s); i++) {
                if (flag) {
                    cout << "9";
                } else {
                    if(i==0 and s[i]=='1') cout<<1;
                    else if (s[i] - '0' > 0) {
                        if (i == siz(s) - 1) {
                            cout << s[i];
                        } else {
                            if (last9 > i + 1) cout << s[i] - '1';
                            else cout << s[i];
                            flag = true;
                        }
                    } else {
                        cout << s[i];
                    }
                }
            }

        }
        cout<<endl;

    }

    return 0;
}
