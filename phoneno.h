//#include<string.h>
#include <stdio.h>
#include <string.h>
struct Contacts{
	char name[20];
	long long int contact_number;
}s1;
FILE *fp;
char fn[50]= "pratik.txt";

void showmenu()
{
    printf("PHONEBOOK!!!");
    printf("\n------------------------------------------------------------------------\n");
    printf("\nMENUS\n");
    printf("\n1-Add Contact \n2-Search Contact \n3-View Contact \n4-Edit Contact \n5-Delete Contact\n");
    printf("\n------------------------------------------------------------------------\n");
}

void addContact()
{
	int i;
	fp=fopen(fn,"ab");
	for(i=0;i<2;i++)
	{
		printf("\nEnter the name: ");
		scanf("%s",s1.name);
		printf("\nEnter the contact number: ");
		scanf("%lld",&s1.contact_number);
		fwrite(&s1,sizeof(struct Contacts),1,fp);
	}
	fclose(fp);
}
	
void searchContact()
{
	char Sname[50];
	fp=fopen(fn,"rb");
	printf("\nEnter the Name to be searched: ");
	scanf("%s",Sname);
	while(fread(&s1,sizeof(struct Contacts),1,fp)>0)
	{
		if(strcmp(Sname,s1.name)==0)
		{
		printf("\nName: %s",s1.name);
		printf("\ncontact number : %lld",s1.contact_number);
		return;
	    }
	}
	printf("\n Data not found");
	fclose(fp);
}

void viewContact()
{
	fp=fopen(fn,"rb");
	printf("\nViewing all data: ");
	while(fread(&s1,sizeof(struct Contacts),1,fp)>0)
	{
		printf("\nName: %s",s1.name);
		printf("\nContact Number: %lld",s1.contact_number);
	}
	fclose(fp);
}

void editContact()
{
	long long int Scontact_number;
	fp=fopen(fn,"rb+");
	printf("\nEnter the contact number to be changed: ");
	scanf("%lld",&Scontact_number);
	while(fread(&s1,sizeof(struct Contacts),1,fp)>0)
	{
		//printf("%d",s1.contact_number);
		//printf("\nName: %s",s1.name);
		if(s1.contact_number==Scontact_number)
		{
		printf("\nName: %s",s1.name);
		printf("\ncontact number : %lld",s1.contact_number);
		
		printf("\n Enter New Number: ");
		scanf("%lld",&s1.contact_number);//& NHI DELA
		printf("Number will be changed!");
		fseek(fp,-sizeof(struct Contacts),SEEK_CUR);
		fwrite(&s1,sizeof(struct Contacts),1,fp);
		break;
	    }
	}

	fclose(fp);
}

void deleteContact()
{
   long long int Scontact_number;
   FILE *fs;
   fs=fopen("pratik_temp.txt","wb+");  
   fp=fopen(fn,"rb+");
   printf("\nEnter the contact number to delete : ");
   scanf("%lld",&Scontact_number);
   while(fread(&s1,sizeof(struct Contacts),1,fp)>0)
   {
   	if(s1.contact_number != Scontact_number)
   	   	fwrite(&s1,sizeof(struct Contacts),1,fs);
   }
   printf("\nData Deleted Successfullyy!!!");
    fclose(fp);
    fclose(fs);
    remove(fn);
    rename("pratik_temp.txt",fn);
    remove("tpratik_temp.txt");
   
}