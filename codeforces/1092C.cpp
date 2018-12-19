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

bool dp[200][3];
vector<string> vec;
int ans[200];
int n;



int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;
    cin>>n;

    string pre,pos;
    bool flag=true;

    for(int i=1;i<=2*n-2;i++){
        string input; cin>>input;

        vec.pb(input);

        if(flag&&input.size()==n-1){
            pre=input;
            flag=false;
        }
        else if(!flag&&input.size()==n-1){
            pos=input;
        }

    }

    string f=pre+pos[pos.size()-1];

    char ans[2*n];
    map<int,char>myMap;
    flag=true;

    bool isPos=true;

    for(int i=0;i<2*n-2;i++){

        if(vec[i].size()==n-1&&flag){
            ans[i]='P';
            flag=false;
        }
        else if(vec[i].size()==n-1&&!flag){
            ans[i]='S';
        }
        else{

            bool haha=true;

            for(int j=0;j<vec[i].size();j++){
                if(vec[i][j]!=f[j]){
                    haha=false;
                    break;
                }
            }
            if(haha&&myMap[(int)vec[i].size()]!='P'){
                myMap[(int)vec[i].size()]='P';
                ans[i]='P';
            }
            else{
                haha=true;
                for(int j=vec[i].size()-1,k=f.size()-1;j>=0;j--,k--){
                    if(f[k]!=vec[i][j]){
                        haha=false;
                        break;
                    }
                }
                if(haha&&myMap[(int)vec[i].size()]!='S'){
                    ans[i]='S';
                    myMap[(int)vec[i].size()]='S';
                }
                else{
                    isPos=false;
                    break;
                }
            }

        }


    }

    if(isPos) {
        for (int i = 0; i < 2 * n - 2; i++) cout << ans[i];
        cout << endl;
        return 0;
    }
    f.clear();
    f=pos+pre[pre.size()-1];
    myMap.clear();

    flag=true;

    isPos=true;

    for(int i=0;i<2*n-2;i++){

        if(vec[i].size()==n-1&&flag){
            ans[i]='S';
            flag=false;
        }
        else if(vec[i].size()==n-1&&!flag){
            ans[i]='P';
        }
        else{

            bool haha=true;

            for(int j=0;j<vec[i].size();j++){
                if(vec[i][j]!=f[j]){
                    haha=false;
                    break;
                }
            }
            if(haha&&myMap[(int)vec[i].size()]!='P'){
                myMap[(int)vec[i].size()]='P';
                ans[i]='P';
            }
            else{
                haha=true;
                for(int j=vec[i].size()-1,k=f.size()-1;j>=0;j--,k--){
                    if(f[k]!=vec[i][j]){
                        haha=false;
                        break;
                    }
                }
                if(haha&&myMap[(int)vec[i].size()]!='S'){
                    ans[i]='S';
                    myMap[(int)vec[i].size()]='S';
                }
                else{
                    isPos=false;
                    break;
                }
            }

        }


    }

    for (int i = 0; i < 2 * n - 2; i++) cout << ans[i];
    cout << endl;
    return 0;

    return 0;
}
