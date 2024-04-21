#include<string>
#include<iostream>
#include<random>
#include<vector>
using namespace std;



class Savings_Account{ 
    static float intrest;
    const int ac_num;
    float bal;
    string name;

    public:
        static int global_ac_num;
        Savings_Account(string n, float b = 0):ac_num(global_ac_num){
            global_ac_num++;
            name = n;
            bal = b;
        }

        float withdraw(float amount){
            if(bal<amount){
                return 0;
            }
            else if(bal-amount>1000){
                bal = bal-amount;
                return amount;
            }
            else{
                return 0;
            }
        }

        float deposit(float amount){
            if (bal + amount<=100000){
                bal = bal+amount;
            }
            return bal;
        }

        void show(){
            cout<<"\nAccount holder : "<<name;
            cout<<"\nAccount number : "<<ac_num;
            cout<<"\nBalance : "<<bal;
        }

        float intrest_year(){
            return bal*intrest;
        }

        void info_row(){
            cout<<ac_num<<"\t"<<name<<"\t"<<bal<<"  +  "<<intrest_year()<<endl;
        }

        
};

int Savings_Account::global_ac_num = 100001;
float Savings_Account::intrest = 0.025;

int main(){
    default_random_engine generator;
    uniform_real_distribution<float> distribution(1000,100000);
    float rand_balance;
    vector<Savings_Account*> accounts;

    cout<<"Enter number of accounts to create : ";
    int n;
    cin>>n;
    string temp_name;
    cin.clear();
    for(int i=0;i<n;i++){
        rand_balance = distribution(generator);
        cout<<"Enter name for account number : "<<Savings_Account::global_ac_num<<"\n->";
        //fflush(stdin);
        if(i==0){
        cin.clear();
        cin.ignore(1);}
        getline(cin,temp_name);
        Savings_Account *dummy = new Savings_Account(temp_name,rand_balance);
        accounts.push_back(dummy);
    }

    cout<<"Ac num\tName\tBalance   Annual Intrest\n";
    for(int i=0;i<n;i++){
        accounts[i]->info_row();
    }

    for(int i=0;i<n;i++){
        delete accounts[i];
    }
}
