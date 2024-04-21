class BankAccount{
  private int accountnumber;
  private float balance;
  private String ownername;
  BankAccount(int accountnumber, float balance, String ownername){
    this.accountnumber = accountnumber;
    this.balance = balance;
    this.ownername = ownername;
  }
  
  public float balance(){
    System.out.println("balance of account "+accountnumber+" :" + ownername);
    System.out.println("\t"+balance);
    System.out.println("--------------------------------------");
    return balance;
  }

  public void add(float amount){
    balance+=amount;
  }

  public void subtract(float amount){
    if(balance<amount){
      System.out.println("Insufficient funds!");
    }
    else{
      balance-=amount;
    }
  }

  public boolean isacnum(int acnum){
    if(acnum==accountnumber){
      return true;
    }
    return false;
  }
}

class AccountManger{
  private BankAccount[] accounts;
  private int currentinsertindex;

  AccountManger(){
    accounts = new BankAccount[5];
    currentinsertindex =0;
  }

  public void showall(){
    System.out.println("=======================");
    for (int i = currentinsertindex-1;i>=0;i--){
      accounts[i].balance();
    }
  }
  
  public void create(int accountnumber, float balance, String ownername){
    if(balance<5000){
      System.out.println("Minimum balance = 5000/- !!");
    }
    else{
      boolean uniqueacnum = true;
      for(int i=currentinsertindex-1;i>=0;i--){
        if(accounts[i].isacnum(accountnumber)){
          uniqueacnum = false;
          break;
        }
      }
      if(uniqueacnum){
        accounts[currentinsertindex++] = new BankAccount(accountnumber,balance,ownername);
      }
      else{
        System.out.println("account already exists !!!");
      }
    }
  }

  public void delete(int accountnumber){
    for(int i = currentinsertindex-1;i>=0;i--){
      if(accounts[i].isacnum(accountnumber)){
        if(i!=currentinsertindex){
          while(i!=currentinsertindex-1){
            accounts[i] = accounts[i+1];
            i++;
          }
          accounts[i] = null;
          currentinsertindex--;
        }
        else{
          accounts[i] = null;
          currentinsertindex--;
        }
        break;
      }
    }
  }


  public void deposit(int accountnumber,float addbalance){
    for(int i = currentinsertindex-1;i>=0;i--){
      if(accounts[i].isacnum(accountnumber)){
        accounts[i].add(addbalance);
      }
    }
  }
  public void withdraw(int accountnumber, float amount){
    for(int i = currentinsertindex-1;i>=0;i--){
      if(accounts[i].isacnum(accountnumber)){
        accounts[i].subtract(amount);
      }
    }  
  }
    
}

class Bank{
  public static void main(String args[]){
    AccountManger mgr = new AccountManger();

    mgr.create(10001, 10000, "ravish kumar");
    mgr.create(10002, 12000, "nikhil gupta");
    mgr.create(10003, 7000, "amrish puri");
    mgr.create(10004, 60000, "shah rukh khan");
    mgr.create(10005, 20000, "narendra modi" );
    mgr.showall();

    mgr.deposit(10005, 300);
    mgr.withdraw(10001, 300);

    mgr.showall();

    mgr.delete(10003);
    
    mgr.showall();

  }
}

