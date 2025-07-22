#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h> 

typedef struct {
    char price[50];
    char rooms[50];
    char bathroom[50];
    char carpark[50];
    char location[100];
    char city[100];
    char type[100];
    char furnish[50];
} Data_row;

void display_data(){
	int rows;
	char buffer[256];
		printf("Number of rows: ");
		scanf("%d", &rows);
		getchar();
	if (rows <= 0){
		printf("The input is not valid try again\n");
		display_data();
	    }
	    FILE *fp = fopen("file.csv", "r");
	if (fp == NULL) {
        printf("Error: Could not open file.\n");
        }
	for (int i = 0; i <= rows; i++){
		if (fgets(buffer, sizeof(buffer), fp) != NULL){
			printf("%s\n", buffer);
		}
		else {
			break;
			}
		}
		fclose(fp);
}

void search_data() {
    char option[100];
    char buffer[256];
    char search_value[100];
    FILE *fp;
    bool found = false;
    printf("Choose column: ");
    scanf("%s", option);
    getchar();
    fp = fopen("file.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
    if (strcmp(option, "Location") == 0 || strcmp(option, "City") == 0 || strcmp(option, "Type") == 0 || 
        strcmp(option, "Furniture") == 0 || strcmp(option, "Price") == 0 || strcmp(option, "Rooms") == 0 || 
        strcmp(option, "Bathroom") == 0 || strcmp(option, "Carpark") == 0) {

        printf("What do you want to find? ");
        scanf("%s", search_value);
        getchar();
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (strstr(buffer, search_value) != NULL) {
                if (!found) {
                    printf("Data found. Details of data:\n");
                    printf("%-20s %-15s %-10s %-6s %-8s %-8s %-10s %-12s\n",
                           "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
                    found = true;
                }
                char location[50], city[50], price[10], rooms[5], bathroom[5], carpark[5], type[15], furnish[15];
                sscanf(buffer, "%49[^,],%49[^,],%9[^,],%4[^,],%4[^,],%4[^,],%14[^,],%14[^\"]",
                       location, city, price, rooms, bathroom, carpark, type, furnish);
                printf("%-20s %-15s %-10s %-6s %-8s %-8s %-10s %-12s\n",
                       location, city, price, rooms, bathroom, carpark, type, furnish);
            }
        }
        if (!found) {
            printf("Data not found.\n");
        }
    } else {
        printf("Invalid column option.\n");
    }
    fclose(fp);
}


void sort_data() {
    char option[100];
    char sort_order[100];
    char buffer[512];
    FILE *fp;
    int count = 0;
    Data_row *data = NULL;
    printf("Choose column: ");
    scanf("%s", option);
    getchar();
    printf("Sort ascending or descending? ");
    scanf("%s", sort_order);
    getchar();
    fp = fopen("file.csv", "r");
    fgets(buffer, sizeof(buffer), fp); 
    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        count++;
        data = (Data_row*) realloc(data, count * sizeof(Data_row));
        if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return;
    }
        sscanf(buffer, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",
               data[count - 1].location, data[count - 1].city, data[count - 1].price,
               data[count - 1].rooms, data[count - 1].bathroom, data[count - 1].carpark,
               data[count - 1].type, data[count - 1].furnish);
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            bool swap = false;
            if (strcmp(option, "Price") == 0) {
                int price_i = atoi(data[i].price);
                int price_j = atoi(data[j].price);
                swap = (strcmp(sort_order, "asc") == 0) ? (price_i > price_j) : (price_i < price_j);
            } else if (strcmp(option, "Rooms") == 0) {
                int rooms_i = atoi(data[i].rooms);
                int rooms_j = atoi(data[j].rooms);
                swap = (strcmp(sort_order, "asc") == 0) ? (rooms_i > rooms_j) : (rooms_i < rooms_j);
            } else if (strcmp(option, "Bathroom") == 0) {
                int bath_i = atoi(data[i].bathroom);
                int bath_j = atoi(data[j].bathroom);
                swap = (strcmp(sort_order, "asc") == 0) ? (bath_i > bath_j) : (bath_i < bath_j);
            } else if (strcmp(option, "Carpark") == 0) {
                int park_i = atoi(data[i].carpark);
                int park_j = atoi(data[j].carpark);
                swap = (strcmp(sort_order, "asc") == 0) ? (park_i > park_j) : (park_i < park_j);
            } else if (strcmp(option, "Location") == 0) {
			   swap = (strcmp(sort_order, "asc") == 0) ? (strcmp(data[i].location, data[j].location) > 0) : (strcmp(data[i].location, data[j].location) < 0);
            } else if (strcmp(option, "City") == 0) {
               swap = (strcmp(sort_order, "asc") == 0) ? (strcmp(data[i].city, data[j].city) > 0) : (strcmp(data[i].city, data[j].city) < 0);
			}
			else {
                printf("Invalid column name.\n");
                free(data);
                return;
            }
            if (swap) {
                Data_row temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    printf("\nData found. Detail of data:\n");
    printf("%-20s %-15s %-10s %-6s %-8s %-8s %-10s %-12s\n",
       "Location", "City", "Price", "Rooms", "Bathroom", "Carpark", "Type", "Furnish");
    for (int i = 0; i < count && i < 10; i++) {
        printf("%-20s %-15s %-10s %-5s %-8s %-8s %-10s %-10s\n",
		data[i].location, data[i].city, data[i].price, data[i].rooms,
		data[i].bathroom, data[i].carpark, data[i].type, data[i].furnish);
    }
    fclose(fp);
    free(data);
}

void export_data(){
	FILE *inputfile, *outputfile;
	char input_file[100] = "file.csv";
	char output_file[100];
	char buffer[256];
		inputfile = fopen(input_file, "r");
	if (inputfile == NULL) {
        printf("Error: Could not open input file.\n");
    }
    printf("File name: ");
    scanf("%s", output_file);
    getchar();
    strcat(output_file, ".csv"); 
    outputfile = fopen(output_file, "w");
    if (outputfile == NULL) {
        printf("Error: Could not open input file.\n");
    }
    while (fgets(buffer, sizeof(buffer), inputfile) != NULL) {
        fputs(buffer, outputfile);
    }
    fclose(inputfile);
    fclose(outputfile);
    printf("Data successfully written to the file %s\n", output_file);
}

int main(){
    int choice;
    while (true) {
        printf("What do you want to do?\n");
        printf("1. Display data\n");
        printf("2. Search Data\n");
        printf("3. Sort Data\n");
        printf("4. Export Data\n");
        printf("5. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            case 1:
                display_data();
                break; 
            case 2:
                search_data();
                break;
            case 3:
                sort_data();
                break;
            case 4:
                export_data();
                break;
            case 5:
                return 0; 
            default:
                printf("Please enter a valid input\n");
                break;
        }
    }
}
