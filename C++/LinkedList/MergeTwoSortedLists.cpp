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
    Node * getHeadPointer(){
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

LinkedList mergerTwoLinkedList(Node *l1, Node *l2){
    LinkedList result;
    
    while(l1!=NULL && l2!=NULL){
        if(l1->data<l2->data){
            result.append(l1->data);
            l1 = l1->next;
        }else{
            result.append(l2->data);
            l2 = l2->next;
        }
    }
    while(l1!=NULL){
            result.append(l1->data);
            l1 = l1->next;
    }
    while(l2!=NULL){
            result.append(l2->data);
            l2 = l2->next;
    }

    return result;
}





int main() {
    LinkedList l1;
    LinkedList l2;
    l1.append(2);
    l1.append(4);
    l1.append(6);
    l1.append(8);
    l1.append(10);
    l2.append(1);
    l2.append(3);
    l2.append(5);
    l2.append(7);
    l2.append(9);
    l1.display();
    l2.display();

    Node *list1 = l1.getHeadPointer();
    Node *list2 = l2.getHeadPointer();

    LinkedList result = mergerTwoLinkedList(list1, list2);
    result.display();

    return 0;
}