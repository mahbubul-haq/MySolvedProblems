#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>02
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define vpll vector<pll>
#define MOD 1000000007
#define EPS 1e-8
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
#define dist2D(x1,y1,x2,y2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
#define dist3D(x1,y1,z1,x2,y2,z2) ((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2))
#define sortv(v) sort(v.begin(),v.end())
#define PI acos(-1.0)

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

///=======================================template=======================================///

ll bigmod(ll a,ll b){
    a%=MOD;
    ll res=1;

    while(b>0){
        if(b&1) res=(res*a)%MOD;
        a=a*a%MOD;
        b>>=1;
    }
    return res;
}

int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n; cin>>n;

    string input; cin>>input;

    if(n<=3){
        if(n==1){
            cout<<0<<endl;
            cout<<input<<endl;
        }
        else if(n==2){
            if(input[0]==input[1]){
                if(input[0]=='R'){
                    input[0]='B';
                }
                else input[0]='R';

                cout<<1<<endl<<input<<endl;
            }
            else {
                cout<<0<<endl<<input<<endl;
            }
        }
        else{
            int cnt0=0,cnt1=0,cnt2=0;
            string temp=input;

            for(int i=0;i<3;i++){
                if(input[i]=='R') cnt0++;
                if(input[i]=='G') cnt1++;
                if(input[i]=='B') cnt2++;
            }

            for(int i=0;i<3;i++){
                if(input[i]=='R'&&cnt0>1){
                    if(cnt1<1) {
                        input[i]='G';
                        cnt1++;
                    }
                    else if(cnt2<1) {
                        input[i]='B';
                        cnt2++;
                    }
                    cnt0--;
                }
                else if(input[i]=='G'&&cnt1>1){
                    if(cnt0<1) {
                        input[i]='R';
                        cnt0++;
                    }
                    else if(cnt2<1) {
                        input[i]='B';
                        cnt2++;
                    }
                    cnt1--;
                }
                else if(input[i]=='B'&&cnt2>1){
                    if(cnt0<1) {
                        input[i]='R';
                        cnt0++;
                    }
                    else if(cnt1<1) {
                        input[i]='G';
                        cnt1++;
                    }
                    cnt2--;
                }
            }

            int nct=0;
            for(int i=0;i<3;i++) if(temp[i]!=input[i]) nct++;
            cout<<nct<<endl;
            cout<<input<<endl;
        }
    }else{

        vector< string > vec;
        vec.pb("RGB");
        vec.pb("RBG");
        vec.pb("BGR");
        vec.pb("BRG");
        vec.pb("GBR");
        vec.pb("GRB");
        string ans;
        int mini=n+5;

        for(int i=0;i<6;i++){
            string temp;
            temp+=vec[i];

            for(int j=3;j<n;j++){
                if(j%3==0) temp+=vec[i][0];
                if(j%3==1) temp+=vec[i][1];
                if(j%3==2) temp+=vec[i][2];
            }
            int cnt=0;

            for(int j=0;j<n;j++){
                if(temp[j]!=input[j]) cnt++;
            }

            if(cnt<mini) {
                mini=cnt; ans=temp;
            }
        }

        cout<<mini<<endl;
        cout<<ans<<endl;

    }

    return 0;
}
