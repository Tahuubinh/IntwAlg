#include <bits/stdc++.h>

using namespace std;

void equilibriumIndex(int a[], int n){
    if (n < 3){
        cout << "No answer!" << endl;
    }
    else{
        bool flag = true;
        int left_sum = 0;
        int right_sum = 0;
        for (int i = 1; i < n; i ++){
            right_sum += a[i];
        }
        for (int i = 1; i < n - 1; i++){
            left_sum += a[i - 1];
            right_sum -= a[i];
            if (left_sum == right_sum){
                cout << i << ' ';
                flag = false;
            }
        }
        if (flag){
            cout << "No answer!" << endl;
        }
    }
}

int main(){
    int a[] = {1, 0, -3, 5, -4, -2, 3, 1, 0, 2};
    int n = sizeof(a) / sizeof(a[0]);
    equilibriumIndex(a, n);

    cout << endl;
    system("pause");
    return 0;
}