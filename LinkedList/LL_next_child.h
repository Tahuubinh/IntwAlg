#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* child;
};

Node* createNode(int data){
    Node* node = new Node;
    node->data = data;
    node->next = NULL;
    node->child = NULL;
    return node;
}

Node* addNext(Node* node, int data){
    if (node == NULL){
        node = createNode(data);
        return node;
    }
    else {
        Node* newnode = createNode(data);
        Node* temp = node;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        return node;
    }
}

Node* addChild(Node* node, int data){
    if (node == NULL){
        node = createNode(data);
        return node;
    }
    else {
        Node* newnode = createNode(data);
        Node* temp = node;
        while (temp->child != NULL){
            temp = temp->child;
        }
        temp->child = newnode;
        return node;
    }
}

void printNext(Node* node){
    while (node != NULL){
        cout << node ->data << ' ';
        node = node->next;
    }
    cout << endl;
}

void printChild(Node* node){
    while (node != NULL){
        cout << node ->data << "\n|\n";
        node = node->child;
    }
    cout << endl;
}

Node* searchNode(Node* head, int data){
    while (head != NULL){
        if (head->data == data){
            return head;
        }
        head = head->next;
    }
    cout << "Unexisted node!\n";
    return NULL;
}

void informationNode(Node* node){
    if (node == NULL){
        return;
    }
    cout << node -> data << '\t';
    if (node->next != NULL)
        cout << node->next->data;
    cout << endl;
    if (node->child != NULL)
        cout << node->child->data << endl;
}

Node* flattenNode(Node* head){      // Should use queue instead of vector
    if (head == NULL){
        cout << "Empty linkedlist";
        return head;
    }

    vector<Node*> LLvector;
    vector<Node*> tempvector;

    Node* tail = head;
    LLvector.push_back(tail);
    while (tail->next != NULL){
        tail = tail->next;
        LLvector.push_back(tail);
    }

    while (!LLvector.empty()){
        for (Node* node: LLvector){
            Node* temp = node->child;
            while (temp != NULL){
                tail->next = temp;
                tail = tail->next;
                if (temp->child != NULL){
                    tempvector.push_back(temp);
                }
                temp = temp->next;
            }
        }
        LLvector.clear();
        LLvector = tempvector;
        tempvector.clear();
    }
    return head;
}