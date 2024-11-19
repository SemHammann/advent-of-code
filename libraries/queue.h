#ifndef QUEUE_H
#define QUEUE_H

#ifndef QUEUELENGHT
	#define QUEUELENGHT 128
#endif
#ifndef QUEUEHEIGHT
	#define QUEUEHEIGHT 128	
#endif

struct Char_Queue
{
    long long unsigned start, end;
    char queue[QUEUELENGHT][QUEUEHEIGHT];
};
struct Char_Queue char_queue;

struct long_long_Queue
{
    long long unsigned start, end;
    int queue[QUEUELENGHT];
};
struct long_long_Queue long_long_queue;

void init_char();
void put_char();
char *get_char();

void init_long_long();
void put_long_long();
int get_long_long();


#endif /* QUEUE_H */
