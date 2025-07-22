#include <stdio.h>  
#include <string.h> //for strlen,strcmp function so i import this 

//new data type and also i use typedef to make coding more efficiently 
typedef struct { 
	char Code[6];
	char Cakename[51];
	int Available;
	int Price;
} ListOfCake;

//List of Cakes from ListOfCake data type i just created
ListOfCake Cakes[] = {
    {"CK001", "Blueberry Cake", 13, 25000},
    {"CK009", "Chocochip Cake", 5, 20000},
    {"CK017", "Mayonaise Cake", 24, 30000},
    {"CK023", "Strawberry ShortCake", 7, 17500}
};

int CakeCount = 4; //this number is for loop limit based on Cakes count

//AddStock function without any return because it's a void function
void AddStock(){
	char CakeCode[6];
	int Quantity; 
	while (true){ //this should be infinite loop until its break at the end of the function
		printf("Input Cake Code [5 chars]: ");
	    scanf("%s", CakeCode); //input the cakecode
	    int len = strlen(CakeCode); //count all the CakeCode characters
	    int found = -1; //first value of found that didn't match 
	    for (int i = 0; i < CakeCount; i++) {
            if (strcmp(Cakes[i].Code, CakeCode) == 0) { //compare if its same between the CakeCode and code from struct ListOfCake
                found = i; //found the index of the ListOfCake Cakes 
                break; //break the for loop because the CakeCode and Code is same
            }
        }
        if (found == -1) {
            printf("--- The Cake doesn't exist ---\n");  //cake doesn't exist message 
            continue;
        }
		if (len != 5) {
		   printf("Code must consist 5 character\n"); //validate the cake code length
		   continue;
		}
		printf("Input Quantity [1..10]: ");
        scanf("%d", &Quantity); //input the quantity you want
        if (Quantity < 1 || Quantity > 10) {
            printf("Quantity must be between 1 and 10\n"); //this if statement here is for validating the quantity limit 
            continue;
        }
        Cakes[found].Available += Quantity; // adding available cake with the quantity you want
        printf("--- Adding Stock Success ---\n"); // success message 
        break; //break the loop otherwise it will be the infinite loop
	}
}

//Sell Function without any return because it's a void function
void Sell(){
	char CakeCode[6];
	int Quantity;
	while (true){ //this should be infinite loop until its break at the end of the function
		printf("Input Cake Code [5 chars]: ");
	    scanf("%s", CakeCode); //input the cakecode
 	    int len = strlen(CakeCode); //count all the CakeCode characters
 	    int found = -1; //first value of found that didn't match 
 	    for (int i = 0; i < CakeCount; i++) {
            if (strcmp(Cakes[i].Code, CakeCode) == 0) {  //compare if its same between the CakeCode and code from struct ListOfCake
                found = i; //found the index of the ListOfCake Cakes 
                break;  //break the for loop because the CakeCode and Code is same
            }
        }
        if (found == -1) {
            printf("--- The Cake doesn't exist ---\n"); //cake doesn't exist message 
            continue;
        }
	    if (len != 5) {
		   printf("Code Must Consist 5 Characters\n"); //validate the cake code length
		   continue;
		}
		printf("Input Quantity [1..%d]: ", Cakes[found].Available);
        scanf("%d", &Quantity); //input the quantity you want
        if (Quantity < 1 || Quantity > Cakes[found].Available) {
            printf("... The quantity of cake is not enough or invalid...\n"); //this if statement here is for validating the quantity limit 
            continue;
        }

        Cakes[found].Available -= Quantity;
        int total = Cakes[found].Price * Quantity; // calculate the total by available cake in the list times the quantity you want to sell
        printf("Total Price is: Rp %d x %d = Rp %d,-\n", Cakes[found].Price, Quantity, total); //Total Price of the calculation
        printf("--- Thank You ---\n"); //Thank You message 
        break; //break the loop otherwise it will be the infinite loop
	}
}

//here's the main function 
int main() {
    int Menu;
    while (true) { //infinite loop hehehe just press ctrl + c to end the program
        printf("BLUE CAKE SHOP CASHIER\n");
        printf("======================\n\n");
        printf("No. | Cake Code | Cake Name             | Available | Price \n");
        printf("-----------------------------------------------------------------\n");
        for (int i = 0; i < CakeCount; i++) {
            printf("%02d. | %s     | %-20s | %9d | Rp. %d,-\n",i + 1, Cakes[i].Code, Cakes[i].Cakename, Cakes[i].Available, Cakes[i].Price);
        } //use for loop to make an update on all the list of cakes here if there's a change because of the function 
        printf("-----------------------------------------------------------------\n");
        printf("Menu:\n"); //here's the menu list and all the choice is yours  
        printf("1. Sell\n"); 
        printf("2. Add Stock\n");
        printf("3. Exit\n");
        printf("Input choice: ");
        scanf("%d", &Menu); //input the choice 
        switch (Menu) { //this case is more like a choice so i choose switch case instead of if else statement
            case 1:
                Sell(); //call the sell function because you choose case 1
                break;
            case 2:
                AddStock(); //call the addstock function because you choose case 2
                break;
            case 3:
                return 0; //exit the program
            default:
                printf("Input is invalid. Please try again.\n"); //if the input is not valid then this words will come in your terminal
        }
    }
    return 0;
}

