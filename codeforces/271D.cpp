#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstring>
#include<math.h>
#include<map>
#include<string>
#include<climits>
#include<algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <list>
#include <iterator>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<long,long>
#define vi vector<int>
#define vii vector<pii>
#define vll vector<ll>
#define MOD 1000000007
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define ff(i,a,b) for(int i=(a);i<=(b);i++)
#define fb(i,a,b) for(int i=(a);i>=(b);i--)
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define debugx(x) cout<<"WTH! "<<x<<endl
#define debug(x,y) cout<<x<<" "<<y<<endl

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

int cntbadarr[1505];
int k1;

int count_unique_substrings(string const& s){
    int siz=s.size();

    const int p=31;///only lowercase letters
    const int mod=1e9 + 9;

    vector<long long> p_pow(siz);
    p_pow[0]=1;

    for(int i=1;i<siz;i++){
        p_pow[i]=(p_pow[i-1]*p)%mod;
    }

    vector<long long> h(siz+1,0);

    for(int i=0;i<siz;i++){
        h[i+1]=(h[i]+(s[i]-'a'+1)*p_pow[i])%mod;
    }

    int cnt=0;

    for(int l=1;l<=siz;l++){
        set<long long> hs;

        for(int i=0;i<=siz-l;i++){
            long long cur_h=(h[i+l]+mod-h[i])%mod;
            cur_h=(cur_h*p_pow[siz-i-1])%mod;

            if(i==0&&cntbadarr[i+l-1]<=k1){
                hs.insert(cur_h);
            }
            else if(i!=0){
                if((cntbadarr[i+l-1]-cntbadarr[i-1])<=k1){
                    hs.insert(cur_h);
                }
            }


        }

       // debug(l,hs.size());

        cnt+=hs.size();
    }

    return cnt;

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input;
    cin>>input;

    string good;
    cin>>good;  cin>>k1;
     //cout<<k1<<endl;

    int cnt=0;
    int n=input.length();
    int cntbad=0;


    if(good[input[0]-97]=='0') cntbadarr[0]=1;
    else cntbadarr[0]=0;

    for(int i=1;i<n;i++){
        if(good[input[i]-97]=='0') cntbadarr[i]=1+cntbadarr[i-1];
        else cntbadarr[i]=cntbadarr[i-1];
    }


    cout<<count_unique_substrings(input)<<endl;


    return 0;
}
