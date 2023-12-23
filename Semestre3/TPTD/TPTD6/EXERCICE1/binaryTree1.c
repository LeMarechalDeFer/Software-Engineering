#include "binaryTree1.h"

Tree *newTree(unsigned int e){
    Tree *tr = malloc(sizeof(Tree));

    if(tr == NULL){
        perror("Erreur d'allocation d'un noeud\n");
        exit(EXIT_FAILURE);
    }

    tr->value = e ;
    tr->tleft = NULL ;
    tr->tright = NULL ;
    tr->parent = NULL ;
    
    printf("Le noeud %u à été initialisé\n", tr->value);

    return tr ;
}

Tree *joinTree(Tree *G, Tree *D, unsigned int r){
    Tree *tr = newTree(r) ;
    tr->tleft = G ;
    tr->tright = D;
    
    if(G != NULL){
        G->parent = tr ;
    }

    if(D != NULL){
        D->parent = tr ;
    }

    return tr ;

}

Tree *createTreeWithTab(unsigned int T[]){
    Tree *root = NULL; 
    Tree *currentNode = NULL;

    if (MAX_TAB < 3) { 
        printf("Pas assez d'éléments pour former un arbre\n");
        return NULL;
    }

    for(int i = 0; i < MAX_TAB; i += 3){
        if(i == 0) {
            root = joinTree(newTree(T[i+1]), newTree(T[i+2]), T[i]);
        } else {
            currentNode = joinTree(newTree(T[i+1]), newTree(T[i+2]), T[i]);
        }
    }
    return root;
}


void clean_tree(Tree *tr){
    
    if(tr == NULL){
        return;
    }

    printf("Suppression de %u\n", tr->value);

    clean_tree(tr->tleft);
    clean_tree(tr->tright);

    free(tr);
}

void print_tree_prefix(Tree *tr){

    if(tr == NULL){
        return;
    }
    if(tr->parent != NULL){
        printf("(%u)=>(%u)\n", tr->parent->value, tr->value);
    }
    else{
        printf("(%u)\n", tr->value);
    }

    if(tr->tleft != NULL){
        print_tree_prefix(tr->tleft); 
    }
    if(tr->tright != NULL){
        print_tree_prefix(tr->tright);
    }
}

unsigned int depth_tree(Tree *tr){
    if(tr ==NULL){
        return -1;
    }
    else{
        unsigned int hG = depth_tree(tr->tleft); 
        unsigned int hD = depth_tree(tr->tright); 
        if(hG>hD){
            return hG+1;
        }
        else{
            return hD+1;
        }
    }
    
}

bool equals_trees(Tree *tr1, Tree *tr2){
    if(tr1 == NULL && tr2 == NULL){
        return true ;
    }
    if(tr1 == NULL || tr2 == NULL){
        return false ;
    }
    else{
        return(tr1->value == tr2->value && equals_trees(tr1->tleft, tr2->tleft) && equals_trees(tr1->tright, tr2->tright));
    }
}


unsigned int sum_tree_leftBranch(Tree *tr) {
    if(tr == NULL) {
        return 0; 
    }

    if(tr->tleft == NULL && tr->tright == NULL) {
        return tr->value; 
    }

    return sum_tree_leftBranch(tr->tleft) + sum_tree_leftBranch(tr->tright);
}

unsigned int sum_of_left_leaves(Tree *A) {
    if(A == NULL || A->tleft == NULL) {
        return 0;
    }
    return sum_tree_leftBranch(A->tleft);
}


void enqueue(QueueNode *head, Tree *node) {
    QueueNode newNode = (QueueNode)malloc(sizeof(Node));
    if(newNode == NULL){
        perror("Erreur allocation mémoire");
        exit(EXIT_FAILURE);
    }
    newNode->node = node;
    newNode->next = NULL;

    if (isEmpty(*head)) {
        *head = newNode;
    } else {
        QueueNode current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

Tree* dequeue(QueueNode *head) {
    if (isEmpty(*head)) {
        return NULL;
    }
    QueueNode temp = *head;
    Tree *node = temp->node;
    *head = (*head)->next;
    free(temp);
    return node;
}


bool isEmpty(QueueNode head) {
    return (head == NULL);
}

void tree_width_course(Tree *A){
    if (A == NULL) return; 

    QueueNode queue = NULL; 
    enqueue(&queue, A); 

    while(!isEmpty(queue)) {
        Tree *current = dequeue(&queue); 

        printf("%u ", current->value);

        if(current->tleft != NULL) {
            enqueue(&queue, current->tleft);
        }
        if(current->tright != NULL) {
            enqueue(&queue, current->tright);
        }
    }
}


