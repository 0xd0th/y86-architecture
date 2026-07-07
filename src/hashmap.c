
#include "./hashmap.h"

typedef struct {
	size_t len;
	unsigned long *vect;

} hashmap;


// implementacao do FNV-1a 
size_t hash(const char *s)
{
    size_t h = 14695981039346656037ULL;

    while (*s) {
        h ^= (unsigned char)*s++;
        h *= 1099511628211ULL;
    }

    return h;
}
