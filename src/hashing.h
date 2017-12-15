#pragma once

/**
 * Calculates the digital root of a hash key.
 *
 * @param hash The hash.
 *
 * @return The calculated digital root.
 */
unsigned long int digital_root(unsigned long int hash);

/**
 * Calculates the hash for a key, taking into account the size of the container.
 *
 * @param key The key to hash.
 * @param size The size of the parent container.
 *
 * @return The generate hash.
 */
unsigned long int hash_key(char * key, size_t size);
