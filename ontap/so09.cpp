#include<bits/stdc++.h>
using namespace std;
void xuly(int n){
    queue<int> Q;
    Q.push(9);
    while(!Q.empty()){
        int x = Q.front();
        Q.pop();
        if(x%n == 0){
            cout << x << endl;
            break;
        }
        Q.push(x*10+6);
        Q.push(x*10 + 8);
    }
}
main(){
    int t, n;
    cin >> t;
    while(t--){
        cin >> n;
        xuly(n);
    }
}

