#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

/* ---------- Tables for the three techniques ---------- */
int linearTable[TABLE_SIZE];
int quadraticTable[TABLE_SIZE];

struct Node {
    int key;
    struct Node *next;
};
struct Node *chainTable[TABLE_SIZE];

/* ---------- Hash function (common to all techniques) ---------- */
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

/* ================= LINEAR PROBING ================= */
void initLinear() {
    for (int i = 0; i < TABLE_SIZE; i++)
        linearTable[i] = -1;  /* -1 marks an empty slot */
}

void insertLinear(int key) {
    int index = hashFunction(key);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i) % TABLE_SIZE;  /* linear probe: h(k)+i */
        if (linearTable[probe] == -1) {
            linearTable[probe] = key;
            printf("Key %d inserted at index %d (linear probing).\n", key, probe);
            return;
        }
    }
    printf("Hash table is full! Cannot insert key %d.\n", key);
}

void displayLinear() {
    printf("\nLinear Probing Table:\n");
    printf("Index\tValue\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (linearTable[i] == -1)
            printf("%d\t-\n", i);
        else
            printf("%d\t%d\n", i, linearTable[i]);
    }
}

/* ================= QUADRATIC PROBING ================= */
void initQuadratic() {
    for (int i = 0; i < TABLE_SIZE; i++)
        quadraticTable[i] = -1;
}

void insertQuadratic(int key) {
    int index = hashFunction(key);
    int i;
    for (i = 0; i < TABLE_SIZE; i++) {
        int probe = (index + i * i) % TABLE_SIZE;  /* quadratic probe: h(k)+i*i */
        if (quadraticTable[probe] == -1) {
            quadraticTable[probe] = key;
            printf("Key %d inserted at index %d (quadratic probing).\n", key, probe);
            return;
        }
    }
    printf("Hash table is full or no free slot found for key %d.\n", key);
}

void displayQuadratic() {
    printf("\nQuadratic Probing Table:\n");
    printf("Index\tValue\n");
    for (int i =
