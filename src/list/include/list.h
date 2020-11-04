#ifndef LIST_H
#define LIST_H

#include <stddef.h>

#define OFFSETOF(struct_name, field_name) \
  (size_t) & ((struct_name *)0)->field_name

#define LIST_ITERATE_START(list_ptr, struct_type, node_ptr)              \
  {                                                                      \
    struct node *curr_node = NULL;                                       \
    struct node *next_node = NULL;                                       \
                                                                         \
    for (curr_node = list_ptr->head; curr_node; curr_node = next_node) { \
      next_node = curr_node->right;                                      \
      node_ptr = (struct_type *)((char *)curr_node - list_ptr->offset);

#define LIST_ITERATE_END \
  }                      \
  }

struct node {
  struct node *left;
  struct node *right;
};

typedef struct {
  struct node *head;
  size_t offset;
} list_t;

void list_init(list_t *list, const size_t offset);
void list_init_node(struct node *node);

void list_add_node(list_t *list, struct node *node);
void list_rem_node(list_t *list, struct node *node);

/* TODO: add find function */

#endif
