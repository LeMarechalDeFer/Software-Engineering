
class BankAccount {
    private int balance;
    
    public BankAccount(int cash){
        balance = cash;
    }

    public int getBalance(){
        return(balance);
    }

    public void deposit(int amount){
        if(amount>0){
            balance += amount;
        }
        else{
            System.out.println("Error");
        }
        
    }
    
    public void withdrawal(int amount){
        if((balance-amount)>0 && amount>0){
            balance -= amount;
        }
        else{
            System.out.println("Error");
        }

    }

    // public static void main(String[] args){
    //     BankAccount ba = new BankAccount(100);
    //     ba.deposit(50);
    //     ba.withdrawal(-5);
    //     System.out.println(ba.getBalance());

    // }
}
