#include <iostream>
#include <cmath>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data){
        this->data = data;
    }
};
Node* insert(Node *root , int key){
    if(root == nullptr)
        return new Node(key);
    if(key > root->data)
        root->right = insert(root->right , key);
    if(key < root->data)
        root->left = insert(root->left , key);
    return root;
}
Node* fill (int v[] , int n){
    Node *root = nullptr;
    for(int i = 0 ; i < n; i++) {
        root = insert(root, v[i]);
    }
    return root;
}
void inOrder(Node *root){
    if(root == nullptr)
        return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}
int main(){
    int a[] = {5,12,4,3,2,7,9,100,293};
    int n = sizeof(a)/sizeof(a[0]);
    Node *root = fill(a,n);
    inOrder(root);
    cout << endl;
}
