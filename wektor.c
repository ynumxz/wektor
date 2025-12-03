#include <stdlib.h>

struct Wektor
{
    int *data;
    long int size;
    long int count;
};

void create(struct Wektor *w, unsigned int size)
{
    w->data = NULL;
    w->size = 0;
    w->count = 0;

    if (size == 0)
    {
        return;
    }

    w->data = malloc(size * sizeof(int));
    if (w->data != NULL)
    {
        w->size = size;
        w->count = 0;
    }
}

void push_back(struct Wektor *w, int element)
{
    if (w->count >= w->size)
    {
        unsigned int newSize = (w->size == 0) ? 1 : w->size * 2;
        int *tmp = realloc(w->data, newSize * sizeof(int));
        if (tmp == NULL)
        {

            return;
        }
        w->data = tmp;
        w->size = newSize;
    }

    w->data[w->count] = element;
    w->count++;
}

int get(struct Wektor *w, int index, int *result)
{
    if (index < 0 || (unsigned int)index >= w->count)
    {
        return 0;
    }

    *result = w->data[index];
    return 1;
}

int set(struct Wektor *w, int index, int element)
{
    if (index < 0 || (unsigned int)index >= w->count)
    {
        return 0;
    }
    w->data[index] = element;
    return 1;
}

void del(struct Wektor *w)
{
    if (w->data != NULL)
    {
        free(w->data);
    }
    w->data = NULL;
    w->size = 0;
    w->count = 0;
}
