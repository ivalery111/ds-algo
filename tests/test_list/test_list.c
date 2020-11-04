#include <assert.h>
#include <setjmp.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

typedef struct {
  char name[16];
  uint32_t age;
  uint8_t weight;

  struct node node;
} human_t;

static void print_human_info(const human_t *human) {
  if (human) {
    fprintf(stdout, "Human info:\n");
    fprintf(stdout, "  name   -> %s\n", human->name);
    fprintf(stdout, "  age    -> %d\n", human->age);
    fprintf(stdout, "  weight -> %d\n", human->weight);
  }
}

static void test_add_node() {
  human_t *h1 = calloc(1, sizeof(human_t));
  snprintf(h1->name, 16, "%s", "human-one");
  h1->age = 20;
  h1->weight = 50;
  list_init_node(&(h1->node));

  human_t *h2 = calloc(1, sizeof(human_t));
  snprintf(h2->name, 16, "%s", "human-two");
  h2->age = 25;
  h2->weight = 55;
  list_init_node(&(h2->node));

  human_t *h3 = calloc(1, sizeof(human_t));
  snprintf(h3->name, 16, "%s", "human-three");
  h3->age = 30;
  h3->weight = 60;
  list_init_node(&(h3->node));

  /* List creation */
  list_t *human_list = calloc(1, sizeof(list_t));
  list_init(human_list, OFFSETOF(human_t, node));

  /* Insertion */
  list_add_node(human_list, &h1->node);
  list_add_node(human_list, &h2->node);
  list_add_node(human_list, &h3->node);

  /* Iteration */
  {
    human_t *human_ptr = NULL;
    LIST_ITERATE_START(human_list, human_t, human_ptr) {
      print_human_info(human_ptr);
    }
    LIST_ITERATE_END;
  }

  /* Find human-one */
  {
    int found_human_one = 0;
    human_t *human_ptr = NULL;
    LIST_ITERATE_START(human_list, human_t, human_ptr) {
      if ((strcmp(human_ptr->name, "human-one") == 0) &&
          (human_ptr->age == 20) && (human_ptr->weight == 50)) {
        found_human_one = 1;
      }
    }
    LIST_ITERATE_END;

    assert(found_human_one == 1);
  }

  if (h1 != NULL) free(h1);
  if (h2 != NULL) free(h2);
  if (h3 != NULL) free(h3);
  if (human_list != NULL) free(human_list);
}

static void test_rem_node() {
  human_t *h1 = calloc(1, sizeof(human_t));
  snprintf(h1->name, 16, "%s", "human-one");
  h1->age = 20;
  h1->weight = 50;
  list_init_node(&(h1->node));

  human_t *h2 = calloc(1, sizeof(human_t));
  snprintf(h2->name, 16, "%s", "human-two");
  h2->age = 25;
  h2->weight = 55;
  list_init_node(&(h2->node));

  human_t *h3 = calloc(1, sizeof(human_t));
  snprintf(h3->name, 16, "%s", "human-three");
  h3->age = 30;
  h3->weight = 60;
  list_init_node(&(h3->node));

  /* List creation */
  list_t *human_list = calloc(1, sizeof(list_t));
  list_init(human_list, OFFSETOF(human_t, node));

  /* Insertion */
  list_add_node(human_list, &h1->node);
  list_add_node(human_list, &h2->node);
  list_add_node(human_list, &h3->node);

  /* Remove human-three */

  list_rem_node(human_list, &h3->node);

  printf("After removing\n");
  {
    human_t *h = NULL;
    LIST_ITERATE_START(human_list, human_t, h) { print_human_info(h); }
    LIST_ITERATE_END;
  }

  if (h1 != NULL) free(h1);
  if (h2 != NULL) free(h2);
  if (h3 != NULL) free(h3);
  if (human_list != NULL) free(human_list);
}
int main(void) {
  test_add_node();
  test_rem_node();

  return 0;
}
