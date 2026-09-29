#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 11

typedef struct Node {
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node **table;
    int amount;
} HashTable;

HashTable *createHashTable(){
    HashTable *table = malloc(sizeof(HashTable));
    if(table == NULL){ return NULL; }

    table->amount = 0;
    table->table = calloc(HASH_SIZE, sizeof(Node*));

    if(table->table == NULL){ free(table); return NULL; }

    return table;
}

int hash(const char *key){
    int result = 0;

    for(int i = 0; key[i] != '\0'; i++){ result = result * 31 + key[i]; }

    return result % HASH_SIZE;
}

void insert(HashTable *table, const char *key, int value){
    int index = hash(key);
    Node *current = table->table[index];

    while(current != NULL){
        if(strcmp(current->key, key) == 0){
            current->value = value;
            return;
        }
        current = current->next;
    }

    Node *new = malloc(sizeof(Node));
    if(new == NULL){ return; }

    new->key = malloc(strlen(key) + 1);
    if(new->key == NULL){ free(new); return; }

    strcpy(new->key, key);
    new->value = value;
    new->next = table->table[index];
    table->table[index] = new;
    table->amount++;
}

int search(HashTable *table, const char *key){
    int index = hash(key);
    Node *current = table->table[index];

    while(current != NULL){
        if(strcmp(current->key, key) == 0){ return current->value; }
        current = current->next;
    }
    return -1;
}

int delete(HashTable *table, const char *key){
    int index = hash(key);
    Node *current = table->table[index];
    Node *previous = NULL;

    while(current != NULL){
        if(strcmp(current->key, key) == 0){ 
            if(previous == NULL){ table->table[index] = current->next; }
            else { previous->next = current->next; }

            free(current->key);
            free(current);
            table->amount--;

            return 1;
        }
        previous = current;
        current = current->next;
    }
    return 0;
}

void deleteTable(HashTable *table){
    for(int i = 0; i< HASH_SIZE; i++){
        Node *current = table->table[i];
        while(current != NULL){
            Node *next = current->next;
            free(current->key);
            free(current);

            current = next;
        }
    }
    free(table->table);
    free(table);
}

int romanToInt(HashTable *table, char* s){
    int result = 0;
    int lenght = strlen(s);
    char temporal[2]; temporal[1] = '\0';

    for(int i = 0; i < lenght; i++){
        temporal[0] = s[i];
        int current_value = search(table, temporal);

        if(i == lenght - 1){ result += current_value; break; }

        temporal[0] = s[i +1];
        int next_value = search(table, temporal);

        temporal[0] = s[i];

        if(current_value < next_value){ result -= current_value; }
        else { result += current_value; }
    }
    return result;
}

int main(void) {
    char roman_number[] = "MXLVII";
    HashTable *table = createHashTable();

    insert(table, "I", 1);
    insert(table, "V", 5);
    insert(table, "X", 10);
    insert(table, "L", 50);
    insert(table, "C", 100);
    insert(table, "D", 500);
    insert(table, "M", 1000);

    int res = romanToInt(table, roman_number);
    printf("Arabic: %d\n", res);

    deleteTable(table);

    return 0;
}
