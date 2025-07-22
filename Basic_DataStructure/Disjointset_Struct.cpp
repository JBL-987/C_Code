#include <stdio.h>
#include <string.h>
#define MAXNODE 10
#define NAME_SIZE 50

typedef struct {
    int parent;
    int rank;
    char name[NAME_SIZE];
    int age;
} Person;

Person people[MAXNODE];
int totalPeople = 0;

void make_set(int index, char* name, int age) {
    people[index].parent = index;
    people[index].rank = 0;
    strcpy(people[index].name, name);
    people[index].age = age;
}

int find_set(int v) {
    if (v == people[v].parent) {
        return v;
    }
    return people[v].parent = find_set(people[v].parent);
}

void union_sets(int a, int b) {
    int parentA = find_set(a);
    int parentB = find_set(b);
    
    if (parentA != parentB) {
        if (people[parentA].rank < people[parentB].rank) {
            int temp = parentA;
            parentA = parentB;
            parentB = temp;
        }
        people[parentB].parent = parentA;
        
        if (people[parentA].rank == people[parentB].rank) {
            people[parentA].rank++;
        }
    }
}

int isSameGroup(int a, int b) {
    int parentA = find_set(a);
    int parentB = find_set(b);
    
    if (parentA == parentB) {
        return 1;
    } else {
        return 0;
    }
}

void printPerson(int index) {
    printf("Person %d: %s (age %d)\n", index, people[index].name, people[index].age);
}

int main() {
    make_set(0, "Alice", 25);
    make_set(1, "Bob", 30);
    make_set(2, "Charlie", 28);
    make_set(3, "Diana", 22);
    make_set(4, "Eve", 35);
    totalPeople = 5;
    printf("=== Social Connection System ===\n\n");
    printf("Initial people:\n");
    for (int i = 0; i < totalPeople; i++) {
        printPerson(i);
    }
    printf("\n");
    printf("Creating connections...\n");
    union_sets(0, 1);
    printf("Connected Alice and Bob\n");
    union_sets(2, 3);
    printf("Connected Charlie and Diana\n");
    union_sets(1, 2);
    printf("Connected Bob and Charlie\n");
    printf("\n");
    printf("Checking connections:\n");
    printf("Are Alice and Charlie in the same group? %s\n", isSameGroup(0, 2) ? "Yes" : "No");
    printf("Are Alice and Eve in the same group? %s\n", isSameGroup(0, 4) ? "Yes" : "No");
    printf("Are Bob and Diana in the same group? %s\n", isSameGroup(1, 3) ? "Yes" : "No");
    printf("\n");
    printf("Group representatives:\n");
    for (int i = 0; i < totalPeople; i++) {
        printf("%s's group leader: %s\n", 
               people[i].name, people[find_set(i)].name);
    }
    return 0;
}
