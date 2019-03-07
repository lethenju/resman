#ifndef RESMAN_H
#define RESMAN_H

void resman_init();

void* resman_alloc(char* name, int size);

void resman_free(void* resource);

void resman_end();

#endif