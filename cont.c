#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXHASH 10
struct HashEntry{
    struct Node *LastNode;
    struct Node *FirstNode;
    int CtrNode;
};

typedef struct Node {
    char phoneNum[50];
    char person[50];
	char email[50]; 
    int num;
    struct Node *next;
}node;

void f01_initial(struct HashEntry *HashTable){
    int i;
    for(i = 0;i<MAXHASH;i++){    
        HashTable[i].FirstNode = NULL;
        HashTable[i].LastNode = NULL;
        HashTable[i].CtrNode = 0;        
        HashTable[i].FirstNode = (node*)malloc(sizeof(node));
        HashTable[i].FirstNode->next = NULL;
    }
}

void f03_print(struct HashEntry *HashTable){
    int i,count;
    char nul[5] = "NULL";
    struct Node *tNode;
    printf("\nPhone        Name       E-mail\n");
    printf("------------------------------------------\n");    
    for(i = 0;i<MAXHASH;i++){
        if(HashTable[i].LastNode != NULL){
            tNode = HashTable[i].FirstNode;
            while(tNode->next != NULL){                
                printf("%-12s %-10s %-15s\n",tNode->phoneNum,tNode->person,tNode->email);
                tNode = tNode -> next;
            }
            printf("\n");
        }  
    }
}

void f04_search(struct HashEntry *HashTable){
    int i;
	char search[50] = {'\0'};
    struct Node *tNode;
    printf("Please enter search data.\nSearch-> ");
    scanf("%s",&search);
    printf("\nPhone        Name       E-mail\n");
    printf("------------------------------------------\n");    
    for(i = 0;i<MAXHASH;i++){
        if(HashTable[i].LastNode != NULL){
            tNode = HashTable[i].FirstNode;
			while(tNode->next != NULL){
                if((strcmp(search,tNode->phoneNum) * strcmp(search,tNode->person) * strcmp(search,tNode->email)) == 0)
					printf("%-12s %-10s %-15s\n",tNode->phoneNum,tNode->person,tNode->email);
                tNode = tNode -> next;
            }
            printf("\n");
        }
    }
}

void f05_add(struct HashEntry *HashTable){
    int key,i,click = 0;
    char phone[60] = {'\0'},name[50] = {'\0'},email[50] = {'\0'};
    struct Node *tNode;

    printf("add a new customer (phone number, name, e-mail):\nInsert: ");
    scanf("%s %s %s",&phone,&name,&email);
    
    if(strlen(phone) <= 10){
        key = hash(phone);

        if(HashTable[key].LastNode != NULL){
            tNode = HashTable[key].FirstNode;        
            while(tNode->next != NULL){        
                if(strcmp(phone,tNode->phoneNum) == 0){
                    click = 1;
                }
                tNode = tNode -> next;
            }
        }
                
        if(click != 1){
            if(HashTable[key].LastNode == NULL){
                HashTable[key].CtrNode++;
                tNode = HashTable[key].FirstNode;                
                tNode->next = (node*)malloc(sizeof(node));
                
                strcpy(tNode->phoneNum,phone);               
                strcpy(tNode->person,name); 
				strcpy(tNode->email,email);
        
                tNode = tNode->next;
                HashTable[key].LastNode = tNode;    
                tNode->next = NULL;                    
            }
            else{
                HashTable[key].CtrNode++;
                tNode = HashTable[key].LastNode;    
                tNode->next = (node*)malloc(sizeof(node));
                
                strcpy(tNode->phoneNum,phone);               
                strcpy(tNode->person,name); 
				strcpy(tNode->email,email);       
          
                tNode = tNode->next;
                HashTable[key].LastNode = tNode;
                tNode->next = NULL;
            }
        }
        else{
            printf("the phone number exists in list");
        }                
    }
    else{
        printf("the phone number is wrong!/n");
    }             
}

void f06_delete(struct HashEntry *HashTable){
    int i;
	char phone[50] = {'\0'},search[50] = {'\0'};
    int key,click = 0;
    struct Node *tNode;
    
    printf("delete a customer (by any data):\nDelete: ");
    scanf("%s",&search);
    
    for(i = 0;i<MAXHASH;i++){
        if(HashTable[i].LastNode != NULL){
            tNode = HashTable[i].FirstNode;
			while(tNode->next != NULL){
                if((strcmp(search,tNode->phoneNum) * strcmp(search,tNode->person) * strcmp(search,tNode->email)) == 0)
					strcpy(phone, tNode->phoneNum);
                tNode = tNode -> next;
            }
        }
    }
    
    key = hash(phone);
    
    if(HashTable[key].LastNode != NULL){
        tNode = HashTable[key].FirstNode;
        if(tNode != NULL){    
            if(strcmp(phone,tNode->phoneNum) == 0){
                printf("\nPhone        Name       E-mail\n");
    			printf("------------------------------------------\n"); 
				printf("%-12s %-10s %-15s\n",tNode->phoneNum,tNode->person,tNode->email);
				printf("Has been deleted...\n"); 
                HashTable[key].FirstNode = tNode->next;
                HashTable[key].CtrNode--;
                click = 1;
            }            
            tNode = tNode -> next;
        }
        while(tNode->next != NULL){    
            if(strcmp(phone,tNode->next->phoneNum) == 0){
                printf("\nPhone        Name       E-mail\n");
    			printf("------------------------------------------\n"); 
				printf("%-12s %-10s %-15s\n",tNode->next->phoneNum,tNode->next->person,tNode->next->email);
                printf("Has been deleted...\n"); 
				tNode->next = tNode->next->next;
                click = 1;
            }
            tNode = tNode -> next;
        }
        
        if(HashTable[key].FirstNode->next == NULL){
            HashTable[key].LastNode = NULL;
        }
    }
    if(click == 0){
        printf("Can not delete.\n");
    }
}

int hash(char* phone){
    int key;
    key = atoi(phone) % MAXHASH;
    return key;
}


int main(){
    char leave;
    int choiceNum,keep = 0,i;
    struct HashEntry HashTable[MAXHASH];
    f01_initial(HashTable);
    
    printf("Wellcome, this is a contacts~\n");
    while(keep == 0){
        printf("\n-----------------------------------------------------------------------\n");
        printf("1. Initial   - initial all value\n");
        printf("2. Print     - print all data\n");
        printf("3. Search    - Search data\n");
        printf("4. AddNew    - add a new customer (phone number, name, e-mail)\n");
        printf("5. DeleteOld - Delete an existing customer\n");
        printf("6. Quit\n");
        printf("Please enter your choice: (1-6)\n->");
        fflush(stdin);
        scanf("%d",&choiceNum);               
        switch (choiceNum) {
            case 1:
                f01_initial(HashTable);
                break;              
            case 2:
                f03_print(HashTable);
                break;        
            case 3:
                f04_search(HashTable);
                break;    
            case 4:
                f05_add(HashTable);
                break;        
            case 5:
                f06_delete(HashTable);
                break;
            case 6:
                printf("Quit? (y / n)\n->");
                fflush(stdin);
                scanf("%s",&leave);
                if(leave == 'y'){
                    keep = 1;
                    printf("Goodbye~\n");
                }
                break;                                    
            default:
                printf("number is worng!\n");
                break;
        }        
    }
    return 0;
}
