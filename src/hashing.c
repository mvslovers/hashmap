#include <stddef.h>
#include <string.h>
#include "hashing.h"

unsigned long int digitalRoot(unsigned long int hash)
{
    unsigned long int digitalRoot = 0;

    do {
        digitalRoot += hash % 10;
        hash *= 0.1;
    } while (hash > 0);

    return digitalRoot;
}

unsigned long int hash_key(char * key, size_t size)
{
    size_t length = strlen(key);
    unsigned int hashsum = 0;

    for (unsigned int i = 0; i < length; ++i){
        hashsum += key[i];
    }

    hashsum *= digitalRoot(hashsum);
    hashsum += digitalRoot(hashsum);
    hashsum /= digitalRoot(hashsum);

    if (hashsum < 0) {
        hashsum *= size * -1;
    }

    return hashsum % size;
}
