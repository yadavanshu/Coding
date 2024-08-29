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

    Node * getHeadPointer() {
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

void bubblesort(Node *head){
    Node *curr = head;
    Node *next = NULL;
    while (curr != NULL){
        next = curr->next;
        while (next != NULL){
            if (curr->data > next->data){
                swap(curr->data, next->data);
            }
            next = next->next;
        }
        curr = curr->next;
    }
    return;
}

int main(){
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(39);
    list.append(11);
    list.append(12);
    list.append(15);
    list.append(13);
    list.append(14);
    list.append(9);
    list.append(8);
    list.append(7);
    list.append(6);
    list.append(5);
    list.display();
    bubblesort(list.getHeadPointer());
    list.display();
    return 0;
}