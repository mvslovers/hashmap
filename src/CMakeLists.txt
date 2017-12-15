set(
    SOURCE_FILES
    hashing.h
    hashing.c
    item.h
    item.c
    itemlist.h
    itemlist.c
    hashmap.h
    hashmap.c
)

add_library(hashmap ${SOURCE_FILES})
