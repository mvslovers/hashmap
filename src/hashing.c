#include <stddef.h>
#include <string.h>
#include "hashing.h"

unsigned long int digital_root(unsigned long int hash)
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

    hashsum *= digital_root(hashsum);
    hashsum += digital_root(hashsum);
    hashsum /= digital_root(hashsum);

    if (hashsum < 0) {
        hashsum *= size * -1;
    }

    return hashsum % size;
}
