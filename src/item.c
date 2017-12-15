#include <stdlib.h>
#include "item.h"

Item * item_new(unsigned long int hash, char * key, char * value)
{
    Item * item = (Item*) malloc(sizeof(Item));

    item->hash = hash;
    item->key = key;
    item->value = value;

    return item;
}
