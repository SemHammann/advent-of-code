#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "queue.h"


void init_char(void)
{
    char_queue.start = 0;
    char_queue.end = 0;
}

void put_char(char vstr[])
{
    strcpy(char_queue.queue[char_queue.end], vstr);
    char_queue.end++;
    if(char_queue.end == QUEUELENGHT)
    {
        char_queue.end = 0;
    }
    assert(char_queue.end != char_queue.start && "queue full");
}

char *get_char(void)
{
    assert(char_queue.end != char_queue.start && "char_queue empty");
    //char *str;
    //strcpy(str, queue.queue[queue.start]);
    size_t queuereturn = char_queue.start;
    char_queue.start++;
    if(char_queue.start == QUEUELENGHT)
    {
        char_queue.start = 0;
    }
    return char_queue.queue[queuereturn];
}


void init_long_long(void)
{
    long_long_queue.start = 0;
    long_long_queue.end = 0;
}

void put_long_long(int number)
{
    long_long_queue.end++;
    if(long_long_queue.end == QUEUELENGHT)
    {
        long_long_queue.end = 0;
    }
    assert(long_long_queue.end != long_long_queue.start && "queue full");
    long_long_queue.queue[long_long_queue.end] = number;
}

int get_long_long(void)
{
    assert(long_long_queue.end != long_long_queue.start && "queue empty");
    size_t number = long_long_queue.queue[long_long_queue.start];
    long_long_queue.start++;
    if(long_long_queue.start == QUEUELENGHT)
    {
        long_long_queue.start = 0;
    }
    return number;
}