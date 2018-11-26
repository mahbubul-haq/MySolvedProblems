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

    int n; cin>>n;
if(n==1){
 cout<<1<<endl;
return 0;
}
if(n==2){
 cout<<1<<" "<<1<<endl;
return 0;
}



    vector< vi > Leafs;
    Leafs.assign(n+1,vi());

    int ara[n+1];
    ff(i,2,n){
        cin>>ara[i];
    }

    int colorn[100005];
    mem(colorn,0);

    fb(i,n,2){

        if(Leafs[i].size()==0){
            colorn[i]=1;
            colorn[ara[i]]=colorn[ara[i]]+1;
            Leafs[ara[i]].pb(i);
        }
        else{

            colorn[ara[i]]=colorn[ara[i]]+colorn[i];
            Leafs[ara[i]].pb(1);

          //  int siz=(int) Leafs[i].size();

            //ff(j,0,siz-1){
            //    Leafs[ara[i]].pb(Leafs[i][j]);
           // }
        }

    }

  //  vii vec;

  //  int cnt[100005];
   // mem(cnt,0);



    //sort(vec.begin(),vec.end());

    sort(colorn+1,colorn+n+1);

  ///  ff(i,0,vec.size()-1) cout<<vec[i].first<<" "<<vec[i].second<<endl;


    //int colorcnt=1;


    for(int k=1;k<=n;k++){

        cout<<colorn[k]<<" ";

    }


    return 0;
}
