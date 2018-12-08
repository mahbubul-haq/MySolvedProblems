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

string text,pattern;
int n,m;
vi indices;
vi border;

void kmpPreprocess(){
    border.assign(m+1,0);
    border[0]=-1;

    int i=0,j=-1;

    while(i<m){

        while(j>=0&&pattern[i]!=pattern[j]) j=border[j];
        i++;j++;
        border[i]=j;
    }

}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    while(cin>>pattern&&pattern!="End"){

            m=pattern.size();

            kmpPreprocess();

            for(int i=1;i<=m-1;i++){
                cout<<border[i]<<" ";
            }
            cout<<border[m]<<endl;
    }

    return 0;
}
