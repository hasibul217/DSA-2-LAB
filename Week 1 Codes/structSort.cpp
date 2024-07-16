#include <iostream>
#include <algorithm>

using namespace std;

struct Employee{
    char name[100];
    int height;
    int age;
};

bool compEmp(struct Employee e1, struct Employee e2){
    if(e1.height > e2.height) return true;
    else if(e1.height == e2.height && e1.age > e2.age) return true;
    else return false;

}


void sortStruct(struct Employee e[], int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n;j++){
            if(e[i].height < e[j].height) swap(e[i], e[j]);
            else if(e[i].height == e[j].height && e[i].age < e[j].age) swap(e[i], e[j]);
        }

    }
}


int main(){
    struct Employee e[100];
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> e[i].name >> e[i].height >> e[i].age;
    }
    cout << "After sorting:" <<endl;
//    sortStruct(e,n);
    sort(e, e+n, compEmp);
    for(int i=0; i<n; i++){
        cout << e[i].name << " " << e[i].height << " " <<  e[i].age << endl;
    }
    return 0;

}
