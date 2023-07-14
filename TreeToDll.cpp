#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
        BinaryTreeNode<int>* head = null;
        BinaryTreeNode<Integer> prev = null;
        BinaryTreeNode<Integer> curr = root;

        while (curr != null) {
            if (curr.left == null) {
                if (head == null)
                    head = curr;
                curr.left = prev;
                if (prev != null)
                    prev.right = curr;
                prev = curr;
                curr = curr.right;
            } else {
                BinaryTreeNode<Integer> next = curr.left;
                while (next.right != null && next.right != curr)
                    next = next.right;
                if (next.right == null) {
                    next.right = curr;
                    curr = curr.left;
                } else {
                    curr.left = next;
                    prev = curr;
                    curr = curr.right;
                }
            }
        }

        return head;
 }