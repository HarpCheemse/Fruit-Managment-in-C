#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

#define MAXSIZE 200
#define NUM_OPTIONS 13
#define OUTOFBOUND -2147483646 //Define OutofBound for Error Return to not have colision with input by user
#define PRINT_RED "\x1b[31m" 
#define PRINT_GREEN "\x1b[32m"
#define PRINT_AQUA "\x1b[36m"
#define PRINT_GOLD "\033[1;33m"
#define PRINT_LIGHT_AQUA "\033[1;33m""\x1b[36m"
#define PRINT_COLOR_RESET "\x1b[0m" 

typedef struct
{
	char name[MAXSIZE];
	int quantities;
	int price_buy;
	int price_sell;
	int sold;
    int profit;
} Fruits;
//////////////////////////////////////////////////////////////////////////////////////Phototyes
void userPrompt();
void printMenu();
void refreshScreen();
void printCredits();
bool floatInputHandler(const char* input);
bool intInputHandler(const char* input);
float floatInput();
int inputNumberOfFruits(int *number_of_fruit);
void inputFruits();
void printSortByMenu();
void switchCaseSortMenu(int *number_of_fruit, Fruits fruit[]);
void printSortByMenuOrderOption();
void Option11(int *number_of_fruit, Fruits fruit[]);
void Option13();
////////////////////////////////////////////////////////////////////////struct
////////////////////////////////////////////////////////////////////////// Print Functions
void userPrompt()
{
	printf(PRINT_GOLD"Enter Your Choice: " PRINT_COLOR_RESET);
}
void printMenu()
{
    char equals[MAXSIZE] = "==========================================================================================================";
    printf(PRINT_AQUA"%s\n"PRINT_COLOR_RESET, equals);
    printf(PRINT_LIGHT_AQUA"                                -----Fruit Manager Menu----- "PRINT_COLOR_RESET);
    printf(PRINT_GOLD"\n\n1.   Input Fruits To Manage");       
    printf("\n2.   Add More Fruits");     
    printf("\n3.   Delete A Specific Fruit");       
    printf("\n4.   Delete All Fruits");
    printf("\n5.   Display Fruits");     
    printf("\n6.   Display A Specific Fruit");
    printf("\n7.   Sort By Properties");        
    printf("\n8.   Maximize Profit With A Budget");
    printf("\n9.   Print Infos To A TxT File");
    printf("\n10.  Print Infos To RAW File");
    printf("\n11.  Import RAW File");
    printf("\n12.  Credit");
    printf("\n13.  Exit The Program\n") ;
    printf(PRINT_COLOR_RESET PRINT_AQUA "%s\n"PRINT_COLOR_RESET, equals);
}
void refreshScreen()
{
	system("cls");
	printMenu();
}
void refreshPrintSortByMenu()
{
    system("cls");
    printSortByMenu();
}
void refreshPrintSortByMenuOrderOption()
{
    system("cls");
    printSortByMenuOrderOption();
}
void printCredits()
{
    refreshScreen();
    printf(PRINT_AQUA"\n\n================================= " PRINT_COLOR_RESET PRINT_LIGHT_AQUA "CREDITS " PRINT_COLOR_RESET PRINT_AQUA"=================================\n" PRINT_COLOR_RESET);
    printf(PRINT_GOLD"\nDeveloped by: HarpCheemse");
    printf("\nVersion: 1.0");
    printf("\n- [Any libraries or resources used]");
    printf("\nContact: [harpcheemse@gmail.com]" PRINT_COLOR_RESET);
    printf(PRINT_AQUA"\n===========================================================================\n"PRINT_COLOR_RESET);
}
void printFruitPropeties(char fruit_name[], int quantity, int buy_price, int sell_price, int sold, int fruit_number)
{
    printf(PRINT_AQUA "\nPlease Input Fruit "PRINT_COLOR_RESET PRINT_GREEN "%d " PRINT_COLOR_RESET PRINT_AQUA "Properties\n\n" PRINT_COLOR_RESET, fruit_number);
    printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    printf(PRINT_AQUA "| " PRINT_COLOR_RESET PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GOLD "%-15s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GOLD "%-15s" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
        "Name", "Quantity", "Buy Price", "Sell Price", "Sold"); 
    printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    if(!strcmp(fruit_name, "NA"))
    {

        printf(PRINT_AQUA "| " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-15c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-15c" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
            '?', '?', '?', '?', '?');     
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    }
    else if(quantity == OUTOFBOUND)
    {
        printf(PRINT_AQUA "| " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20s" PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-15c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-15c" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
            fruit_name, '?', '?', '?', '?');     
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    }
    else if(buy_price == OUTOFBOUND)
    {
        printf(PRINT_AQUA "| " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20s" PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-15c" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
            fruit_name, quantity, '?', '?', '?');    
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    }
    else if(sell_price == OUTOFBOUND)
    {   
        printf(PRINT_AQUA "| " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20s" PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-20c" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-15c" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
            fruit_name, quantity, buy_price, '?', '?');  
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    }
    else if(sold == OUTOFBOUND)
    {
        printf(PRINT_AQUA "| " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20s" PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_RED "%-15c" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
            fruit_name, quantity, buy_price, sell_price, '?');  
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    }
    else
    {
        printf(PRINT_AQUA "| " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20s" PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-20d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
            fruit_name, quantity, buy_price, sell_price, sold);  
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
    }
    return;
}
void printFruitTable(char fruit_name[], int quantity, int buy_price, int sell_price, int sold)
{
    printf(PRINT_AQUA "| " PRINT_COLOR_RESET 
        PRINT_GREEN "%-20s" PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GREEN "%-20d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GREEN "%-20d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
        PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
        fruit_name, quantity, buy_price, sell_price, sold);  
    printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
}
void printFruitTablePreview(Fruits fruit[], int index)
{
    int j;
    if(index>=1)
    {
        printf(PRINT_LIGHT_AQUA"\n\n                                -----Fruit Manager Preview---- \n"PRINT_COLOR_RESET);
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
        printf(PRINT_AQUA "| " PRINT_COLOR_RESET PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GOLD "%-15s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
            PRINT_GOLD "%-15s" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
            "Name", "Quantity", "Buy Price", "Sell Price", "Sold"); 
        printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
        for(j = 0; j<index; j++) printFruitTable(fruit[j].name, fruit[j].quantities, fruit[j].price_buy, fruit[j].price_sell, fruit[j].sold);
    }
    return;
}
void printSortByMenu()
{
    char equals[MAXSIZE] = "==========================================================================================================";
    printf(PRINT_AQUA"%s\n"PRINT_COLOR_RESET, equals);
    printf(PRINT_LIGHT_AQUA"                      -----Sort By Functions----- "PRINT_COLOR_RESET);
    printf(PRINT_GOLD"\n\n1.   Sort By Name");       
    printf("\n2.   Sort By Quanity");     
    printf("\n3.   Sort By Price Bought");       
    printf("\n4.   Sort By Price Sold");
    printf("\n5.   Sort By Number Of Fruit Sold");     
    printf("\n6.   Sort By Profit");
    printf("\n7.   Back To Menu");        
    printf("\n8.   Exit The Program\n");
    printf(PRINT_COLOR_RESET PRINT_AQUA "%s\n"PRINT_COLOR_RESET, equals);
}
void printSortByMenuOrderOption()
{
    char equals[MAXSIZE] = "==========================================================================================================";
    printf(PRINT_AQUA"%s\n"PRINT_COLOR_RESET, equals);
    printf(PRINT_LIGHT_AQUA"                                 -----Sort By Functions----- "PRINT_COLOR_RESET);
    printf(PRINT_GOLD"\n\n1. "PRINT_COLOR_RESET PRINT_GREEN"Ascending" PRINT_COLOR_RESET PRINT_GOLD" Order" PRINT_COLOR_RESET);       
    printf(PRINT_GOLD"\n\n2. "PRINT_COLOR_RESET PRINT_RED"Descending" PRINT_COLOR_RESET PRINT_GOLD" Order\n" PRINT_COLOR_RESET);  
    printf(PRINT_COLOR_RESET PRINT_AQUA "%s\n"PRINT_COLOR_RESET, equals);
}
//////////////////////////////////////////////////////////////////////////////////////Input ALGORITHM
void clearBuffer() 
{
    while (getchar() != '\n'); 
}
bool floatInputHandler(const char* input)
{
	int index = 0;
	int comma = 0;
	if(input[0] == '.' && (input[1] >'9' || input[1]<'0')) return false; //if input is at 1st pos is - and second pos is not in rnage of 0 to 9 return false
	if(input[0] =='-') return false;
    int length = strlen(input);
    for(; index<length; index++)
    {
    	if(input[index] == '.')
    	{
    		comma++;
    		if(comma>1) return false;
    		continue;
		}
        if(input[index] <='9' && input[index]>='0') continue;
        else return false;
    }
    return true;
}
bool intInputHandler(const char* input)
{
	int index = 0;
	if(input[0] =='.') return false;
	if(input[0] =='-') return false;
    int length = strlen(input);
    for(; index<length; index++)
    {
        if(input[index] <='9' && input[index]>='0') continue;
        else return false;
    }
    return true;
}
int intInput()
{
	char buffer[MAXSIZE];
    while(1)
    {
        fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
        if(intInputHandler(buffer)) return atoi(buffer);
        else
        {
        	return OUTOFBOUND;
		}
    }
}
float floatInput()
{
	char buffer[MAXSIZE];
    while(1)
    {
        fgets(buffer, sizeof(buffer), stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
        if(floatInputHandler(buffer)) return strtof(buffer, NULL);
        else
        {
        	return OUTOFBOUND;
		}
    }
}
int inputNumberOfFruits(int *number_of_fruit)
{
    printf(PRINT_LIGHT_AQUA"\nInput Number Of Fruits\n" PRINT_COLOR_RESET);
    userPrompt();
    while(1)
    {
        *number_of_fruit = intInput();
        if(*number_of_fruit == OUTOFBOUND)
        {
            refreshScreen();
            printf(PRINT_RED"Invalid Input! Please Enter Number Between 1 And 100\n" PRINT_COLOR_RESET);
            printf(PRINT_LIGHT_AQUA"Input Number Of Fruits\n" PRINT_COLOR_RESET);
            userPrompt();
        }
        else if(*number_of_fruit <= 0 || *number_of_fruit >100)
        {
            refreshScreen();
            printf(PRINT_RED"Invalid Input! Please Enter Number Between 1 And 100\n" PRINT_COLOR_RESET);
            printf(PRINT_LIGHT_AQUA"Input Number Of Fruits\n" PRINT_COLOR_RESET);
            userPrompt();
        }
        else break;
    }
    return *number_of_fruit;
}
void inputFruitTableMenu(int i, Fruits fruit[])
{
    refreshScreen();
    printFruitPropeties("NA", OUTOFBOUND, OUTOFBOUND, OUTOFBOUND, OUTOFBOUND, i+1);
    printf(PRINT_GOLD"Please Enter Fruit Name: " PRINT_COLOR_RESET);
    printFruitTablePreview(fruit, i);
    printf("\033[26;26H");
    fgets(fruit[i].name, MAXSIZE, stdin);
    fruit[i].name[strcspn(fruit[i].name, "\n")] = '\0';
    refreshScreen();
    printFruitPropeties(fruit[i].name, OUTOFBOUND, OUTOFBOUND, OUTOFBOUND, OUTOFBOUND, i+1);
    printf(PRINT_GOLD"Please Enter Fruit Quantity: " PRINT_COLOR_RESET);
    printFruitTablePreview(fruit, i);
    printf("\033[26;30H");
    scanf("%d", &fruit[i].quantities);
    refreshScreen();
    printFruitPropeties(fruit[i].name, fruit[i].quantities, OUTOFBOUND, OUTOFBOUND, OUTOFBOUND, i+1);
    printf(PRINT_GOLD"Please Enter Fruit Bought Price: " PRINT_COLOR_RESET);
    printFruitTablePreview(fruit, i);
    printf("\033[26;34H");
    scanf("%d", &fruit[i].price_buy);
    refreshScreen();
    printFruitPropeties(fruit[i].name, fruit[i].quantities, fruit[i].price_buy, OUTOFBOUND, OUTOFBOUND, i+1);
    printf(PRINT_GOLD"Please Enter Fruit Sold Price: " PRINT_COLOR_RESET);
    printFruitTablePreview(fruit, i);
    printf("\033[26;32H");
    scanf("%d", &fruit[i].price_sell);
    refreshScreen();
    printFruitPropeties(fruit[i].name, fruit[i].quantities, fruit[i].price_buy, fruit[i].price_sell, OUTOFBOUND, i+1);
    printf(PRINT_GOLD"Please Enter Numbers Of Fruit Sold: " PRINT_COLOR_RESET);
    printFruitTablePreview(fruit, i);
    printf("\033[26;37H");
    scanf("%d", &fruit[i].sold);
    return;
}
void inputFruits(int *number_of_fruit, Fruits fruit[])
{
    for(int i = 0; i < *number_of_fruit; i++)
    {
        inputFruitTableMenu(i, fruit);
        clearBuffer();
    }
    refreshScreen();
    printf(PRINT_GREEN"Initalizing Fruits Succesfully\n\n"PRINT_COLOR_RESET);
    userPrompt();
    printFruitTablePreview(fruit, *number_of_fruit);
    printf("\033[20;20H");
    return;
}
////////////////////////////////////////////////////////////////////////////////////////////// Logic Functionss
bool isFruitManagerEmpty(int number_of_fruit)
{
    if(number_of_fruit == 0)
    {
        refreshScreen();
        printf(PRINT_RED"No Fruit To Manage! Please Input Fruits First\n\n"PRINT_COLOR_RESET);
        userPrompt();
        return 1;
    }
    else return 0;
}
int compareAscFruitName(const void *a, const void *b) 
{
    return strcmp(((Fruits*)a)->name, ((Fruits *)b)->name);
}
int compareDescFruitName(const void *a, const void *b) 
{
    return strcmp(((Fruits*)b)->name, ((Fruits *)a)->name);
}
int compAscFruitQuantity(const void *a, const void *b) 
{
    return (((Fruits *)a) -> quantities - ((Fruits *)b) -> quantities);
}
int compDescFruitQuantity(const void *a, const void *b) 
{
    return (((Fruits *)b) -> quantities - ((Fruits *)a) -> quantities);
}
int compAscFruitPriceBuy(const void *a, const void *b) 
{
    return (((Fruits *)a) -> price_buy - ((Fruits *)b) -> price_buy);
}
int compDescFruitPriceBuy(const void *a, const void *b) 
{
    return (((Fruits *)b) -> price_buy - ((Fruits *)a) -> price_buy);
}
int compAscFruitPriceSell(const void *a, const void *b) 
{
    return (((Fruits *)a) -> price_sell - ((Fruits *)b) -> price_sell);
}
int compDescFruitPriceSell(const void *a, const void *b) 
{
    return (((Fruits *)b) -> price_sell - ((Fruits *)a) -> price_sell);
}
int compAscFruitSold(const void *a, const void *b) 
{
    return (((Fruits *)a) -> sold - ((Fruits *)b) -> sold);
}
int compDescFruitSold(const void *a, const void *b) 
{
    return (((Fruits *)b) -> sold - ((Fruits *)a) -> sold);
}
int compAscProfit(const void *a, const void *b) 
{
    return (((Fruits *)a) -> profit - ((Fruits *)b) -> profit);
}
int compDescProfit(const void *a, const void *b) 
{
    return (((Fruits *)b) -> profit - ((Fruits *)a) -> profit);
}
int findMinProfit(Fruits fruit[], int number_of_fruit)
{
    int i;
    int min_profit = fruit[0].profit;
    for (i = 1; i < number_of_fruit; i++)
    {
        if (fruit[i].profit < min_profit) min_profit = fruit[i].profit;
    }
    return min_profit;
}

/////////////////////////////////////////////////////////////////////////main menu options
void Option1(int *number_of_fruit, Fruits fruit[])
{
    printf("\n\n");
    userPrompt();
    int user_selection = intInput();
    switch (user_selection)
    {
    case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
        refreshScreen();
        printf(PRINT_RED "No Fruit To Manage! Please Input Fruits First" PRINT_COLOR_RESET);
        Option1(number_of_fruit, fruit);
        break;
    case 1: 
        refreshScreen();
        *number_of_fruit = inputNumberOfFruits(number_of_fruit);
        inputFruits(number_of_fruit, fruit);
        break;
    case 11:
        Option11(number_of_fruit, fruit);
        break;
    case 12:
        printCredits();
        printf(PRINT_GOLD"\nPress Any Enter To Continue"PRINT_COLOR_RESET);
        clearBuffer();
        refreshScreen();
        Option1(number_of_fruit, fruit);
        break;
    case 13:
        Option13(number_of_fruit, fruit);
        break;
    default:
        refreshScreen();
        printf(PRINT_RED "Invalid Input! Please Select Valid Option" PRINT_COLOR_RESET);
        Option1(number_of_fruit, fruit);
        break;
    }
    return;
}
void reselectOption1(int *number_of_fruit, Fruits fruit[])
{
    refreshScreen();
    printf(PRINT_GOLD"\nYour Data Has Already Been Inputted. Do You Want To Reset Y/N? \n");
    printf("Please Enter " PRINT_COLOR_RESET PRINT_GREEN "Y " PRINT_COLOR_RESET PRINT_GOLD"or "PRINT_COLOR_RESET PRINT_RED "N\n\n" PRINT_COLOR_RESET);
    userPrompt();
    char user_selection[MAXSIZE];
    fgets(user_selection, MAXSIZE, stdin);

    if((user_selection[0] == 'y' || user_selection[0] == 'Y') && user_selection[1] == '\n')
    {
    	refreshScreen();
    	printf(PRINT_GREEN"Your Data Has Been Reset Successfully\n" PRINT_COLOR_RESET);
        *number_of_fruit = inputNumberOfFruits(number_of_fruit);
        inputFruits(number_of_fruit, fruit);
        return;
    }
    if((user_selection[0] == 'n' || user_selection[0] == 'N')  && user_selection[1] == '\n')
	{
		refreshScreen();
		printf(PRINT_GREEN"Your Data Remain Unchanged\n\n"PRINT_COLOR_RESET);
		userPrompt();
	}
    else
    {
        refreshScreen();
        printf(PRINT_RED"Invalid Input! Back To Menu\n\n"PRINT_COLOR_RESET);
        userPrompt();
    } 
    return;
}
void Option2(int *number_of_fruit, Fruits fruit[])
{
    refreshScreen();
    if(*number_of_fruit == 100)
    {
        printf(PRINT_RED"Fruit Manager Is Full! Cannot Add More Fruit\n\n"PRINT_COLOR_RESET);
        userPrompt();
        return;
    }
    printf(PRINT_LIGHT_AQUA"\nAdd 1 More Fruit To Manage\n" PRINT_COLOR_RESET);
    inputFruitTableMenu(*number_of_fruit, fruit);
    clearBuffer();
    (*number_of_fruit)++;
    refreshScreen();
    printf(PRINT_GREEN"Adding Fruits Succesfully\n\n"PRINT_COLOR_RESET);
    userPrompt();
    printFruitTablePreview(fruit, *number_of_fruit);
    printf("\033[20;20H");
    return;
}
void Option3(int *number_of_fruit, Fruits fruit[])
{
    int i, j;
    int found = 0;
    char fruit_to_remove[MAXSIZE];
    refreshScreen();
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    printf(PRINT_LIGHT_AQUA"\nDelete a Fruit From Fruit Manager\n"PRINT_COLOR_RESET);
    userPrompt();
    fgets(fruit_to_remove, MAXSIZE, stdin);
    fruit_to_remove[strcspn(fruit_to_remove, "\n")] = '\0';
    for(i=0; i<*number_of_fruit; i++)
    {
        if(strcmp(fruit_to_remove, fruit[i].name) == 0)
        {
            found = 1;
            for(j = i; j<(*number_of_fruit)-1; j++)
            {
                fruit[j] = fruit[j+1];
            }
            (*number_of_fruit)--;
            break;
        }
    }
    refreshScreen();
    if(found == 1)
    {
        printf(PRINT_GREEN"Remove %s From Fruit Manager Successfully\n\n"PRINT_COLOR_RESET, fruit_to_remove);


    }
    else
    {
        printf(PRINT_RED"There Is No Fruit Named %s To Be Removed\n\n"PRINT_COLOR_RESET, fruit_to_remove);
    }
    userPrompt();
    return;
}
void Option4(int *number_of_fruit, Fruits fruit[])
{
    refreshScreen();
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    (*number_of_fruit) = 0;
    printf(PRINT_GREEN"Remove All From Fruit Manager Successfully\n\n"PRINT_COLOR_RESET);
    userPrompt();
    return;
}
void Option5(int *number_of_fruit, Fruits fruit[])
{
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    refreshScreen();
    printf(PRINT_LIGHT_AQUA"\nDisplaying Fruits Inputted\n" PRINT_COLOR_RESET);
    userPrompt();
    printFruitTablePreview(fruit, *number_of_fruit);
    printf("\033[20;20H");
    return;
}
void Option6(int *number_of_fruit, Fruits fruit[])
{
	int found = 0;
    int i;
    char fruit_to_display[MAXSIZE];
    refreshScreen();
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    printf(PRINT_LIGHT_AQUA"\nDisplay a Fruit From Fruit Manager\n"PRINT_COLOR_RESET);
    userPrompt();
    fgets(fruit_to_display, MAXSIZE, stdin);
    fruit_to_display[strcspn(fruit_to_display, "\n")] = '\0';
    refreshScreen();
    printf("\n\n");
    userPrompt();
    for(i=0; i<*number_of_fruit; i++)
    {
        if(strcmp(fruit_to_display, fruit[i].name) == 0)
        {
            printf(PRINT_LIGHT_AQUA"\n\n                                -----Fruit Manager Preview---- \n"PRINT_COLOR_RESET);
            printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
            printf(PRINT_AQUA "| " PRINT_COLOR_RESET PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
                PRINT_GOLD "%-15s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
                PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
                PRINT_GOLD "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
                PRINT_GOLD "%-15s" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
                "Name", "Quantity", "Buy Price", "Sell Price", "Sold"); 
            printf(PRINT_AQUA"----------------------------------------------------------------------------------------------------------\n"PRINT_COLOR_RESET);
            printFruitTable(fruit[i].name, fruit[i].quantities, fruit[i].price_buy, fruit[i].price_sell, fruit[i].sold);
            found = 1;
            break;
        }
    }
    if(found == 0)
    {
    	refreshScreen();
    	printf(PRINT_RED"No Fruit Named %s To Be Displayed\n\n"PRINT_COLOR_RESET, fruit_to_display);
    	userPrompt();
    	return;
	}
    printf("\033[20;20H");
    return;
}
void Option7(int *number_of_fruit, Fruits fruit[])
{
    refreshScreen();
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    switchCaseSortMenu(number_of_fruit, fruit);
    return;
}
void Option8()
{
    refreshScreen();
    printf(PRINT_RED"This Function Has No Use Right Now :/\n\n"PRINT_COLOR_RESET);
    userPrompt();
    return;
}
void Option9(int *number_of_fruit, Fruits fruit[])
{
    refreshScreen();
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    FILE *fruit_manager;
    int i;
    fruit_manager = fopen("fruit_manger.txt", "w");
    if(fruit_manager == NULL)
    {
        printf(PRINT_RED"Error: Unable To Write File\n\n"PRINT_COLOR_RESET);
        userPrompt();
        return;
    }
    fprintf(fruit_manager, "\n\n                                                -----Fruit Manager Preview---- \n");
    fprintf(fruit_manager, "---------------------------------------------------------------------------------------------------------------------------------\n");
    fprintf(fruit_manager, "| %-20s | %-15s | %-20s | %-20s | %-15s | %-20s |\n",  
            "Name", "Quantity", "Buy Price", "Sell Price", "Sold", "Profit");
            fprintf(fruit_manager, "---------------------------------------------------------------------------------------------------------------------------------\n");
    for(i =0 ; i< *number_of_fruit; i++)
    {
        fruit[i].profit = fruit[i].sold * (fruit[i].price_sell - fruit[i].price_buy);
        fprintf(fruit_manager, "| %-20s | %-15d | %-20d | %-20d | %-15d | %-20d |\n",  
            fruit[i].name, fruit[i].quantities, fruit[i].price_buy, fruit[i].price_sell, fruit[i].sold, fruit[i].profit);  
        fprintf(fruit_manager, "---------------------------------------------------------------------------------------------------------------------------------\n");
    }
    fclose(fruit_manager);
    printf(PRINT_GREEN"Successfully Saved File\n\n"PRINT_COLOR_RESET);
    userPrompt();
    return;
}
void Option10(int *number_of_fruit, Fruits fruit[])
{
    refreshScreen();
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    FILE *RAW_fruit_manager;
    int i;
    RAW_fruit_manager = fopen("RAW_fruit_manager.txt", "w");
    if(RAW_fruit_manager == NULL)
    {
        printf(PRINT_RED"Error: Unable To Write File\n\n"PRINT_COLOR_RESET);
        userPrompt();
        return;
    }
    fprintf(RAW_fruit_manager, "%d\n", *number_of_fruit);
    for(i=0; i<*number_of_fruit; i++)
    {
        fprintf(RAW_fruit_manager,"%s\n", fruit[i].name);
        fprintf(RAW_fruit_manager,"%d\n", fruit[i].quantities);
        fprintf(RAW_fruit_manager,"%d\n", fruit[i].price_buy);
        fprintf(RAW_fruit_manager,"%d\n", fruit[i].price_sell);
        fprintf(RAW_fruit_manager,"%d\n", fruit[i].sold);
    }
    fclose(RAW_fruit_manager);
    printf(PRINT_GREEN "Successfully Saved RAW File\n\n"PRINT_COLOR_RESET);
    userPrompt();
    return;
}
void Option11(int *number_of_fruit, Fruits fruit[])
{
    FILE *RAW_fruit_manager;
    refreshScreen();
    int i;
    RAW_fruit_manager = fopen("RAW_fruit_manager.txt", "r");
    if ("RAW_fruit_manager" == NULL) {
        printf(PRINT_RED "Error: Unable To Open File\n" PRINT_COLOR_RESET);
        fclose(RAW_fruit_manager); 
        return;
    }
    fscanf(RAW_fruit_manager, "%d", number_of_fruit);
    for(i = 0; i< *number_of_fruit; i++)
    {
        fscanf(RAW_fruit_manager, "%s", fruit[i].name);
        fscanf(RAW_fruit_manager, "%d", &fruit[i].quantities);
        fscanf(RAW_fruit_manager, "%d", &fruit[i].price_buy);
        fscanf(RAW_fruit_manager, "%d", &fruit[i].price_sell);
        fscanf(RAW_fruit_manager, "%d", &fruit[i].sold);
    }
    fclose(RAW_fruit_manager);
    refreshScreen();
    printf(PRINT_GREEN "Successfully Import RAW File To Fruit Manager\n\n"PRINT_COLOR_RESET);
    userPrompt();
    return;
}
void Option12()
{
    printCredits();
    printf(PRINT_GOLD"\nPress Any Enter To Continue"PRINT_COLOR_RESET);
    clearBuffer();
    refreshScreen();
    printf("\n\n");
    userPrompt();
    return;
}
void Option13()
{
    refreshScreen();
    printf(PRINT_GREEN"\n\nExit Program Successfully\n" PRINT_GOLD);
    exit(0);
}
//////////////////////////////////////////////////////////////////////////Sort Menu Options
void SortOption1(int *number_of_fruit, Fruits fruit[])
{
    int user_selection;
    refreshPrintSortByMenuOrderOption();
    while(1)
    {
        printf(PRINT_LIGHT_AQUA"\nWhich Order Do You Want To Sort Fruits Name?\n"PRINT_COLOR_RESET);
        userPrompt();
        user_selection = intInput();
        if(user_selection != 1 && user_selection != 2)
        {
            refreshPrintSortByMenuOrderOption();
            printf(PRINT_RED"Invalid Input! Please Input A Valid Option"PRINT_COLOR_RESET);
            continue;
        }
        else break;
    }
    refreshPrintSortByMenu();
    if(user_selection == 1)
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Name In " PRINT_COLOR_RESET PRINT_GREEN "Ascending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compareAscFruitName);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }
    else
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Name In " PRINT_COLOR_RESET PRINT_RED "Descending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compareDescFruitName);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }  
    return; 
}
void SortOption2(int *number_of_fruit, Fruits fruit[])
{
    int user_selection;
    refreshPrintSortByMenuOrderOption();
    while(1)
    {
        printf(PRINT_LIGHT_AQUA"\nWhich Order Do You Want To Sort Fruits Quantity\n"PRINT_COLOR_RESET);
        userPrompt();
        user_selection = intInput();
        if(user_selection != 1 && user_selection != 2)
        {
            refreshPrintSortByMenuOrderOption();
            printf(PRINT_RED"Invalid Input! Please Input A Valid Option"PRINT_COLOR_RESET);
            continue;
        }
        else break;
    }
    refreshPrintSortByMenu();
    if(user_selection == 1)
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Quantity In " PRINT_COLOR_RESET PRINT_GREEN "Ascending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compAscFruitQuantity);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }
    else
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Quantity In " PRINT_COLOR_RESET PRINT_RED "Descending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compDescFruitQuantity);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }  
    return; 
}
void SortOption3(int *number_of_fruit, Fruits fruit[])
{
    int user_selection;
    refreshPrintSortByMenuOrderOption();
    while(1)
    {
        printf(PRINT_LIGHT_AQUA"\nWhich Order Do You Want To Sort Fruits Bought Price\n"PRINT_COLOR_RESET);
        userPrompt();
        user_selection = intInput();
        if(user_selection != 1 && user_selection != 2)
        {
            refreshPrintSortByMenuOrderOption();
            printf(PRINT_RED"Invalid Input! Please Input A Valid Option"PRINT_COLOR_RESET);
            continue;
        }
        else break;
    }
    refreshPrintSortByMenu();
    if(user_selection == 1)
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Bought Price In " PRINT_COLOR_RESET PRINT_GREEN "Ascending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compAscFruitPriceBuy);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }
    else
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Bought Price In " PRINT_COLOR_RESET PRINT_RED "Descending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compDescFruitPriceBuy);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }  
    return; 
}
void SortOption4(int *number_of_fruit, Fruits fruit[])
{
    int user_selection;
    refreshPrintSortByMenuOrderOption();
    while(1)
    {
        printf(PRINT_LIGHT_AQUA"\nWhich Order Do You Want To Sort Fruits Sold Price\n"PRINT_COLOR_RESET);
        userPrompt();
        user_selection = intInput();
        if(user_selection != 1 && user_selection != 2)
        {
            refreshPrintSortByMenuOrderOption();
            printf(PRINT_RED"Invalid Input! Please Input A Valid Option"PRINT_COLOR_RESET);
            continue;
        }
        else break;
    }
    refreshPrintSortByMenu();
    if(user_selection == 1)
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Sold Price In " PRINT_COLOR_RESET PRINT_GREEN "Ascending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compAscFruitPriceSell);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }
    else
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Fruits Sold Price In " PRINT_COLOR_RESET PRINT_RED "Descending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compDescFruitPriceSell);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }  
    return; 
}
void SortOption5(int *number_of_fruit, Fruits fruit[])
{
    int user_selection;
    refreshPrintSortByMenuOrderOption();
    while(1)
    {
        printf(PRINT_LIGHT_AQUA"\nWhich Order Do You Want To Sort Number Of Fruits Sold\n"PRINT_COLOR_RESET);
        userPrompt();
        user_selection = intInput();
        if(user_selection != 1 && user_selection != 2)
        {
            refreshPrintSortByMenuOrderOption();
            printf(PRINT_RED"Invalid Input! Please Input A Valid Option"PRINT_COLOR_RESET);
            continue;
        }
        else break;
    }
    refreshPrintSortByMenu();
    if(user_selection == 1)
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Number Of Fruits Sold In " PRINT_COLOR_RESET PRINT_GREEN "Ascending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compAscFruitSold);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }
    else
    {
        printf(PRINT_LIGHT_AQUA"\nSorted Number Of Fruits Sold In " PRINT_COLOR_RESET PRINT_RED "Descending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compDescFruitSold);
        userPrompt();
        printFruitTablePreview(fruit, *number_of_fruit);
        printf("\033[15;20H");
        return;
    }  
    return; 
}
void SortOption6(int *number_of_fruit, Fruits fruit[])
{
    int i;
    int user_selection;
    refreshPrintSortByMenuOrderOption();
    while(1)
    {
        printf(PRINT_LIGHT_AQUA"\nWhich Order Do You Want To Sort Fruits Quantity\n"PRINT_COLOR_RESET);
        userPrompt();
        user_selection = intInput();
        if(user_selection != 1 && user_selection != 2)
        {
            refreshPrintSortByMenuOrderOption();
            printf(PRINT_RED"Invalid Input! Please Input A Valid Option"PRINT_COLOR_RESET);
            continue;
        }
        else break;
    }
    for(i =0 ; i< *number_of_fruit; i++) fruit[i].profit = fruit[i].sold * (fruit[i].price_sell - fruit[i].price_buy);
    refreshPrintSortByMenu();
    if(user_selection == 1) 
    {
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compAscProfit);
        printf(PRINT_LIGHT_AQUA"\nSorted Profit In " PRINT_COLOR_RESET PRINT_GREEN "Ascending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
    }
    else
    {
        qsort(fruit, *number_of_fruit, sizeof(Fruits), compDescProfit);
        printf(PRINT_LIGHT_AQUA"\nSorted Profit In " PRINT_COLOR_RESET PRINT_RED "Descending " PRINT_COLOR_RESET PRINT_LIGHT_AQUA"Order\n"PRINT_COLOR_RESET);
    } 
    userPrompt();
    printf(PRINT_LIGHT_AQUA "\n\n                                -----Fruit Manager Preview---- \n" PRINT_COLOR_RESET);
    printf(PRINT_AQUA "-------------------------------------------------------------------------------------------------------------\n" PRINT_COLOR_RESET);
    printf(PRINT_AQUA "| " PRINT_COLOR_RESET PRINT_GREEN "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
           PRINT_GREEN "%-15s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
           PRINT_GREEN "%-15s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
           PRINT_GREEN "%-15s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
           PRINT_GREEN "%-10s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
           PRINT_GREEN "%-15s" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
           "Name", "Quantity", "Buy Price", "Sell Price", "Sold", "Profit"); 
    printf(PRINT_AQUA "-------------------------------------------------------------------------------------------------------------\n" PRINT_COLOR_RESET);
    for (i = 0; i < *number_of_fruit; i++)
    {
        fruit[i].profit = fruit[i].sold * (fruit[i].price_sell - fruit[i].price_buy);
        printf(PRINT_AQUA "| " PRINT_COLOR_RESET PRINT_GREEN "%-20s" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
               PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
               PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
               PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
               PRINT_GREEN "%-10d" PRINT_COLOR_RESET PRINT_AQUA " | " PRINT_COLOR_RESET 
               PRINT_GREEN "%-15d" PRINT_COLOR_RESET PRINT_AQUA " |\n" PRINT_COLOR_RESET,  
               fruit[i].name, fruit[i].quantities, fruit[i].price_buy, fruit[i].price_sell, 
               fruit[i].sold, fruit[i].profit);  
    printf(PRINT_AQUA "-------------------------------------------------------------------------------------------------------------\n" PRINT_COLOR_RESET);
    }
    printf("\033[15;20H");
    return; 
}
/// /////////////////////////////// //////////////////////////////////////// main menu handling
void (*menuFunctions[NUM_OPTIONS])(int *, Fruits *) = {reselectOption1,
    Option2, Option3, Option4, Option5, Option6, Option7, Option8, Option9, 
    Option10, Option11, Option12, Option13
};
void switchCase(int *number_of_fruit, Fruits fruit[])
{
    int user_selelection;
    while (1)
    {
        user_selelection = intInput();
        if(user_selelection >= 1 && user_selelection <= NUM_OPTIONS) 
        {
            menuFunctions[user_selelection - 1](number_of_fruit, fruit);
        }
        else
        {
            refreshScreen();
            printf(PRINT_RED "Please Enter A Valid Option!\n\n" PRINT_COLOR_RESET);
            userPrompt();
            continue;
        }
    }
    return;
}
/// /////////////////////////////// //////////////////////////////////////// sort menu handling
void switchCaseSortMenu(int *number_of_fruit, Fruits fruit[])
{
    if(isFruitManagerEmpty(*number_of_fruit)) return;
    refreshPrintSortByMenu();
    printf(PRINT_LIGHT_AQUA"\nSort By Functions\n"PRINT_COLOR_RESET);
    userPrompt();
    while(1)
    {
        int user_selection =  intInput();
        refreshPrintSortByMenu();
        switch (user_selection)
        {
        case 1:
            SortOption1(number_of_fruit, fruit);
            break;
        case 2:
            SortOption2(number_of_fruit, fruit);
            break;
        case 3:
            SortOption3(number_of_fruit, fruit);
            break;
        case 4:
            SortOption4(number_of_fruit, fruit);
            break;
        case 5:
            SortOption5(number_of_fruit, fruit);
            break;
        case 6:
            SortOption6(number_of_fruit, fruit);
            break;
        case 7:
            refreshScreen();
            printf(PRINT_GREEN"Returned To Main Menu\n\n");
            userPrompt();
            return;
        case 8:
            Option13(number_of_fruit, fruit);
            break;
        default:
            refreshPrintSortByMenu();
            printf(PRINT_RED"Invalid Option! Please Input Valid Option\n"PRINT_COLOR_RESET);
            printf(PRINT_LIGHT_AQUA"Sort By Functions\n" PRINT_COLOR_RESET);
            userPrompt();
            break;
        }
    }
    return;  
}
//////////////////////////////////////////////////////////////////////////////main functions

int main()
{
    int number_of_fruit;
    Fruits fruit[MAXSIZE];
	printMenu();
    Option1(&number_of_fruit, fruit);
    switchCase(&number_of_fruit, fruit);
	return 0;
}