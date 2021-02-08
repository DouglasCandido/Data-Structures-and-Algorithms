// Implementação de uma Árvore Binária

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int somatorio = 0;

struct bin_tree {
int data;
struct bin_tree * right, * left;
};
typedef struct bin_tree node;

void insert(node ** tree, int val)
{
    node *temp = NULL;
    if(!(*tree))
    {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

void print_preorder(node * tree)
{
    if (tree)
    {
        printf("%d\n",tree->data);
        print_preorder(tree->left);
        print_preorder(tree->right);
    }

}

void print_inorder(node * tree)
{
    if (tree)
    {
        print_inorder(tree->left);
        printf("%d\n",tree->data);
        somatorio += tree->data;
        print_inorder(tree->right);
    }
}

void print_postorder(node * tree)
{
    if (tree)
    {
        print_postorder(tree->left);
        print_postorder(tree->right);
        printf("%d\n",tree->data);
    }
}

void deltree(node * tree)
{
    if (tree)
    {
        deltree(tree->left);
        deltree(tree->right);
        free(tree);
    }
}

node* search(node ** tree, int val)
{
    if(!(*tree))
    {
        return NULL;
    }

    if(val < (*tree)->data)
    {
        search(&((*tree)->left), val);
    }
    else if(val > (*tree)->data)
    {
        search(&((*tree)->right), val);
    }
    else if(val == (*tree)->data)
    {
        return *tree;
    }
}

int minValue(node * tree)  
{  
node *current = tree;
/* loop down to find the leftmost leaf */
while (current->left != NULL)  
{  
    current = current->left;  
}  
return(current->data);  
}  

int maxValue(node * tree)  
{  
node *current = tree;
/* loop down to find the leftmost leaf */
while (current->right != NULL)  
{  
    current = current->right;  
}  
return(current->data);  
}  

int main()
{
    node *root;
    node *tmp;
    //int i;

    root = NULL;
    /* Inserting nodes into tree */
    insert(&root, 10);
    insert(&root, 5);
    insert(&root, 0);
    insert(&root, 1);
	insert(&root, -7);
	insert(&root, 3);
	insert(&root, 800);

    /* Printing nodes of tree */
    printf("Pre Order Display\n");
    print_preorder(root);
    
    cout <<endl;

    printf("In Order Display\n");
    print_inorder(root);
    
    cout << endl;

    printf("Post Order Display\n");
    print_postorder(root);
    
    cout << endl;

    /* Search node into tree */
    tmp = search(&root, 100);
    if (tmp)
    {
        printf("Searched node=%d\n", tmp->data);
    }
    else
    {
        printf("Data Not found in tree.\n");
    }
    
	cout << endl;
    cout << "Somatorio de todos os elementos: " << somatorio << endl;
    cout << endl;
    
    int min_value = minValue(root);
    
    int max_value = maxValue(root);
    
    int diferenca = max_value - min_value;
    
    cout << "Valor minimo: " << min_value << endl;
    
    cout << "Valor maximo: " << max_value << endl;
    
    cout << "Diferenca entre o Valor Maximo e o Valor Minimo: " << diferenca << endl;

    /* Deleting all nodes of tree */
    deltree(root);
    
    return 0;
    
}
