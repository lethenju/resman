#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "resman_types.h"
#include "resman.h"

static resman_ctx *context;

void resman_init()
{
    context = malloc(sizeof(resman_ctx));
    memset(context, '\0', sizeof(resman_ctx));
    context->current_id = 0;
}

void *resman_alloc(char *name, int size)
{
    resman_resource *res = context->list;
    if (res==NULL) // first one
    {
        context->list = malloc(sizeof(resman_resource));
        res = context->list;
    } 
    else
    {
        while (res->next != NULL)
            res = res->next;
        res->next = malloc(sizeof(resman_resource));
        res = res->next;
    }
    
    memset(res, '\0', sizeof(resman_resource));
    res->resource_id = context->current_id;
    res->resource_name = strdup(name);
    res->nb_bytes = size;
    res->ptr_to_res = malloc(size);
    memset(res->ptr_to_res, '\0', size);
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
    resman_resource *res = context->list;
    printf("== RESMAN RESOURCE DEBUG INFO == \n\n");
    while (res != NULL)
    {
        printf("ID : %d | size : %d | name : %s \n", res->resource_id, 
                                                     res->nb_bytes,
                                                     res->resource_name );
        res = res->next;
    }
}

int resman_get_number_of_resources()
{
    resman_resource *res = context->list;
    int nb_resource = 0;
    while (res != NULL)
    {
        nb_resource++;
        res = res->next;
    }
    return nb_resource;
}


int resman_get_id_of_resource(char* name)
{
    resman_resource *res = context->list;
    while (res != NULL)
    {
        if (!strcmp(res->resource_name, name)) return res->resource_id;
        res = res->next;
    }
    return -1; 
}


char* resman_get_name_of_resource(int id)
{
    resman_resource *res = context->list;
    while (res != NULL)
    {
        if (res->resource_id == id) return res->resource_name;
        res = res->next;
    }
    return NULL; 
}


int resman_get_size_of_resource(int id)
{
    resman_resource *res = context->list;
    while (res != NULL)
    {
        if (res->resource_id == id) return res->nb_bytes;
        res = res->next;
    }
    return -1; 
}

int resman_get_total_size_allocated()
{
    resman_resource *res = context->list;
    int total_size = 0;
    while (res != NULL)
    {
        total_size += res->nb_bytes;
        res = res->next;
    }
    return -1; 
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
