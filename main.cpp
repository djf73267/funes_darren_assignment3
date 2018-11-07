#include <iostream>

#include <fstream>

#include "BinaryTree.h"

using namespace std;

int main(int argc, const char * argv[])
{

    string line;
    int i;
    int j;
    string cherry;
    ifstream myfile (argv[1]); //reads input from arguementc
    if (myfile.is_open())
    {
        Node *apple = new Node(); //creates a node
                BinaryTree *tree = new BinaryTree(); //creates a empty tree
                cout<< line << '\n';
        while(myfile.is_open()){
            while ( myfile >> j)
            {
                tree -> insertItem(j,apple); //inserts the values at start of a empty node in a empty tree


            }

            cout<< "insert (i), delete (d), length(l), quit (q), inOrder (n), preOrder (p), postOrder (o), get same level siblings (c), and retrieve (r)" << endl;
            cout<< "Press Command: "<< endl;
            //reads different commands and responds accordingly
            cin >> line;
            if(line == "q"){
                cout <<" Quitting Program...";
                myfile.close();
                
            }
            if(line == "d"){
                cout << "Delete Value: ";
                
                cin >> i;
                
                tree->deleteItem(apple,i);
                
            }
            if(line == "l"){
                cout << "Length of tree is: ";
                cout << tree->getLength(apple) << endl;
                
                
            }
            if(line == "i"){
           
                cout<< "Insert Value: ";
                cin >> i;
               tree-> insertItem(i, apple);
            }
            if(line == "n"){
                tree->inOrder(apple);
            }
            if(line == "p"){
                tree->preOrder(apple);
            }
            if(line == "o"){
                tree->postOrder(apple);
            }
            
            if (line == "c"){
                cout<<"Item to find same level nonsiblings: ";
                cin>>i;
                
                cout << "Level of " << i << " is: ";
                cout << tree->getLevel(apple, i)<< endl;
            }

        }

        myfile.close();
    }

    else cout << "Unable to open file";

    return 0;
    
    
}




    
    
    

