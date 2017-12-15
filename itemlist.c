#include <stdlib.h>
#include <string.h>
#include "itemlist.h"

ItemList *itemlist_new()
{
    ItemList *list = (ItemList*) malloc(sizeof(ItemList));

    list->item = NULL;
    list->next = NULL;

    return list;
}

bool itemlist_add(ItemList *list, Item *item)
{
    // If current node has no item, put argument item here
    if (list->item == NULL) {
        list->item = item;

        return true;
    }

    // Make sure next is not NULL before proceeding
    if (list->next == NULL) {
        list->next = itemlist_new();
    }

    // Add to next node and return its return value
    return itemlist_add(list->next, item);
}

Item *itemlist_get(ItemList *list, char *key)
{
    // If current node item is not null and keys are equal, item has been found
    if (list->item != NULL && strcmp(list->item->key, key) == 0) {
        return list->item;
    }

    // If next node exists, search in next node
    if (list->next != NULL) {
        return itemlist_get(list->next, key);
    }

    // Failure, return null
    return NULL;
}

bool itemlist_has(ItemList *list, char *key)
{
    Item *item = itemlist_get(list, key);

    return item != NULL;
}

bool itemlist_remove(ItemList *list, char *key)
{
    // If current node item not null and keys are equal, item to remove has been found
    if (list->item != NULL && strcmp(list->item->key, key) == 0) {
        Item *currentItem = list->item;
        ItemList *currentNext = list->next;

        Item *newItem = NULL;
        ItemList *newNext = NULL;

        if (list->next != NULL) {
            newItem = list->next->item;
            newNext = list->next->next;
        }

        list->item = newItem;
        list->next = newNext;

        free(currentItem);
        free(currentNext);

        return true;
    }

    // If next node exists, recurse
    if (list->next != NULL) {
        return itemlist_remove(list->next, key);
    }

    // Item not found, failure.
    return false;
}
