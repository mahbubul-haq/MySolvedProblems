#include<bits/stdc++.h>
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int T; cin>>T;

    ff(cas,1,T){

        ll cnt=1;
        string input; cin>>input;
        int siz=input.size();
        for(int i=0;i<siz;i++){
            if(i==0&&input[i]=='?'){
                while(input[i]=='?') i++;
                i--;
            }
            else if(input[i]=='?'){
                char ch=input[i-1];
                int tempcnt=0;
                while(i<siz&&input[i]=='?') {
                        i++;
                        tempcnt++;
                }
                if(i==siz){
                    break;
                }
                else{
                    char ch1=input[i];
                    if(ch!=ch1) cnt=(cnt*(tempcnt+1))%MOD;
                }
            }
        }
        cout<<cnt<<endl;

    }

    return 0;
}
