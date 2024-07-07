#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    Node * listHead(){
        return head;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int length(Node *head){
    int len = 0;
    while(head!=NULL){
        len++;
        head = head->next;
    }
    return len;
}

int intersection(Node *l1, Node *l2){
    int len1 = length(l1);
    int len2 = length(l2);
    int count = 0;
    if(len1>len2){
        count = len1 - len2;
        while(count>0){
            l1 = l1->next;
            count--;
        }
    }else{
        count = len2 - len1;
        while(count>0){
            l2 = l2->next;
            count--;
        }
    }
    while(l1!=NULL && l2!=NULL){
        if(l1->data==l2->data)
            return l1->data;
        l1 = l1->next;
        l2 = l2->next;
    }
    return -1;
}

int main() {
    LinkedList l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    
    LinkedList l2;
    l2.append(8);
    l2.append(4);
    l2.append(5);
    l2.append(6);
    l2.append(7);
    l1.display();
    l2.display();
    Node *list1 = l1.listHead(), *list2 = l2.listHead();

    cout << intersection(list1, list2);

    return 0;
}