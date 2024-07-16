#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int c[100];
    int n,d,tc = 0;
    cin >> n >> d;
    for(int i=0; i<d; i++) cin >> c[i] ;
    sort(c, c+d, greater<int>());
    for(int i=0; i<d && n>0; i++){
        if(c[i] <= n){
            tc += n/c[i];
            n = n%c[i];
        }
    }
    cout << tc << endl;
    return 0;
}

