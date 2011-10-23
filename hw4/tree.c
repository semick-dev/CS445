#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include "symboltable.h"
#include "yyparse.tab.h"


//WORKHORSE. HO!
node* makeNode(int label, symbol_table* parent, token* tok, int nchildren, ...){
  
  node* new = (node*) malloc(sizeof( node ));
  
  new->parent = parent;
  new->label = label;
  new->nchildren = nchildren;
  new->tok = tok;
  // new->parent = parent;
    
  new->children = 0;
  if(nchildren > 0){
    new->children = (node**)malloc(sizeof(node*) * nchildren);
    
    int i;
    va_list va;
    
    va_start(va,nchildren);
    for(i = 0; i<nchildren; i++){
      new->children[i] = va_arg(va, node*);
    }
    va_end(va);
  }
  
  return new;
}

void yysemantics(node* head){  
  //build the symbol tables
  buildSymbolTables(head, NULL);
  
  //treePrint
  traverseTree(head,NULL,0);
}


void buildSymbolTables(node* head, node* parent_node){
  if(head != NULL){
    //get the symbol tables organized
    if(head->parent == NULL){
      if(parent_node != NULL)
	head->parent = parent_node->parent; 
    }
    else {
      if(parent_node != NULL)
	head->parent->parent = parent_node->parent;
    }
    
    
    int n = head->nchildren;      
    int i;
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
      }
      else{
	buildSymbolTables(head->children[i], head);
      }
    }
    
  }
}


void traverseTree(node* head, node* parent_node, int level){
  if(head != NULL){
    int n = head->nchildren;
    // if( level > 0 && head->text == NULL) level--;
    
    //general information about the node
    printf("Label: %d -- ", head->label);
    printf("Symbol Table Pointer: %p\n", &(head->parent));
    
    
    
    int j = 0;
    for(j; j < level; j++){
      //printf("%d", level);
    }
    if(head->tok != NULL){
      if(head->tok->text != NULL){
	//printf("Mem:%p,%s", head, head->text);
	printf("%s ", head->tok->text);
	printf("%d", head->label);
	printf(" Symbol Table Pointer: %p", &(head->parent));
	printf("\n");
      }
      else{
	//printf("Null Text, Memory Location %p\n", head);
      }
    }
    
    int i;
    int k;
    /*printf("My Memory Location: %p\n", head);
    for(k = 0; k < n; k++){      
      if(head->children[k]==NULL){
	//printf("Kid's NULL. \n");
      }
      else{
	printf("%d: %p, ", k,head->children[k]);
	//traverseTree(head->children[i], level++);
      }
      }*/
    //printf("\n");
    
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
	//printf("Kid's NULL. \n");
      }
      else{
	//printf("Child Memory Location %p\n", head->children[i]);
	traverseTree(head->children[i], head, level++);
      }
    }
    
  }
}





/*
void verboseTraverseTree(node* head, int level){
  if(head != NULL){
    int i;
    int n = head->nchildren;
    if(head->text != NULL){
      printf("%s", head->text);
      printf("\n");
    }
    
    
    
    for(i = 0; i < n; i++){      
      if(head->children[i]==NULL){
	//printf("Kid's NULL. \n");
      }
      else{
	printf("Level %d children: \n", n);
	printf("%s\n", head->children[i]->text);
	//traverseTree(head->children[i], level++);
      }
    }
    
  }
}
*/



