#pragma once
#include <stdbool.h>
#include "item.h"

/**
 * Item list structure.
 */
struct ItemList_t;
typedef struct ItemList_t
{
    Item *item;
    struct ItemList_t *next;
} ItemList;

/**
 * Creates a new item list.
 *
 * @return The created item list.
 */
ItemList *itemlist_new();

/**
 *
 * @param list The list to add to.
 * @param item The item to add.
 *
 * @return True on success, false on failure.
 */
bool itemlist_add(ItemList *list, Item *item);

/**
 * Retrieves an item from the list.
 *
 * @param list The list to retrieve from.
 * @param key The key of the item to retrieve.
 *
 * @return The item, or a null pointer if no item with the given key was found.
 */
Item *itemlist_get(ItemList *list, char *key);

/**
 * Checks whether the list has an item with a specific key.
 *
 * @param list The list to search.
 * @param key The key of the item to search for.
 *
 * @return True if an item with the given key was found, false if not.
 */
bool itemlist_has(ItemList *list, char *key);

/**
 * Removes an item from the list.
 *
 * @param list The list to remove from.
 * @param key The key of the item to remove.
 *
 * @return True on success, false on failure.
 */
bool itemlist_remove(ItemList *list, char *key);
