#include<bits/stdc++.h>
using namespace std;
int account_pointer = 7894;
class bank
{
	private:
		string name;
		int acc_no;
		int money;
		int balance;
		string pass;
		int ch;
		int i,n;
		
	public:
		bank(){
			balance = 0;
		}
		void bal(){
			cout<<"Balance is : "<<balance<<"\n";
		}
		bool check_user(int acc,string pas){
			if(acc_no == acc && pass == pas){
				return true;
			}else{
				return false;
			}
		}
		void create_user(string n,string pa){
			name = n;
			pass = pa;
			acc_no = account_pointer;
			cout<<"Note your Acc no : "<<account_pointer<<"\n";
			account_pointer++;
		}
		
		void deposit()
		{
			cout<<"How much amount you want to deposit : ";
			cin>>money;
			balance+=money;
			cout<<"Your balance is : "<<balance<<"\n";
		}
		
		void withdraw()
		{
			cout<<"How much amount you want to withdraw  ";
			cin>>money;
			if(money>balance)
			{
				cout<<"Insufficient balance";
			}
			else
			{
				balance-=money;
				cout<<"Remaining Balance : "<<balance<<"\n";
			}
		}			
};
int main()
{
	int kk = 0;
	bank b;
	bank user[kk];
	string name;
	int i;
	int acc;
	string pass;
	bool letcheck = false;
	int flag = 0;
	int flag2=0;
	int choice;
	while(1)
	{
		int ch;
		cout<<"\n\n------WELCOME TO SBI BANK ------\n\n";
		cout<<"what do you want \n \n 1) Login(already have an account) \n 2) Signup (New USer)\n 3) Exit";
		cout<<"\n Enter your choice : ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"enter your acc_no : ";
			cin>>acc;
			cout<<"enter your pass : ";
			cin>>pass;
			
			for(i = 0;i<kk;i++){
				letcheck = user[i].check_user(acc,pass);
				if(letcheck == true){
					cout<<"Login Successful\n";
					flag = 1;
					break;
				}else{
					continue;
				}
			}
			if(flag == 0){
				cout<<"Invalid User\n";
				continue;
			}
			if(flag == 1){
				while(1)
				{
				cout<<"1) Deposit \n 2) Withdrawl \n 3) Balance \n 4) Logout \n";
				cout<<"Enter Your Choice : ";
				cin>>choice;
				switch(choice)
				{
					case 1:
							user[i].deposit();
							break;
					case 2:
							user[i].withdraw();
						  break;
					case 3:
							user[i].bal();
							break;
					case 4:
							flag2=1;
							break;
					default :
						cout<<"Invalid choice\n";
						break;
				}
				if(flag2==1)
				{
					break;
				}
			}	
		}
		}
		else if(ch==2)
		{

			bank useri;
			cout<<"enter your name : ";
			cin>>name;
			cout<<"enter your pass : ";
			cin>>pass;
			useri.create_user(name,pass);
			user[kk] = useri;
			kk++;
		}
		else if(ch==3)
		{
			exit(1);
		}
		
	}
	return 0;
	
}