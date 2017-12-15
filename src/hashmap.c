#include <stdlib.h>
#include "hashing.h"
#include "hashmap.h"

/**
 * [NON-API] Utility method for retrieving the item list and hash for a given key.
 *
 * @param hashmap The hashmap.
 * @param hash The item key hash.
 *
 * @return The item list, or a null pointer.
 */
ItemList* hashmap__getItemList(Hashmap *hashmap, unsigned long int hash)
{
    if (hash > (hashmap->size - 1)) {
        // Hash is out of bounds, for some reason
        return NULL;
    }

    return &hashmap->lists[hash];
}

Hashmap *hashmap_new(size_t size)
{
    Hashmap *hashmap = (Hashmap*) malloc(sizeof(Hashmap));

    hashmap->size = size;
    hashmap->lists = calloc(size, sizeof(ItemList));

    return hashmap;
}

bool hashmap_set(Hashmap * hashmap, char *key, char *value)
{
    unsigned long int hash = hash_key(key, hashmap->size);
    ItemList *list = hashmap__getItemList(hashmap, hash);

    if (list == NULL) {
        return false;
    }

    // Replace value if exists
    Item *existing = itemlist_get(list, key);
    if (existing) {
        existing->value = value;
        return true;
    }

    // Create new Item
    Item *item = item_new(hash, key, value);
    // Add to list and return its success return value
    return itemlist_add(list, item);
}


char *hashmap_get(Hashmap *hashmap, char *key)
{
    unsigned long int hash = hash_key(key, hashmap->size);
    ItemList *list = hashmap__getItemList(hashmap, hash);

    if (list == NULL) {
        return NULL;
    }

    Item *item = itemlist_get(list, key);

    if (item == NULL) {
        return NULL;
    }

    return item->value;
}

bool hashmap_has(Hashmap *hashmap, char *key)
{
    return hashmap_get(hashmap, key) != NULL;
}

bool hashmap_remove(Hashmap *hashmap, char *key)
{
    unsigned long int hash = hash_key(key, hashmap->size);
    ItemList *list = hashmap__getItemList(hashmap, hash);

    if (list == NULL) {
        return false;
    }

    return itemlist_remove(list, key);
}
