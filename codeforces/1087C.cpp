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

    int ax,ay,bx,by,cx,cy;

    cin>>ax>>ay>>bx>>by>>cx>>cy;

    int distab=dist2D(ax,ay,bx,by);
    int distac=dist2D(ax,ay,cx,cy);
    int distbc=dist2D(bx,by,cx,cy);


    int ans=0;

    set<pii> ansa;
    ansa.insert(pii(ax,ay));
    ansa.insert(pii(bx,by));
    ansa.insert(pii(cx,cy));

    int tempax,tempay,tempby,tempcy,tempbx,tempcx;

    int minx=min(ax,min(bx,cx));

    if(minx==ax){
        minx=min(bx,cx);
        if(minx==bx){

        }
        else {
            tempbx=bx,tempby=by;
            bx=cx,by=cy;
            cx=tempbx,cy=tempby;
        }
    }
    else if(minx==bx){

        tempax=ax,tempay=ay;
        ax=bx,ay=by;
        bx=tempax,by=tempay;

        minx=min(bx,cx);
        if(minx==bx){

        }
        else {
            tempbx=bx,tempby=by;
            bx=cx,by=cy;
            cx=tempbx,cy=tempby;
        }

    }
    else{

        tempax=ax,tempay=ay;
        ax=cx,ay=cy;

        cx=tempax,cy=tempay;

        minx=min(bx,cx);
        if(minx==bx){

        }
        else {
            tempbx=bx,tempby=by;
            bx=cx,by=cy;
            cx=tempbx,cy=tempby;
        }


    }
            for(int i=ax;i<=bx;i++){
                ansa.insert(pii(i,ay));
            }


            for(int i=min(ay,by);i<=max(ay,by);i++){
                ansa.insert(pii(bx,i));
            }

            for(int i=min(cy,by);i<=max(cy,by);i++){
                ansa.insert(pii(bx,i));
            }

            for(int i=bx;i<=cx;i++){
                ansa.insert(pii(i,cy));
            }

    cout<<ansa.size()<<endl;

    set<pii> ::iterator it=ansa.begin();

    while(it!=ansa.end()){
        cout<<(*it).first<<" "<<(*it).second<<endl;
        it++;
    }



    return 0;
}
