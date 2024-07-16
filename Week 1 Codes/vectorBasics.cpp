#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int> a){
    for(int i=0; i<a.size(); i++) cout << a[i] << " ";
    cout << endl;
}

int main(){
    int n, x;
    // Vector Declaration
    vector<int> a ;

    // Input in a vector
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        a.push_back(x);
    }

    cout << "Size: " << a.size() << endl;
    print_vec(a);
    a.push_back(100);
    cout << "Size: " << a.size() << endl;
    print_vec(a);

//    a.erase(a.begin() + 2);
    a.erase(a.end()-1);

    cout << "Size: " << a.size() << endl;
    print_vec(a);
    return 0;
}
