#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define len 50
#define lenn 50

int avl_id();

struct car
{
	int idd;
	char namee[30]; 
	char features[100];
	float cost;
}nexa;


struct date{
    int month,day,year;
    };
struct emp
	{
	     int id;
		char name[len];
		int age;
		char address[len];
		char Gender[10];
		float salary;
		long long int phone;
		struct date dob;
		struct date joined;
		
	};

char fname[]={"mydb.dat"};

struct datee{
    int dayy,monthh,yearr;
    };

struct customer
{
	int sr_no;
	char nname[lenn];
	char aaddress[100];
	double mobile_no;
	char carname[lenn];
	float price;
	struct datee d;
}c1;

char fnam[]={"CR.dat"};
//FUNCTION TO INSERT  CAR RECORDS TO THE FILE
void insert()
{
	FILE *fp;
	fp = fopen("car.dat", "a");
	printf("Enter the ID no   :");
	scanf("%d", &nexa.idd);
	printf("Enter the Name      :");
	scanf("%s", &nexa.namee);
	printf("Enter the Features      :");
	scanf("%s", &nexa.features);
	printf("Enter the Cost      :");
	scanf("%f", &nexa.cost);
	fwrite(&nexa, sizeof(nexa), 1, fp);
	fclose(fp);
}


//    FUNCTION TO DISPLAY CAR RECORDS
void disp()
{
	FILE *fp1;
	fp1 = fopen("car.dat", "r");
	//printf("\nID Number\tName\tCost\n\n");
	while (fread(&nexa, sizeof(nexa), 1, fp1))
{
	printf("\nID = %d\n", nexa.idd);
	printf("NAME = %s\n",nexa.namee); 
	printf("FEATURES = %s\n",nexa.features);
	printf("COST = %.2f L\n", nexa.cost);
}
	fclose(fp1);
}


//    FUNCTION TO SEARCH THE GIVEN CAR RECORD
void search()
{
	FILE *fp2;
	int r, s, avl;
	printf("\nEnter the ID no you want to search  :");
	scanf("%d",&r);
	avl = avl_id(r);
	if (avl == 0)
	printf("ID number %d is not available in the file\n",r);
	else
		{
		fp2 = fopen("car.dat", "r");
		while (fread(&nexa, sizeof(nexa), 1, fp2))
			{
			s = nexa.idd;
			if (s == r)
				{
				printf("\nID no = %d", nexa.idd);
				printf("\nName = %s", nexa.namee);
				printf("\nFeatures = %s", nexa.features);
				printf("\nCost = %.2f L\n", nexa.cost);
				}
			}
		fclose(fp2);
		}
}



//    FUNCTION TO DELETE A  CAR RECORD
void deletefile()
{
	FILE *fpo;
	FILE *fpt;
	int r, s;
	printf("Enter the ID no you want to delete :");
	scanf("%d", &r);
	if (avl_id(r) == 0)
	printf("ID no %d is not available in the file\n", r);
	else
		{
		fpo = fopen("car.dat", "r");
		fpt = fopen("TempFile.dat", "w");
			while (fread(&nexa, sizeof(nexa), 1, fpo))
			{
			s =nexa.idd;
			if (s != r)
			fwrite(&nexa, sizeof(nexa), 1, fpt);
			}
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("car.dat", "w");
		fpt = fopen("TempFile.dat", "r");
		while (fread(&nexa, sizeof(nexa), 1, fpt))
		fwrite(&nexa, sizeof(nexa), 1, fpo);
		printf("\nRECORD DELETED\n");
		fclose(fpo);
		fclose(fpt);
		}

}
//    FUNCTION TO UPDATE THE  CAR RECORD 
void update()
{
	int avl;
	FILE *fpt;
	FILE *fpo;
	int s, r, ch;
	printf("Enter id number to update:");
	scanf("%d", &r);
	avl = avl_id(r);
	if (avl == 0)
		{
		printf("ID number %d is not Available in the file", r);
		}
	else
		{
		fpo = fopen("car.dat", "r");
		fpt = fopen("TempFile.dat", "w");
			while (fread(&nexa, sizeof(nexa), 1, fpo))
			{
			s = nexa.idd;
			if (s != r)
			fwrite(&nexa, sizeof(nexa), 1, fpt);
			else
				{
				printf("\n\t1. Update Name of ID Number %d", r);
				printf("\n\t2. Update Features of ID Number %d", r);
				printf("\n\t3. Update Cost of ID Number %d", r);
				printf("\n\t4. Update ALL Name,Features and Cost of ID Number %d", r);
				printf("\nEnter your choice:");
				scanf("%d", &ch);
				switch (ch)
					{
					case 1:
						printf("Enter Name:");
						scanf("%s", &nexa.namee);
						break;
					case 2:
						printf("Enter Features:");
						scanf("%s", &nexa.features);
						break;
					case 3:
						printf("Enter cost : ");
						scanf("%f", &nexa.cost);
						break;
					case 4:
						printf("Enter Name: ");
						scanf("%s", &nexa.namee);
						printf("Enter Features:");
						scanf("%s", &nexa.features);
						printf("Enter cost: ");
						scanf("%f", &nexa.cost);
						break;
					default:
						printf("Invalid Selection");
						break;
					}
				fwrite(&nexa, sizeof(nexa), 1, fpt);
			}
		}
		 
		fclose(fpo);
		fclose(fpt);
		fpo = fopen("car.dat", "w");
		fpt = fopen("TempFile.dat", "r");
		while (fread(&nexa, sizeof(nexa), 1, fpt))
			{
			fwrite(&nexa, sizeof(nexa), 1, fpo);
			}
		fclose(fpo);
		fclose(fpt);
		printf("RECORD UPDATED");
	}
}


/* FUNCTION TO SORT THE RECORD //car*/
void sort()
{
	int a[20], count = 0, i, j, t, c;
	FILE *fpo;
	fpo = fopen("car.dat", "r");
	while (fread(&nexa, sizeof(nexa), 1, fpo))
		{
		a[count] = nexa.idd;
		count++;
		}
	c = count;
	for (i = 0; i<count - 1; i++)
		{
		for (j = i + 1; j<count; j++)
			{
			if (a[i]>a[j])
				{
				t = a[i];
				a[i] = a[j];
				a[j] = t;
				}
			}
		}
	
	count = c;
	for (i = 0; i<count; i++)
		{
		rewind(fpo);
		while (fread(&nexa, sizeof(nexa), 1, fpo))
			{
			if (a[i] == nexa.idd)
				{
				printf("\nID = %d\n",nexa.idd);
				printf("NAME = %s\n", nexa.namee);
				printf("FEATURES = %s\n", nexa.features);
				printf("COST = %.2f L\n", nexa.cost);
				}
			}
		}
}

//    FUNCTION TO CHECK GIVEN ID NO. IS AVAILABLE //car
int avl_id(int rno)
{

	FILE *fp;
	int c = 0;
	fp = fopen("car.dat", "r");
	while (!feof(fp))
		{
		fread(&nexa, sizeof(nexa), 1, fp);

		if (rno == nexa.idd)
			{
			fclose(fp);
			return 1;
			}
		}
	fclose(fp);
	return 0;
}

//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT //car
int empty()
{
	int c = 0;
	FILE *fp;
	fp = fopen("car.dat", "r");
	while (fread(&nexa, sizeof(nexa), 1, fp))
	c = 1;
	fclose(fp);
	return c;
}


void append()
	{
		FILE *fp;
		struct emp t1;

		fp=fopen(fname,"ab");

		if(fp==NULL)
		{
			printf("error while opening the file\n");
			exit(1);	
		}	
		
		printf("\n-----------------------------------");
		printf("\nEnter today's date(dd/mm/yyyy):");
	    scanf("%d/%d/%d",&t1.joined.day,&t1.joined.month,&t1.joined.year);
		printf("\nEnter the employe_id: ");
		scanf("%d",&t1.id);
		printf("\nEnter the name: ");
		scanf("%s",&t1.name);
		printf("\nEnter the Address: ");
		scanf("%s",&t1.address);
		printf("\nEnter DOB(dd/mm/yyyy):");
	  	scanf("%d/%d/%d",&t1.dob.day,&t1.dob.month,&t1.dob.year);
	  	printf("\nEnter age: ");
		scanf("%d",&t1.age);	
		printf("\nEnter Gender: ");
		scanf("%s",t1.Gender);
		printf("\nEnter the salary: ");
		scanf("%f",&t1.salary);
		printf("\nEnter the Phone Number: ");
		scanf("%llu",&t1.phone);
		printf("\n----------------------------------");
		
		fwrite(&t1,sizeof(t1),1,fp);
		
		printf("\nData saved successfully..!!\n");
		fclose(fp);
	}

//--------------------------------------------TO MODIFY THE DETAIL--------------------------------
void modify()
	{
		FILE *fp,*fp1;	
		struct emp t,t1;
		int id,found=0,count=0;

		fp=fopen(fname,"rb");
		fp1=fopen("temp.dat","wb");

		if(fp==NULL)
		{
			printf("error while opening the file\n");
			exit(1);	
		}	
		
		if(fp1==NULL)
		{
			printf("error while opening\n");
			exit(1);	
		}	
		
		printf("\nEnter the Emp ID you want to Modify:");
		scanf("%d",&id);

		while(1)
		{		
			fread(&t,sizeof(t),1,fp);

			if(feof(fp))
			{
				break;
			}
			if(t.id==id)
			{
				found=1;
				printf("\nEnter Employee ID:");
				scanf("%d",&t.id);

				fflush(stdin);
				printf("\nName : %s\n",t.name);
				printf("\nEnter Employee Salary:");
				scanf("%f",&t.salary);
				printf("\nEnter the Phone Number: ");
				scanf("%llu",&t.phone);
				printf("\nEnter the Address: ");
				scanf("%s",&t.address);
				fwrite(&t,sizeof(t),1,fp1);
				
			}
			else
			{
				fwrite(&t,sizeof(t),1,fp1);
			}
		}
		fclose(fp);
		fclose(fp1);

		if(found==0)
		{
			printf("Sorry No Record Found\n\n");
		}	
		else
		{
			fp=fopen(fname,"wb");
			fp1=fopen("temp.dat","rb");
		
			while(1)
			{
				fread(&t,sizeof(t),1,fp1);

				if(feof(fp1))
				{
				break;
				}
				fwrite(&t,sizeof(t),1,fp);
			}

		}		
		fclose(fp);
		fclose(fp1);
	}	
//-----------------------------------------DELETE THE DETAIL--------------------------------------------
void del()
	{
		FILE *fp,*fp1;
		struct emp t,t1;
		int id,found=0,count=0;
	
		fp=fopen(fname,"rb");
		fp1=fopen("temp.dat","wb");
		if(fp1==NULL)
		{
			printf("error while opening the file\n");
			exit(1);	
		}	
		if(fp==NULL)
		{
			printf("error while opening\n");
			exit(1);	
		}	
		printf("\nEnter the Emp ID you want to Delete:");
		scanf("%d",&id);

		while(1)
		{
			fread(&t,sizeof(t),1,fp);

			if(feof(fp))
			{	
				break;
			}
			if(t.id==id)
			{
				found=1;
			}
			else
			{		
				fwrite(&t,sizeof(t),1,fp1);
			}
		}
		fclose(fp);
		fclose(fp1);

		if(found==0)
		{
			printf("Sorry No Record Found\n\n");	
		}
		else
		{
			fp=fopen(fname,"wb");
			fp1=fopen("temp.dat","rb");

			while(1)
			{
				fread(&t,sizeof(t),1,fp1);

				if(feof(fp1))
				{
					break;
				}	
				fwrite(&t,sizeof(t),1,fp);
			}
		}
			fclose(fp);
		fclose(fp1);
	}
//------------------------------------------------SEARCH BY ID----------------------------
void search_by_id()
	{
		FILE *fp;
		struct emp t;
		int id,found=0;

		fp=fopen(fname,"rb");                
		
		if(fp==NULL)
		{
			printf("error while opening file\n");
			exit(1);	
		}	
		
		printf("\nEnter the Emp ID:");
		scanf("%d",&id);

		while(1)
		{
			fread(&t,sizeof(t),1,fp);

			if(feof(fp))
			{	
				break;
			}
			if(t.id==id)
			{
				found=1;
				printf("\n========================================================\n\n");
				printf("\t\t Employee Details of %s\n\n",t.name);
				printf("========================================================\n\n");

				printf("\n\t employee DETAILS \n\n");
				printf("\tEmployee id: %d\n \tFull_Name: %s\n \tDOB: %d/%d/%d \n\tAge: %d\n \tGender: %s\n \tAddress: %s\n \tPhone Number:%llu\n \tsalary: %g\n\tjoined : %d/%d/%d\n",t.id, t.name,t.dob.day, t.dob.month,t.dob.year,t.age,t.Gender,t.address,t.phone,t.salary,t.joined.day,t.joined.month,t.joined.year);
				
				printf("\n========================================================\n\n");
				found++;			
			}	
		}
		if(found==0)
		{		
			printf("\nSorry No Record Found");
		}
		fclose(fp);
	}
//---------------------------------------------------SEARCH BY NAME----------------------------
void search_by_name()
	{
		FILE *fp;
		struct emp t;
		int found=0;
		char name[20];

		fp=fopen(fname,"rb");
		
		if(fp==NULL)
		{
			printf("error while opening the file\n");
			exit(1);	
		}	
		
		printf("\nEnter the Employee Name:");
		scanf("%s",&name);

		while(1)
		{	
			fread(&t,sizeof(t),1,fp);

			if(feof(fp))
			{
				break;
			}
			if(strcmp(name,t.name)==0)
			{
				printf("\n========================================================\n\n");
				printf("\t\t Employee Details of %s\n\n",t.name);
				printf("========================================================\n\n");
				
				printf("\tEmployee id: %d\n \tFull_Name: %s\n \tDOB: %d/%d/%d \n\tAge: %d\n \tGender: %s\n \tAddress: %s\n \tPhone Number:%llu\n \tsalary: %g\n\tjoined : %d/%d/%d\n",t.id, t.name,t.dob.day, t.dob.month,t.dob.year,t.age,t.Gender,t.address,t.phone,t.salary,t.joined.day,t.joined.month,t.joined.year);
				
				printf("\n========================================================\n\n");
				found++;
			}	
		}
		if(found==0)
		{	
		printf("\nSorry No Record Found");
		}	
		fclose(fp);
	}

void search_employee()
	{
		int choice;
		printf("\n1.search by name\n 2.search by id\n");
		printf("enter your choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:search_by_name();
			break;
			case 2:search_by_id();
			break;
			default : printf("\n Invalid Input");
		}
	}

//-----------------------------------------TO DISPLAY THE LIST OF EMPLOYEE---------------------------------	
void view_list()
	{
		FILE *fp;
		struct emp t;

		fp=fopen(fname,"rb");

		if(fp==NULL)
		{
			printf("error while opening opening the file\n");
			exit(1);	
		}	
		
		printf("\n========================================================\n\n");
		printf("\t\t All Employee Details\n\n");
		printf("========================================================\n\n");

		printf("ID\tName  \tSalary\t\tPhone no\n\n");

		while(1)
		{
			fread(&t,sizeof(t),1,fp);

			if(feof(fp))
			{
				break;
			}
			printf("%d\t",t.id);
			printf("%s\t",t.name);
			printf("%.1f/-  \t",t.salary);
			printf("%llu\t\n\n",t.phone);
		}		
		printf("========================================================\n\n");

		fclose(fp);
	}
void addc()
	{
		FILE *fz;
		struct customer c1;

		fz=fopen(fnam,"ab");
		printf("\n-----------------------------------");
		printf("\nEnter the sr.no: ");
		scanf("%d",&c1.sr_no);
		printf("\nEnter the name: ");
		scanf("%s",&c1.nname);
		printf("\nEnter the Address: ");
		scanf("%s",&c1.aaddress);
		printf("\nEnter the Phone Number: ");
		scanf("%lf",&c1.mobile_no);
		printf("\nEnter the car name:");
		scanf("%s",&c1.carname);
		printf("\nEnter the price: ");
		scanf("%f",&c1.price);
		printf("\nEnter today's date(dd/mm/yyyy):");
	  scanf("%d/%d/%d",&c1.d.dayy,&c1.d.monthh,&c1.d.yearr);
		printf("\n----------------------------------");
		
		fwrite(&c1,sizeof(c1),1,fz);
		
		printf("\nData saved successfully..!!\n");
		fclose(fz);
	}


//---------------------------------------------------SEARCH BY NAME----------------------------
void search_customer()
	{
		FILE *fz;
		struct customer c2;
		int found=0;
		char nname[20];

		fz=fopen(fnam,"rb");

		printf("\nEnter the Customer Name:");
		scanf("%s",&nname);

		while(1)
		{	
			fread(&c2,sizeof(c2),1,fz);

			if(feof(fz))
			{
				break;
			}
			if(strcmp(nname,c2.nname)==0)
			{
				printf("\n========================================================\n\n");
				printf("\t\t Customer Details of %s\n\n",c2.nname);
				printf("========================================================\n\n");
				
				printf("\nSr.No: %d\n \tFull_Name: %s\n \tAddress: %s\n \tPhone Number:%lf\n \tCar name:%s\n \tprice: %f\n\tDate:%d/%d/%d\n \t",c2.sr_no,c2.nname,c2.aaddress,c2.mobile_no,c2.carname,c2.price,c2.d.dayy,c2.d.monthh,c2.d.yearr);
				
				printf("\n========================================================\n\n");
				found++;
			}	
		}
		if(found==0)
		{	
		printf("\nSorry No Record Found");
		}	
		fclose(fz);
	}
//-----------------------------------------TO DISPLAY THE LIST OF CUSTOMER---------------------------------	
void viewlist()
	{
		FILE *fz;
		struct customer c2;

		fz=fopen(fnam,"rb");

		printf("\n========================================================\n\n");
		printf("\t\t All Customer Details\n\n");
		printf("========================================================\n\n");

		printf("Sr.No.\tName \tAddress \tPhone no \tCar name\t Price\n\n");

		while(1)
		{
			fread(&c2,sizeof(c2),1,fz);

			if(feof(fz))
			{
				break;
			}
			printf("%d\t",c2.sr_no);
			printf("%s\t",c2.nname);
			printf("%s\t",c2.aaddress);
			printf("%lf\t",c2.mobile_no);
			printf("%s\t",c2.carname);
			printf("%.2f L \t",c2.price);
			printf("\n");
		}		
		printf("========================================================\n\n");

		fclose(fz);
	}
	
void adminmenu();
void custmain();
// CAR MAIN PROGRAM
void carmain()
{	system("clear");
	int c, ep;
	do
	{
	
	printf("\n\t---------Select your choice---------\n");
	printf("\n\t1. CREATE \n\t2. DISPLAY  \n\t3. SEARCH");
	printf("\n\t4. DELETE\n\t5. UPDATE\n\t6. SORT");
	printf("\n\t7. To go back");
	printf("\n\t8. EXIT");
	printf("\n\t------------------------------------------\n");
	printf("\nEnter your choice:");
	scanf("%d", &c);
	system("clear");
	printf("\n");
	switch (c)
		{
		case 1:
			insert();
			break;
		case 2:
			ep = empty();
			if (ep == 0)
			printf("\nThe file is EMPTY\n");
			else
			disp();
			break;
		case 3:
			search();
			break;
		case 4:
			deletefile();
			break;
		case 5:
			update();
			break;
		case 6:
			ep = empty();
			if (ep == 0)
			printf("\n The file is EMPTY\n");
			else
			sort();
			break;
		
		case 7: 
			adminmenu();
			break;

		case 8:
			printf("\n\n\n\t\tTHANK YOU..........!!!\n\n\n");
			exit(1);
			break;

		case 9: carmain();
			break;

		default:
			printf("\nYour choice is wrong\nPlease try again...\n");
			break;

		}printf("\n\n1.Press 9 go back\n2.press 7 to go in  main_nmenu\n :");
			scanf("%d",&c);  
			system("clear");
	} while (c == 9);


}

// EMP MAIN PROGRAM  
void empmain()
	{	system("clear");
		int chh,ans;
		do	
		{
			
			printf("\n\t\t==================Employee Management System=============\n\n");
	
			printf("1. Add the employee\n\n");
			printf("2. update the details\n\n");
			printf("3. Delete the employee detail\n\n");
			printf("4. Search the employee detail \n\n");
			printf("5. view all the list\n\n");
			printf("6. Exit\n\n");
			printf("7. go back\n\n");
		
			printf("========================================================\n\n");

			printf("\nPlease enter your Choice:");
			scanf("%d",&chh);
			
			system("clear");	
			switch(chh)
			{
				case 1: append();
					break;
	
				case 2: modify();
					break;
		
				case 3: del();
					break;
		
				case 4:search_employee();
					break;
	
				case 5: view_list();
					break;
	
				case 6:	printf("\n\n\n\t\tTHANK YOU...........!!!\n\n\n");
					exit(1);
        				break;
														
				
				case 7: adminmenu();
					break;
				case 8: empmain();
					break;

				default : printf("\n Invalid Input"); 
					break;
			}
			printf("\n\n1. press 7 to go in  main_nmenu\n2. Press 8 go back\n");
			scanf("%d",&chh); 
		system("clear");
		}while(chh == 8);
	}

//CUSTOMER MAIN PROGRAM
void custmain()
	{	system("clear");
		int ch;
		do	
		{
			
			printf("\n\t\t==================Customer Management System=============\n\n");
	
			printf("1. Add the customer\n\n");
			printf("2. Search the customer detail \n\n");
			printf("3. View all the list\n\n");
			printf("5. Exit\n\n");
			printf("6. To go back\n\n");
		
			printf("========================================================\n\n");

			printf("\nPlease enter your Choice:");
			scanf("%d",&ch);
			system("clear");
			switch(ch)
			{
				case 1: addc();
					break;
				
				case 2:search_customer();
					break;
	
				case 3: viewlist();
					break;
				
				case 4:custmain();
					break;
										
				case 5: printf("\n\n\n\t\tTHANK YOU...........!!\n\n\n");
					exit(1);
        				break;

				case 6: adminmenu();
					break;

				default : printf("\n Invalid Input");
			}
			printf("\n\n1.Press 4 go back\n2.press 6 to go in  main_nmenu\n");
			scanf("%d",&ch); 
			system("clear");
		}while(ch == 4);
	}


void adminmenu()
{
		int option,c,ep,chh,ans ,ch;
		do
		{
		printf("\n\n\t\tWELCOME TO CAR SHOWROOM MANAGEMENT SYSTEM\n\n");
		printf("1.Employee records\n\n");
		printf("2.Car records\n\n");
		printf("3.Customer records\n\n");
		printf("4.Exist\n\n");
		printf("\nPlease enter your Choice:");
			scanf("%d",&option);
		system("clear");
		switch(option)
			{
				case 1: empmain();
					break;
				case 2: carmain();
					break;
				
				case 3: custmain();
					break;
				case 4: printf("\n\n\n\t\tTHANK YOU......!!!\n\n\n");
						exit(1);
				default : printf("\n Invalid Input");
			}
			
		}while(option != 4);

}


void usermenu()
{
		int optionn,ep,c,chh,ans,ch;
		do
		{
		printf("\n\n\t\tWELCOME TO CAR SHOWROOM MANAGEMENT SYSTEM\n\n");
		printf("1. Display Employee records\n\n");
		printf("2. Display Customer records\n\n");
		printf("3. Customer search\n\n");
		printf("4. Display Car records\n\n");
		printf("5. Car search\n\n");
		printf("7. Exist\n\n");
		printf("\nPlease enter your Choice:");
		scanf("%d",&optionn);
		system("clear");
		switch(optionn)
			{
				case 1: view_list();
					break;
				case 2: viewlist();
					break;
	
				case 3:search_customer();
					break;
				
				case 4: ep = empty();
					if (ep == 0)
					printf("\nThe file is EMPTY\n");
					else
					disp();
					break;
				case 5:
					search();
					break;
				case 6: usermenu();
					break;
				case 7: printf("\n\n\n\t\tThank Tou....!!!\n\n");
					exit(1);
	
				default : printf("\n Invalid Input");
		 }
		 printf("\n\n1.Press 6 to go back\n2.press 7 to exit  :");
			scanf("%d",&optionn); 
			system("clear");
			
		}while(optionn == 6);

}

int main()
{    
	system("clear");
        char pass[10],password[10]="adminpass",para[10]="userpass";
        int i=0;

	 printf("\n\t\tCAR SHOWROOM MANAGEMENT SYSTEM\n");	
         printf("\n\t\tEnter the password to login:");
         scanf("%s",pass);
    
         if (strcmp(pass,password)==0)
	        {
		printf("\n\nPassword Match!\n");
   		system("clear");
		adminmenu();
		}
	else if
		(strcmp(pass,para)==0)
	        {
		printf("\n\nPassword Match!\n");
	        system("clear");
	          usermenu();
		            
          	}
	else
	        {  
		printf("\n\nWrong password!!");
	        do{
			int main_exit;
		        printf("\nEnter 1 to try again and 0 to exit:");
		        scanf("%d",&main_exit);
		        if (main_exit==1)
		                {

		                    system("clear");
		                    main();
		                }

		        else if (main_exit==0)
		                {
		                system("clear");
		                exit(1);}
		        else
		                {
				printf("\nInvalid Option Selected...! Try Again");
		                system("clear");
		                }
			}while(1);
		    }
	return 0;
}

