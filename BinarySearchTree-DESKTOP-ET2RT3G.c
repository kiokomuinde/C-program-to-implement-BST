#include "BinarySearchTree.h"


/******
 * In this file, provide all of the definitions of the queue functions as described in BinarySearchTree.h.
 *
 * ****/
BinarySearchTree newBinarySearchTree(){

	//Mollocing our tree
	BinarySearchTree tree = (BinarySearchTree) malloc(sizeof(BinarySearchTree));

	tree->root = NULL;

	return tree;
	
}

//Secondary function for freeBinarySearhTree.
void miniFreeBinarySearchTree (NodeT *root);
void miniFreeBinarySearchTree (NodeT *root)
{	   //Checking for null since you cant free an empty space.
       if (root != NULL) {
        miniFreeBinarySearchTree(root->right);

        //Recursion to loop through the tree node
        miniFreeBinarySearchTree(root->left);
        free(root);
    }
}

void freeBinarySearchTree(BinarySearchTree tree){

	//Free our tree after freing the nodes
	if (tree->root == NULL)
		free(tree);
	miniFreeBinarySearchTree(tree->root);

}

//Allocate new node
NodeT *allocateNode(Element value){

	NodeT *newNode;
    newNode = malloc(sizeof(NodeT));
    newNode->element = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

//Secondary Function for search Function
NodeT *miniSearch(NodeT *root, int searchValue);

	NodeT *miniSearch(NodeT *root, int searchValue){

		if (root == NULL)
		{
			return NULL;
		}

		if(root->element.accountNumber==searchValue) //if root->element.accountNo is searchValue then the the account is found
        {
        	return root;
        }

		else if(searchValue>root->element.accountNumber) //searchValue is greater, so we will search the right subtree
	        return miniSearch(root->right, searchValue);
	    else //searchValue is smaller than the account number, so we will search the left subtree
	        return miniSearch(root->left,searchValue);

	}


NodeT *search(BinarySearchTree tree, int searchValue){

	 if (miniSearch(tree -> root, searchValue) == NULL)
	 {
	 	printf("Account number %d is not available.\n", searchValue);
	 }

}


//Secondary Function for insert Function
NodeT *miniInsert(NodeT *root, Element value);
NodeT *miniInsert(NodeT *root, Element value){
	
    if(root==NULL)
        return allocateNode(value);

    // Value is equal to account number. Should not be inserted
    else if(value.accountNumber == root->element.accountNumber)
    	return NULL;
    //Value is greater. Should be inserted to right	
    else if(value.accountNumber>root->element.accountNumber)
    	

    	root->right = miniInsert(root->right, value);
        
    else // Value is smaller should be inserted to left
        root->left = miniInsert(root->left,value);
    return root;
}

int insert(BinarySearchTree tree, Element value){

	//searching for the place to insert data

	tree -> root = miniInsert(tree -> root, value);

	if (tree->root == NULL)
	{
		return TRUE;
	}else{

		return FALSE;
	}

}

//Secondary Function for inorder Function
void inorder(NodeT *root);

	void inorder(NodeT *root)
	{
	    if(root!=NULL) // checking if the root is not null
	    {
	        inorder(root->left); // visiting left child
	        printf(" %d ",root->element.accountNumber);
	        printf(" %.2f \n",root->element.accountBalance);// printing data at root
	        inorder(root->right);// visiting right child
	    }
	}

void printInOrder(BinarySearchTree tree){

	inorder(tree -> root);
}

//Secondary Function for preorder Function
void printPreorder(NodeT* root);
void printPreorder(NodeT* root)
{
    if (root == NULL)
        return;
 
    /* first print data of node */
    printf(" %d  ", root->element.accountNumber);
    printf("%.2f\n", root->element.accountBalance);
 
    /* then recur on left sutree */
    printPreorder(root->left);
    /* now recur on right subtree */
    printPreorder(root->right);
}

void printPreOrder(BinarySearchTree tree){

	printPreorder(tree -> root);
}
