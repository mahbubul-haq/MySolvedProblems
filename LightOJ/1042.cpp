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

    int n;

    cin>>n;

    ff(i,1,n){
        int N;
        cin>>N;

        string str;

        while(N){
            str+=(N%2)+48;
            N/=2;
        }
        str+='0';



       // cout<<str<<endl;

       // string str1;
        int siz=str.size();

        bool flag=false;
        int cnt=0;

        ff(ii,0,siz-1){
            if(flag&&str[ii]=='0'){
                str[ii]='1';
                for(int j=0;j<cnt-1;j++){
                    str[j]='1';
                }
                for(int j=cnt-1;j<ii;j++) str[j]='0';
                break;
            }
            if(str[ii]=='1') {
                    cnt++;
                    flag=true;
            }
            ///else if(!flag&&str[ii]=='0') flag=true;
        }

        //cout<<str<<endl;

        ll ans=0;

        ll mult=1;

        for(int ii=0;ii<siz;ii++){
            int temp=str[ii]-48;
            ans+=mult*temp;
            mult*=2;
        }

        cout<<"Case "<<i<<": "<<ans<<endl;


    }

    return 0;
}
