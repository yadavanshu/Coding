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

    int middleNode(){
        if(head==NULL)
            return -1;
        Node *slow = head;
        Node *fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow->data;
    }

    void reverseLinkedList(){
        Node *curr = head;
        Node *prev=NULL, *next = NULL;
        while(curr!=NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    void recursiveReverseLinkedList(Node *curr){
        if(curr==NULL)
            return;
        recursiveReverseLinkedList(curr);
        }

};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    list.append(6);
    list.append(7);

    list.display();
    cout<<list.middleNode()<<endl;
    cout << "ReverseList: ";
    list.reverseLinkedList();
    list.display();
    return 0;
}