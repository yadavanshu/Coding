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

    int length(){
        Node *temp = head;
        int count = 0;
        while(temp){
            count++;
            temp=temp->next;
        }
        return count;
    }

    void deleteFromBack(int n){
        if(head == NULL)
            return;
        int len = length();
        if(len==1){
            delete (head);
            return;
        }
        if(n>len)
            return;
        if(n==len){
            Node *temp = head;
            head = head->next;
            delete (temp);
            return;
        }
        int target = len - n - 1;
        Node *curr = head;
        while(target>0){
            curr = curr->next;
            target--;
        }
        Node *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return;
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
    int n = 2;
    list.deleteFromBack(n);
    list.display();
    return 0;
}