#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
unordered_map<int, bool> taken;
int Set(int mask, int pos) { return mask = (mask | (1 << pos));}
int lim;
void rec(int mask, int pos, vector<int> &ara) {
    if (pos > lim)
        return;
    if (!taken[mask]) {
        ara.push_back(mask);
        taken[mask] = true;
    }
    if (ara.size() >= 100)
        return ;
    rec(Set(mask, pos), pos + 1, ara);
    rec(mask, pos + 1, ara);
}
 
int main() {
 
    vector<int> ara[2];
    int mask = 0;
    for (int i = 0; i < 7; i ++) {
        mask = Set(mask, i);
    }
 
    lim = 14;
    rec(mask, 7, ara[0]);
    mask = 0;
    for (int i = 7; i < 14; i ++) {
        mask = Set(mask, i);
    }
    lim = 7;
    rec(mask, 0, ara[1]);
 
    cout << "?";
 
    for (int i = 0; i < 100; i++) {
        cout << " " << ara[0][i];
    }
    cout << endl;
    cout << flush;
    int x, ans = 0;
    cin >> x;
 
    for (int i = 0; i < 7; i++) {
        if (!(x & (1 << i))) {
            ans = Set(ans, i);
        }
    }
 
    cout <<"?";
    for (int i = 0; i < 100; i++) {
        cout << " " << ara[1][i];
    }
    cout << endl;
    cout << flush;
    cin >> x;
 
    for (int i = 7; i < 14; i++) {
        if (!(x & (1 << i))) {
            ans = Set(ans, i);
        }
    }
 
    cout << "! " << ans << endl;
 
    return 0;
}
