//
//  main.c
//  binary_tree_implementation
//
//  Created by Anoja Rajalakshmi on 9/16/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

struct node* insert_node(struct node* node, int data) {
    // 1. If the tree is empty, return a new, single node
    if (node == NULL) {
        node = newNode(data);
        return (node);
    }
    else {
        // 2. Otherwise, recur down the tree
        if (data <= node->data) node->left = insert_node(node->left, data);
        else node->right = insert_node(node->right, data);
        
        return(node); // return the (unchanged) node pointer
    } 
}
/*
 Given a binary tree, return true if a node
 with the target data is found in the tree. Recurs
 down the tree, chooses the left or right
 branch by comparing the target to each node.
 */
static int search(struct node* node, int target) {
    // 1. Base case == empty tree
    // in that case, the target is not found so return false
    if (node == NULL) {
        return(false);
    }
    else {
        // 2. see if found here
        if (target == node->data) return(true);
        else {
            // 3. otherwise recur down the correct subtree
            if (target < node->data) return(search(node->left, target));
            else return(search(node->right, target));
        } 
    } 
}

int size(struct node* node) {
    if (node==NULL) {
        return(0);
    } else {
        return(size(node->left) + 1 + size(node->right));
    }
}
int main(int argc, const char * argv[]) {
    struct node* root =NULL;
    root = newNode(10);
    root->left = newNode(7);
    root->right = newNode(15);
    root->left->left = newNode(3);
    root->left->right = newNode(8);
    root->right->left = newNode(12);
    root->right->right = newNode(20);
    printf("%d\n",search(root,20));
    printf("%d\n",size(root));

    return 0;
}