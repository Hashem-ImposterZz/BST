#include <iostream>
#include <cmath>
#include<vector>
#include<map>
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
    void preOrder(Node *root){
        if(root == nullptr)
            return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
    
    void order(vector < Node*> &v,Node *root){
        if(root == nullptr)
            return;
        order(v,root->left);
        v.push_back(root);
        order(v,root->right);
    }
    
    Node* insert(Node *root , int key){
        if(root == nullptr)
            return new Node(key);
        if(key > root->data)
            root->right = insert(root->right , key);
        if(key <= root->data)
            root->left = insert(root->left , key);
        return root;
    }
    Node* midRoot(vector <Node*> &v , int l , int r){
        if(l > r)
            return nullptr;
        if(l == r)
        {
            v[l]->right = nullptr;
            v[l]->left = nullptr;
            return v[l];
        }
        int mid = (l+r)/2;
        Node *curr = v[mid];
        curr->right=midRoot(v, mid + 1, r);
        curr->left=midRoot(v, l, mid - 1);
        return curr;
    }
public:
    void insert(int key){
        Node *curr = root;
        num++;
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
    void preorder(){
        Node *curr = root;
        preOrder(curr);
        cout << endl;
    }
    int size(){
        return num;
    }
    void makeItBalanced(){
        vector < Node*> v;
        Node *curr = root;
        order(v,curr);
        root = midRoot(v, 0, v.size() - 1);
        cout << root->data << endl;
    }
};
int main(){
    int n , x;
    cin >> n;
    BST s;
    for(int i = 0 ;i  < n; i++){
        cin >> x;
        s.insert(x);
    }
    s.makeItBalanced();
    s.preorder();
}
