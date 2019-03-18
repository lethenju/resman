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

/** Prints the allocated resources for debug purposes
 */ 
void resman_print_resources();

/** Returns the number of resources allocated by resman
 *  @return int : the number of resources allocated by resman
 */  
int resman_get_number_of_resources();

/** Gets the id of a given resource name
 *  @param name : the name of the resource 
 *  @returns int : the id of the resource or -1 if the resource doesnt exist
 */ 
int resman_get_id_of_resource(char* name);

/** Gets the name of a given resource id
 *  @param id : the id of the resource
 *  @returns char* : the name of the resource or NULL if the resource doesnt exist
 */ 
char* resman_get_name_of_resource(int id);

/** Gets the size of a resource in bytes
 *  @param id : the id of the resource
 *  @returns int : the size of the resource in bytes or -1 if the resource doesnt exist
 */ 
int resman_get_size_of_resource(int id);

/** Gets the total allocated size at this moment
 *  @returns the total allocated size in bytes
 */ 
int resman_get_total_size_allocated();

/** Ends the resource manager and frees all resources allocated with it.
 */
void resman_end();


#endif
