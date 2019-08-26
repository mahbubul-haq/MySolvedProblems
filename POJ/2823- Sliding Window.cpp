#include <iostream>
#include <vector>
#include <deque>
#include <cstdio>
using namespace std;

#define vi vector<int>
#define ll long long
#define pb push_back
#define sfi(x) scanf("%d",&x)
#define sfii(x,y) scanf("%d %d",&x,&y)



///=======================================template=======================================///

int main()
{
   // ios_base::sync_with_stdio(false),cin.tie(),cout.tie();
    //FI;//FO;
    //FastIO;//timeInit;

    int n; sfi(n);
    int k,x; sfi(k);

    deque<pair<int,int> > maxq,minq;

    vi mini,maxi;
    int now=0;

    while(now<n){
        sfi(x);

        while(!maxq.empty() and maxq.front().first<x)
            maxq.pop_front();

        while(!minq.empty() and minq.front().first>x)
            minq.pop_front();

        maxq.push_front(make_pair(x,now));
        minq.push_front(make_pair(x,now));

        while(maxq.back().second<=now-k){
            maxq.pop_back();
        }
        while(minq.back().second<=now-k)
            minq.pop_back();

        if(now>=k-1) {
            mini.push_back(minq.back().first);
            maxi.push_back(maxq.back().first);
        }

        now++;
    }

    for(int i=0;i<n-k+1;i++){
        printf("%d ",mini[i]);
    }
    printf("\n");
    for(int i=0;i<n-k+1;i++){
        printf("%d ",maxi[i]);
    }
    printf("\n");

    //timeTaken;
}
