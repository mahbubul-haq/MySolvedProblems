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

vi border;

void kmpPreprocess(string const input){
    int siz=input.size();
    border.assign(siz+1,0);
    border[0]=-1;
    int i=0,j=-1;

    while(i<siz){
        while(j>=0&&input[i]!=input[j]){ j=border[j];}

        i++,j++;
        border[i]=j;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    string input; cin>>input;

    kmpPreprocess(input);

    int siz=input.size();

    if(border[siz]==0){
        cout<<"Just a legend"<<endl;
        return 0;
    }

    int temp=border[siz];

    bool taken[siz+1]; mem(taken,false);

    for(int i=1;i<siz;i++){

        if(border[i]<=i-1){
            taken[border[i]]=true;
        }

    }
    int j=border[siz];
    int idx=-1;
    while(j!=-1){

        if(taken[j]){
            idx=j;
            break;
        }
        j=border[j];

    }

    if(idx==-1||idx==0){
        cout<<"Just a legend"<<endl;
    }
    else{
        for(int i=0;i<idx;i++) cout<<input[i];
    }

    cout<<endl;

    return 0;
}
