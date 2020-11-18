#include <stdlib.h>
#ifndef CAT_H
#define CAT_H
#define BUFFER_LENGTH 128

int dynamic_buffer(char **line, size_t *buffer_length, void *input);

#endif
