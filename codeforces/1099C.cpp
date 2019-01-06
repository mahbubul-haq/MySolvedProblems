#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pii pair<int,int>
#define ll long long
#define pll pair<ll,ll>
#define vi vector<int>
#define vvi vector<vi>
#define vii vector<pii>
#define vvii vector<vii>
#define vll vector<ll>
#define MOD 998244353
#define EPS 1e-7
#define mem(x,y) memset(x,y,sizeof x)
#define INF 1e9
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

///=======================================template=======================================///

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input; cin>>input;
    int k; cin>>k;

    int ccane=0,snoflake=0;

    for(int i=0;i<input.size();i++){
        if(input[i]=='*')snoflake++;
        if(input[i]=='?') ccane++;
    }

    if(snoflake==0){
        if(k>input.size()-ccane){
            cout << "Impossible" << endl;
        }
        else if(k<input.size()-2*ccane){
            cout<<"Impossible"<<endl;
        }
        else{
            int val=(input.size()-ccane)-k;
            vector<char> ans;
            for(int i=0;i<input.size();i++){
                if(input[i]=='?'){
                    if(val>0){
                        ans.pop_back();
                        val--;
                    }
                }
                else ans.pb(input[i]);

            }

            for(int a=0;a<ans.size();a++) cout<<ans[a];
            cout<<endl;
        }
    }
    else {
        if (k < (input.size() - 2 * snoflake - 2 * ccane)) {
cout << "Impossible" << endl;
        } else {

            int val = k - (input.size() - 2 * snoflake - 2 * ccane)-1;

            bool flag=true;

            vector<char> ans;

            for(int i=0;i<input.size();i++){
                if(input[i]=='?'){
                    ans.pop_back();
                }
                else if(input[i]=='*'&&flag&&val>-1){
                    char temp=ans.back();
                    for(int j=1;j<=val;j++) ans.pb(temp);
                    flag=false;
                }
                else if(input[i]=='*'){
                    ans.pop_back();
                }
                else ans.push_back(input[i]);
            }
            for(int a=0;a<ans.size();a++) cout<<ans[a];
            cout<<endl;
        }


    }

    return 0;
}
