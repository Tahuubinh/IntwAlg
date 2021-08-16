/*
    Time: O(n)
    Space: O(n)
*/
#include <bits/stdc++.h>

using namespace std;

char* stack_to_string(stack<char> charStack){
    int stackSize = charStack.size();
    char* string_from_stack = new char[stackSize + 1];
    int i = stackSize - 1;
    while (!charStack.empty()){
        string_from_stack[i] = charStack.top();
        --i;
        charStack.pop();
    }
    // return string in C
    string_from_stack[stackSize] = '\0';
    char* pointer = string_from_stack;
    return pointer;
}

bool isPalindrome(char* s, int low, int high){
    if (strlen(s) == 0){
        return true;
    }
    if(low < high){
        if (s[low] == s[high]){
            return isPalindrome(s, low + 1, high - 1);
        }
        else {
            return false;
        }
    }
    return true;
}

bool isPalindrome(stack<char> charStack){
    void printStack(stack<char> charStack);
    char* string_from_stack = stack_to_string(charStack);
    return isPalindrome(string_from_stack, 0, charStack.size() - 1);
}

void printStack(stack<char> charStack){
    // while (!charStack.empty()){
    //     cout << charStack.top() << ' ';
    //     charStack.pop();
    // }
    // cout << endl;
    if (!charStack.empty()){
        char temp = charStack.top();
        charStack.pop();
        printStack(charStack);
        cout << temp << ' ';
    } // bottom goes up
}

bool isRotatedPalindrome(char s[]){
    int length = strlen(s);
    stack<char> charStack;
    // s has the same palindrome state as charStack
    for (int i = 0; i < length; i++){
        if (charStack.empty()){
            charStack.push(s[i]);
        }
        else if (s[i] == charStack.top()){
            charStack.pop();
        }
        else {
            charStack.push(s[i]);
        }
    }
    return isPalindrome(charStack);
}



int main(){
    char s[] = "bbcbbaa";
    printf(s);
    cout << endl;
    cout << s << endl;
    // stack<char> charStack;
    // charStack.push('d');
    // charStack.push('c');
    // charStack.push('c');
    // charStack.push('d');
    // printStack(charStack);
    // cout << endl;
    // cout << isPalindrome(charStack);
    // cout << endl;
    // char* string_from_stack = stack_to_string(charStack);
    cout << isRotatedPalindrome(s);
    // cout << isPalindrome(stack_to_string(charStack), 0, strlen(stack_to_string(charStack) - 1)) << endl;
    // printf(stack_to_string(charStack));              // having some errors



    cout << endl;
    system("pause");
    return 0;
}