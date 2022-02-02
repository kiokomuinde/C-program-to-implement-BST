#include "BinarySearchTree.h"
#include <time.h>
#define MAX_LINE_LENGTH 50

int main(int argc, char *argv[])
{
    //Initializing time taken by this program.
    clock_t t;
    t = clock();

    //Checking for input arguments and validation
    if( argc == 1 || argc > 2) {
      printf("ERROR: Missing commandline input for the input file\n");
      exit(EXIT_FAILURE);
    }
    //Declaring and defining the file pointer
    FILE *inputFile;
    inputFile = fopen(argv[1], "r");
    if(inputFile == NULL){

        perror("Error opening input file");
        return -1;
    }

    //Declaring temp variables to be used inside the loop
    char *accBal, ch[MAX_LINE_LENGTH];
    char first[10], second[10], third[10];

    NodeT *root = NULL;

    BinarySearchTree tree = newBinarySearchTree();

    Element element;

    //Looping through the file line by line.
    while((fgets(ch, MAX_LINE_LENGTH, inputFile)) != NULL){

        sscanf(ch,"%s %s %s", &first, &second, &third);
        
        if (strcmp(first, "PRINT") == 0)
        {
            //Conditions for each command read from the file.
            if (strcmp(second, "INORDER") == 0)
            {
                printInOrder(tree);
                printf("\n");
            }else if ("PREORDER")
            {
            	printPreOrder(tree);
            }
 
         
        }
        if (strcmp(first, "CREATE") == 0)
        {       

        	element.accountBalance = 0.0;
        	element.accountNumber = atoi(second);

            //Inserting the newly created elemnt to the node which is added to the tree.
            insert(tree, element);

        }else if (strcmp(first, "SALE") == 0)
        {
            //Search for the account to update the balance.
            search(tree, atoi(second))->element.accountBalance += strtod(third, &accBal);
        }
        
    }


    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
  
    printf("List took %.4f seconds to execute \n", time_taken);

    fclose(inputFile);

    //Freeing our tree and the nodes.
    freeBinarySearchTree(tree);


    return 0;
}
