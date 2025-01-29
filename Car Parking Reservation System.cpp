#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int index=0;
 struct date
       {
       int day, month, year;
       };
struct car
       {
       
       int ID;
       char owner_name[20], owner_surname[20], make[20], model[20];
       struct date reg_date, ns_date; 
       }car_directory[100];

        int swap(int a,int b)
        {
                int temp=a;
                a=b;
                b=temp;
        }

void readFromFile()
{
	
	FILE *f;
	f=fopen("Data.txt","r");
	cout<<"Read from file";
	struct car c;
		
	index=-1;
	while(fscanf(f, "%d%s%s%s%s%d%d%d%d%d%d" ,&c.ID,c.owner_name,c.owner_surname,c.make,c.model,&c.reg_date.day,
	&c.reg_date.month,&c.reg_date.year,&c.ns_date.day,&c.ns_date.month,&c.ns_date.year)!=EOF)
	{
	
	index++;
	car_directory[index]= c;	
}
	fclose(f);
}


void add_Car ()
{
        FILE *f;
        char answer;
        char choice;
       if(index>99)
       {
               cout<<"The Parking area is full!"<<endl;
       }
       else{
               start:
                index++;
                f=fopen("Data.txt", "a+");
                cout<<"Please enter your Id: ";
                cin>>car_directory[index].ID;
                cout<<"Please enter your Name: ";
                cin>>car_directory[index].owner_name;
                cout<<"Please enter your Surename: ";
                cin>>car_directory[index].owner_surname;
                cout<<"Please enter the the car was Made: ";
                cin>>car_directory[index].make;
                cout<<"Please enter the the car Model: ";
                cin>>car_directory[index].model;
                cout<<"Please enter the Registeration date Day: ";
                cin>>car_directory[index].reg_date.day;
                cout<<"Please enter the Registeration date Month: ";
                cin>>car_directory[index].reg_date.month;
                cout<<"Please enter the Registeration date Year: ";
                cin>>car_directory[index].reg_date.year;
                cout<<"Please Enter next service date Day: ";
                cin>>car_directory[index].ns_date.day;
                cout<<"Please Enter next service date Month: ";
                cin>>car_directory[index].ns_date.month;
                cout<<"Please Enter next service date Year: ";
                cin>>car_directory[index].ns_date.year;
                fprintf(f,"\n %d   %s   %s   %s   %s   %d   %d   %d  %d   %d   %d",car_directory[index].ID,car_directory[index].owner_name,car_directory[index].owner_surname,car_directory[index].make,car_directory[index].model,car_directory[index].model,car_directory[index].reg_date.day,car_directory[index].reg_date.month,car_directory[index].reg_date.year,car_directory[index].ns_date.day,car_directory[index].ns_date.month,car_directory[index].ns_date.year);

                fclose(f);
                }

}

int search_car_by_ID(int searchByID)
{
        FILE *f;
        f=fopen("Data.txt", "r");
        for(int i=0; i<index; i++)
        {
                        if(searchByID==car_directory[i].ID)
                {
                        return i;
                }
                        return -1;
        }

        fclose(f);
}

int search_car_by_RY(int searchByRY)
{
        FILE *f;
        f=fopen("Data.txt", "r");
        for(int i=0; i<index; i++)
        {
                        if(searchByRY==car_directory[i].reg_date.year)
                {
                        return i;
                }
                        return -1;
        }

        fclose(f);
}

void delete_car()
{ 
        int deletcar;
        cout<<"Which car ID you want to Depart: ";
        cin>>deletcar;
        FILE *f;
        f=fopen("Data.txt", "w");
        for(int j=0; j<index; j++)
        {
                if(car_directory[j].ID==deletcar)
                  {
		
                         for(int i=0;i<index;i++)
                         {
                                  swap(car_directory[i].ID,car_directory[i+1].ID);
                                  strcpy(car_directory[i].owner_name,car_directory[i+1].owner_name);
                                  strcpy(car_directory[i].owner_surname,car_directory[i+1].owner_surname);
                                  strcpy(car_directory[i].make,car_directory[i+1].make);
                                  strcpy(car_directory[i].model,car_directory[i+1].model);
                                  swap(car_directory[i].reg_date.day,car_directory[i+1].reg_date.day);
                                  swap(car_directory[i].reg_date.month,car_directory[i+1].reg_date.month);
                                  swap(car_directory[i].reg_date.year,car_directory[i+1].reg_date.year);
                                  swap(car_directory[i].ns_date.day,car_directory[i+1].ns_date.day);
                                  swap(car_directory[i].ns_date.month,car_directory[i+1].ns_date.month);
                                  swap(car_directory[i].ns_date.year,car_directory[i+1].ns_date.year);
                          }
                  }
        }
        fclose(f);


}

void available_car()
{	
        for(int i=0; i<=index; i++)
	{
	cout<<car_directory[i].ID <<"\t"<<car_directory[i].owner_name<< "\t"<<car_directory[i].owner_surname<<"\t"<<car_directory[i].make
		<<"\t"<<car_directory[i].model<<"\t"<<car_directory[i].reg_date.day<<"\\"
		<<car_directory[i].reg_date.month<<"\\"<<car_directory[i].reg_date.year<<"\t"
		<<car_directory[i].ns_date.day<<"\\"<<car_directory[i].ns_date.month<<"\\"<<car_directory[i].ns_date.year<<"\t"<<endl;
	}

}

void update_car()
{
        int updatecar;
        FILE *f;
        cout<<"Please enter ID of the car information you want to update: ";
        cin>>updatecar;
        f=fopen("Data.txt", "a+");
        for(int i=0; i<index; i++)
        {
                if(updatecar==car_directory[i].ID)
                {
                        cout<<"Please enter your new Id: ";
                        cin>>car_directory[i].ID;
                        cout<<"Please enter your new Name: ";
                        cin>>car_directory[i].owner_name;
                        cout<<"Please enter your new Surename: ";
                        cin>>car_directory[i].owner_surname;
                        cout<<"Please enter the the car was Made: ";
                        cin>>car_directory[i].make;
                        cout<<"Please enter the the car Model: ";
                        cin>>car_directory[i].model;
                        cout<<"Please enter the Registeration date Day: ";
                        cin>>car_directory[i].reg_date.day;
                        cout<<"Please enter the Registeration date Month: ";
                        cin>>car_directory[i].reg_date.month;
                        cout<<"Please enter the Registeration date Year: ";
                        cin>>car_directory[i].reg_date.year;
                        cout<<"Please Enter next service date Day: ";
                        cin>>car_directory[i].ns_date.day;
                        cout<<"Please Enter next service date Month: ";
                        cin>>car_directory[i].ns_date.month;
                        cout<<"Please Enter next service date Year: ";
                        cin>>car_directory[i].ns_date.year;
                        fprintf(f,"\n %d   %s   %s   %s   %s   %d   %d   %d  %d   %d   %d",car_directory[i].ID,car_directory[i].owner_name,car_directory[i].owner_surname,car_directory[i].make,car_directory[i].model,car_directory[i].model,car_directory[i].reg_date.day,car_directory[i].reg_date.month,car_directory[i].reg_date.year,car_directory[i].ns_date.day,car_directory[i].ns_date.month,car_directory[i].ns_date.year);
                        cout<<endl<<endl<<"Your car information was UPDATED"<<endl<<endl;

                }
                        cout<<"there was not a car by this ID"<<endl;
        }

        fclose(f);




}

int main()
{
    int choice;
    int search_Type;
     char answer;
    system ( "cls" ) ;

	start:;
     system ( "cls" ) ;
     cout<<"____________________________________________________________________"<<endl;
     cout<<"********************************************************************"<<endl;
     cout<<"                 Car PARKING RESERVATION SYSTEM                 "<<endl;
     cout<<"1. Add a new car to directory"<<endl;
     cout<<"2. Delete a car from the directory"<<endl;
     cout<<"3. List available cars in the directory"<<endl;
     cout<<"4. Search a car: "<<endl;
     cout<<"5. Update car information"<<endl;
     cout<<"6. Sort according to car ID"<<endl;
     cout<<"7. Quit"<<endl;
     cout<<"____________________________________________________________________"<<endl;
     cout<<"********************************************************************"<<endl;
     cout <<"Enter your Choice : ";
        cin>>choice;
	do{
	
        switch(choice)
         {
             case 1: system ( "cls" ) ;
                     cout<<"Add a new Car: "<<endl<<endl;  
                     add_Car();
                      break;

             case 2: system ( "cls" ) ;
                     cout<<"Departure a Car: "<<endl;
                     delete_car();
                      break;

             case 3: system ( "cls" ) ;
                     cout<<"Available Cars: "<<endl;
                     available_car();
                     break;

             case 4:system ( "cls" ) ;

              		cout<<"Search for a Car (1 for for searching by ID /2 for searching by Registeration Year): ";
              		cin>>search_Type;
                     if(search_Type==1)
                     {
                        int result;
                     	int searchByID;
                        cout<<"Enter The ID: ";
                        cin>>searchByID;
                        result=search_car_by_ID(searchByID);
                        if(result>=0)
                        cout<<"The car is in the "<<result+1<<" index."<<endl;
                        else
                        cout<<"There is not a car By this ID."<<endl;
                        break;

                     }
                     else if(search_Type==2)
                     {
                        int result;
                     	int searchByRY;
                        cout<<"Enter the Registeration Year: ";
                        cin>>searchByRY;
                        search_car_by_RY(searchByRY);
                        if(result>=0)
                        cout<<"The car is in the "<<result+1<<" index."<<endl;
                        else
                        cout<<"There is not a car By this ID."<<endl;
                        break;
                     }
                     break;

             case 5: system ( "cls" ) ;
                      cout<<"Update a Car information "<<endl;
                      update_car();
                     break;
             case 6: system ( "cls" ) ;
                      cout<<"Sort the cars by ID: "<<endl;
                     break;     
             case 7:break;
             default: cout<<"Please Select from the menu!"<<endl;
}
         cout<<"\nDo you want to continue in this MENU, press y/n : "<<endl;
         cin>>answer;
         if(answer=='y')
         {
             continue;
         }
         else
         {
             goto start;
         }

}while(choice!=7);

}
