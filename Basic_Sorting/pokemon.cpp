#include <stdio.h>
#include <string.h>

#define MAX 101

typedef struct{
	char name[MAX];
	int damage;
	char type[MAX];
	double finaldamage;
} Pokemon;

void swap(Pokemon *a, Pokemon *b){
	Pokemon temp = *a;
	*a = *b;
	*b = temp;
}

int partition(Pokemon *pokemon, int low, int high){
    double float_pivot = pokemon[high].finaldamage;
    char string_pivot[MAX];
    strcpy(string_pivot, pokemon[high].name);
    int left = low;
    int right = high - 1;
    while(left <= right){
        while(left <= right && (pokemon[left].finaldamage < float_pivot || (pokemon[left].finaldamage == float_pivot && strcmp(pokemon[left].name, string_pivot) < 0))){
            left++;
        }
        while(left <= right && (pokemon[right].finaldamage > float_pivot || (pokemon[right].finaldamage == float_pivot && strcmp(pokemon[right].name, string_pivot) >= 0))){
            right--;
        }
        if (left <= right){
            swap(&pokemon[left], &pokemon[right]);
        }
    }
    swap(&pokemon[left], &pokemon[high]);
    return left;
}

void quicksort(Pokemon *pokemon, int low, int high){
	if (low < high){
		int p = partition(pokemon, low, high);
		quicksort(pokemon, low, p - 1);
		quicksort(pokemon, p + 1, high);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	getchar();
	Pokemon pokemon[n];
	char Grass[MAX] = "Grass";
    char Fire[MAX] = "Fire";
	char Water[MAX] = "Water";
	char Poison[MAX] = "Poison";
	for (int i = 0; i < n; i++){
		scanf("%[^#]#%[^#]#%d", pokemon[i].name, pokemon[i].type, &pokemon[i].damage);
	    getchar();
	    if (strcmp(pokemon[i].type, Grass) == 0 || strcmp(pokemon[i].type, Fire) == 0){
	    	pokemon[i].finaldamage = pokemon[i].damage * 0.5;
		}
		else if (strcmp(pokemon[i].type, Water) == 0){
	    	pokemon[i].finaldamage = pokemon[i].damage * 2;
		}
		else if (strcmp(pokemon[i].type, Poison) == 0){
	    	pokemon[i].finaldamage = pokemon[i].damage * 1.0;
		}
		else {
			printf("Not Valid Pokemon Type\n");
		}
	}
	
	quicksort(pokemon, 0, n - 1);
	
	for (int i = 0; i < n; i++){
		printf("%.2lf %s\n", pokemon[i].finaldamage, pokemon[i].name);
	}
	
	return 0;
}
