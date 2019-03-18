#include <stdlib.h>
#include <string.h>
#include "resman_types.h"
#include "resman.h"

static resman_ctx *context;

void resman_init()
{
    context = malloc(sizeof(resman_ctx));
    memset(context, 0, sizeof(resman_ctx));
    context->current_id = 0;
}

void *resman_alloc(char *name, int size)
{
    resman_resource *res = context->list;
    while (res != NULL)
        res = res->next;
    res = malloc(sizeof(resman_resource));
    memset(res, NULL, sizeof(resman_resource));
    res->resource_id = context->current_id;
    res->resource_name = name;
    res->nb_bytes = size;
    res->ptr_to_res = malloc(size);
    memset(res->ptr_to_res, NULL, size);
    context->current_id++;
    return res->ptr_to_res;
}

void resman_free(void *resource)
{
    resman_resource *res = context->list;
    if (res->ptr_to_res == resource)
    {
        resman_resource *new_first = context->list->next ;
        free(context->list->ptr_to_res);
        free(context->list->resource_name);
        free(context->list);
        context->list = new_first;
    } 
    else 
    {
        while (res->next->ptr_to_res != resource)
            res = res->next; // finding the resource
        // we have to remove the element in the middle of the queue.
        // so we have to free the unused element
        free (res->next->ptr_to_res);
        free (res->next->resource_name);
        free (res->next);
        // then set the before element's next on the next directly, 
        res->next = res->next->next;
    }
}


void resman_print_resources()
{
    //TODO IMPLEMENT
}

int resman_get_number_of_resources()
{
    //TODO IMPLEMENT
    return 0;
}


int resman_get_id_of_resource(char* name)
{
    //TODO IMPLEMENT
    return 0;
}


char* resman_get_name_of_resource(int id)
{
    //TODO IMPLEMENT
    return "";
}


int resman_get_size_of_resource(int id)
{
    //TODO IMPLEMENT
    return 0;
}

int resman_get_total_size_allocated()
{
    //TODO IMPLEMENT
    return 0;
}

void resman_end()
{  
    resman_resource *res = context->list;
    while (res != NULL)
    {
        // free all resources
        resman_resource *next = res->next;
        free(res->resource_name);
        free(res->ptr_to_res);
        free(res);
        res = next; 
    }
    free (context);
}
