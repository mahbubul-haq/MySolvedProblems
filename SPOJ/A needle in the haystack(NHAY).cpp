#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
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

class compare{
public:
    bool operator()(pii x,pii y){
        if(x.second==y.second){
            return x.first<y.first;
        }
        return x.second<y.second;
    }
};

ostream& operator<<(ostream &os,const pll &a){
    os<<a.first<<" "<<a.second;
}

pll operator+(const pll &a, const ll &b){ return { a.first+b,a.second+b };}
pll operator*(const pll &a,const ll &b){ return {a.first*b,a.second*b};}
pll operator+(const pll &a,const pll &b){ return {a.first+b.first,a.second+b.second};}
pll operator-(const pll &a,const pll &b){ return { a.first-b.first,a.second-b.second};}
pll operator*(const pll &a,const pll &b){ return {a.first*b.first,a.second*b.second};}
pll operator%(const pll &a,const pll &b){ return {a.first%b.first,a.second%b.second};}

int Set(int N,int pos) { return N=N|(1<<pos); }
int reset(int N,int pos){ return N=N&~(1<<pos);}
bool check(int N,int pos){  return (bool) (N&(1<<pos));}

pll p={67,71};
pll mod={1e9+9,1e9+7};
vector<pll> p_pow;

void pow_comp(int l,int siz){
    
    if(l==0){
        p_pow.emplace_back();
        p_pow[l]={1L,1L};
        for(int i=1;i<=siz;i++){
            p_pow.emplace_back();
            p_pow[i]=(p_pow[i-1]*p)%mod;
        } 
    }
    else{
        for(int i=l+1;i<=siz;i++){
            p_pow.emplace_back();
            p_pow[i]=(p_pow[i-1]*p)%mod;
        }
    }
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    int mini=0;
    
    
    while(cin>>n){
        string pattern,text;
        cin>>pattern>>text;

        if(n>text.size()){
            cout<<endl;
            continue;
        }
        
        pow_comp(mini,n);
        
        mini=max(mini,n);

        pll patternhash={0L,0L};
        
        for(int i=0;i<n;i++){
            patternhash=(patternhash+p_pow[n-i-1]*(pattern[i]-'A'+1))%mod;
        }
        
        pll hashvalue={0L,0L};
        
        for(int i=0;i<n;i++){
            hashvalue=(hashvalue+p_pow[n-i-1]*(text[i]-'A'+1))%mod;
        }
        
        if(hashvalue==patternhash) cout<<0<<endl;
        
        int siz=text.size();
        
        for(int i=n;i<siz;i++){
            hashvalue=(((hashvalue+mod-(p_pow[n-1]*(text[i-n]-'A'+1))%mod)%mod)*p)%mod+(text[i]-'A'+1);
            hashvalue=hashvalue%mod;
            if(hashvalue==patternhash){
                cout<<i-n+1<<endl;
            }
        }

    }


    return 0;
}
