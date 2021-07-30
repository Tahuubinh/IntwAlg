#include <bits/stdc++.h>

using namespace std;

void findPair(int a[], int n, int sum){
    map<int, int> flag;
    for (int i = 0; i < n; ++i){
        flag[a[i]] = 1;
    }
    // for (int i = 0; i < 10; ++i){
    //     cout << i << " : " << flag[i] << endl;
    // }
    for (int i = 0; i < n; ++i){
        if(flag[sum - a[i]]){
            cout << a[i] << ' ' << sum - a[i] << endl;
        }
    }
}

int main(){
    int arr[] = { 8, 7, 2, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(int);
    findPair(arr, n, 10);

    cout << endl;
    system("pause");
    return 0;
}