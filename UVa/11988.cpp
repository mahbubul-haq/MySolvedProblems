#include<iostream>
#include<cstdio>
#include<set>
#include<queue>
#include<cstring>
#include<math.h>
#include<map>
#include<string>
#include<climits>
#include<algorithm>
#include <iomanip>
#include <vector>
#include <stack>
#include <list>
#include <iterator>
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


    string input;

    while(cin>>input){
        list<char> text;
     //   debugx(input);


        bool flag=false;
        int i=0;
        while(i<(int)input.size()){


            if(flag){
                string temp;

                while(i<(int)input.size()&&input[i]!='['&&input[i]!=']'){
                    temp+=input[i++];
                }

               // list<char>::iterator it=text.begin();

                fb(j,(int)temp.size()-1,0){
                    text.push_front(temp[j]);
                }

                if(input[i]=='[') {
                    flag=true;
                }
                else flag=false;

                i++;

            }
            else if(!flag&&input[i]=='['){
                flag=true; i++;
            }
            else if(input[i]!=']') text.push_back(input[i++]);
            else i++;

        }

        list<char>::iterator it=text.begin();

        while(it!=text.end()) cout<<*it++;
        cout<<endl;

    }



    return 0;
}
