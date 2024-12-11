#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "hash.h"

int hash_code(int key)
{
	return key % SIZE;
}

struct Data_Item *hash_search(int key)
{
	int hash_index = hash_code(key);

	while(hash_array[hash_index] != NULL)
	{
		if(hash_array[hash_index]->key == key)
			return hash_array[hash_index];

		hash_index++;

		hash_index %= SIZE;
	}

	return NULL;
}

void hash_insert(int key, int data)
{
	struct Data_Item *item = (struct Data_Item*) malloc(sizeof(struct Data_Item));
	item->data = data;
	item->key = key;

	int hash_index = hash_code(key);

	while(hash_array[hash_index] != NULL && hash_array[hash_index]->key != -1)
	{
		hash_index++;
		hash_index %= SIZE;
	}

	hash_array[hash_index] = item;
}

struct Data_Item *hash_delete(struct Data_Item *item)
{
	int key = item->key;

	int hash_index = hash_code(key);

	while(hash_array[hash_index] != NULL)
	{
		if(hash_array[hash_index]->key == key)
		{
			struct Data_Item *tmp = hash_array[hash_index];
			hash_array[hash_index] = dummy_item;
			return tmp;
		}
		hash_index++;

		hash_index %= SIZE;
	}
	return NULL;
}

void hash_display()
{
	int i ;

	for(i = 0; i < SIZE; i++)
	{
		if(hash_array[i] != NULL)
			printf(" (%d, %d)", hash_array[i]->key, hash_array[i]->data);
		else
			printf(" ~~ ");
	}
	printf("\n");
}

void hash_fix_dummy_item()
{
	dummy_item = (struct Data_Item*) malloc(sizeof(struct Data_Item));
	dummy_item->data = -1;
	dummy_item->key -1;
}