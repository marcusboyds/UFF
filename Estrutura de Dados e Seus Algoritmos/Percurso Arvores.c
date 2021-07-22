#include <stdio.h>
#include <stdlib.h>

// Create a node
struct LSE {
  char data;
  struct LSE* next;
};

struct node
{
    char data;
    struct node* left;
    struct node* right;
};

struct LSE* armazenarArvore(struct node* root, struct LSE **head_ref) {
  if (root == NULL) return;
  insertAtBeginning(&head_ref, root->data);
  armazenarArvore(root->left);
  armazenarArvore(root->right);
}

void insertAtBeginning(struct LSE** head_ref, char *new_data) {
  // Allocate memory to a node
  struct LSE* new_node = (struct LSE*)malloc(sizeof(struct LSE));

  // insert the data
  new_node->data = new_data;

  new_node->next = (*head_ref);

  // Move head to new node
  (*head_ref) = new_node;
}

struct node* newNode(char *data)
{
    struct node* node = (struct node*) malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

int main()
{
    //Arvore 1
    struct node *arvore1 = newNode("a");
    arvore1->left = newNode("b");
    arvore1->right = newNode("c");

    //Arvore 2
    struct node *arvore2 = newNode("b");
    arvore2->left = newNode("a");
    arvore2->right = newNode("c");
    
    //Armazernar conteudo da Arvore 1 na lista 1
    struct LSE *lista1 = NULL;
    struct LSE *lista1 = armazenarArvore(arvore1);
    
    //Armazernar conteudo da Arvore 2 na lista 2
    struct LSE *lista2 = NULL;
    struct LSE *lista2 = armazenarArvore(arvore2);

  return 0;
}