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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n1,n2,w;

    int cas=1;
    while(cin>>n1>>n2>>w&&!(n1==0&&n2==0&&w==0)){
        vi t1(n1+2,-1),t2(n2+2,-1);

        int cntt1=0,cntt2=0;

        for(int i=0;i<w;i++){
            int x; cin>>x;

            int kk=0;
            bool flag=true;

            while(true){
                kk++; if(kk>3000) break;

                if(flag){

                    int fx=x%n1;
                    if(t1[fx]==-1){
                        t1[fx]=x;
                        cntt1++;
                        break;
                    }
                    else{

                        flag=false;
                        int temp=x;
                        x=t1[fx];
                        t1[fx]=temp;

                    }

                }
                else{

                    int fx=x%n2;
                    if(t2[fx]==-1){
                        t2[fx]=x;
                        cntt2++;
                        break;
                    }
                    else{

                        flag=true;
                        int temp=x;
                        x=t2[fx];
                        t2[fx]=temp;

                    }

                }

            }

        }
        cout<<"Case "<<cas++<<":"<<endl;

        if(cntt1!=0){

            cout<<"Table 1"<<endl;
            for(int i=0;i<n1;i++){
                if(t1[i]!=-1){
                    cout<<i<<":"<<t1[i]<<endl;
                }
            }

        }
        if(cntt2!=0){

            cout<<"Table 2"<<endl;
            for(int i=0;i<n2;i++){
                if(t2[i]!=-1){
                    cout<<i<<":"<<t2[i]<<endl;
                }
            }

        }



    }

    return 0;
}
