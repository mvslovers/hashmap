#include <stdio.h>
#include "src/hashmap.h"

int main()
{
    Hashmap *map = hashmap_new(10);
    hashmap_set(map, "name", "andre");
    hashmap_set(map, "surname", "jenkins");
    hashmap_set(map, "career", "software developer");
    hashmap_set(map, "institute", "uom");
    hashmap_set(map, "cousin", "miguel muscat");
    hashmap_set(map, "memelevel", "0");
    hashmap_set(map, "memelevel", "999");

    hashmap_remove(map, "cousin");

    for (unsigned int i = 0; i < map->size; ++i) {
        printf("Index #%d [", i);

        ItemList *list = &(map->lists[i]);

        if (list != NULL && list->item != NULL) {
            while (list != NULL && list->item != NULL) {
                char *key = list->item->key;
                printf("\n\t(%s) %s", key, hashmap_get(map, key));
                list = list->next;
            }
            printf("\n");
        }

        printf("]\n");
    }

    return 0;
}
