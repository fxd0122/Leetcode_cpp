#ifndef DATASTRUCTRUES_AVL_H_
#define DATASTRUCTRUES_AVL_H_

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int val, height;
    Node *lchild, *rchild;
};

Node* newNode(int val){
    Node* node = new Node;
    node->val = val;
    node->lchild = node->rchild = nullptr;
    node->height = 1;
    return node;
}

int getHeight(Node* &root){
    if(!root) return 0;
    return root->height;
}

int getBalanceFactor(Node* &root){
    return getHeight(root->lchild) - getHeight(root->rchild);
}

void updateHeight(Node* &root){
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
}

void searchAVL(Node* &root, int x){
    if(!root) cout << "search failed!\n";
    if(x == root->val) cout << root->val << " is founed!\n";
    else if(x < root->val) searchAVL(root->lchild, x);
    else searchAVL(root->rchild, x);
}

void leftRotation(Node* &root){
    Node* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void rightRotation(Node* &root){
    Node* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void AVLInsert(Node* &root, int x){
    if(!root){
        root = newNode(x);
        return ;
    }
    if(x < root->val){
        AVLInsert(root->lchild, x);
        updateHeight(root);
        if(getBalanceFactor(root) == 2){
            if(getBalanceFactor(root->lchild) == 1){ // LL
                rightRotation(root);
            }
            else if(getBalanceFactor(root->lchild) == -1){
                leftRotation(root->lchild);
                rightRotation(root);
            }
        }
    }
    else{
        AVLInsert(root->rchild, x);
        updateHeight(root);
        if(getBalanceFactor(root) == -2){
            if(getBalanceFactor(root->rchild) == -1){ // RR
                leftRotation(root);
            }
            else if(getBalanceFactor(root->rchild) == 1){
                rightRotation(root->rchild);
                leftRotation(root);
            }
        }

    }
}

Node* createAVL(vector<int> &data, int n){
    Node* root = nullptr;
    for(auto p : data){
        AVLInsert(root, p);
    }
    return root;
}

#endif