#include <bits/stdc++.h>

using namespace std;

void Boyer_Moore(int a[], int n){
    int m = a[0];
    int count = 0;
    for (int i = 0; i < n; ++i){
        if (count == 0){
            m = a[i];
            count = 1;
        }
        else if (m == a[i]){
            ++count;
        }
        else{
            --count;
        }
    }
    int check = 0; // check if m is really the answer
    for (int i = 0; i < n; ++ i){
        if (a[i] == m){
            ++check;
        }
    }
    if (check > n/2){
        cout << m << endl;
    }
    else {
        cout << "No suitable element!" << endl;
        cout << m << ' ' << check;
    }
}

int main(){
    int arr[] = { 1, 2, 7, 2, 1, 1, 2, 2, 2, 2, 8 };
    int n = sizeof(arr)/sizeof(arr[0]);
    Boyer_Moore(arr, n);

    cout << endl;
    system("pause");
    return 0;
}