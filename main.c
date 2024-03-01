#include<stdio.h>
#include<stdlib.h>

#define max_patients 100

struct patient{
	int patientid;
	char name[50];
	int age;
	char gender;
	char healthcompatibility[100];
};

struct patient patients[max_patients];
int numpatients = 0;

void clearscreen()
	{
	system("cls");	
	}
void clearinputbuffer()
	{
	 int c;
     while ((c = getchar()) != '\n' && c != EOF);
	}

void addpatient()
{
	printf("Patient ID : ");
	scanf("%d", &patients[numpatients].patientid);	
	
	printf("Patient Name : ");
	scanf("%s", &patients[numpatients].name);	
	
	printf("Patient Age : ");
	scanf("%d", &patients[numpatients].age);	

	printf("Patient Gender (M/F) : ");
	scanf(" %c", &patients[numpatients].gender);	
	
	printf("Patient Health Compatibility : ");
	scanf("%s", &patients[numpatients].healthcompatibility);

	clearinputbuffer();
	numpatients++;
	printf("Patient added successfully.\n");	
}

void viewpatient()
{
  int id;
  printf("Patient ID: ");
  scanf("%d", &id);

  int index = -1;
  for (int i = 0; i < numpatients; i++) {
    if (patients[i].patientid == id) {
      index = i;
      break;
    }
  }

  if (index != -1) {
    printf("Patient Information:\n");
    printf("ID: %d\n", patients[index].patientid);
    printf("Name: %s\n", patients[index].name);
    printf("Age: %d\n", patients[index].age);
    printf("Gender: %c\n", patients[index].gender);
    printf("Health Compatibility: %s\n", patients[index].healthcompatibility);
  } else {
    printf("Patient not found.\n");
  }
  
  printf("\nPress any key to continue...");
  getchar();  

  clearinputbuffer(); 
}


void displayallpatients()
{
	clearscreen();
	
	FILE *file = fopen("ALL_patients.txt", "w");
	if(file == NULL)
	{
		printf("Error opening file.\n");
		return ;
	}
	if(numpatients > 0)
	{
		fprintf(file,"All Paitents.\n");
		for(int i = 0; i < numpatients; i++)
		{
fprintf(file, "%d.ID : %d,\n  Name : %s\n  Age : %d\n  Gender : %c\n  HealthCompatibility : %s\n\n",i+1,patients[i].patientid, patients[i].name, patients[i].age, patients[i].gender, patients[i].healthcompatibility);
		}
	printf("Patient information added to All_patients.txt.\n");
	}
	else
	{
		fprintf(file, "No patients available.");
		printf("No patients available.\n");
	}
	fclose(file);

	printf("\nPress any key to continue...");
    getchar();
	
	clearinputbuffer();
}

void dischargepatient()
{

	clearscreen();
	if(numpatients > 0)
	{
		int id;
        	printf("Enter patient ID to discharge : ");
        	scanf("%d", &id);

		int index = -1 ;
		for(int i = 0; i < numpatients; i++)
		{
			if(patients[i].patientid == id)
			{
			index = i;
			break;
			}
		}
	 if (index != -1)
        {
            for (int i = index; i < numpatients - 1; i++)
            {
                patients[i] = patients[i + 1];
            }
            numpatients--;
            printf("Patient removed successfully.\n");
        }
        else
            {
            	printf("Patient with ID %d not found.\n", id);
            }
    	}
    else
    {
        printf("No patients available to remove.\n");
    }
	printf("\nPress Enter to continue...");
	getchar();

    clearinputbuffer();
}	

void savedata()
{
    clearscreen();
    FILE *file = fopen("patient_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < numpatients; i++)
    {
        fprintf(file, "Patient ID : %d, Name : %s, Age : %d, Gender : %c, Health Compatibility : %s\n",patients[i].patientid, patients[i].name, patients[i].age, patients[i].gender, patients[i].healthcompatibility);
    }
    fclose(file);

    printf("Data saved to patient_data.txt.\n");

    printf("\nPress Enter to continue...");
	getchar();

    clearinputbuffer();
}

void front()
{
    clearscreen();
    puts("  ");
    puts("  ");
    puts("  ");
    puts("  ");
    puts("  ");
    puts("\t\t\t\t\t\t\t\t***************************************");
    puts("\t\t\t\t\t\t\t\t*                                     *");
    puts("\t\t\t\t\t\t\t\t*                                     *");
    puts("\t\t\t\t\t\t\t\t*                                     *");
    puts("\t\t\t\t\t\t\t\t*\t\tWELCOME               *");
    puts("\t\t\t\t\t\t\t\t*                                     *");
    puts("\t\t\t\t\t\t\t\t*                                     *");
    puts("\t\t\t\t\t\t\t\t*                                     *");
    puts("\t\t\t\t\t\t\t\t***************************************");

    printf("\nPress Enter to continue...");
    clearinputbuffer();
    clearscreen();
}

void members()
{
    clearscreen();
    puts("  ");
    puts("  ");
    puts("  ");
    puts("  ");
    puts("\t\t\t\t\t\t\t\t         * * * * * * * * * *");
    puts("\t\t\t\t\t\t\t\t       *                     *");
    puts("\t\t\t\t\t\t\t\t      *     PROGRAMMING       *");
    puts("\t\t\t\t\t\t\t\t     *      FUNDAMENTALS       *");
    puts("\t\t\t\t\t\t\t\t    *                           *");
    puts("\t\t\t\t\t\t\t\t   *      SIR ZUBAIR UDDIN       *");
    puts("\t\t\t\t\t\t\t\t  *                               *");
    puts("\t\t\t\t\t\t\t\t *          PROJECT BY :           *");
    puts("\t\t\t\t\t\t\t\t*     CSC-23F-138_MUSHAHID_CS1C     *");
    puts("\t\t\t\t\t\t\t\t*     CSC-23F-148_MUFADDAL_CS1C     *");
    puts("\t\t\t\t\t\t\t\t *    CSC-23F-257_MUHAMMAD_CS1C    *");
    puts("\t\t\t\t\t\t\t\t  *                               *");
    puts("\t\t\t\t\t\t\t\t   *      DEPARTMENT OF          *");
    puts("\t\t\t\t\t\t\t\t    *     COMPUTER SCIENCE      *");
    puts("\t\t\t\t\t\t\t\t     *                         *");
    puts("\t\t\t\t\t\t\t\t      *     SECTION : CS1C    *");
    puts("\t\t\t\t\t\t\t\t       *                     *");
    puts("\t\t\t\t\t\t\t\t         * * * * * * * * * *");

    printf("\nPress Enter to continue...");
    clearinputbuffer();
    clearscreen();
}

void projectname()
{
    clearscreen();
    puts("  ");
    puts("  ");
    puts("  ");
    puts("  ");
    puts("  ");
    puts("\t\t\t\t\t\t\t\t******************************************");
    puts("\t\t\t\t\t\t\t\t*                                        *");
    puts("\t\t\t\t\t\t\t\t*                                        *");
    puts("\t\t\t\t\t\t\t\t*        HOSPITAL                        *");
    puts("\t\t\t\t\t\t\t\t*                MANAGEMENT              *");
    puts("\t\t\t\t\t\t\t\t*                          SYSTEM        *");
    puts("\t\t\t\t\t\t\t\t*                                        *");
    puts("\t\t\t\t\t\t\t\t*                                        *");
    puts("\t\t\t\t\t\t\t\t******************************************");

    printf("\nPress Enter to continue...");
    clearinputbuffer();
    clearscreen();
}
int main()
{
	front();
	members();
	projectname();
		
	int selection;	
	do
	{
	clearscreen();
	puts("  ");
        puts("  ");
        puts("  ");
        puts("  ");
        puts("  ");
        puts("  ");
        puts("  ");
        puts("  ");
        puts("\t\t\t\t\t\t\t\t***************************************");
        puts("\t\t\t\t\t\t\t\t*                                     *");
        puts("\t\t\t\t\t\t\t\t*                                     *");
        puts("\t\t\t\t\t\t\t\t*                                     *");
        printf("\t\t\t\t\t\t\t\t*\tMENU                          *\n");
        printf("\t\t\t\t\t\t\t\t*\t1. Add Patient                *\n");
        printf("\t\t\t\t\t\t\t\t*\t2. View Patient by ID         *\n");
        printf("\t\t\t\t\t\t\t\t*\t3. Display all Patients       *\n");
        printf("\t\t\t\t\t\t\t\t*\t4. Discharge Patient          *\n");
        printf("\t\t\t\t\t\t\t\t*\t5. Save Data                  *\n");
        printf("\t\t\t\t\t\t\t\t*\t6. Exit                       *\n");
        puts("\t\t\t\t\t\t\t\t*                                     *");
        puts("\t\t\t\t\t\t\t\t*                                     *");
        puts("\t\t\t\t\t\t\t\t*                                     *");
        puts("\t\t\t\t\t\t\t\t***************************************");
	
	printf("Make your selection : ");
	scanf("%d", &selection);
	
	switch(selection)
	{
	case 1 :
		clearscreen();
		addpatient();
		break;
	case 2 :
		clearscreen();
		viewpatient();
		break;
	case 3 :
		clearscreen();
		displayallpatients();
		break;
	case 4 :
		clearscreen();
		dischargepatient();
		break;
	case 5 :
		clearscreen();
		savedata();
		break;
	case 6 :
		clearscreen();
		printf("Exiting program...");
		break;	
	}
	}
	while(selection != 6);
	return 0;
}