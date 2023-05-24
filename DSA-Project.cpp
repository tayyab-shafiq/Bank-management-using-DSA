#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
	
	Node(int val)
	{
		data = val;
		next = NULL;
		prev = NULL;
		
	}
};
	// ****  Variables  **** // 
	Node* deposit = new Node(0);
	Node* withdraw = new Node(0);
	Node* amt_transfer = new Node(0);
	string acc_pin;
	string recv_card_num;	// receivers card Number 
	int pin_len = 0;
	int ran_acc_num;
	int ran_stan_num;
	int rec_num_len = 0;
	int choice;
	int w;
	int d;
	int amt;	// used in Transfer balance

class Intro
{
	public: 
	void intro()
	{
		string ls = "\n\n\n\n";
        string ts = "\t\t\t\t\t";
		
		cout<<"\n\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb WELCOME to DSA-ATM MACHINE \xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
    }
};

class ATM
{
		public:
			void Date_time()
			{
				time_t ttime = time(0);
				char* dt = ctime(&ttime);
				cout <<"\n\t\t\t\t\tDate & Time: " << dt << endl;
			}
		public:
			void card() // get Card from user
        	{
            	string ls = "\n\n\n";
            	string ts = "\t\t\t\t\t\t";
            

            	cout<<ls<<ts<<"========================="<<endl;
            	cout<<ts<<"*\tATM of DSA\t*"<<endl;
            	cout<<ts<<"========================="<<endl;

            	cout<<"\n\n"<<ts<<"Press <Enter> to Insert your Card: "<<endl;
            
        	}
        
        public:
        	void card_Pin() // get card pin of ONLY 4-digits 
        	{
        		if (cin.get() == '\n') 
				{
					cout<<"\n\n\t\t\t\t\t\tEnter your 4-digit Pin: "<<endl;
            		cin>>acc_pin; 
					
					system ("CLS");
					
				}
				else{
					cout<<"\n\n\tYour Card is Not Insert!"<<endl;
				}
			}
			
		public:
			void balanceEnquiry()
			{
				cout<<"\n\t\t\t\t\t```Your Current balance is: "<<deposit->data<<" ```"<<endl;
				
				if(deposit->data==0)
				{
					cout<<"\n\t\t\t\t```You have no Balance! Please Deposit some Amount``` "<<endl;
				}
			}
		
		public:
			void Withdraw()
			{
				cout<<"\n\t\t\tEnter Amount you want to Withdraw: "<<endl;
				cin>>w;
				withdraw->data = w;
			}
		public:
			void WithdrawTranscript()
        	{

            	system ("CLS");
            	cout<<"\t\t\t\t\t==============================="<<endl;
            	cout<<"\t\t\t\t\t\tMY BANK LIMITED"<<endl;
            	cout<<"\t\t\t\t\t================================="<<endl;
            	cout<<"\n\t\t\t\t\t\tCash Withdrawal"<<endl;
            	cout<<"\t\t\t\t\t\t***************"<<endl;
            
            	Random_Card_Num();
            	Random_Acc_Num();
            	Random_STAN_Num();
            	cout<<"\n\t\t\t\t\tTransaction Amount: PKR "<<withdraw->data<<endl;
            	cout<<"\n\t\t\t\t\tYour Current Balance is: PKR "<<deposit->data<<endl;

            	cout<<"\n\t\t\t\t\t================================="<<endl;
            	cout<<"\t\t\t\t\t================================="<<endl;
        	}
        	
        public:
        	void Deposit()
        	{
        		cout<<"\n\t\t\tEnter Amount you want to Deposit: "<<endl;
            	cin>>d;

            	deposit->data = deposit->data + d;
			}
		
		public:
			void DepositTranscript()
			{
				system ("CLS");
            	cout<<"\t\t\t\t\t==============================="<<endl;
            	cout<<"\t\t\t\t\t\tMY BANK LIMITED"<<endl;
            	cout<<"\t\t\t\t\t================================="<<endl;
            	cout<<"\n\t\t\t\t\t\tCash Deposit"<<endl;
            	cout<<"\t\t\t\t\t\t***************"<<endl;
            	
            	Date_time();	// date and time
            	
				Random_Card_Num();
            	Random_Acc_Num();
            	Random_STAN_Num();
            	cout<<"\n\t\t\t\t\tTransaction Amount: PKR "<<d<<endl;
            	cout<<"\n\t\t\t\t\tYour Current Balance is: PKR "<<deposit->data<<endl;

            	cout<<"\n\t\t\t\t\t================================="<<endl;
            	cout<<"\t\t\t\t\t================================="<<endl;
			}
			
		public:
			void Mini_Statement()
			{
				system ("CLS");
            	cout<<"\t\t\t\t\t==============================="<<endl;
            	cout<<"\t\t\t\t\t\tMY BANK LIMITED"<<endl;
            	cout<<"\t\t\t\t\t================================="<<endl;
            	cout<<"\n\t\t\t\t\t\tMINI STATEMENT"<<endl;
            	cout<<"\t\t\t\t\t\t***************"<<endl;
            
            	Date_time();
            	
				Random_Card_Num();
            	Random_Acc_Num();
            	Random_STAN_Num();
            	cout<<"\n\t\t\t\t\tFirst last Transaction: PKR "<<d<<endl;
            	cout<<"\n\t\t\t\t\tLast Transaction: PKR "<<withdraw->data<<endl;
            	cout<<"\n\t\t\t\t\tYour Current Balance is: PKR "<<deposit->data<<endl;

            	cout<<"\n\t\t\t\t\t================================="<<endl;
            	cout<<"\t\t\t\t\t================================="<<endl;
			}
		
		public:
			void Transfer_Balance()
			{
				cout<<"\n\t\t\tEnter Receiver's Account Number: "<<endl;
				cin>>recv_card_num;
				if(recv_card_num.length()==10)
				{
					cout<<"\n\t\t\tEnter Amount to transfer: "<<endl;
					cin>>amt;
					
					amt_transfer->data = amt;
					
					if(amt_transfer->data > deposit->data)
					{
						system ("CLS");
						cout<<"\n\t\t\t\t\tYou don't have Sufficient balance to Transfer"<<endl;
						
					}
					else if(amt_transfer->data <= deposit->data)
					{
						system ("CLS");
						cout<<"\n\t\t\tAmount Transfer Successfully!"<<endl;
						deposit->data = deposit->data - amt_transfer->data;
						
					}
				}
				else{
					cout<<"\n\t\t\tCard Number is Not Correct!"<<endl;
				}
			}
		
		public:
			void Random_Card_Num() {
    	
    			long long cardnumber = 1 + rand() % 9;
    	
    			for (int i = 1; i < 16; i++)
        		cardnumber = cardnumber * 10 + rand() % 10;
    			cout<<"\n\t\t\t\t\tYour Card Number: "<<cardnumber<<endl;
			}
		public:
			void Random_Acc_Num() {
    	
    			long long cardnumber = 1 + rand() % 9;
    	
    			for (int i = 1; i < 10; i++)
        		cardnumber = cardnumber * 10 + rand() % 10;
    			cout<<"\n\t\t\t\t\tAccount Number: "<<cardnumber<<endl;
			}
		public:
			void Random_STAN_Num() {
    	
    			long long cardnumber = 1 + rand() % 9;
    	
    			for (int i = 1; i < 6; i++)
        		cardnumber = cardnumber * 10 + rand() % 10;
    			cout<<"\n\t\t\t\t\tSTAN Number: "<<cardnumber<<endl;
			}
		
		public:
		void MainMenu()
		{
				if (acc_pin.length() == 4)
            {

                cout<<"\n\t\t\t\t\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\n\n";
                cout<<"\n\n\t\t\t\t\t||* WELCOME TO `DSA-ATM` *||"<<endl;
                cout<<"\n\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~  \n"<<endl;
                cout<<"\t\t\t\t\t1. For Balance Enquiry\n"<<endl;
                cout<<"\t\t\t\t\t2. For Cash Withdraw \n"<<endl;
                cout<<"\t\t\t\t\t3. For Cash Deposit\n"<<endl;
                cout<<"\t\t\t\t\t4. For Mini Statement\n"<<endl;
                cout<<"\t\t\t\t\t5. For Transfer balance\n"<<endl;
                cout<<"\t\t\t\t\t6. Exit\n"<<endl;
                cout<<"\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~ \n"<<endl;
                cout<<"\t\t\t\t\tPlease ENTER YOUR CHOICE : "<<endl;


            }
            else
            {
                cout<<"\n\n\tYour Card Pin is Not Correct!"<<endl;
                
            }
         	
			cin>>choice;
			
			do
            {
                switch (choice)
                {

                    case 1:
                        {

                            system ("CLS");
                            balanceEnquiry();
                            MainMenu();
                            break;
                        }

                        
                    case 2:
                        {
                            Withdraw();
                            if (withdraw->data % 100 != 0)
                            {
                            	system ("CLS");
                                cout<<"\n\t\t\t\t\tPlease Enter Amount `above or equal` to 100"<<endl;
                                
                            }
                            else if( withdraw->data > deposit->data)
                            {
                                cout<<"\n\t\t\t\t\tYour Account Balance is Insufficient !"<<endl;
                            }
                            else
                            {
                                deposit->data = deposit->data - withdraw->data;
                                WithdrawTranscript();
                            }
                            
                            MainMenu();
                            break;
                        }
                    case 3:
                        {
                            Deposit();
                            DepositTranscript();
                            MainMenu();
                            break;
                        }
                    case 4:
                        {
                            Mini_Statement();
                            MainMenu();
                            break;
                        }
                    case 5:
                        {
                            Transfer_Balance();
                            MainMenu();
                            break;
                        }


                }
            } while (choice != 6);
		}
};
int main()
{
	Intro i;
	i.intro();
	
	ATM a;
	a.card();
	a.card_Pin();
	a.MainMenu();
	return 0;
}
