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

    Node *LinkedListHead(){
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
    void display(Node *head) {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }


Node *addTwoNumbers(Node *l1, Node *l2){
    int sum = 0;
    int carry = 0;
    Node *ans = new Node(0);
    Node *tmp = ans;
    while(l1!=NULL || l2!=NULL || carry){
        sum = 0;
        if(l1!=NULL){
            sum += l1->data;
            l1 = l1->next;
        }
        if(l2!=NULL){
            sum += l2->data;
            l2 = l2->next;
        }
        sum += carry;

        carry = sum / 10;
        Node *dummy = new Node(sum % 10);
        ans->next = dummy;
        ans = ans->next;
    }
    return tmp->next;
}

int main() {
    LinkedList list1;
    LinkedList list2;
    list1.append(1);
    list1.append(2);
    list1.append(3);
    list1.display();
    list2.append(1);
    list2.append(2);
    list2.append(3);
    list2.append(3);
    list2.append(3);
    list2.append(3);
    list2.display();
    Node *l1 = list1.LinkedListHead();
    Node *l2 = list2.LinkedListHead();

    Node *ans = addTwoNumbers(l1, l2);
    display(ans);

        return 0;
}