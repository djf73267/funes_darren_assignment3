#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "DataType.h"

//struct
struct Node{
    int key_value; //indetifier for values
    Node*  left;
    Node* right;
    
};

class BinaryTree{
    
public:
    
    BinaryTree(); //constructor
    BinaryTree(Node* leaf);
    ~BinaryTree(); //deconstructor
    
    /**
     Parameter:int key Node* leaf
     Objective: inserts item within the tree as a leaf based on the node that is predessceor
     
     **/
    void insertItem(int key, Node *leaf); //inserting item
    
    /**
     Parameter: Node* leaf int key
     Objective: deletes item within the tree and connects the child if any to the predessecor node
     
     **/
    Node* deleteItem(Node *leaf, int key); //deleting item in tree
    
    
    int getLevelUtil(Node *leaf, int data, int level);
    
    int getLevel(Node *leaf, int data);
    /**
     Parameter: none
     Objective: returns length of the tree assuming this means height
     
     **/
    
    
    //Prints left node right
    void inOrder(Node *leaf);
    
    
    int getLength(Node* leaf);
    
    /**
     Parameter: none
     Objective: prints the tree in "in order"
     
     **/
    
    
    /**
     Parameter: none
     Objective: prints the tree inpost order
     Prints left right node
     **/
    void postOrder(Node* leaf);
    
    /**
     Parameter: none
     Objective: prints the tree in pre o rder
     prints node left right
     **/
    void preOrder(Node *leaf);
    
    /**
     Parameter: none
     Objective: quits the program
     
     **/
    void quit();
    
    
    
private:
    
    int length;
    
    Node *leaf;
    
    
    
};

#endif
