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

    int q; cin>>q;

    ff(i,1,q){
        ll l,r;
        cin>>l>>r;

        ll maxo,maxe,mine,mino,cnt=0;

        if(l==r){
            if(l%2==0) cout<<l<<endl;
            else cout<<-l<<endl;
            continue;
        }

        if(r%2==0){
            maxe=r;
            maxo=r-1;
        }
        else{
            maxe=r-1;
            maxo=r;
        }

        if(l%2==0){
            mine=l;
            mino=l+1;

        }
        else{
            mine=l+1;
            mino=l;
        }

        mine=mine/2;
        maxe=maxe/2;

        cnt+=2*((maxe*(maxe+1))/2 - (mine-1)*mine/2);

        ll oddcnt=0;

        oddcnt=oddcnt+(maxo*(maxo+1)/2);
        oddcnt-=((maxo/2)*(maxo/2+1));

        if(mino!=1) {
            oddcnt -= (mino - 2) * (mino-1)/2;
            oddcnt += ((mino-3)/2)*((mino-3)/2+1);
        }

        if(maxe==mine) cnt=maxe*2;

        if(mino==maxo) oddcnt=mino;

        cout<<cnt-oddcnt<<endl;
    }

    return 0;
}
