#include <stdio.h>
#include <string.h>

#define MAX 1001

typedef struct {
    char city[MAX];
    double degree;
    char metric;
    double sortDegree;  
} Location;

void swap(Location *a, Location *b) {
    Location temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Location *location, int low, int high) {
    double pivot = location[high].sortDegree;
    char strpivot[MAX];
    strcpy(strpivot, location[high].city);
    int left = low;
    int right = high - 1;
    
    while (left <= right) {
        while (left <= right && 
              (location[left].sortDegree < pivot || 
              (location[left].sortDegree == pivot && strcmp(location[left].city, strpivot) < 0))) {
            left++;
        }
        while (left <= right && 
              (location[right].sortDegree > pivot || 
              (location[right].sortDegree == pivot && strcmp(location[right].city, strpivot) >= 0))) {
            right--;
        }
        if (left <= right) {
            swap(&location[left], &location[right]);
        }
    }
    swap(&location[left], &location[high]);
    return left;
}

void quicksort(Location *location, int low, int high) {
    if (low < high) {
        int p = partition(location, low, high);
        quicksort(location, low, p - 1);
        quicksort(location, p + 1, high);
    }
}

double convertToFahrenheit(double celsius) {
    return celsius * 1.8 + 32;
}

double convertToCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

int main() {
    FILE *fp;
    int n = 0;
    Location location[MAX];
    
    fp = fopen("testdata.in", "r");
    if (fp == NULL) {
        printf("File is empty\n");
        return 1;
    }
    
    char line[MAX + 50]; 
    while(fscanf(fp, "%[^#]#%lf#c", location[n].city, &location[n].degree, &location[n].metric) == 3) {
        location[n].sortDegree = location[n].degree;
        if (location[n].metric == 'F') {
            location[n].sortDegree = convertToCelsius(location[n].degree);
        }
        
        n++;
    }
    fclose(fp);
    
    quicksort(location, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%s is %.2lf%c\n", 
               location[i].city, 
               location[i].degree, 
               location[i].metric);
    }
    
    return 0;
}
