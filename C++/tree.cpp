/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;

struct Tree{
    int key;
    Tree *left;
    Tree *right;
    Tree(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};

void preorder(Tree *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    
}
int height(Tree *root){
    if(root==NULL) return 0;
    else
        return 1+max(height(root->left),height(root->right));
}

int getSize(Tree *root){
    if(root==NULL) return 0;
    else
        return 1+getSize(root->left)+getSize(root->right);
}

int maximum(Tree *root){
    if(root==NULL) return INT_MIN;
    else
        return max(root->key,max(maximum(root->left),maximum(root->right)));
}
void levelorder(Tree *root){
    if(root ==NULL) return;
    queue<Tree *> qt;
    qt.push(root);
    while(!qt.empty()){
        Tree *curr=qt.front();
        qt.pop();
        cout<<curr->key<<" ";
        if(curr->left!=NULL)
            qt.push(curr->left);
        if(curr->right!=NULL)
            qt.push(curr->right);
    }
}
void linebyline(Tree *root){
    if(root==NULL) return;
    queue<Tree *> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for(int i=0;i<n;i++){
            Tree* curr=q.front();
            q.pop();
            cout<<curr->key<<" ";
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
        cout<<endl;
    }
}

void spiral(Tree *root){
    if(root==NULL) return;
    queue<Tree *> q;
    stack<int> s;
    q.push(root);
    bool flag=false;
    while(!q.empty()){
        int count=q.size();

        for(int i=0;i<count;i++){
            Tree *curr=q.front();
            q.pop();
            if(flag)
                s.push(curr->key);
            else
                cout<<curr->key<<" ";
            
            if(curr->left!=NULL)
                q.push(curr->left);
            if(curr->right!=NULL)
                q.push(curr->right);
        }
        if(flag){
            while(!s.empty()){
                cout<<s.top()<<" ";
                s.pop();
            }
        }
        flag=!flag;
        cout<<endl;
    }
}



int maximumwidth(Tree *root){
    if(root==NULL) return 0;
    queue<Tree *> q;
    int ans=1;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        ans=max(ans,n);
        for(int i=0;i<n;i++){
            Tree* curr=q.front();
            q.pop();
            if(curr->left!=NULL) q.push(curr->left);
            if(curr->right!=NULL) q.push(curr->right);
        }
    }
    return ans;
}

int main()
{
    cout<<"hello world!!";
    cout<<endl;
    Tree *root=new Tree(10);
    root->left=new Tree(20);
    root->right=new Tree(30);
    root->left->left=new Tree(40);
    root->left->right=new Tree(50);
    root->right->left=new Tree(60);
    root->right->right=new Tree(70);
    root->left->left->left=new Tree(80);
    root->left->left->right=new Tree(90);
    root->left->right->left=new Tree(100);
    root->left->right->right=new Tree(110);
    root->right->right->left=new Tree(120);
    root->right->right->right=new Tree(130);
    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl<<"Height: "<<height(root);
    cout<<endl<<"Maximum: "<<maximum(root);
    cout<<endl<<"Size: "<<getSize(root);
    cout<<endl<<"LevelOrder: ";
    levelorder(root);
    cout<<endl<<"LevelOrder(LineByLine): ";
    linebyline(root);
    cout<<endl<<"Maximum Width: "<<maximumwidth(root);
    cout<<endl<<"Spiral Order: ";
    spiral(root);
    
    
    return 0;
}

