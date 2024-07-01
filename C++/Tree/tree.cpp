#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int data;
    Tree *left;
    Tree *right;
    Tree(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

void display(Tree *root){
    if(root ==NULL)
        return;
    display(root->left);
    cout << root->data << " ";
    display(root->right);
}




int main(){
    Tree *root = new Tree(10); 
    root->left = new Tree(20); 
    root->right = new Tree(30); 
    display(root);
    return 0;
}