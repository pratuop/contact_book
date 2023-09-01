#include<stdio.h>
#include"phoneno.h"
#include<string.h>
int main()
{
	int i,choice;
	char Sname[20];
	long long int Scontact_number;
	
	showmenu();
	do
    {
	    printf("\nEnter choice number from 1 to 5: ");
	    scanf("%d",&choice);
	    switch(choice)
        {
            case 1:
                addContact();
                break;
            case 2:
                searchContact();
                break;
            case 3:
                viewContact();
                break;
           case 4:
               editContact();
               break;
            case 5:
              deleteContact();
              break;
            default :printf("Invalid Choice!!!");
        }
    }
    while (choice!=6);
}