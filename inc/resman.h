#ifndef RESMAN_H
#define RESMAN_H

/** Inits the resource manager system
 */
void resman_init();

/** Replaces your malloc call
 *  @param name : Give a name to your allocation to better keep track of it
 *  @param size : The size of your allocation, in bytes
 *  @returns void* : A pointer to your allocated memory
 */
void* resman_alloc(char* name, int size);

/** Replaces your free call
 *  @param resource : a pointer to your resource
 */
void resman_free(void* resource);

/** Ends the resource manager and frees all resources allocated with it.
 */
void resman_end();

#endif
