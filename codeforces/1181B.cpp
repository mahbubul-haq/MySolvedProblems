#include <bits/stdc++.h>
using namespace std;

#define dist2D(x1,y1,x2,y2)         ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2)   ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define EPS                         1e-12
#define FastIO                      ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define FI                          freopen("in.txt","r",stdin)
#define FO                          freopen("out.txt","w",stdout)
#define fap(x)                      cout<<"WTH: "<<x<<endl
#define ff                          first
#define fof(i,x,y)                  for(int i=x;i<(int)y;i++)
#define fob(i,x,y)                  for(int i=x;i>=(int)y;i--)
#define INF                         1000000000
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

template<class T> ostream& operator<<(ostream &os,const pair<T,T> &a) { os<<a.ff<<" "<<a.ss; }
ll power(ll a,int b){
    ll po=1;
    while(b){
        if(b&1)
            po*=a;
        a*=a;
        b>>=1;
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
    FastIO;

    int n; cin>>n;

    string s; cin>>s;
    vector<pair<string,string> > ans;

    int mid=n/2;

    if(n==2){
        ll ans1=(s[0]-'a') + (s[1]-'0');
        cout<<ans1<<endl;
        return 0;
    }

    if(s[mid]!='0'){
        //if(n==99989)
           // fap(1);
        if(n&1){
            ans.pb(mp(s.substr(0,mid),s.substr(mid)));
            if(s[mid+1]!='0')
                ans.pb(mp(s.substr(0,mid+1),s.substr(mid+1)));
            if(mid+2<siz(s) and s[mid+2]!='0')
                ans.pb(mp(s.substr(0,mid+2),s.substr(mid+2)));
            if(mid-1>0 and s[mid-1]!='0')
                ans.pb(mp(s.substr(0,mid-1),s.substr(mid-1)));
        }
        else{
            ans.pb(mp(s.substr(0,mid),s.substr(mid)));
        }
    }
    else{
        int lasti=siz(s),firsti=0;

        for(int i=mid;i<siz(s);i++){
            if(s[i]!='0')
            {
                lasti=i;
                break;
            }
        }
        for(int i=mid;i>-1;i--){
            if(s[i]!='0'){
                firsti=i;
                break;
            }
        }

        if(firsti!=0){
            ans.pb(mp(s.substr(0,firsti),s.substr(firsti)));
        }
        if(lasti!=siz(s)){
            ans.pb(mp(s.substr(0,lasti),s.substr(lasti)));
        }
    }

    for(int i=0;i<siz(ans);i++){
        string temp;
        int ii=siz(ans[i].ff)-1,jj=siz(ans[i].ss)-1;
        int hand=0;
        while(true){
            if(ii<0 and jj<0) break;
            int fir,sec;

            if(ii<0) fir=0;
            else {
                fir=ans[i].ff[ii]-'0';
                ii--;
            }

            if(jj<0) sec=0;
            else{
                sec=ans[i].ss[jj]-'0';
                jj--;
            }

            int add=hand+fir+sec;
            int rem=add%10;
            temp+=to_string(rem);
            hand=add/10;
        }
        if(hand)
            temp+=to_string(hand);
        reverse(temp.begin(),temp.end());
        ans[i].ff=temp;
    }

    int anss=0;

    for(int i=1;i<siz(ans);i++){
        if(siz(ans[i].ff)<siz(ans[anss].ff)){
            anss=i;
        }
        else if(siz(ans[i].ff)==siz(ans[anss].ff)){
            bool flag=false;
            for(int j=0;j<siz(ans[i].ff);j++){
                if(ans[i].ff[j]<ans[anss].ff[j]){
                    flag=true;
                }
                else if(ans[i].ff>ans[anss].ff)
                    break;
            }
            if(flag)
                anss=i;
        }
    }

    cout<<ans[anss].ff<<endl;

    return 0;
}
