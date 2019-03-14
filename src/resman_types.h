#ifndef RESMAN_TYPES_H
#define RESMAN_TYPES_H

typedef struct resman_resource_t resman_resource;

typedef struct resman_resource_t
{
    int resource_id;
    char *resource_name;
    int nb_bytes;
    void *ptr_to_res;
    resman_resource *next;
} resman_resource;

typedef struct resman_ctx_t
{
    resman_resource *list;
    int current_id;
} resman_ctx;


#endif