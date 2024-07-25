#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
    void display(){
        Node *curr = this;
        while(curr!=NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
        return;
    }
};

class Listnode{
    public:
    int data;
    Listnode *next;
    Listnode(int x) : data(x), next(NULL){};
    void display()
    {
        Listnode *curr = this;
        while (curr != NULL){
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
        return;
    }
};


int main(){
    Listnode *head=new Listnode(12);
    head->next = new Listnode(13);
    head->next->next = new Listnode(14);
    head->display();

    Node *root=new Node(15);
    root->next = new Node(16);
    root->next->next = new Node(17);
    root->display();
    
    while (root != NULL)
    {
        Node *temp = root;
        root = root->next;
        delete temp;
    }

    while (head != NULL)
    {
        Listnode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}