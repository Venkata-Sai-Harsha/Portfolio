abstract class Account {
    protected double balance;
    public Account(double balance) {
        this.balance = balance;
    }
    public abstract void deposit(double amount);
    public abstract void withdraw(double amount);
    public abstract double getBalance();
}

class SavingsAccount extends Account {
    public SavingsAccount(double balance) {
        super(balance);
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0){
            balance += amount;
        }
    }

    @Override
    public void withdraw(double amount) {
        if (amount > 0 && amount <= balance){
            balance -= amount;
        }else{
            System.out.println("Insufficient balance in SavingsAccount");
        }
    }

    @Override
    public double getBalance() {
        return balance;
    }
}

class CheckingAccount extends Account {
    private static final double OVERDRAFT_LIMIT = 1000;
    public CheckingAccount(double balance) {
        super(balance);
    }

    @Override
    public void deposit(double amount) {
        if (amount > 0){
            balance += amount;
        }
    }

    @Override
    public void withdraw(double amount) {
        if (balance - amount >= OVERDRAFT_LIMIT){
            balance -= amount;
        }else{
            System.out.println("Overdraft limit exceeded in CheckingAccount");
        }
    }

    @Override
    public double getBalance() {
        return balance;
    }
}

public class q2 {
    public static void main(String[] args) {
        Account savings = new SavingsAccount(5000.0);
        Account checking = new CheckingAccount(1500.0);
        System.out.println("Savings Account Transactions ");
        savings.deposit(200.0);
        savings.withdraw(300.0);
        System.out.println("Savings Balance: " + savings.getBalance());

        System.out.println("\nChecking Account Transactions");
        checking.deposit(100.0);
        checking.withdraw(600.0); 
        checking.withdraw(100.0); 
        System.out.println("Checking Balance: " + checking.getBalance());
    }
}
