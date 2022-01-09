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
class BST{
private:
    Node *root = nullptr;
    int num = 0;
    void inOrder(Node *root){
        if(root == nullptr)
            return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
    Node* insert(Node *root , int key){
        if(root == nullptr)
            return new Node(key);
        if(key > root->data)
            root->right = insert(root->right , key);
        if(key < root->data)
            root->left = insert(root->left , key);
        return root;
    }
public:
    void insert(int key){
        Node *curr = root;
        root = insert(curr , key);
    }
    void fill (int v[] , int n){
        for(int i = 0 ; i < n; i++) {
            insert(v[i]);
        }
    }
    void inorder(){
        Node *curr = root;
        inOrder(curr);
        cout << endl;
    }
};
int main(){
    int a[] = {5,12,4,3,2,7,9,100,293};
    int n = sizeof(a)/sizeof(a[0]);
    BST s;
    s.fill(a, n);
    s.inorder();
}
