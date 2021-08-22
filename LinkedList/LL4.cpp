#include <bits/stdc++.h>
#include "LL_next_child.h"

using namespace std;

int main(){
    Node* head = createNode(1);
    for (int i = 2; i < 6; ++i){
        head = addNext(head, i);
    }

    head = addChild(head, 6);

    Node* temp = searchNode(head, 3);
    temp = addChild(temp, 8);
    temp = temp->child;
    temp = addNext(temp, 9);

    temp = head->child;
    temp = addNext(temp, 7);
    temp = temp->next;
    temp = addChild(temp, 10);
    temp = temp->child;
    temp = addNext(temp, 11);
    temp = temp->next;
    temp = addChild(temp, 12);
    temp = temp->child;

    printNext(head);

    informationNode(head->child->next);

    Node* flat_node = flattenNode(head);
    printNext(flat_node);

    // vector<int> v;
    // v.assign(6, 8);
    // v.push_back(6);
    // vector<int> u;
    // u = v;
    // for (int i:u){
    //     cout << i;
    // }
    // v.clear();
    // cout << endl;
    // for (int i:u){
    //     cout << 'u';
    //     cout << i;
    // }
    // cout << endl;
    // for (int i:v){
    //     cout << i;
    // }

    
    cout << endl;
    system("pause");
    return 0;
}