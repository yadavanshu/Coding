#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
class Solution
{
public:
    Node *insertAtBegining(Node *head, int x)
    {
        if (head == NULL)
        {
            head = new Node(x);
            return head;
        }
        Node *temp = new Node(x);
        temp->next = head;
        return temp;
    }

    Node *insertAtEnd(Node *head, int x)
    {
        if (head == NULL)
        {
            head = new Node(x);
            return head;
        }
        Node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = new Node(x);
        return head;
    }
    void printList(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << "\n";
    }
    void deleteNode(Node *node)
    {
        Node *nextNode = node->next;
        node->data = node->next->data;
        node->next = node->next->next;
        delete (nextNode);
    }
    int lengthLinkedlist(Node *head)
    {
        int count = 0;
        while (head != NULL)
        {
            count++;
            head = head->next;
        }
        return count;
    }

};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    Node *head = NULL;
    for (int i = 0; i < n; ++i)
    {
        int data, indicator;
        cin >> data;
        cin >> indicator;
        Solution obj;
        if (indicator)
            head = obj.insertAtEnd(head, data);
        else
            head = obj.insertAtBegining(head, data);
    }
    obj.printList(head);
    cout << obj.lengthLinkedlist(head);
    cout << endl;
    return 0;
}