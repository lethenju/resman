#ifndef RESMAN_TYPES_H
#define RESMAN_TYPES_H

typedef struct resman_resource_t resman_resource;

/** Resource list structure that wraps resources allocations
 */
typedef struct resman_resource_t
{
    int resource_id;       // the ID of the resource, incremented for each new resource
    char *resource_name;   // the name of the resource, to help debuggers understand the code
    int nb_bytes;          // the size of the resource, in bytes
    void *ptr_to_res;      // a pointer to the actual resource
    resman_resource *next; // a pointer to the next resource in the list
} resman_resource;

/** Context structure of the resman module
 */
typedef struct resman_ctx_t
{
    resman_resource *list; // a pointer to the resource list
    int current_id;        // the id of the latest allocated structure
} resman_ctx;

#endif
