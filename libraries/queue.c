//V2.0

//maak keer lengte goed werkend

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "queue.h"


void init_char(struct Char_Queue *char_queue)
{
    (*char_queue).start = 0;
    (*char_queue).end = 0;
}

void put_char(char vstr[], struct Char_Queue *char_queue)
{
    strcpy((*char_queue).queue[(*char_queue).end], vstr);
    (*char_queue).end++;
    if((*char_queue).end == QUEUELENGTH)
    {
        (*char_queue).end = 0;
    }
    assert((*char_queue).end != (*char_queue).start && "char_queue full");
}

char *get_char(struct Char_Queue *char_queue)
{
    assert((*char_queue).end != (*char_queue).start && "char_queue empty");
    //char *str;
    //strcpy(str, queue.queue[queue.start]);
    size_t queuereturn = (*char_queue).start;
    (*char_queue).start++;
    if((*char_queue).start == QUEUELENGTH)
    {
        (*char_queue).start = 0;
    }
    return (*char_queue).queue[queuereturn];
}


void init_long_long_unsigned(struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    (*long_long_unsigned_queue).start = 0;
    (*long_long_unsigned_queue).end = 0;
}

void put_long_long_unsigned(size_t number, struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    (*long_long_unsigned_queue).end++;
    if((*long_long_unsigned_queue).end == QUEUELENGTH)
    {
        (*long_long_unsigned_queue).end = 0;
    }
    assert((*long_long_unsigned_queue).end != (*long_long_unsigned_queue).start && "long_long_unsigned_queue full");
    (*long_long_unsigned_queue).queue[(*long_long_unsigned_queue).end] = number;
}

size_t get_long_long_unsigned(struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    assert((*long_long_unsigned_queue).end + 1 != (*long_long_unsigned_queue).start && "long_long_unsigned_queue empty");
    size_t number = (*long_long_unsigned_queue).queue[(*long_long_unsigned_queue).start];
    (*long_long_unsigned_queue).start++;
    if((*long_long_unsigned_queue).start == QUEUELENGTH)
    {
        (*long_long_unsigned_queue).start = 0;
    }
    return number;
}