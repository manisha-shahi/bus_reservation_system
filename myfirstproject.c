#include <stdio.h>
#include <string.h>
#include<stdlib.h>

char reg_username[20];
char reg_password[20];
char username[20];
char password[20];
char email_id[30]; 
char mobile_no[20];
char Source_city[25];
char Destination_city[25];
int  number[10]={0};

int Total_seats = 50;
int Payment = 1500;
int Bus_number;
int Seats;
int Choice;
int Ticket_no;
int invalid;

void signup();
int login();
void menu();
void bookticket();
void cancelticket();
void checkstatus();

int main()
{
    system("color 0A");
    printf("===== BUS RESERVATION SYSTEM =====");
    printf("\n1. Signup");
    printf("\n2. Exit");
    printf("\nEnter choice: ");
    scanf("%d", &Choice);

    if (Choice == 1)
    {
        signup();

        if (login() == 1)
        {
            menu();   
        }
        else
        {
            printf("\nLogin Failed!");
        }
    }

    return 0;
}

void signup()
{
    while (1)
    {
        invalid=0;
        system("color 0B");
        printf("\n****** SIGN UP ******");
        printf("\nCreate Username: ");
        scanf("%s", &reg_username);
        for (int i = 0; reg_username[i] != '\0'; i++)
        {
            if((reg_username[i] >= 'A' && reg_username[i] <= 'Z') || (reg_username[i] >= 'a' && reg_username[i] <= 'z'))
            {
            }
     else
            {
                printf("invalid Username (numbers not allowed)\n");
                invalid=1;
                 break; 
            }
        }
        if (invalid) continue;    
     invalid = 0;
     printf("Create Password: ");
     scanf("%s", reg_password);
      for (int i = 0; reg_username[i] != '\0'; i++)
        {
      if(strlen(reg_password)<=6 && strlen(reg_password)>=6)
      {

      }
      else
     {
         printf("invalid password");
        invalid=1;   
        break; 
      }
    }
    if (invalid)continue; 
     
       invalid = 0;
        printf("please enter mobile number(only 10 digit):");
        scanf("%s",&mobile_no);
        for(int i=0; i<10; i++)
        {
            if(mobile_no[i]<'0' || mobile_no[i]>'9')
         {   
        if (strlen(mobile_no)!=10)
        
        {
            printf("invalid mobile number\n");
            invalid=1;
            break;
        }
      }
     }
      if (invalid)continue; 
     
     printf("please enter email id :"); 
     scanf("%s",&email_id);
    
  printf("\nSignup Successful!");
  break;
   }
  }


int login()
{
    system("color 0C");
    printf("\n==== LOGIN ====");
    printf("\nEnter Username: ");
    scanf("%s", &username);

    printf("Enter Password: ");
    scanf("%s", &password);

    if (strcmp(username, reg_username) == 0 &&
        strcmp(password, reg_password) == 0)
    {
        printf("\nLogin Successful!");
        return 1;
    }
    return 0;
}


void menu()
{
    do
    {
        system("color 0E");
        printf("\n\n****** MENU ******");
        printf("\n1. Book Ticket");
        printf("\n2. Cancel Ticket");
        printf("\n3. Check Status");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &Choice);

        switch (Choice)
        {
        case 1:
            bookticket();
            break;
        case 2:
            cancelticket();
            break;
        case 3:
            checkstatus();
            break;
        case 4:
            printf("\nThank You!");
            break;
        default:
            printf("\nInvalid Choice");
        }
    } while (Choice != 4);
}


void bookticket()
{
    system("color 0F");
    printf("\nEnter Bus Number: ");
    scanf("%d", &Bus_number);

    printf("Enter Seats: ");
    scanf("%d", &Seats);

    if (Seats > Total_seats)
    {
        printf("\nNot enough seats!");
        return;
    }

    printf("Source City: ");
    scanf("%s", &Source_city);

    printf("Destination City: ");
    scanf("%s", &Destination_city);

    Total_seats =Total_seats - Seats;
    Payment = Seats * 1500;

    printf("\nBooking Successful!");
    printf("\nPayment: %d", Payment);
}

void cancelticket()
{   
    system("color 0A");
    printf("\nEnter bus Number: ");
    scanf("%d", &Ticket_no);

    printf("Seats to cancel: ");
    scanf("%d", &Seats);

    Total_seats =Total_seats + Seats;
    printf("\nTicket Cancelled Successfully!");
}

void checkstatus()
{
    system("color 0F");
    printf("\nBus Number: %d", Bus_number);
    printf("\nSource: %s", Source_city);
    printf("\nDestination: %s", Destination_city);
    printf("\nAvailable Seats: %d", Total_seats);
}
