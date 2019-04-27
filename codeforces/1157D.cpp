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

    ll n; cin>>n;
    ll k; cin>>k;

    if(n==1 and k==1){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        return 0;
    }
    else if(n==1){
        cout<<"NO"<<endl;
        return 0;
    }
    else if(k==1){
        cout<<"YES"<<endl;
        cout<<n<<endl;
        return 0;
    }

    ll l=1,r=n;
    ll mid;

    while(l<=r){
        ll val;
        mid=(l+r)>>1;

        val=((mid+k)*(mid+k+1))/2-(mid*(mid+1))/2;
        if(val>n) r=mid;
        else if(val<n) l=mid+1;
        else break;

        if(l==r) {
            mid=l;
            break;
        }
    }

    ll val=((mid+k)*(mid+k+1))/2-(mid*(mid+1))/2;
    if(val>n) mid--;

    mid++;

    //cerr<<mid<<endl;

    ll tempsum=0,sum=0,tempmid=mid;

    for(int i=1;i<k-1;i++){
        //cout<<mid<<" ";
        tempsum+=tempmid;
        tempmid++;
    }

    ll nn=n-tempsum;
    ll tmid=mid;

    //if(k==2) tempmid

    if(nn>=tempmid+tempmid+1 and (nn<=(tempmid-1)*6 or k==2)){


        ll le=tempmid,ri=(tempmid-1)*2;

        if(k==2) ri=tempmid*2;
        bool flg=false;

        while(le<=ri){
            mid=(le+ri)>>1;
            if(nn-mid<=mid*2 and nn-mid>mid){
                cout<<"YES"<<endl;
                for(int i=1;i<k-1;i++){
                    cout<<tmid<<" ";
                    sum+=tmid;
                    tmid++;
                }

                cout<<mid<<" "<<nn-mid<<endl;
                return 0;
            }
            else if(nn-mid<=mid){
                ri=mid;
            }
            else if(nn-mid>mid) le=mid+1;
            if(flg){
                cout<<"NO"<<endl;
                return 0;
            }
            if(le==ri ) flg=true;
        }

    }
    else cout<<"NO"<<endl;


   /* if(n-tempmid-tempsum>tempmid*2+1){
        if(tempmid+1>(tempmid-1)*2){
            cout<<"NO"<<endl;
            return 0;
        }
        if(n-tempsum-tempmid-1<=tempmid+1){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    else{
        if(n-sum-tempmid<=tempmid){
            cout<<"NO"<<endl;
            return 0;
        }
    }


    cout<<"YES"<<endl;

    for(int i=1;i<k-1;i++){
        cout<<mid<<" ";
        sum+=mid;
        mid++;
    }


    if(n-mid-sum>mid*2+1){
        cout<<mid+1<<" ";
        cout<<n-sum-mid-1<<endl;
    }
    else{
        cout<<mid<<" ";
        cout<<n-sum-mid<<endl;
    }
*/

    return 0;
}
