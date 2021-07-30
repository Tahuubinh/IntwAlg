#include <bits/stdc++.h>

using namespace std;

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print(int a[], int n){
    for (int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << endl;
}

int everySecond(int a[], int n){
    int last_index = n - 2;
    cout << last_index << endl;
    for (int i = 1; i <= last_index; i = i + 2){
        if (a[i] < a[i - 1]){
            swap(&a[i], &a[i-1]);
            print(a, n);
        }
        if (a[i] < a[i + 1]){
            swap(&a[i], &a[i+1]);
            print(a, n);
        }
    }
    if (n % 2 == 0){
        if (a[n] < a[n - 1]){
            swap(&a[n], &a[n-1]);
        }
    }
}

int main(){
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    // int a[] = {9, 6, 8, 3, 7};
    // int a[] = {6, 9, 2, 5, 4, 1};
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n);
    // swap(&a[1], &a[2]);
    // print(a, n);
    everySecond(a, n);
    print(a, n);



    cout << endl;
    system("pause");
    return 0;
}