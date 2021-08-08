#include <stdio.h>
#include <stdlib.h>
#include <linked_list.h>

node_t *list_create(void *data)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void list_destroy(node_t **head, void (*fp) (void *data))
{
    node_t *current_node = *head;

    while (current_node != NULL)
    {
        node_t *next_node = current_node->next;
        fp(current_node->data);
        free(current_node);
        current_node = next_node;
    }

    head = NULL;
}

void list_push(node_t *head, void *data)
{
    node_t *current_node = head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }

    current_node->next = list_create(data);
    current_node->next->data = data;
}

void list_unshift(node_t **head, void *data)
{
    node_t *new_node = list_create(data);
    new_node->next = *head;
    *head = new_node;
}

void *list_pop(node_t **head)
{
    void *return_value = NULL;

    if ((*head)->next == NULL)
    {
        return_value =  (*head)->data;
        free(*head);
        head = NULL;
    }
    else
    {
        node_t *current_node = *head;
        while (current_node->next->next != NULL)
        {
            current_node = current_node->next;
        }
        return_value = current_node->next->data;
        free(current_node->next);
        current_node->next = NULL;
    }
    return return_value;
}

void *list_shift(node_t **head)
{
    void *return_value = NULL;

    if ((*head)->next == NULL)
    {
        return_value = (*head)->data;
        free(*head);
        *head = NULL;
    }
    else
    {
        node_t *new_head = (*head)->next;
        return_value = (*head)->data;
        free(*head);
        *head = new_head;
    }

    return return_value;
}

void list_print(node_t *head)
{
    node_t *current_node = head;
    while (current_node != NULL)
    {
        printf("%s", (char *) current_node->data);
        current_node = current_node->next;
    }
}

void *list_remove(node_t **head, int pos)
{
    if (pos == 0)
    {
        return list_shift(head);
    }

    node_t *current_node = *head;
    node_t *prev_node = NULL;
    for(int i = 1; i < pos-1; ++i)
    {
        if(current_node == NULL)
        {
            return NULL;
        }
        prev_node = current_node;
        current_node = current_node->next;
    }

    prev_node->next = current_node->next;

    void *data = current_node->data;
    free(current_node);
    return data;
}

void list_visitor(node_t *head, void (*fp)(void *data))
{
    node_t *current_node = head;

    while (current_node != NULL)
    {
        node_t *next_node = current_node->next;
        fp(current_node->data);
        current_node = next_node;
    }
}
