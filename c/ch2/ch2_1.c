/*
Compile
gcc -g -O0 --std=c89 ./ch2_1.c `pkg-config --cflags --libs glib-2.0` -o ch2_1.elf

Valgrind output showing where lost bytes occur
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./ch2_1.elf
*/

#include <glib.h>

struct Node
{
    gint32 data;
    struct Node *next;
};
typedef struct Node Node;

struct LinkedList
{
    Node *head;
};
typedef struct LinkedList LinkedList;

LinkedList *create_list()
{
    LinkedList *list = (LinkedList *)g_malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

Node *create_node()
{
    Node *n = (Node *)g_malloc(sizeof(Node));
    n->next = NULL;
    return n;
}

void list_append(LinkedList *list, Node *item)
{
    if (list->head == NULL)
    {
        list->head = item;
    }
    else
    {
        Node *current = list->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = item;
    }
}

void list_print(LinkedList *list)
{
    Node *current = list->head;
    if (list->head == NULL)
    {
        g_print("Nothing to print");
    }
    else
    {
        while (current->next != NULL)
        {
            current = current->next;
            g_print("Item=%d\n", current->data);
        }
    }
}

void list_free(LinkedList *list)
{
    Node *tmp;
    while (list->head != NULL)
    {
        tmp = list->head;
        list->head = list->head->next;
        g_free(tmp);
    }
    g_free(list);
}

main()
{
    GRand *random = g_rand_new_with_seed(0);
    LinkedList *list = NULL;
    list = create_list();

    gsize i = 0;
    for (i = 0; i < 100; i++)
    {
        Node *new = create_node();
        new->data = g_rand_int(random) % 100;
        list_append(list, new);
    }
    list_print(list);
    list_free(list);
    g_free(random);
}