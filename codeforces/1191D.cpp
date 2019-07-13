 #include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<ll>
#define pb push_back
 
void a(){
    cout<<"sjfnb"<<endl;
    exit(0);
}
 
void b(){
    cout<<"cslnb"<<endl;
    exit(0);
}
 
int main()
{
    //FI;//FO;
    //FastIO;//timeInit;
 
    int n; cin>>n;
 
    if(n==1){
        int x; cin>>x;
        if(x&1){
            a();
        }
        else b();
    }
 
    ll cnt=0;
 
    int nn=n;
    ll last=0;
    vll data;
    while(n--){
        ll aa; cin>>aa;
        data.pb(aa);
    }
 
    sort(data.begin(), data.end());
    
    int cn=0;
    
    for(int i=1;i<nn;i++){
        if(data[i]==data[i-1])
            cn++;
        if(data[i]==data[i-1] and data[i]==0)
            b();
        if(data[i]==data[i-1] and (i>1 and data[i-2]+1==data[i-1]))
            b();
 
    }
    if(cn>1)
        b();
    
    int j=0;
    for(int i=0;i<nn;i++){
        ll cntt=(data[i]-j>0? data[i]-j:0);
        if(data[i]-j>=0)
            j++;
        cnt+=cntt;
    }
 
    if(cnt&1)
        a();
    else b();
 
    //timeTaken;
    return 0;
}
