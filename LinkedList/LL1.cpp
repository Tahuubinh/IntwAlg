#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    return node;
}

Node* push(Node* node, int data){
    if (node == NULL){
        node = new Node;
        node->data = data;
        node->next = NULL;
        return node;
    }
    else {
        Node* newnode = new Node;
        newnode->data = data;
        newnode->next = NULL;
        Node* temp = node;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        return node;
    }
}

void printLL(Node* node){
    while (node != NULL){
        cout << node ->data << ' ';
        node = node->next;
    }
    cout << endl;
}

int main(){
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    Node* head = NULL;

    for (int i = 0; i < n; ++i) {
        head = push(head, keys[i]);
    }
    
    // while (node != NULL){
    //     cout << node ->data << ' ';
    //     node = node->next;
    // }
    printLL(head);
 
    // insert cycle
    //head->next->next->next->next->next = head->next->next;


    cout << endl;
    system("pause");
    return 0;
}