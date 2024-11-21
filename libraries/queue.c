//V4.0

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "queue.h"


void init_char(struct Char_Queue *char_queue)
{
    (*char_queue).front = 0;
    (*char_queue).back = 0;
}

void push_front_char(char vstr[], struct Char_Queue *char_queue)
{
    strcpy((*char_queue).queue[(*char_queue).front], vstr);
    (*char_queue).front--;
    if((*char_queue).front == 0)
    {
        (*char_queue).front = QUEUELENGTH;
    }
    assert((*char_queue).back != (*char_queue).front && "char_queue full");
}

void push_back_char(char vstr[], struct Char_Queue *char_queue)
{
    strcpy((*char_queue).queue[(*char_queue).back], vstr);
    (*char_queue).back++;
    if((*char_queue).back == QUEUELENGTH)
    {
        (*char_queue).back = 0;
    }
    assert((*char_queue).back != (*char_queue).front && "char_queue full");
}

char *pop_front_char(struct Char_Queue *char_queue)
{
    assert((*char_queue).back != (*char_queue).front && "char_queue empty");
    size_t queuereturn = (*char_queue).front;
    (*char_queue).front++;
    if((*char_queue).front == QUEUELENGTH)
    {
        (*char_queue).front = 0;
    }
    return (*char_queue).queue[queuereturn];
}

char *pop_back_char(struct Char_Queue *char_queue)
{
    assert((*char_queue).back != (*char_queue).front && "char_queue empty");
    size_t queuereturn = (*char_queue).back;
    (*char_queue).back--;
    if((*char_queue).back == 0)
    {
        (*char_queue).back = QUEUELENGTH;
    }
    return (*char_queue).queue[queuereturn];
}



void init_long_long_unsigned(struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    (*long_long_unsigned_queue).front = 0;
    (*long_long_unsigned_queue).back = 0;
}

void push_front_long_long_unsigned(size_t number, struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    (*long_long_unsigned_queue).front--;
    if((*long_long_unsigned_queue).front == 0)
    {
        (*long_long_unsigned_queue).front = QUEUELENGTH;
    }
    assert((*long_long_unsigned_queue).back != (*long_long_unsigned_queue).front && "long_long_unsigned_queue full");
    (*long_long_unsigned_queue).queue[(*long_long_unsigned_queue).front] = number;
}

void push_back_long_long_unsigned(size_t number, struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    (*long_long_unsigned_queue).back++;
    if((*long_long_unsigned_queue).back == QUEUELENGTH)
    {
        (*long_long_unsigned_queue).back = 0;
    }
    assert((*long_long_unsigned_queue).back != (*long_long_unsigned_queue).front && "long_long_unsigned_queue full");
    (*long_long_unsigned_queue).queue[(*long_long_unsigned_queue).back] = number;
}

long long unsigned pop_front_long_long_unsigned(struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    assert((*long_long_unsigned_queue).back + 1 != (*long_long_unsigned_queue).front && "long_long_unsigned_queue empty");
    size_t number = (*long_long_unsigned_queue).queue[(*long_long_unsigned_queue).front];
    (*long_long_unsigned_queue).front++;
    if((*long_long_unsigned_queue).front == QUEUELENGTH)
    {
        (*long_long_unsigned_queue).front = 0;
    }
    return number;
}

long long unsigned pop_back_long_long_unsigned(struct long_long_unsigned_Queue *long_long_unsigned_queue)
{
    assert((*long_long_unsigned_queue).back + 1 != (*long_long_unsigned_queue).front && "long_long_unsigned_queue empty");
    size_t number = (*long_long_unsigned_queue).queue[(*long_long_unsigned_queue).back];
    (*long_long_unsigned_queue).back--;
    if((*long_long_unsigned_queue).back == 0)
    {
        (*long_long_unsigned_queue).back = QUEUELENGTH;
    }
    return number;
}



void init_long_long(struct long_long_Queue *long_long_queue)
{
    (*long_long_queue).front = 0;
    (*long_long_queue).back = 0;
}

void push_front_long_long(size_t number, struct long_long_Queue *long_long_queue)
{
    (*long_long_queue).front--;
    if((*long_long_queue).front == 0)
    {
        (*long_long_queue).front = QUEUELENGTH;
    }
    assert((*long_long_queue).back != (*long_long_queue).front && "long_long_queue full");
    (*long_long_queue).queue[(*long_long_queue).front] = number;
}

void push_back_long_long(size_t number, struct long_long_Queue *long_long_queue)
{
    (*long_long_queue).back++;
    if((*long_long_queue).back == QUEUELENGTH)
    {
        (*long_long_queue).back = 0;
    }
    assert((*long_long_queue).back != (*long_long_queue).front && "long_long_queue full");
    (*long_long_queue).queue[(*long_long_queue).back] = number;
}

long long pop_front_long_long(struct long_long_Queue *long_long_queue)
{
    assert((*long_long_queue).back + 1 != (*long_long_queue).front && "long_long_queue empty");
    size_t number = (*long_long_queue).queue[(*long_long_queue).front];
    (*long_long_queue).front++;
    if((*long_long_queue).front == QUEUELENGTH)
    {
        (*long_long_queue).front = 0;
    }
    return number;
}

long long pop_back_long_long(struct long_long_Queue *long_long_queue)
{
    assert((*long_long_queue).back + 1 != (*long_long_queue).front && "long_long_queue empty");
    long long number = (*long_long_queue).queue[(*long_long_queue).back];
    (*long_long_queue).back--;
    if((*long_long_queue).back == 0)
    {
        (*long_long_queue).back = QUEUELENGTH;
    }
    return number;
}
