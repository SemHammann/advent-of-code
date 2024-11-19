#ifndef QUEUE_H
#define QUEUE_H

#ifndef QUEUELENGTH
	#define QUEUELENGTH 128
#endif
#ifndef QUEUEHEIGHT
	#define QUEUEHEIGHT 128	
#endif

typedef struct Char_Queue
{
    long long unsigned start, end;
    char queue[QUEUELENGTH][QUEUEHEIGHT];
}Char_Queue_t;
//struct Char_Queue char_queue;

typedef struct long_long_unsigned_Queue
{
    long long unsigned start, end;
    int queue[QUEUELENGTH];
}long_long_unsigned_Queue_t;
//struct long_long_unsigned_Queue long_long_unsigned_queue;

void init_char(struct Char_Queue *char_queue);
void put_char(char vstr[], struct Char_Queue *char_queue);
char *get_char(struct Char_Queue *char_queue);

void init_long_long_unsigned(struct long_long_unsigned_Queue *long_long_unsigned_queue);
void put_long_long_unsigned(size_t number, struct long_long_unsigned_Queue *long_long_unsigned_queue);
size_t get_long_long_unsigned(struct long_long_unsigned_Queue *long_long_unsigned_queue);


#endif /* QUEUE_H */
