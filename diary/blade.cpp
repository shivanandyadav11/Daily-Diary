#include <windows.h>
#include "mmsystem.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
using namespace std;
class diary
{    
  char place[100],note[500000],note1[500000],time[20],time1[20];
  double date,date1;
	 public:
	 	void input()       //To input information
	 	{    
	 		cout<<"\n\n\n\n              Enter the Date(2017) in this format only 01.01  ";
	 		PlaySound(TEXT("e_date.wav"),NULL,SND_SYNC);
	 		cin>>date;
	 		fflush(stdin);
	 		cout<<"\n\n                Enter time in this format 00.00(am/pm)  ";
	 		PlaySound(TEXT("e_time.wav"),NULL,SND_SYNC);
	 		cin.getline(time,20);
	 		fflush(stdin);
	 		cout<<"\n\n                Enter place  ";
	 		PlaySound(TEXT("p.wav"),NULL,SND_SYNC);
	 		cin.getline(place,100);
	 		fflush(stdin);
	 		cout<<"\n\n                Write your note in diary  ";
	 		PlaySound(TEXT("e_note.wav"),NULL,SND_SYNC);
	 		cin.getline(note,500000);
	 		fflush(stdin);
		 }
		 void display() //To display particular information
		 {
		 	cout<<"\n\n";
		 	cout<<"     "<<date<<".2017"<<"                                                                      "<<time<<"\n\n";
		 	cout<<"                                              "<<place<<"\n\n\n\n\n";
		 	cout<<note<<"\n\n";
		 	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
		 	cout<<"------------------------------------------------------------------------------------------------------------------------\n";
		 	cout<<"\n\n";
		 	getch();
		 }
		  void complete_display() //To display complete information
		 {
		 	cout<<"\n\n";
		    cout<<"     "<<date<<".2017"<<"                                                                       "<<time<<"\n\n\n";
		 	cout<<"                                             "<<place<<"\n\n\n\n\n";
		 	cout<<note<<"\n\n";
		 	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
		 	cout<<"-----------------------------------------------------------------------------------------------------------------------";
		 	cout<<"\n\n";
		 	getch();
		 }
		 void modify()      //To input information for modification in daily diary
	 	{    
	 		cout<<"\n\n\n                  Enter the Date(2017) in this format only 01.01  ";
	 		PlaySound(TEXT("e_date.wav"),NULL,SND_SYNC);
	 		cin>>date;
	 		fflush(stdin);
	 		cout<<"\n\n\n                  Enter modified time in this format 00.00(am/pm)  ";
	 		PlaySound(TEXT("e_time.wav"),NULL,SND_SYNC);
	 		cin.getline(time,20);
	 		fflush(stdin);
	 		cout<<"\n\n\n                  Enter modified place  ";
	 		PlaySound(TEXT("p.wav"),NULL,SND_SYNC);
	 		cin.getline(place,100);
	 		fflush(stdin);
	 		cout<<"\n\n\n                  Write your modified note in diary.";
	 		PlaySound(TEXT("mod_note.wav"),NULL,SND_SYNC);
	 		cin.getline(note,500000);
	 		fflush(stdin);
		 }
		 
		 void reminder()
		 {
		 	cout<<"\n\n\n\n              Enter the Date(2017) in this format only 01.01  ";
		 	PlaySound(TEXT("e_date.wav"),NULL,SND_SYNC);
	 		cin>>date1;
	 		fflush(stdin);
	 		cout<<"\n\n                Enter time in this format 00.00(am/pm)  ";
	 		PlaySound(TEXT("e_time.wav"),NULL,SND_SYNC);
	 		cin.getline(time1,20);
	 		fflush(stdin);
	 		cout<<"\n\n                Add reminder  ";
	 		PlaySound(TEXT("add_rem.wav"),NULL,SND_SYNC);
	 		cin.getline(note1,500000);
		 }
		  void rem_show()
		  {
		  	cout<<"\n\n";
		  	cout<<"                                              ..........REMINDER..........\n\n\n\n";
		    cout<<"     "<<date1<<".2017"<<"                                                                       "<<time1<<"\n\n\n";
		 	cout<<note1<<"\n\n";
		 	cout<<"-----------------------------------------------------------------------------------------------------------------------\n";
		 	cout<<"-----------------------------------------------------------------------------------------------------------------------";
		 	cout<<"\n\n";
		 	getch();
		  }
		  
		 double return_date() // It returns the date which is entered.
		 {
		 	return date;
		 }
		 

};

//function declerations.

void enter_info();                 //function declered for information

void view_info(double);           //function declered for viewing particular information

void modify(double);             //function declered  for modifying information

void remove(double);            //function declered for removing information

void view_comp();              //function declared for seeing complete information of diary

void diary_information();      //function declared to show the information about diary.

void add_reminder();          //function declared to add content in reminder

void show_reminder();         // function to show reminder

//enter information

void enter_info()
	 	{ 
		 diary obj;
		 ofstream write_file;
		 char choice ='y';
	 	  	write_file.open("diary007.dat",ios::binary|ios::app);
	 	  	while(choice=='y'|| choice=='Y')
	 	  {
	 	    obj.input();
	 	  	write_file.write((char*)(&obj), sizeof(diary));
	 	  	cout<<"\n\n\n                        Do you want to add another(y/n)  ";
	 	  	PlaySound(TEXT("d_want.wav"),NULL,SND_SYNC);
	 	  	cin>>choice;
		   }
		   write_file.close();
	 		
		 }
		 
		 
//view particular information

	 	void view_info(double dat)
	 	{   system("color 4f");
	 	    diary obj;
	 	    bool flag=false;
	 	    ifstream read_file;
	 	    read_file.open("diary007.dat",ios::binary);
	 	    if(!read_file)
	 	      {
		      cout<<"File could not be open.";
		       return;
	          }
	          while(read_file.read((char *)(&obj), sizeof(diary)))
	          {	
			  if(obj.return_date()==dat)
	          	{
	          	
	          		obj.display();
	          		flag=true;
		        } 
			  }
			  read_file.close();
	         if(flag==false)
	     	cout<<"\n\n                    Information does not exist";
	 	     getch();
		 }
		 
///modify information

	 	void modify(double dat)
	 	{
	 	 	bool f=false;
	 	 	diary obj;
	 	 	fstream m_file;
	 	 	m_file.open("diary007.dat",ios::binary|ios::in|ios::out);
	 	 	
	 	 	if(!m_file)
	 	 	{
	 	 		cout<<"file can not be open.";
	 	 		return;
			  }
			  while(!m_file.eof() && f==false)
	           {
	 		   m_file.read((char *) (&obj), sizeof(diary));
	 		   if(obj.return_date()==dat)
	 		   {
	 		   	obj.complete_display();
	 		   	cout<<"\n\n\n                      Make Changes in your Diary\n\n\n";
	 		   	obj.modify();
	 		   	double pos=(-1)*static_cast<double>(sizeof (diary));  // style cast to make it signed so that 
	 		   	m_file.seekg(pos,ios::cur);
	 		   	m_file.write((char *) (&obj), sizeof(diary));
	 		   	cout<<"\n\n\n                      Content changed successfully..\n";
	 		   	f=true;
	 		   	getch();
				}
	 		}
	 		m_file.close();
	 		if(f==false)
	 	    cout<<"\n\n\n                           record does not exist.\n";
		    getch();
	}

//remove information

void remove(double dat)
{
	system("color 4f");
	  diary obj;
	ifstream read_file;
	ofstream write_file;
	read_file.open("diary007.dat",ios::binary);
	if(!read_file)
	{
		cout<<"File could not be open ";
		return;
	}
	write_file.open("copy.dat",ios::binary);
	read_file.seekg(0,ios::beg);
	while(read_file.read((char *) (&obj), sizeof(diary)))
	{
		if(obj.return_date()!=dat)
		{
			write_file.write((char *) (&obj), sizeof(diary));
		}
	}
    read_file.close();
	write_file.close();
	remove("diary007.dat");
	rename("copy.dat","diary007.dat");
	cout<<"\n\n\tRecord Removed ..";
	getch();
}


//view complete information
	 	void view_comp()
	 	{   system("color 4f");
	 	    diary obj;
	 	    ifstream read_file;
	 	    read_file.open("diary007.dat",ios::binary);
	 	    if(!read_file)
	 	      {
		      cout<<"File could not be open ";
		       return;
	          }
	          while(read_file.read((char *) (&obj), sizeof(diary)))
	          {
	          		obj.complete_display();	
			  }
			  read_file.close();
		 }		 

//add reminder to new reminder file

void add_reminder()
	 	{ 
		 diary obj;
		 ofstream write_file;
		 char choice ='y';
	 	  	write_file.open("reminder1.dat",ios::binary|ios::app);
	 	  	while(choice=='y'|| choice=='Y')
	 	  {
	 	    obj.reminder();
	 	  	write_file.write((char*)(&obj), sizeof(diary));
	 	  	cout<<"\n\n\n                        Do you want to add another(y/n)  ";
	 	  	PlaySound(TEXT("d_want.wav"),NULL,SND_SYNC);
	 	  	cin>>choice;
		   }
		   write_file.close();
	 		
		 }
  
// show reminder

void show_reminder()
	 	{   system("color 4f");
	 	    diary obj;
	 	    ifstream read_file;
	 	    read_file.open("reminder1.dat",ios::binary);
	 	    if(!read_file)
	 	      {
		      cout<<"File could not be open ";
		       return;
	          }
	          while(read_file.read((char *) (&obj), sizeof(diary)))
	          {
	          		obj.rem_show();	
			  }
			  read_file.close();
			  getch();
		 }	

//diary introduction

void diary_information()
{
	 cout<<"\n\n\n                           ....PERSONAL DAILY DIARY....\n\n\n\n\n";
	 cout<<"                               Name - Shivanand \n\n\n";
	 cout<<"                               Address - house no 97,gorakhpur,Uttar Pradesh(273400).\n\n\n";
	 cout<<"                               Birthday - 23/July/1999\n\n\n";
	 cout<<"                               Email -1110shiva1110@gmail.com\n\n\n";
	 cout<<"                               Youtube channel -KnowTeq\n\n\n";
	 cout<<"                               Present Collage - Lovely Professional University\n\n\n\n\n\n";
	 cout<<"                               MISTAKES ARE THE PROOF THAT YOU ARE LEARNING\n\n";
	 PlaySound(TEXT("e_any.wav"),NULL,SND_SYNC);
     getch();
}



// main of class 

int main()
{
	char c='1';
	 int choice;
	 int counter=0;
	 int p;
	 double dat;
 char password[20]="12345";
	 char pass[20];
  int remi=1;    //It is for reminder 
  

while(1)
	{
		system("cls");
		system("color 4f");
			system("cls");
			fstream object1("pass.txt",ios::app);
	  ifstream object2("pass.txt");
	  cout<<"\n\n\n";
	  PlaySound(TEXT("dd.wav"),NULL,SND_SYNC);
		cout<<"                                                     DAILY DIARY";
        
		cout<<"\n\n\n\n\n\n\n\n";
		cout<<"                                             ENTER PASSWORD TO OPEN DIARY ";
    PlaySound(TEXT("password.wav"),NULL,SND_SYNC);
	  object1<<"12345"<<endl;     // default password //
		cout<<"\n\n\n\n                                               Password- ";
		cin>>pass;
      object2.seekg(0);
	  object2>>password;
	  object1.close();
	  object2.close();
	  if(strcmp(pass,password)==0)
	
		{
			system("cls");
			if(remi==1)
			{
			PlaySound(TEXT("per.wav"),NULL,SND_SYNC);	
			diary_information();
			system("cls");
			show_reminder();
			
	     	}
	     	remi=0;
			system("cls");
		switch(c)
        {
        	case '1':
        		{
        		
        			{
        				system("cls");
        				system("color 30");
        				cout<<"\n\n\n\n";
        				cout<<"                                                        DAILY DIARY";
        				cout<<"\n\n\n\n\n\n";
        				cout<<"                          1-Enter Information\n\n";
        				PlaySound(TEXT("info.wav"),NULL,SND_SYNC);
						cout<<"                          2-view  particular page\n\n";
        				PlaySound(TEXT("particular_page.wav"),NULL,SND_SYNC);
						cout<<"                          3-Modify Information\n\n";
						PlaySound(TEXT("modify_info.wav"),NULL,SND_SYNC);
        				cout<<"                          4-remove Information of page\n\n";                      
        				PlaySound(TEXT("remove.wav"),NULL,SND_SYNC);
						cout<<"                          5-Change password\n\n";
        				PlaySound(TEXT("change_password.wav"),NULL,SND_SYNC);
						cout<<"                          6-view complete pages\n\n";
        				PlaySound(TEXT("view_complete_info.wav"),NULL,SND_SYNC);
						cout<<"                          7-Add Reminder\n\n";
        				PlaySound(TEXT("add_reminder.wav"),NULL,SND_SYNC);
						cout<<"                          8-Exit\n\n\n\n";
        				PlaySound(TEXT("exit.wav"),NULL,SND_SYNC);
						cout<<"                          Enter Your Choice... ";
        				PlaySound(TEXT("choice.wav"),NULL,SND_SYNC);
						cin>>choice;
        				system("cls");//Clear screen
        				switch(choice)
        				{
        					
        					case 1:

        						{   
								system("cls");
        							cout<<"\n\n\n                    Enter Information\n";
        							system("color 1f");
        							enter_info();
								}
								break;//break case 1
							case  2:
								{ system("cls");
								system("color 2f");
        						
        							cout<<"\n\n\n               Enter date(2017) in this format only 01.01  ";
        						    cin>>dat;
        						    view_info(dat);
        						    
								}          
								break;//break case 2
								case 3:
									{
									system("cls");
									system("color 5f");
        							cout<<"\n\n\n               Enter date(2017) in this format only 01.01  ";
        						    cin>>dat;
        							modify(dat);
									}
									break;//break case 3
									case 4:
										{
									      system("cls");
									      system("color 6f");
									      cout<<"\n\n\n          Enter date(2017) in this format only 01.01  ";
        						          cin>>dat;
        							      remove(dat);
										}
										break;//break exit
										case 5:
											{
												system("cls");
												system("color 7f");
        							            cout<<"\n\n\n                Change password\n\n";
	                                              ofstream object("pass.txt");
		                                        cout<<"                        Enter new password: ";
												PlaySound(TEXT("n_pass.wav"),NULL,SND_SYNC); 
		                                         cin>>password;
		                                         object<<password<<endl;
		                                          object.close();
		                                         cout<<"password changed successfully\n";
		                                         PlaySound(TEXT("ch_pass.wav"),NULL,SND_SYNC);
		                                         PlaySound(TEXT("e_any.wav"),NULL,SND_SYNC);
		                                         getch();
												
											}
											break;
									       case 6:
							         	    {   
								                  system("cls");
							                      system("color 2f");
        						                  view_comp();
        						    
							               	 }          
								            break;//break case 6
								            case 7:
        					                   	{   
								                 system("cls");
        						                	cout<<"\n\n\n                    Add Reminder\n";
        						                	PlaySound(TEXT("add_rem.wav"),NULL,SND_SYNC);
        							               system("color 1f");
        						                       	add_reminder();
								                }
								break;//break case 1
								            
											case 8:
												{
								                 system("cls");
								                 system("color 9f");
								                 cout<<"\n\n\n\n\n\n";
        							             cout<<"                                                        Good Bye\n";
												 cout<<	"\n\n\n";
        							             cout<<"                                                       See You Soon";
        							             PlaySound(TEXT("b_exit.wav"),NULL,SND_SYNC);
        							             cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
												 exit(1);
												}
									
						}
					}
			
				}
				break;
				
        		
		}
     }
	else
	{
		if(counter==3)
	    {
		exit(1);
	    }
	    else
	    ++counter;
		cout<<"\n\n\n                      WRONG PASSWORD "<<endl;
		cout<<"\n\n                PRESS ANY KEY TO RE-ENTER PASSWORD ";
		getch();
	}
	
}
return 0;
}	

