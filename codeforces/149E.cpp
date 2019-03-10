#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define pii pair<int,int>
#define PQ priority_queue
#define ld long double
#define ll long long
#define pll pair<ll,ll>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-12
#define mem(x,y) memset(x,y,sizeof x)
#define INF 100000000
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define FASTIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define PI acos(-1.0)
#define FI freopen("in.txt","r",stdin)
#define FO freopen("out.txt","w",stdout)
#define debug(x) cout<<"WTH: "<<x<<endl
#define fof(i,x,y) for(int i=x;i<(int)y;i++)
#define fob(i,x,y) for(int i=x;i>=(int)y;i--)

template<class T>
class compare{
public:
    bool operator()(pair<T,T> x,pair<T,T> y){
        if(x.first==y.first){
            return x.ss>y.ss;
        }
        return x.ff>y.ff;
    }
};

template<class T>
ostream& operator<<(ostream &os,const pair<T,T> &a){
    os<<a.ff<<" "<<a.ss;
}
template<class T>
void print(vector<T> vec){
    fof(i,0,vec.size()) cout<<vec[i]<<" "; cout<<endl;
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

vi kmpPreprocess(string &pattern){
    int m=pattern.size();
    vi border(m+1,0);
    border[0]=-1;

    int i=0,j=-1;

    while(i<m){
        while(j>=0&&pattern[i]!=pattern[j]) j=border[j];
        j++,i++;
        border[i]=j;
    }
    return border;
}

int kmp(string text,string &pattern,vi &border1,vi &border2){
    int n=text.size();
    int m=pattern.size();
    vi lens(m+1,n+2);
    int i=0,j=0;

    while(i<n){
        while(j>=0&&text[i]!=pattern[j]) j=border1[j];
        i++,j++;
        int l;
        l=j;

        if(l!=0&&lens[l]==n+2){
            lens[l]=i;
        }
    }

    //print(lens);

    reverse(text.begin(),text.end());
    reverse(pattern.begin(),pattern.end());

    i=0,j=0;

    while(i<n){
        while(j>=0&&text[i]!=pattern[j]) j=border2[j];
        i++,j++;

        int l=j;

        if(j!=0&&lens[m-l]<=n-i) return 1;
    }

    return 0;
}

int main()
{
    //FI;FO;
    FASTIO;

    string input;
    cin>>input;

    int m; cin>>m;

    int cnt=0;
    while(m--){
        string pattern;

        cin>>pattern;
        vi border1=kmpPreprocess(pattern);
        string pattern1=pattern;
        reverse(pattern1.begin(),pattern1.end());

        vi border2=kmpPreprocess(pattern1);

        cnt+=kmp(input,pattern,border1,border2);
        //debug(input);
    }

    cout<<cnt<<endl;

    return 0;
}

