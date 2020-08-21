#include<stdio.h>
typedef struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
}NODE;


void inorder(NODE *root)
{
	if(root==NULL)
	{
		return;
	}
	inorder(root->left);
	printf(" %d",root->data);
	inorder(root->right);
}

void preorder(NODE *root)
{
	if(root==NULL)
	{
		return;
	}
	printf(" %d",root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(NODE *root)
{
	if(root==NULL)
	{
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf(" %d",root->data);
}



NODE *insert(NODE *node,int n)
{
	NODE *new1;
	if(node==NULL)
	{
		new1=(NODE *)malloc(sizeof(NODE));
		new1->data=n;
		new1->left=NULL;
		new1->right=NULL;
		return new1;
	}
	else
	{
		if(n<node->data)
			node->left=insert(node->left,n);
		else
		    node->right=insert(node->right,n);
	}
	return node;
}


void create(NODE **pr)
{
	int n;
	char ch;
	do{
		printf("\nEnter value to insert: ");
		scanf("%d",&n);
		*pr=insert(*pr,n);
		printf("\nDo you want to insert more Node: ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch=='Y' || ch=='y');
}
int main()
{
	NODE *root=NULL;
	create(&root);
	printf("\nInorder output-: ");
	inorder(root);
	printf("\nPre-Order output-: ");
	preorder(root);
	printf("\nPost-order output-: ");
	postorder(root);
}
