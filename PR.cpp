#include <iostream>  
#include <string>
#include <cstdlib>  //for window shifting
#include <windows.h> //for handle console to add colours
using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);   //HANDLE datatype for adding colours

//STRUCTURES

 //struct for login portal
struct User{        
    string name;
    string password;
};

 //struct for subjects
struct subject {   
    int totaldays;
    int engpresent;
    int urdupresent;
    int mathspresent;
    int pfpresent;
};

 //struct for student details
struct Student {    
    int sapid;
    string name;
    int session;
    string department;
    subject sub;    //added other struct of subject
};

 //FUNCTIONS
 
  //function to add students
void addStudent(Student students[], int& count) {  //pass by reference

    if (count >= 10) {     //if condition to make the user enter uptil 10 students
    	SetConsoleTextAttribute(h, 12);
        cout << "\n** STUDENT VACANCY FULL **\n";  //output shown if students are equal or greater than 10
        return;
    }
    
    SetConsoleTextAttribute(h, 14);    //changes colour
    cout << "\n** ADD THE STUDENT DETAILS **\n";   //input being taken by user
    SetConsoleTextAttribute(h, 15);
    
    cout << "\nEnter the student SAP ID: ";    
    cin >> students[count].sapid;
    cin.ignore();
    cout << "Name: ";
    getline(cin, students[count].name);
    cout << "Session: ";
    cin >> students[count].session;
    cin.ignore();
    cout << "Department: ";
    getline(cin, students[count].department);
    
    SetConsoleTextAttribute(h, 14);
	cout<<"\n*** ADD STUDENT ATTENDANCE ***\n";  //input being taken by user
	SetConsoleTextAttribute(h, 15);
	
    cout << "\nEnter total number of days per subject: ";
	cin >> students[count].sub.totaldays;
	cout << "\nEnter number of days attended in English: ";
	cin >> students[count].sub.engpresent;
	cout << "Enter number of days attended in Urdu: ";
	cin >> students[count].sub.urdupresent;
	cout << "Enter number of days attended in Maths: ";
	cin >> students[count].sub.mathspresent;
	cout << "Enter number of days attended in Programming Fundamentals: ";
	cin >> students[count].sub.pfpresent;
    count++;
    
    SetConsoleTextAttribute(h, 10);
    cout << "\n*** DETAILS ADDED SUCCESSFULLY ***\n\n";  //output shown after successfully adding details
    SetConsoleTextAttribute(h, 15);
}

 //function to show students 
void showStudent(Student students[], int count) { //pass by value

	float eng,urdu,maths,pf;  //float to calculate individual attendance perecentages

	SetConsoleTextAttribute(h, 14);
    cout << "\n*** STUDENT DETAILS WITH ATTENDANCE ***\n\n";
    if (count == 0) {
    	SetConsoleTextAttribute(h, 12);  
        cout << "-- No student records found --\n";  //if count=0 that is no details entered for student then output of no details found shown
        SetConsoleTextAttribute(h, 15);
        return;
    }
    
    for (int i = 0; i < count; i++) {  //for loop used to find sapid to show details for that student
    	SetConsoleTextAttribute(h, 15);
        cout << "SAP ID: " << students[i].sapid << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Session: " << students[i].session << endl;
        cout << "Department: " << students[i].department << endl;
       
        if (students[i].sub.totaldays > 0) {  //only runs if total days greater than 0
        
            SetConsoleTextAttribute(h, 14); 
            cout << "\nAttendance percentages:\n " << endl;
            SetConsoleTextAttribute(h, 15); 
            
            cout << "Total Days per subject: " << students[i].sub.totaldays << endl;
            cout << "English Attendance: " << (eng = students[i].sub.engpresent * 100) / students[i].sub.totaldays << "%" << endl;
            cout << "Urdu Attendance: " << (urdu = students[i].sub.urdupresent * 100) / students[i].sub.totaldays << "%" << endl;
            cout << "Maths Attendance: " << (maths = students[i].sub.mathspresent * 100) / students[i].sub.totaldays << "%" << endl;
            cout << "Programming Fundamentals Attendance: " << (pf = students[i].sub.pfpresent * 100) / students[i].sub.totaldays << "%" << endl;
        } 
		else {
        	SetConsoleTextAttribute(h, 12);
            cout << "\nAttendance: Not entered yet.\n";   //shows error if no. of days is 0 or less
            SetConsoleTextAttribute(h, 15);
        }
        
        SetConsoleTextAttribute(h, 10);
        cout << "\n\n<><><><><><><><><><><><><><><><><><><><><><>\n\n";
        SetConsoleTextAttribute(h, 15);
    }
}

 //function to search students 
void searchStudent(Student students[], int count) {  //pass by value

	float eng,urdu,maths,pf; //float to calculate individual attendance perecentages
	SetConsoleTextAttribute(h, 14); 
	
    cout << "\n*** SEARCH THE STUDENT DETAILS ***\n\n";
    
    if (count == 0) {   //if count=0 that is no details entered for student then output of no details found shown
    	SetConsoleTextAttribute(h, 12);
        cout << "-- No search details found --\n";
        SetConsoleTextAttribute(h, 15);
    } 
    
	else {
        int id, d = 0;
        SetConsoleTextAttribute(h, 15);
        cout << "Enter the Student SAP ID: ";
        cin >> id;        //id asked by user
        
        for (int k = 0; k < count; k++) {  //for loop used to find sapid to show details for that student
        
        if (id == students[k].sapid) { //if entered id is equal to sapid then show details
        
            d++;
            cout << "\nName: " << students[k].name << endl;
            cout << "Session: " << students[k].session << endl;
            cout << "Department: " << students[k].department<< endl;
            
        if (students[k].sub.totaldays > 0) {
            SetConsoleTextAttribute(h, 14); 
            cout << "\nAttendance percentages:\n " << endl;
            SetConsoleTextAttribute(h, 15); 
            
            cout << "English Attendance: " << (eng = students[k].sub.engpresent * 100) / students[k].sub.totaldays << "%" << endl;
            cout << "Urdu Attendance: " << (urdu = students[k].sub.urdupresent * 100) / students[k].sub.totaldays << "%" << endl;
            cout << "Maths Attendance: " << (maths = students[k].sub.mathspresent * 100) / students[k].sub.totaldays << "%" << endl;
            cout << "Programming Fundamentals Attendance: " << (pf = students[k].sub.pfpresent * 100) / students[k].sub.totaldays << "%" << endl;
            
            SetConsoleTextAttribute(h, 10);
            cout << "\n*** SEARCH COMPLETED SUCCESSFULLY ***\n\n";  //output shown after successfully searching details
            SetConsoleTextAttribute(h, 15);
        }
        
        else {
        	SetConsoleTextAttribute(h, 12);
            cout << "\nAttendance: Not entered yet.\n";   //shows error if no. of days is 0 or less
            SetConsoleTextAttribute(h, 15);
        	
		}
        }
        }
        if (d == 0) {     //if d=0 that is above if condition doesnot run then error shown that detail not found
        	SetConsoleTextAttribute(h, 12);
            cout << "\n-- Student Details Not Found --\n";
            SetConsoleTextAttribute(h, 15);
        }
    }
}

 //function to update students 
void updateStudent(Student students[], int count) {  //pass by value

	SetConsoleTextAttribute(h, 14);
    cout << "\n*** UPDATE THE STUDENT DETAILS ***\n\n";
    if (count == 0) {  //if count=0 that is no details entered for student then output of no details found shown
    	SetConsoleTextAttribute(h, 12);
        cout << "-- No details found --\n";
        SetConsoleTextAttribute(h, 15);
    } 
	else {
        int id, s = 0;
        SetConsoleTextAttribute(h, 15);
        cout << "Enter the Student SAP ID: ";
        cin >> id;    //id asked by user
        cout << endl;
        
        for (int l = 0; l < count; l++) {  //for loop used to find sapid to update details for that student
        
            if (id == students[l].sapid) { //if entered id is equal to sapid then update details  
                SetConsoleTextAttribute(h, 14);
                cout << "\n*** ADD THE STUDENT DETAILS ***\n\n";
                SetConsoleTextAttribute(h, 15);  //when found then details updated by taking input by user
                cout << "Name: ";
                cin.ignore();
                getline(cin,students[l].name);
                cout << "Session: ";
                cin >> students[l].session;
                cin.ignore();
                cout << "Department: ";
                getline(cin,students[l].department);
                SetConsoleTextAttribute(h, 14);
            	cout<<"\n*** ADD STUDENT ATTENDANCE ***\n";  //input being taken by user
            	SetConsoleTextAttribute(h, 15);
                cout << "\nEnter total number of days per subject: ";
		       	cin >> students[l].sub.totaldays;
		       	cout << "\nEnter number of days attended in English: ";
		      	cin >> students[l].sub.engpresent;
		     	cout << "Enter number of days attended in Urdu: ";
		      	cin >> students[l].sub.urdupresent;
		     	cout << "Enter number of days attended in Maths: ";
		     	cin >> students[l].sub.mathspresent;
		     	cout << "Enter number of days attended in Programming Fundamentals: ";
		     	cin >> students[l].sub.pfpresent;
		     	
		     	SetConsoleTextAttribute(h, 10);
                cout << "\n*** STUDENT DETAILS UPDATED SUCCESSFULLY ***\n\n";  //output shown after successfully updating details
                SetConsoleTextAttribute(h, 15);
                s++;
            }
        }
        if (s == 0) {
        	SetConsoleTextAttribute(h, 12);
            cout << "\n-- Student Details Not Found --\n";  //if s=0 that is above if condition doesnot run then error shown that detail not updated
            SetConsoleTextAttribute(h, 15);
        }
    }
}

 //function to delete students 
void deleteStudent(Student students[], int& count) {   //pass by reference
	SetConsoleTextAttribute(h, 14);
    cout << "\n*** DELETE THE STUDENT DETAILS ***" << endl;
    
    if (count == 0) {  //if count=0 that is no details entered for student then output of no details found shown
    	SetConsoleTextAttribute(h, 12);
        cout << "-- No Search Details Found --\n";
        SetConsoleTextAttribute(h, 15);
    }
	else {
        int id, t = 0;
        SetConsoleTextAttribute(h, 15);
        cout << "\nEnter the Student SAP ID to delete: ";   //id asked by user
        cin >> id;
        
        for (int m = 0; m < count; m++) {  //for loop used to find sapid to delete details for that student
        
            if (id == students[m].sapid) { //if entered id is equal to sapid then delete details  
            
                for (int n = m; n < count - 1; n++) {  //for loop 
                    students[n] = students[n + 1];  //shift all students to one place left
                }
                count--; //last duplicate element removed by count also number of students reduced by 1
                t++;
                
                SetConsoleTextAttribute(h, 10);
                cout << "\n*** DELETED SUCCESSFULLY ***\n\n"; //output shown after successfully deleteing details
                SetConsoleTextAttribute(h, 15);
                break;
            }
        }
        if (t == 0) {
        	SetConsoleTextAttribute(h, 12);
            cout << "\n-- Student Details Not Found --\n"; //if t=0 that is above if condition doesnot run then error shown that detail not deleted
            SetConsoleTextAttribute(h, 15);
        }
    }
}

 //function to calculate overall percentage
void overallpercentage(Student students[],int count){  //pass by value
	SetConsoleTextAttribute(h, 14);
	cout<<"\n*** OVERALL PERCENTAGE ***\n" <<endl;
	
	 if (count == 0) {    //if count=0 that is no details entered for student then output of no details found shown
	 	SetConsoleTextAttribute(h, 12);
        cout << "-- No Details Found --\n";
        SetConsoleTextAttribute(h, 15);
    } 
	else {
        int id, f = 0;
        SetConsoleTextAttribute(h, 15);
        cout << "Enter the Student SAP ID: ";  //id asked by user
        cin >> id;
        
        for (int n = 0; n < count; n++) {   //for loop used to find sapid to find overall percentage for that
        
        if (id == students[n].sapid) { //if entered id is equal to sapid then calculate details  
             f++;
             cout << "\nName: " << students[n].name << endl;
             cout << "Session: " << students[n].session << endl;
             cout << "Department: " << students[n].department<< endl;
             
             if (students[n].sub.totaldays > 0) {
             float eng = (students[n].sub.engpresent * 100) / students[n].sub.totaldays;   //eng % calculated
             float urdu = (students[n].sub.urdupresent * 100) / students[n].sub.totaldays;   //urdu % calculated
             float maths =  (students[n].sub.mathspresent * 100) / students[n].sub.totaldays;   //maths % calculated
             float pf =  (students[n].sub.pfpresent * 100) / students[n].sub.totaldays;   //pf % calculated
             
             float totalattendance = (eng+urdu+maths+pf)/4;  //overall % calcualted
             
             SetConsoleTextAttribute(h, 10);
             cout << "\nOverall attendance percentage: " << totalattendance << "%" << endl;  //output shown after successfully finding overall percentage
             cout << "\n*** OVERALL ATTENDANCE DISPLAYED SUCCESSFULLY ***\n\n";  //output shown after successfully calculating percentage
             SetConsoleTextAttribute(h, 15);
		    }
		
		    else {
			SetConsoleTextAttribute(h, 12);
            cout << "\nAttendance: Not entered yet.\n";   //shows error if no. of days is 0 or less
            SetConsoleTextAttribute(h, 15);
		}
	}
}
if (f == 0) {
	        SetConsoleTextAttribute(h, 12);
            cout << "\n\n-- Student Detail Not Found --\n";  //if f=0 that is above if condition doesnot run then error shown that overall percentage not found
            SetConsoleTextAttribute(h, 15);
        }
}
}

//function to calculate overall percentage
void eligibility(Student students[],int count){  //pass by value
	SetConsoleTextAttribute(h, 14);
    cout<<"\n*** ELIGIBILITY ***\n" <<endl;
    
	 if (count == 0) {     //if count=0 that is no details entered for student then output of no details found shown
	 	SetConsoleTextAttribute(h, 12);
        cout << "-- No Details Found --\n";
        SetConsoleTextAttribute(h, 15);
    } 
	else {
    	int id, t = 0;
    	SetConsoleTextAttribute(h, 15);    	
        cout << "Enter the Student SAP ID: ";  //id asked by user
        cin >> id;
        
        for (int o = 0; o < count; o++) {  //for loop used to find sapid to calculate eligibility
        
            if (id == students[o].sapid) { //if entered id is equal to sapid then calculate details 
			t++; 
            cout << "\nName: " << students[o].name << endl;
            cout << "Session: " << students[o].session << endl;
            cout << "Department: " << students[o].department<< endl;
            
            if (students[o].sub.totaldays > 0) {
            float eng = (students[o].sub.engpresent * 100) / students[o].sub.totaldays;
            float urdu = (students[o].sub.urdupresent * 100) / students[o].sub.totaldays;
            float maths =  (students[o].sub.mathspresent * 100) / students[o].sub.totaldays;
            float pf =  (students[o].sub.pfpresent * 100) / students[o].sub.totaldays;
             
            float totalattendance = (eng+urdu+maths+pf)/4;
        
          		if(totalattendance>=75){
            	SetConsoleTextAttribute(h, 10);
            	cout << "\n You are eligible!" << endl;
            	SetConsoleTextAttribute(h, 15);
				}
    	  		else {
    	   		SetConsoleTextAttribute(h, 12);
    	   		cout << "\n You are not eligible!" << endl;
    	    	SetConsoleTextAttribute(h, 15);
				}
			SetConsoleTextAttribute(h, 10);
            cout << "\n*** ELIGIBILITY DISPLAYED SUCCESSFULLY ***\n\n";  //output shown after successfully showing eligibility
            SetConsoleTextAttribute(h, 15);
     	}       
	        else {
			SetConsoleTextAttribute(h, 12);
            cout << "\nAttendance: Not entered yet.\n";   //shows error if no. of days is 0 or less
            SetConsoleTextAttribute(h, 15);
		}
	        
    }
}
    
    if (t == 0) {
    	   SetConsoleTextAttribute(h, 12);
            cout << "\n\n-- Student Detail Not Found --\n";  //if o=0 that is above if condition doesnot run then error shown that student eligibilty not calculated
            SetConsoleTextAttribute(h, 15);
        }

}
}

//function for login
bool login(User users[], int size) {  
    string inputname, inputpass;
    
    SetConsoleTextAttribute(h, 14);
    cout << " Enter username: ";  //username and password asked by user
    cin >> inputname;
    cout << " Enter password: ";
    cin >> inputpass;
    
    for(int i = 0 ; i < size ; i++){   //for loop to check the name and password
    
        if (users[i].name == inputname && users[i].password == inputpass) {  //if both username and password are correct then login success shown
        
			SetConsoleTextAttribute(h, 10);
            cout<<" Login success!"<<endl;
            cout<<" Welcome to the portal "<<users[i].name<<"!"<<endl;   //personalized welcome message for user
            SetConsoleTextAttribute(h, 15);
            return true; //return true if login
        }
    }
    
    SetConsoleTextAttribute(h, 12);
    cout << " Login failed.\n";    //Login failed if any one of the entered details is wrong
	cout << " Username or password is incorrect\n";
    SetConsoleTextAttribute(h, 15);
    return false; //return falso if not log in
}


//main function
 int main(){
 	char select; //char for menu
 	Student students[10];  //students array for struct Student such that only 10 students to be entered
 	int studentCount = 0;  //initial students count = 0 

    SetConsoleTextAttribute(h, 5);
    cout << "\t\t\t\t\t><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><"<<endl;
    SetConsoleTextAttribute(h, 11);
 	cout << "\t\t\t\t\t**********************************************************************************************"<<endl;   
 	cout << "\t\t\t\t\t********************************* STUDENT ATTENDANCE SYSTEM **********************************"<<endl;   //Main portal design
 	cout << "\t\t\t\t\t*****************************| By Aroosa Feroz & Aleena Akhtar |******************************"<<endl;
 	cout << "\t\t\t\t\t**********************************************************************************************"<<endl;
 	SetConsoleTextAttribute(h, 5);
 	cout << "\t\t\t\t\t><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><"<<endl;
 	
 	SetConsoleTextAttribute(h, 14);
 	cout << "\n\n\n\t\t\t\t\t\t\t*****************--------- WELCOME ---------******************\n";  //welcome message
 	
 	mainmenu: //label for main menu
 	SetConsoleTextAttribute(h, 3);
 	cout << "\n\n\t\t\t\t\t\t\t\t----------------- MAIN MENU -----------------\n\n" << endl;  //main menu shown
 	
 	SetConsoleTextAttribute(h, 1);
 	cout << " ARE YOU TEACHER OR STUDENT?:"<<endl;  //asked by user to select teacher,student or exit
 	SetConsoleTextAttribute(h, 15);
 	cout << "\n a. TEACHER\n";
    cout << "\n b. STUDENT\n";
    cout << "\n x. EXIT\n";
    cout << endl;
    
    SetConsoleTextAttribute(h, 2);
      cout << " Select your Option -> ";
      cin >> select;   //option selected by user
      SetConsoleTextAttribute(h, 15);
      
    switch(select) {  //switch used for main menu
    
        //case a for teacher
        case 'A':
        case 'a': { 
        	User users[2] = {    //username and passwords for teachers i.e 2 teachers only
                   {"Hareem","111"},
                   {"Shazwa","111"}
				    };
				     SetConsoleTextAttribute(h, 7);
				     
				 int choice;
				     
		     	 system ("cls"); //new screen added
		     	 
                 cout << "\n\t\t\t\t\t\t\t\t     --- | WELCOME TO RIPHAH PORTAL | ---\n" << endl; //welcome shown
                 SetConsoleTextAttribute(h, 15);
                 cout << " Fill in the credentials for teacher in order to login:" << endl;
                 
                 bool loggedin = login(users, 2); //login function called such that the result of that function is equal to loggedin variable
                 
            if(loggedin){ //if bool loggedin is true i.e information is correctly entered then options shown to further proceed
                  while (1) { //infinite loop that keeps on running until 6 and 7 option is selected
            
            	SetConsoleTextAttribute(h, 11);
                cout << "\n\t\t\t\t\t\t\t\t    ||***********************************||";
                cout << "\n\t\t\t\t\t\t\t\t    ||************* TEACHER *************||";
                cout << "\n\t\t\t\t\t\t\t\t    ||***********************************||\n";  //teacher design
                SetConsoleTextAttribute(h, 6);
                
                cout << "\n 1. ADD STUDENT DETAILS";     //options shown to further perform indicated actions
                cout << "\n 2. SHOW STUDENT DETAILS";
                cout << "\n 3. SEARCH STUDENT DETAILS";
                cout << "\n 4. UPDATE STUDENT DETAILS";
                cout << "\n 5. DELETE STUDENT DETAILS";
                cout << "\n 6. BACK TO MAIN MENU";
                cout << "\n 7. EXIT\n\n";
                
                SetConsoleTextAttribute(h, 2);
                cout << "\nEnter Your Choice -> ";
                cin >> choice;
                SetConsoleTextAttribute(h, 15);
                
                cout << endl;
                
                switch (choice) {  //nested switch used for teacher's options
                    case 1:
                        addStudent(students, studentCount);  //function call to add students
                        break;
                    case 2:
                        showStudent(students, studentCount); //function call to show students
                        break;
                    case 3:
                        searchStudent(students, studentCount); //function call to search student
                        break;
                    case 4:
                        updateStudent(students, studentCount); //function call to update student details
                        break;
                    case 5:
                        deleteStudent(students, studentCount); //function call to delete student
                        break;
                    case 6:
                        goto mainmenu;   //if 6 selected then go to label mainmenu 
                        break;
                    case 7:
                    	system ("cls"); //new screen
 
            			SetConsoleTextAttribute(h, 5);
						cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> " << endl;  //Goodbye output
						SetConsoleTextAttribute(h, 9);
						cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t ----------------- GOODBYE -----------------"<< endl;
						SetConsoleTextAttribute(h, 5);
						cout << "\n\n\n\n\n\n\n\t\t\t\t\t <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> " << endl;
						SetConsoleTextAttribute(h, 15);
						exit(0);   //function call that immediately terminates the program (included in cstdlib header file).
						break;
						
                    default:
                    	SetConsoleTextAttribute(h, 12);
                        cout << "Invalid choice! Please try again.\n";   //if not selected from 1-6 then default error shown
                        break;
                }
            }
        }
        else {    //else i.e if loggedin is false then go to label mainmenu 
        	goto mainmenu;
		}
    }
    
        //case b for student
        case 'b':
        case 'B':{
        	User users[2] = {  //username and passwords for students i.e 2 students only
                   {"Aroosa","111"},
                   {"Aleena","111"}
				     };
				    
				 SetConsoleTextAttribute(h, 7);
				 
				 int choice;
				 
				 system ("cls"); //new screen added
				 
                 cout << "\n\t\t\t\t\t\t\t\t     --- | WELCOME TO RIPHAH PORTAL | ---\n" << endl; //welcome shown
                 SetConsoleTextAttribute(h, 15);
                 
                 cout << " Fill in the credentials for student in order to login" << endl;
                 
                bool loggedin=login(users, 2);
                
            if(loggedin){ //if bool loggedin is true i.e information is correctly entered then options shown to further proceed
        
        	while (1){ //infinite loop that keeps on running until 4 and 5 option is selected
        	   
        	   
                SetConsoleTextAttribute(h, 11);
                cout << "\n\t\t\t\t\t\t\t\t    ||***********************************||";
                cout << "\n\t\t\t\t\t\t\t\t    ||************* STUDENT *************||";     //student design
                cout << "\n\t\t\t\t\t\t\t\t    ||***********************************||\n";   
                SetConsoleTextAttribute(h, 6);

                cout << "\n 1. SEARCH MY ATTENDANCE";  //options shown to further perform indicated actions
                cout << "\n 2. SHOW OVERALL PERCENTAGE";
                cout << "\n 3. ELIGIBILITY CRITERIA";
                cout << "\n 4. BACK TO MAIN MENU";
                cout << "\n 5. EXIT";
                
                
                SetConsoleTextAttribute(h, 2);
                cout << "\nEnter Your Choice -> ";
                cin >> choice;
                SetConsoleTextAttribute(h, 15);
                cout << endl;
                
                switch (choice) {  //nested switch used for student's options
                	case 1:
                        searchStudent(students, studentCount);  //function call to search detail
                        break;
                    case 2:
                    	overallpercentage(students, studentCount);  //function call to find overall percentage
                    	break;
                    case 3:
                        eligibility(students, studentCount);   //function call to check eligibilty
                    	break;
                	case 4:
                        goto mainmenu;         //if 4 selected then go to label mainmenu 
                        break;
                    case 5:
                    	system ("cls"); //new screen
 
            			SetConsoleTextAttribute(h, 5);
						cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> " << endl;  //Goodbye output
						SetConsoleTextAttribute(h, 9);
						cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t ----------------- GOODBYE -----------------"<< endl;
						SetConsoleTextAttribute(h, 5);
						cout << "\n\n\n\n\n\n\n\t\t\t\t\t <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> " << endl;
						SetConsoleTextAttribute(h, 15);
						exit(0);  //function call that immediately terminates the program (included in cstdlib header file).
						break;
                    
                    default:
                    SetConsoleTextAttribute(h, 12);
                    cout << "\nInvalid choice! Please try again.\n";  //if not selected from 1-4 then default error shown
		        	break;
		}
	}
}
            else {   //else i.e if loggedin is false then go to label mainmenu 
        	    goto mainmenu;
		}
    }
    
    //case x to exit
    case 'X':
 	case 'x':{
 		
 	        system ("cls"); //new screen
 
            SetConsoleTextAttribute(h, 5);
			cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> " << endl;  //Goodbye output
			SetConsoleTextAttribute(h, 9);
			cout << "\t\t\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t ----------------- GOODBYE -----------------"<< endl;
			SetConsoleTextAttribute(h, 5);
			cout << "\n\n\n\n\n\n\n\t\t\t\t\t <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> " << endl;
			SetConsoleTextAttribute(h, 15);
			break;
		}
		
		
	//default
    default: {
            	SetConsoleTextAttribute(h, 12);
            cout << "\nInvalid choice! Please try again.\n";  //if not selected a,b or x then default error shown
            goto mainmenu;  //also program go to label mainmenu
		}
}
            SetConsoleTextAttribute(h, 15);
            
return 0;

}
