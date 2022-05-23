#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//STRUCTURE NODE
struct node {
	struct node *left;
	char *data;
	struct node *right;
};
typedef struct node tree_node;




//FUNCTIONS
void insert(tree_node **tree, char *s){
	tree_node *temp = NULL;

  if(*tree == NULL){
		printf("\n\nPlace is NUll\n");
    temp = (tree_node *)malloc(sizeof(tree_node));
		temp->left = NULL;
		temp->right = NULL;

		temp->data = malloc(strlen(s)+1);
		printf("'%s' inside\n", s);
    strcpy(temp->data, s);

		*tree = temp;
	} 
	//IF STRING "S" appears first in dictionary move it to the left 
	else if(strcmp(s,(*tree)->data)<0){
		printf("\n%s < %s", s, (*tree)->data);//HELPS me visually keeep track
		printf("\t: Copying '%s' to left", s);//HELPS me visually keeep track
		insert(&((*tree)->left), s);
	}
	//IF STRING "S" appears after the node's string move it to the right
	else if(strcmp(s, (*tree)->data)>0){
		printf("\n%s > %s", s, (*tree)->data);//HELPS me visually keeep track
		printf("\t: Copying '%s' to right", s); //HELPS me visually keeep track
		insert(&((*tree)->right),s);
	} else{
		printf("\n\nError in Inseration?!?\n\n");
	}
}




//DONE
void print_preorder(tree_node *tree){
	if(tree != NULL){
		printf("\t%s \n", tree->data);
		print_preorder(tree->left);
		print_preorder(tree->right);
	}
}
//DONE
void print_inorder(tree_node *tree){
	if(tree != NULL){
		print_inorder(tree->left);
		printf("\t%s \n", tree->data);
		print_inorder(tree->right);
	}

}
//DONE
void print_postorder(tree_node *tree){
	if(tree != NULL){ 
		print_preorder(tree->left);
		print_preorder(tree->right);
	  printf("\t%s \n", tree->data);
	}
}
//DONE
void cleanup(tree_node *tree){
	if(tree){
		cleanup((*tree).left);
		cleanup((*tree).right);
		free(tree);
	}
}




//SEARCH
tree_node *search(tree_node **tree, char *val){
	
	if(tree != NULL){
		if(strcmp(val,(*tree)->data) < 0){
			if((*tree)->left){
				return search(&(*tree)->left, val);//RECURSION SEARCH
			} else{//IF "Left" is Null return a NULL NODE
				tree_node *null_node;
				null_node = (tree_node*)malloc(sizeof(tree_node));
				null_node->right = NULL;
				null_node->left = NULL;
				null_node->data = NULL;
				//printf("\nreturning NULL node");
				return null_node;
			}
		}else if(strcmp(val,(*tree)->data) > 0){
			if((*tree)->right){
				return search(&(*tree)->right, val);//RECURSION
			} else{//IF "Left" is Null return a NULL NODE
				tree_node *null_node;
				null_node = (tree_node*)malloc(sizeof(tree_node));
				null_node->right = NULL;
				null_node->left = NULL;
				null_node->data = NULL;
			//	printf("\nreturning NULL node");
				return null_node;
			}
		} else if(strcmp(val,(*tree)->data)==0){//If FOund return Node
			return *tree;
		}
	}

}



//DELETE
void delete(tree_node *tree, char *s){
	tree_node *this_node= (tree_node *)malloc(sizeof(tree_node));
	if(tree != NULL){
		this_node = search(&tree, s);
		free(this_node);
	}
}


//populate_tree
tree_node *populate_tree(char *filename){
	tree_node *root;
	root = NULL;

	FILE *fptr;
	char string[25];

	int flag = 1;
	fptr = fopen(filename, "r");
	
	while(flag == 1){
		flag = fscanf(fptr, "%s ", string);
		if(flag == -1) break;//If it reaches end of file "EOF" = -1 exit while loop
			//	printf("%s and %d\n",string ,flag);
				insert(&root, string);
		
	}

	fclose(fptr);

	return root;
}



//spellcheck
void spellcheck(tree_node *root, char *filename){
	FILE *filePTR;
	char str[35];
	

	int Flag = 1; 
	int position = 1;//USED for printing position of word in inputted txt file
	filePTR = fopen(filename, "r");

	tree_node *found = (tree_node *)malloc(sizeof(tree_node));

	while(Flag == 1){
		
		Flag = fscanf(filePTR, "%s ", str);
		if(Flag == -1)break;

		//LOWERCASE the string/Word
		for(int i = 0; str[i]; i++){
			if((strcmp(&str[i], ".") == 0 )|| (strcmp(&str[i], ",") == 0)){//Deals with "PERIODS" and COMMAs
				str[i] = '\0';
			}
  	str[i] = tolower(str[i]);
		}

		found = search(&root, str);	
		if(found->data == NULL){
			printf("Word \"%s\" on line 1, word %d mispelled or not found in dictionary.\n", str, position);
		}

		position++;
	}

	fclose(filePTR);
}




























//MAIN FUNCTION
int main(void) {
  char filename[30];
	tree_node *root;
	root = populate_tree("words.txt");



	//Demo Print
	printf("_______________________________________");
	printf("\n\n\n\n\n\nPre Order Display\n");
	print_preorder(root);

	printf("In Order Display (Dictionary Order)\n");//Dictionary order
	print_inorder(root);

	printf("Post Order Display\n");
	print_postorder(root);


	//Run program on specificied input
	printf("\n\nEnter filename (WITH \".txt\"): ");
	scanf("%s", filename);

	printf("Running spellcheck on %s....\n\n\n", filename);
	spellcheck(root, filename);




	//DELETE tree to freee memory
	printf("\n\nProgram complete, cleaning up memory...");
	cleanup(root);


  return 0;
}