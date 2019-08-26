#include <bits/stdc++.h>
using namespace std;
 
#define endl                        "\n"
#define INF              1000000000000000000
#define ld                          long double
#define ll                          long long
#define mem(x,y)                    memset(x,y,sizeof x)
#define mp                          make_pair
#define msi                         map<string,int>
#define mii                         map<int,int>
#define mis                         map<int,string>
#define MOD                         998244353
#define PI                          acos(-1.0)
#define PQ                          priority_queue
#define pb                          push_back
#define pib                         pair<int,bool>
#define pii                         pair<int,int>
#define pll                         pair<ll,ll>
#define sfi(x)                      scanf("%d",&x)
#define sfii(x,y)                   scanf("%d%d",&x,&y)
#define sfiii(x,y,z)                scanf("%d%d%d",&x,&y,&z)
#define siz(x)                      (int)x.size()
#define sortv(v)                    sort(v.begin(),v.end())
#define ss                          second
#define timeTaken                   endd=clock();cout<<(double)(endd-beginn)/CLOCKS_PER_SEC*1000<<endl
#define timeInit                    clock_t beginn=clock(),endd
#define ull                         unsigned long long
#define umsi                        unordered_map<string,int>
#define umii                        unordered_map<int,int>
#define umis                        unordered_map<int,string>
#define vb                          vector<bool>
#define vi                          vector<int>
 
 
///=======================================template=======================================///
 
class data{
public:
    ll suff,pref,ans,sum;
    data(){
        suff=pref=ans=sum=0;
    }
    data(ll x){
        suff=pref=ans=sum=x;
    }
};
 
vi ara;
vector<data> st;
 
int left(int node){return (node<<1);}
int right(int node){return (node<<1)|1;}
int mid(int l,int r){
    return (l+r)>>1;
}
 
void combine(int node){
    st[node].sum=st[left(node)].sum+st[right(node)].sum;
    st[node].ans=max(st[left(node)].ans,max(st[right(node)].ans,st[left(node)].suff+st[right(node)].pref));
    st[node].pref=max(st[right(node)].pref+st[left(node)].sum,st[left(node)].pref);
    st[node].suff=max(st[right(node)].sum+st[left(node)].suff,st[right(node)].suff);
}
 
data combine(data lef,data rig){
    data temp;
    temp.sum=lef.sum+rig.sum;
   temp.ans=max(lef.ans,max(rig.ans,lef.suff+rig.pref));
   temp.pref=max(rig.pref+lef.sum,lef.pref);
    temp.suff=max(rig.sum+lef.suff,rig.suff);
    return temp;
}
 
void build(int node,int l,int r){
    if(l==r){
        st[node].sum=st[node].pref=st[node].suff=st[node].ans=ara[l];
    }
    else{
        build(left(node),l,mid(l,r));
        build(right(node),mid(l,r)+1,r);
        combine(node);
    }
}
 
void update(int node,int l,int r,int idx,int val){
    if(idx<l or idx> r)
        return ;
    if(l==r and idx==l){
        st[node].pref=st[node].suff=st[node].ans=st[node].sum=val;
        return;
    }
    update(left(node),l,mid(l,r),idx,val);
    update(right(node),mid(l,r)+1,r,idx,val);
    combine(node);
}
 
data query(int node,int l, int r, int i,int j){
    if(i>r or j<l)
        return {-INF};
    if(l>=i and r<=j){
        return st[node];
    }
    data lef=query(left(node),l,mid(l,r),i,j);
    data rig=query(right(node),mid(l,r)+1,r,i,j);
    if(lef.suff==-INF)
        return rig;
    if(rig.suff==-INF)
        return lef;
    return combine(lef,rig);
}
 
int main()
{
    //FI;//FO;
    //FastIO;//timeInit;
 
 
    int n; cin>>n;
    ara.resize(n);
    st.resize(4*n,data());
 
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
 
    build(1,0,n-1);
 
    int q; cin>>q;
 
    while(q--){
        int type; cin>>type;
 
        if(type){
            int x,y;
            cin>>x>>y;
            x--,y--;
            cout<<query(1,0,n-1,x,y).ans<<endl;
        }
        else{
            int x,val;
            cin>>x>>val;
            x--;
            update(1,0,n-1,x,val);
        }
    }
 
 
    //timeTaken;
    return 0;
} 
