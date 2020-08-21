#include<stdio.h>
#include<malloc.h>
typedef struct Node
{
	struct Node *left;
	int data;
	struct Node *right;
}NODE;
NODE *insert(NODE *node,int n)
{
	NODE *new1;
	if(node==NULL)
	{
		new1=(NODE *)malloc(sizeof(NODE));
		new1->data=n;
		new1->left=new1->right=NULL;
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
void inorder(NODE *node)
{
	if(node==NULL)
	    return;
	inorder(node->left);
	printf("%d ",node->data);
	inorder(node->right);
}
void preorder(NODE *node)
{
	if(node==NULL)
	    return;

	printf("%d ",node->data);
	preorder(node->left);
	preorder(node->right);
}
void postorder(NODE *node)
{
	if(node==NULL)
	    return;

	postorder(node->left);
	postorder(node->right);
	printf("%d ",node->data);
}
void create(NODE **pp)
{
	int n;
	char ch;
	do{
		printf("Enter value for new node: ");
		scanf("%d",&n);
		*pp=insert(*pp,n);
		printf("\nDo you want to continue : ");
		fflush(stdin);
		scanf("%c",&ch);
	}while(ch!='n');
}
int FindSize(NODE *node)
{
	if(node!=NULL)
	   return FindSize(node->left)+1+FindSize(node->right);
	else
	   return 0;
}
int FindDepth(NODE *node)
{
	if (node!=NULL)
    {
        int ld = FindDepth(node->left);
        int rd = FindDepth(node->right);

        if (ld > rd)
            return ld+1;
        else
            return rd+1 ;
    }
    else
        return 0;
}
int MinValue(NODE *node)
{
	if (node!=NULL)
    {
        while(node->left!=NULL)
            node = node->left;

        return node->data;
    }
    else
        return 0;
}
int MaxValue(NODE *node)
{
	if (node!=NULL)
    {
        while(node->right!=NULL)
            node = node->right;

        return node->data;
    }
    else
        return 0;
}
NODE * search(NODE *node, int n)
{
    if (node == NULL || node->data == n)
       return node;
    if (n>node->data)
       return search(node->right, n);
    else
    	return search(node->left, n);
}
void mirror(NODE* node)
{
  if (node==NULL)
    return;
  else
  {
    NODE * temp;
    mirror(node->left);
    mirror(node->right);
    temp = node->left;
    node->left  = node->right;
    node->right = temp;
  }
}
NODE* deleteNode(NODE * root, int key)
{
    if (root == NULL) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
  	else
	  	if (key > root->data)
        	root->right = deleteNode(root->right, key);
  		else
    	{
        	if (root->left == NULL)
        	{
            NODE *temp = root->right;
            free(root);
            return temp;
        	}
        	else if (root->right == NULL)
        	{
            	NODE *temp = root->left;
            	free(root);
            	return temp;
        	}
  			NODE * temp = MinValue(root->right);

        	root->data = temp->data;

			root->right = deleteNode(root->right, temp->data);
    	}
    return root;
}
int main()
{
	NODE *p=NULL;
	int n;
	NODE *temp;
	create(&p);
	inorder(p);
	printf("\n");
	preorder(p);
	printf("\n");
	postorder(p);
    //	printf("\nSize of Tree = %d",FindSize(p));
    printf("\nEnter value to serach : ");
    scanf("%d",&n);
    temp=search(p,n);
    if(temp==NULL)
       printf("\n%d does not exist ",n);
    else
       printf("\n%d found at location %u",n,temp);
}
