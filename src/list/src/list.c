#include "list.h"

void list_init(list_t *list, const unsigned long offset) {
  if (list) {
    list->head = NULL;
    list->offset = offset;
  }
}
void list_init_node(struct node *node) {
  if (node) {
    node->left = NULL;
    node->right = NULL;
  }
}

static void _add_next(struct node *curr_node, struct node *new_node) {
  if (curr_node->right == NULL) {
    curr_node->right = new_node;
    new_node->left = curr_node;
    return;
  }

  struct node *temp_node = curr_node->right;
  curr_node->right = new_node;
  new_node->left = curr_node;
  new_node->right = temp_node;
  temp_node->left = new_node;
}
void list_add_node(list_t *list, struct node *node) {
  list_init_node(node);

  if (list->head == NULL) {
    list->head = node;
    return;
  }

  struct node *head = list->head;
  _add_next(node, head);

  list->head = node;
}

static void _rem_node(struct node *node) {
  if (node == NULL) return;

  if (node->left == NULL) {
    if (node->right) {
      node->right->left = NULL;
      node->right = NULL;
      return;
    }
    return;
  }

  if (node->right == NULL) {
    node->left->right = NULL;
    node->left = NULL;

    return;
  }

  node->left->right = node->right;
  node->right->left = node->left;
  node->left = NULL;
  node->right = NULL;
}
void list_rem_node(list_t *list, struct node *node) {
  struct node *head = list->head;

  if (head == node) list->head = head->right;

  _rem_node(node);
}
