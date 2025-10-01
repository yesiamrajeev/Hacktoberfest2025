#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

typedef struct Node {
    int key;
    char value[50];
    struct Node* next;
} Node;

Node* hashTable[SIZE];

// Simple hash function
int hash(int key) {
    return key % SIZE;
}

// Insert key-value
void insert(int key, char* value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    strcpy(newNode->value, value);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

// Search key
char* search(int key) {
    int index = hash(key);
    Node* temp = hashTable[index];
    while(temp) {
        if(temp->key == key) return temp->value;
        temp = temp->next;
    }
    return NULL;
}

// Display
void display() {
    for(int i=0;i<SIZE;i++) {
        printf("[%d] -> ", i);
        Node* temp = hashTable[i];
        while(temp) {
            printf("(%d,%s) -> ", temp->key, temp->value);
            temp=temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    insert(1,"Apple");
    insert(2,"Banana");
    insert(12,"Mango");
    insert(22,"Orange");

    display();

    int key=12;
    char* val=search(key);
    if(val) printf("Key %d has value %s\n", key, val);
    else printf("Key %d not found\n", key);

    return 0;
}
