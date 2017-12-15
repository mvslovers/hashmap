#pragma once

typedef struct Item_t {
    char * key;
    char * value;
    unsigned long int hash;
} Item;

Item * item_new(unsigned long int hash, char * key, char * value);
