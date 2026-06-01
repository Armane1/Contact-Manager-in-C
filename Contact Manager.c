#include <stdio.h>

#include <string.h>

struct CreateAccount
{
    int ID;
    char NAME[50];
    int BALANCE;
};


void CreateAccount()
{
    FILE *fptr = fopen("accounts.txt" , "a");

    if(fptr == NULL)
    {
        printf("The file has not opened and exited with error 1");
        return;
    }

    struct CreateAccount a;

    printf("Please Enter the Id of the user : \n");
    scanf("%d" , &a.ID);
    getchar();
    
    printf("Please Enter the Name of the user : \n");
    fgets(a.NAME , sizeof(a.NAME), stdin);
    a.NAME[strcspn(a.NAME, "\n")] = '\0';
    
    printf("Please Enter the Balance of the user : \n");
    scanf("%d" , &a.BALANCE);
    getchar();


    fprintf(fptr, "%d  %s %d \n" , a.ID , a.NAME , a.BALANCE);

    fclose(fptr);

}



void ShowAccounts()
{
    FILE *file = fopen("accounts.txt" , "r");

    if(file == NULL)
    {
        printf("Ure file has not opened : \n");
        return;
    }

    struct CreateAccount a;

    printf("-----Accounts Lists : ----- \n");
    while(fscanf(file , "%d %s %d" , &a.ID , a.NAME , &a.BALANCE )== 3)
    {
        printf("\n");
        printf("ID : %d | NAME : %s | BALANCE : %d" , a.ID , a.NAME , a.BALANCE);
        printf("\n");
        printf("\n");
    };
}

void Deposit()
{
    
    int IDD;
    int AMOUNT;

    
    FILE *ff = fopen("accounts.txt" , "r");

    if(ff == NULL)
    
    {
        printf("The file has not opened and exited with error 1");
        return;
    }

    FILE *tt = fopen("tt.txt" , "w");
    
    if(tt == NULL)
    
    {
        printf("The file has not opened and exited with error 1");
        return;
    }


    struct CreateAccount a;

    printf("Enter The ID : \n");
    scanf("%d" , &IDD);

    printf("\n");

    printf("Enter the Amount : \n");
    scanf("%d" , &AMOUNT);

    while(fscanf(ff ,"%d %s %d",  &a.ID,
              a.NAME,
              &a.BALANCE) == 3)
    {

            if(a.ID == IDD)
            {
                    a.BALANCE += AMOUNT;
                    printf("The New Balance of this ID : %d is %d" , a.ID , a.BALANCE);
                    printf("\n");
            }
            fprintf(tt, "%d %s %d\n" , a.ID , a.NAME , a.BALANCE);
    }
    
 

    printf("Deposit Done Successfully\n");

    
    fclose(ff);
    fclose(tt);

    remove("accounts.txt");
    rename("tt.txt" , "accounts.txt");
};


void Withdraw()
{

int FindedId = 0;
int Aamount = 0;

 
FILE *fo = fopen("accounts.txt" , "r");

FILE *to = fopen("tt.txt" , "w");

if(fo == NULL || to == NULL )
{
    printf("There is A error to opening the file : \n");
    return;
}

struct CreateAccount a;

printf("Enter ID U want to withdraw to it : \n");
scanf("%d" , &FindedId);

printf("Enter Amount U want it : \n");
scanf("%d" , &Aamount);

while(fscanf(fo , "%d %s %d" , &a.ID , a.NAME , &a.BALANCE) == 3)
    {
        if (Aamount <= a.BALANCE || FindedId == a.ID)
        {
        a.BALANCE -= Aamount;
        printf("The New Balance of this ID : %d is %d" , a.ID, a.BALANCE);
        printf("\n");
        }
        else
        {
            printf("Account not found Or operation has not succed : \n");
        }
   }

    fprintf(to, "%d %s %d\n" , a.ID , a.NAME , a.BALANCE);

    remove("accounts.txt");
    rename("tt.txt" , "accounts.txt");
 

    printf("Deposit Done Successfully\n");

    
    fclose(fo);
    fclose(to);

};

void CheckBalance()
{
    int ID = 0;
    int found = 0;
    
    FILE *extra = fopen("accounts.txt" , "r");

    struct CreateAccount a;

    if(extra == NULL)
    {
        printf("ooops : \n");
        return;
    }

    printf("Enter Id u want to check his balance : \n");
    scanf("%d" , &ID);

    while(fscanf(extra, "%d %s %d\n", &a.ID , a.NAME , &a.BALANCE) == 3)
    {
        if(a.ID == ID)
        {
            printf("The id : %d his balance is : %d" , a.ID , a.BALANCE);
            printf("\n");
            found = 1;
        }

    }

        if(found == 0)
        {
            printf("Account not found\n");
        }


    fclose(extra);
};



int main()
{
    int choose = 0;
    while(1)
 {
    printf("What u want to do : \n");
    printf("\n");
    printf("1. Create Account\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");    
    printf("4. Check Balance\n");     
    printf("5. Show Accounts\n");  
    printf("6. Exit \n");

    scanf("%d", &choose);
    getchar();
    
    if (choose == 1)
    {
        CreateAccount();
    }
    else if (choose == 2)
    {
        Deposit();
    }

    else if (choose == 3)
    {
        Withdraw();
    }

    else if (choose == 4)
    {
        CheckBalance();
    }

    else if (choose == 5)
    {
        ShowAccounts();
    }
    
    else if (choose == 6)
    {
        break;
    }

    else 
    {
        printf("U've entred a invalid operation : \n");
    }

 }
    return 0;

}