#include "BinarySearchTree.h"


/******
 * In this file, provide all of the definitions of the queue functions as described in BinarySearchTree.h.
 *
 * ****/

BinarySearchTree newBinarySearchTree(){

	BinarySearchTree tree = (BinarySearchTree) malloc(sizeof(BinarySearchTree));

	tree->root = NULL;

	return tree;
	
}


void miniFreeBinarySearchTree (NodeT *root);
void miniFreeBinarySearchTree (NodeT *root)
{
    //post-order like FatalError hinted at
       if (root != NULL) {
        miniFreeBinarySearchTree(root->right);
        // free(root->element); //if data was heap allocated, need to free it
        miniFreeBinarySearchTree(root->left);
        free(root);
    }
}

void freeBinarySearchTree(BinarySearchTree tree){

	if (tree->root == NULL)
		free(tree);
	miniFreeBinarySearchTree(tree->root);

}


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

		if(root->element.accountNumber==searchValue) //if root->data is x then the element is found
        {
        	return root;
        }

		else if(searchValue>root->element.accountNumber) // x is greater, so we will search the right subtree
	        return miniSearch(root->right, searchValue);
	    else //x is smaller than the data, so we will search the left subtree
	        return miniSearch(root->left,searchValue);

	}


NodeT *search(BinarySearchTree tree, int searchValue){

	 if (miniSearch(tree -> root, searchValue) == NULL)
	 {
	 	printf("Account number %d is not available.\n", searchValue);
	 }

}


//Secondary Function for search Function
NodeT *miniInsert(NodeT *root, Element value);
NodeT *miniInsert(NodeT *root, Element value){
	
    if(root==NULL)
    	// printf("%d\n", value.accountNumber);
        return allocateNode(value);

    // x is greater. Should be inserted to right
    else if(value.accountNumber == root->element.accountNumber)

    	return NULL;
    // x is greater. Should be inserted to right	
    else if(value.accountNumber>root->element.accountNumber)
    	

    	root->right = miniInsert(root->right, value);
        
    else // x is smaller should be inserted to left
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
