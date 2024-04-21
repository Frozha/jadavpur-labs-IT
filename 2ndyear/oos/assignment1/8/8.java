abstract class Account {
    int accountNumber;
    static int nextaccountnumber = 100001;
    String holderName;
    float balance;

    Account(String name, float balance) {
        accountNumber = nextaccountnumber++;
        holderName = name;
        this.balance = balance;
    }

    void show() {
        System.out.println("Holder name : " + holderName);
        System.out.println("Account number : " + accountNumber);
        System.out.println("Balance : $" + balance);
        System.out.println("-------------------------------------");
    }
}

class SavingsAccount extends Account {
    static float intrestRate = 0.025f;

    float calculateYearlyIntrest() {
        return intrestRate * (super.balance);
    }

    static void updateIntrest(float newrate) {
        intrestRate = newrate;
    }

    SavingsAccount(String name, float balance) {
        super(name, balance);
    }

    @Override
    void show() {
        System.out.println("Yearly intrest : " + calculateYearlyIntrest());
        super.show();
    }
}

class CurrentAccount extends Account {
    CurrentAccount(String name, float balance) {
        super(name, balance);
    }
}

class Manager {
    Account[] accounts;
    int nextindex;
    int size;

    Manager(int numberofaccounts) {
        nextindex = 0;
        accounts = new Account[numberofaccounts];
        size = numberofaccounts;
    }

    void addSavingsAc(String name, float balance) {
        if (nextindex < size) {
            accounts[nextindex++] = new SavingsAccount(name, balance);
        }
    }

    void removeAc(int acnumber) {
        for (int i = 0; i < nextindex; i++) {
            if (accounts[i].accountNumber == acnumber) {
                accounts[i] = null;
                while (i < nextindex - 1) {
                    accounts[i] = accounts[i + 1];
                    i++;
                }
                accounts[i] = null;
                nextindex--;
                break;
            }
        }
    }

    void addCurrentAc(String name, float balance) {
        if (nextindex < size) {
            accounts[nextindex++] = new CurrentAccount(name, balance);
        }
    }

    void showall() {
        for (int i = 0; i < nextindex; i++) {
            accounts[i].show();
        }
    }
}

class Main {
    public static void main(String[] args) {
        Manager m = new Manager(5);
        m.addSavingsAc("hrithvik 1", 12000);
        m.addSavingsAc("hrithvik 2", 22000);
        m.addCurrentAc("hrithvik 3", 33000);
        m.addCurrentAc("hrithvik 4", 23000);
        m.addCurrentAc("hrithvik 5", 43000);
        m.showall();
    }
}

