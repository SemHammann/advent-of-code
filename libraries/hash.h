//V0.1

#ifndef HASH_BLOEM_H
#define HASH_BLOEM_H

#define SIZE 100000

struct Data_Item
{
	int data;
	int key;
};

struct Data_Item *hash_array[SIZE];
struct Data_Item *dummy_item;
struct Data_Item *item;

int hash_code(int key);
struct Data_Item *hash_search(int key);
void hash_insert(int key, int data);
struct Data_Item *hash_delete(struct Data_Item *item);
void hash_display();
void hash_fix_dummy_item();

#endif