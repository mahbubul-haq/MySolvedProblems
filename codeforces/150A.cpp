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
#define MAX 4e18
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

    ll q; cin>>q;

    vll vec;

    int sqr=sqrt(q);

    ff(i,2,sqr){
        if(q%i==0){
            if(q/i==i) vec.pb(i);
            else{
                vec.pb(i);
                vec.pb(q/i);
            }
        }
    }

    sort(vec.begin(),vec.end());

    int siz=vec.size();

    if(siz==0){
        cout<<1<<endl;
        cout<<0<<endl;
        return 0;
    }

   // ff(i,0,siz-1) cout<<vec[i]<<" ";

    ff(i,0,siz-1){

        if(q%vec[i]==0){

            ff(j,i+1,siz-1){
                if(vec[j]%vec[i]==0){
                    cout<<1<<endl;
                    cout<<vec[j]<<endl;
                    return 0;
                }
            }

        }

    }

    cout<<2<<endl;


    return 0;
}
