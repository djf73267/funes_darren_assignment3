#include "BinaryTree.h"
#include <stddef.h>
#include <iostream>
#include <fstream>


using namespace std;

    
BinaryTree::BinaryTree(){
        leaf= NULL;
    } //constructor

BinaryTree::BinaryTree(Node* leaf){
    this->leaf = leaf;
} //constructor

    /**
     Parameter: int key, Node* leaf
     Objective: inserts item as it compares leaf node value to given value
     and recusively checks the node further until there is empty space to create a new node to insert value in tree
     **/
void BinaryTree::insertItem(int key, Node *leaf)
{
    if(key< leaf->key_value) // if the given key is less than the value the leaf node is point to then to the left
    {
        if(leaf->left!=NULL)
            insertItem(key, leaf->left); //recursively runs through node until there is no node left of leaf
        else
        {
            leaf->left=new Node; //creates new node
            leaf->left->key_value=key; //Sets given value to leaf node
            leaf->left->left=NULL;    //Sets the left child of the child Node to null
            leaf->left->right=NULL;   //Sets the right child of the child Node to null
        }
    }
    else if(key>=leaf->key_value) //else to the right
    {
        if(leaf->right!=NULL)
            insertItem(key, leaf->right); //recursively runs through node until there is no node right of leaf
        else
        {
            leaf->right=new Node; //Creates new node
            leaf->right->key_value=key; //Sets given value to leaf node
            leaf->right->left=NULL;  //Sets the left child of the child Node to null
            leaf->right->right=NULL; //Sets the right child of the child Node to null
        }
    }
}

/* Helper function for getLevel().  It returns level of the data if data is
 present in tree, otherwise returns 0.*/
int BinaryTree::getLevelUtil(Node *leaf, int key, int level)
{
    if (leaf == NULL){ //if the tree is empty then the level would return 0
          return 0;
    }
    if (leaf->key_value == key){
        return level;
    }
    int downlevel = getLevelUtil(leaf->left, key, level+1); //recursively looks down the left for
    if (downlevel != 0){
        return downlevel;
    }
    downlevel = getLevelUtil(leaf->right, key, level+1);
    return downlevel;
}

/* Returns level of given data value */
int BinaryTree::getLevel(Node *leaf, int key) //base case if level is not intially given
{
    return getLevelUtil(leaf,key,1);
}


    Node *minValueNode(Node* node)
{
    Node* current = node;
    
   //loop to find the smallest value in the tree
    while (current->left != NULL)
        current = current->left;
    
    return current;
}


/**
 Parameter: Node* leaf, int key
 Objective: deletes item within the tree and connects the child if any to the predessecor Node
 It is possible to shorten the paramters to just the key however one must create a new function
 to satisfy the recursion of moving to a different node
 **/


Node* BinaryTree::deleteItem(Node *leaf, int key)
{
    // base case
    if (leaf == NULL) return leaf;
    
    // if key thats going to be deleted is smaller than the root key which would then it would travel down the left.
    if (key < leaf->key_value)
        leaf->left = deleteItem(leaf->left, key);
    
    // if the key to be deleted is greater than the root key, then it would down the right
    else if (key > leaf->key_value)
        leaf->right = deleteItem(leaf->right, key);
    
    // if its same then more conditional statements must be made
    else
    {
        // node with only one child or no child
        // right child exists
        if (leaf->left == NULL)
        {
            Node *temp = leaf->right; //temporarily stores the node right of the leaf and deallocates the leaf
            free(leaf);
            return temp;
        }
        //left child exists
        else if (leaf->right == NULL)
        {
            Node *temp = leaf->left; //temporarily stores the node left of the leaf and deallocates the leaf
            free(leaf); //deallocates the memory of the node leaf
            return temp;
        }
        
        // node with two children
       Node* temp = minValueNode(leaf->right);
        
       //copies values that were save to the leaf
    leaf->key_value = temp->key_value;
        
        // Delete the inorder successor
        // deletes the node when the key orginally came from
        leaf->right = deleteItem(leaf->right, temp->key_value);
    }
    return leaf;
}
    /**
     Parameter: Node* leaf (to prevent this more functions required to keep the recursion)
     Objective: returns length of the tree assuming this means number of values.
     Returns an int of the values
     **/
int BinaryTree::getLength(Node* leaf)
    {
        if (leaf==NULL)
            return 0;
        else
      return (getLength(leaf->left) + 1 + getLength(leaf->right));
        
    }
    
    /**
     Parameter: none
     Objective: prints the tree in "in order"
     
     **/
void BinaryTree::inOrder(Node *leaf){
    
    if(leaf!= NULL){
        inOrder(leaf->left);
        
        cout << leaf -> key_value << " ";
        
        inOrder(leaf->right);
    }
    
}


    /**
     Parameter: none
     Objective: prints the tree inpost order
     
     **/
void BinaryTree::postOrder(Node* leaf) {
    if(leaf != NULL) {
    postOrder(leaf->left);
    postOrder(leaf->right);
    cout << leaf -> key_value << " ";
    }
}

    /**
     Parameter: none
     Objective: prints the tree in pre o rder
     
     **/
void BinaryTree::preOrder(Node *leaf){

    if (leaf != NULL)
    {
        cout<<leaf->key_value<<" ";
        preOrder(leaf->left);
        preOrder(leaf->right);
    }
    
}

    
    /**
     Parameter: none
     Objective: quits the program
     
     **/
void BinaryTree::quit(){
    exit(0);
    }
    


    
    
    
