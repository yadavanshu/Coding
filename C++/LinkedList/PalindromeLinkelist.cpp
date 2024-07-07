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

    Node * linkedListHead(Node *head){
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

    bool palindromeLinkedlist1(){
        stack<int> st;
        Node *curr = head;
        while(curr!=NULL){
            st.push(curr->data);
            curr=curr->next;
        }
        curr = head;
        while(curr!=NULL && curr->data==st.top()){
            st.pop();
            curr = curr->next;
        }
        return curr==NULL;
    }

};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(3);
    list.append(2);
    list.append(1);
    list.display();
    if(list.palindromeLinkedlist1())
        cout << "true";
    else
        cout << "false";
    cout << endl;
    list.display();
    return 0;
}