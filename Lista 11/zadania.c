#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
    int value;
    struct Node* left;
    struct Node* right;
} Node, *NodePtr;

NodePtr create_node(int value){
    NodePtr new_node = malloc(sizeof(Node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

int count_nodes(NodePtr tree){
    if(!tree) return 0;
    return 1 + count_nodes(tree->left) + count_nodes(tree->right);
}

int tree_height(NodePtr tree){
    if(!tree) return 0;
    int left_nodes = count_nodes(tree->left);
    int right_nodes = count_nodes(tree->right);
    return 1 + (left_nodes > right_nodes ? left_nodes : right_nodes);
}

int max(NodePtr tree){
    if(!tree) return 1 << 31;
    int left = max(tree->left);
    int right = max(tree->right);
    return left > right ? left : right;
}

int min(NodePtr tree){
    if(!tree) return __INT_MAX__;
    int left = min(tree->left);
    int right = min(tree->right);
    return left < right ? left : right;
}

bool is_bst(NodePtr tree){
    if(!tree) return true;
    if((tree->value > min(tree->right)) && (tree->right != NULL)) return false;
    if((tree->value < max(tree->left)) && (tree->left != NULL)) return false;
    if(!is_bst(tree->left) || !is_bst(tree->right)) return false;
    return true;
}

int main(){
    NodePtr tree = create_node(69);
    tree->left = create_node(420);
    tree->left->left = create_node(23);
    tree->right = create_node(37);
    printf("%i\n", count_nodes(tree));
    printf("%i\n", tree_height(tree));
    return 0;
}
