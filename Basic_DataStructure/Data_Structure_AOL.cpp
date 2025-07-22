#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <conio.h>

#define SIZE 256 

typedef struct node {
	bool endofword;
	struct node *word[SIZE];
	char description[SIZE];
}Trie;

void (*menu_ptr)();

void menu();

void set_menu_ptr(){
	menu_ptr = menu;
}

Trie *root = NULL;

Trie *createnode(){
	Trie *newnode = (Trie*)malloc(sizeof(Trie));
	for (int i = 0; i < SIZE; i++){
		newnode->word[i] = NULL;
	}
	newnode->endofword = false;
	newnode->description[0] = '\0';
	return newnode;
}

void insertnode(Trie **root, const char word[], const char description[]){
	if (*root == NULL){
		*root = createnode();
	} 
	Trie *curr = *root;
	    while (*word){
           int index = (unsigned char)*word;
           if (curr->word[index] == NULL){
               curr->word[index] = createnode();
            }
        curr = curr->word[index];
        word++;
    }
    curr->endofword = true;
    strcpy(curr->description, description);
}

bool searchnode(Trie *root, const char word[], char description[]){
	if (root == NULL){
		return false;
	}
	Trie *curr = root;
	    while (*word){
           int index = (unsigned char)*word;
           if (curr->word[index] == NULL){
               return false;
            }
        curr = curr->word[index];
        word++;
    }
    if (curr->endofword){
    	strcpy(description, curr->description);
        return true;
	}
	return false;
}

void getAllWords(Trie *node, char prefix[], int level, char allwords[][SIZE], int *wordcount) {
    if (node->endofword) {
        strcpy(allwords[*wordcount], prefix);
        (*wordcount)++;
    }
    
    for (int i = 0; i < SIZE; i++) {
        if (node->word[i] != NULL) {
            prefix[level] = (char)i;
            prefix[level + 1] = '\0';
            getAllWords(node->word[i], prefix, level + 1, allwords, wordcount);
        }
    }
}

void getallwords(Trie *root, const char prefix[], char allwords[][SIZE], int *wordcount){
	if (root == NULL) {
	    return;	
	}
    Trie *curr = root;
    const char *ptr = prefix;
    while (*ptr) {
        int index = (unsigned char)*ptr;
        if (curr->word[index] == NULL) {
            return;
        }
        curr = curr->word[index];
        ptr++;
    }    
    char tempprefix[SIZE];
    strcpy(tempprefix, prefix);
    int level = strlen(prefix);
    if (curr->endofword) {
        strcpy(allwords[*wordcount], tempprefix);
        (*wordcount)++;
    }
    for (int i = 0; i < SIZE; i++) {
        if (curr->word[i] != NULL) {
            tempprefix[level] = (char)i;
            tempprefix[level + 1] = '\0';
            getAllWords(curr->word[i], tempprefix, level + 1, allwords, wordcount);
        }
    }
}

void insert(){
	char word[SIZE];
	char description[SIZE];
	while (true){
		printf("Input a new slang word [Must be more than 1 characters and contains no space]: ");
	    scanf("%[^\n]", word);
	    getchar();
	    int len = strlen(word);
	    bool isvalid = true;
	    if (len <= 1){
	       printf("Input is not valid press enter to continue...\n");
           while(getch() != 13);
		   system("cls");
		   continue;
	    } 
	     for (int i = 0; i < len; i++){
            if (isspace(word[i]) || ispunct(word[i]) || isdigit(word[i])){
            	isvalid = false;
                break;
            }
        }
        if (!isvalid){
        	printf("Input is not valid press enter to continue...\n");
            while(getch() != 13);
            system("cls");
            continue;
        } else {
            break;
        }
	}
	while (true){
		printf("Input a new slang word description [Must be more than 2 words]: ");
	    scanf("%[^\n]", description);
	    getchar();
	    int desclen = strlen(description);
	    int wordcount = 0;
	    for (int i = 0; i < desclen; i++){
            if (isspace(description[i]) && !isspace(description[i+1]) && description[i+1] != '\0'){
                wordcount++;
            }
        }
        if (desclen > 0 && !isspace(description[0])){
            wordcount++;
        }
        if (wordcount <= 2){
        	printf("Input is not valid press enter to continue...\n");
            while(getch() != 13);
            system("cls");
            continue;
        } else {
            break;
        }
	}
	char sameword[SIZE];
    bool isexist = searchnode(root, word, sameword);
    insertnode(&root, word, description);
    printf("\n");
    if (isexist){
    	printf("Successfully updated a slang word.\n");
	} else {
		printf("Successfully released new slang word.\n");
	}
    printf("Press enter to continue...");
    while(getch() != 13);
	system("cls");
	menu_ptr();
}
	
void search(){
	char word[SIZE];
	char description[SIZE];
	while (true){
		printf("Input a slang word to be searched [Must be more than 1 characters and contains no space]: ");
	    scanf("%[^\n]", word);
	    getchar();
	    int len = strlen(word);
	    bool isvalid = true;
	    if (len <= 1){
	       printf("Input is not valid press enter to continue...\n");
           while(getch() != 13);
		   system("cls");
		   continue;
	    } 
	     for (int i = 0; i < len; i++){
            if (isspace(word[i]) || ispunct(word[i]) || isdigit(word[i])){
            	isvalid = false;
                break;
            }
        }
        if (!isvalid){
        	printf("Input is not valid press enter to continue...\n");
            while(getch() != 13);
            system("cls");
            continue;
        } else {
            break;
        }
	}
	if (!searchnode(root, word, description)) {
        printf("There is no word \"%s\" in the dictionary.\n", word);
    } else {
        printf("\n");
	    printf("Slang word  : %s\n", word);
	    printf("Description : %s\n", description);
	}
	printf("\n");
    printf("Press enter to continue...");
    while(getch() != 13);
	system("cls");
	menu_ptr();	
}

void view_prefix(){
	char prefix[SIZE];
	printf("Input a prefix to be searched: ");
	scanf("%s", prefix);
	getchar();
	char allwords[SIZE][SIZE];
    int wordcount = 0;
    getallwords(root, prefix, allwords, &wordcount);
	if (wordcount == 0){
		printf("There is no prefix \"%s\" in the dictionary.\n", prefix);
	} else {
		printf("Words starts with \"%s\":\n", prefix);
		for (int i = 0; i < wordcount; i++){
			printf("%d. %s\n", i+1, allwords[i]);
		}
	}
	printf("Press enter to continue...\n");
    while(getch() != 13);
    system("cls");
    menu_ptr();
}

void view(){
	if (root == NULL){
		printf("There is no slang word yet in the dictionary.\n");
	} else {
		char allwords[SIZE][SIZE];
	    int wordcount = 0;
	    char prefix[SIZE] = "";
		getAllWords(root, prefix, 0, allwords, &wordcount);
		if (wordcount == 0){
			printf("There is no slang word yet in the dictionary.\n");
		} else {
		   printf("List of all slang words in the dictionary:\n");
	       for (int i = 0; i < wordcount; i++){
		        printf("%d. %s\n",i+1 , allwords[i]);
	        }
		}
		printf("Press enter to continue...\n");
	    while(getch() != 13);
	    system("cls");
	    menu_ptr();	
	}
}

void menu(){
	int option;
	while (true){
		printf("1. Release a new slang word\n");
	    printf("2. Search a slang word \n");
	    printf("3. View all slang words starting with a certain prefix word\n");
	    printf("4. view all slang words\n");
	    printf("5. exit\n");
	    printf(">>");
	    scanf("%d", &option);
	    getchar();
	    switch(option){
	    	case 1:
	    	   system("cls");
			   insert();
			   break;
		    case 2:
		       system("cls");
			   search();
			   break;
		    case 3:
		       system("cls");
			   view_prefix();
			   break;
		    case 4:
		       system("cls");
			   view();
			   break;
		    case 5:
		       system("cls");
			   printf("Thank you... Have a nice day :)\n");
			   exit(0);
		    default:
			   printf("wrong input try again\n");
			   printf("Press enter to continue...\n");
			   while(getch() != 13);
		       system("cls");
		}
	}
}

int main(){
	set_menu_ptr();
	menu();
	return 0;
}
