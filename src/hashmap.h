#pragma once
#include <stdbool.h>
#include "itemlist.h"

typedef struct Hashmap_t
{
    ItemList *lists;
    size_t size;
} Hashmap;

/**
 * Creates a new hashmap.
 *
 * @param size The page size of the hasmap.
 *
 * @return The created hashmap.
 */
Hashmap *hashmap_new(size_t size);

/**
 * Sets an entry in the hashmap, overriding any existing value.
 *
 * @param hashmap The hashmap to add to.
 * @param key The key of the entry to set.
 * @param value The value to set.
 *
 * @return True on success, false on failure.
 */
bool hashmap_set(Hashmap * hashmap, char *key, char *value);

/**
 * Retrieves a value from the hashmap.
 *
 * @param hashmap The hashmap to retrieve from.
 * @param key The key of the value to retrieve.
 *
 * @return The value, or a null pointer if no value was found for the given key.
 */
char *hashmap_get(Hashmap *hashmap, char *key);

/**
 * Checks if the hashmap contains a value for a given key.
 *
 * @param hashmap The hashmap to search.
 * @param key The key to search for.
 *
 * @return True if a value was found for the given key, false otherwise.
 */
bool hashmap_has(Hashmap * hashmap, char *key);

/**
 * Removes a value from the hashmap.
 *
 * @param hashmap The hashmap to remove from.
 * @param key The key of the value to remove.1
 *
 * @return True on success, false on failure.
 */
bool hashmap_remove(Hashmap * hashmap, char *key);
