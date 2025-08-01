 
#include<iostream>	// class 
#include<fstream>
#include<stdio.h>// header file
using namespace std;

class Account{
		private:
//when we write a word like this searchName is known as canel case
			string searchName,searchEmail,searchPassword;
			string userName,userEmail,userPassword;
		
		public:
			void signUp();
			void login();
			void forget();
				fstream f;
};

void Account::signUp()
{
	fflush(stdin);
	// it is used to clean buffer 
	cout<<"Enter the userName:";
		getline(cin,userName);
/*
	cin>>userName; 
	cout<<userName;
	if we use this then we can't get right output means that like 
	for example:- as "we enter in userName": "my name is kanika"
	then only it returns 'my' not entire sentence.
	so to handel this problem use getline function
	where we should tell in the bracks(cin,userName)it is 
	not compluasry to write always cin we should also
	write anything from which we should get the
	sentence or anything u write.it is basiclly used
	 for read data or jo ya userName  iski jgh or
	  kuch likh sakta h ya sirf isliya used kiya ja rha h so 
	  hm bta saka ki hma data kidhar store krna h read krna k baad
	*/

	//kidhar se read krna h or kidhar store krna h
	fflush(stdin);
	cout<<endl<<"Enter the userEmail:";
	getline(cin,userEmail);
	
	fflush(stdin);
	
	cout<<endl<<"Enter the userPassword:";
	getline(cin,userPassword);		
	// yha tk jo data h usko user se program me read kriaya
	
	f.open("Login.txt", ios::out | ios::app);
	//in this line we use two modes which are
	// out used for write and app used for append
	f<<userName<<"*";
	f<<userEmail<<"*";
	f<<userPassword<<"\n";	// * it is used to seprate
	//yha se data ko program se file me write krya
	f.close();	
}

void Account::login()
{
	 int found=0;
	fflush(stdin);
	cout<<"Enter your searchEmail:";		
	getline(cin,searchEmail);
	
	fflush(stdin);
	cout<<endl<<"Enter your searchPassword:";
	getline(cin,searchPassword);
	
	f.open("Login.txt", ios::in);			// yha data file se program me read kiya
	// in is used to read data from file

	// yha getline ma user is liya likha h kyuki hmara data database me is naam sa save h
	
	while(!f.eof())		//! agr yha not ka symbol nhi use krta tho ya program loop me jb
						// ata jb program end ho jata isliya ! not ka sybol use kra hmna
	{
			getline(f,userName,'*');
			getline(f,userEmail,'*');
			getline(f,userPassword);
			
//			cout<<userName<<endl;
//			cout<<userEmail<<endl;
//			cout<<userPassword<<endl;
		if(searchEmail==userEmail)
		{
			if(searchPassword==userPassword)
			{
				
				found=1;
				break;
			}
			
		}
		
	getline(f,userEmail);
	getline(f,userPassword);

//	agr hm isko asa likha ga tho ya 
//	hmko jitna bhi data save hoga uska
//	ek line me hi show kr dega isvgh
//	se program work nhi kra ga per agr
//	hm isma ek third argument add kr deta 
//	h tho vo in "*" doubleQuets me tho vo
//    error dega isliya hma usko singleQuet
//	me close krna pda ga so that vo uska
//	single charater ki trh use kr saka
	// yha ab jo bhi kiya usma hmna data
	// ko program se user k pass write kraya
	
//	getline(f,userName,'*');
//	getline(f,userEmail,'*');
//	getline(f,userPassword);
//	cout<<userName;
//	cout<<userEmail;
//	cout<<userPassword;
	}
	if(found==1)
			cout<<endl<<"You have sucessfully login";
		else
			cout<<"Wrong user id or password"<<endl;
	
}

void Account::forget()
{
		

	
		f.open("Login.txt", ios::in);
			fflush(stdin);	
		cout<<"Enter your searchName:";		
		getline(cin,searchName);
			getline(f,userName,'*');
			getline(f,userEmail,'*');
			getline(f,userPassword);
			
			if(searchName==userName)
			{
//					
							fflush(stdin);
							cout<<"Enter your searchEmail:";		
							getline(cin,searchEmail);
							
				if(searchEmail==userEmail)
				{
					cout<<userPassword;
				}
				else
				{
					cout<<"Wrong userEmail"<<endl;
				}
			}
			else{
				cout<<"Wrong userName"<<endl;
			}
		
	
}
int main()
{
	Account user1;
	int choice;
	do{
		

	cout<<"Enter 1: for SignUp"<<endl;
	cout<<"Enter 2: for Login"<<endl;
	cout<<"Enter 3: for Forgot Password"<<endl;
	cout<<"Enter 4: for Exit"<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
				user1.signUp();
				break;
				
		case 2:
				user1.login();
				break;
				
				case 3:
					user1.forget();
					break;
					case 4:
						cout<<"Exit"<<endl;
						break;
						default:
							cout<<"Wrong choice ,try again";
	}
		}while(choice!=4);


	
	return 0;
}


