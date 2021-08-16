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

bool checkCycle(Node* head){
    if (head == NULL)
        return false;
    Node* slow = head;
    Node* fast = head -> next;
    while (fast != NULL && fast -> next != NULL){
        if (fast == slow){
            return true;
        }
        fast = fast -> next -> next;
        slow = slow -> next;
    }
    return false;
}

int main(){
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    Node* head = NULL;

    for (int i = 0; i < n; ++i) {
        head = push(head, keys[i]);
    }
    
    
    printLL(head);
 
    // insert cycle
    //head->next->next->next->next->next = head->next->next;
    if (checkCycle(head)){
        cout << "Have cycle";
    }
    else{
        cout << "No cycle";
    }


    cout << endl;
    system("pause");
    return 0;
}