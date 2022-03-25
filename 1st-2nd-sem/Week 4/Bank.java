class Account {
    int id;
    String name;
    float bal;

    Account() {
        id = 001;
        name = "NN";
        bal = 0;
    }

    void withdraw(float mon) {
        if (bal < mon) {
            System.out.println("BALANCE INSUFFICIENT!!!");
        } else {
            bal = bal - mon;
            System.out.println("Money withdrawn: -" + mon);
        }
    }

    void deposit(float mon) {
        bal = bal + mon;
        System.out.println("Money deposited: +" + mon);
    }

    void dispbal() {
        System.out.println("Balance: " + bal);
    }
}

class Bank {
    float m;
    public static void main(String args[]) {
        Account a1 = new Account();
        a1.dispbal();
        a1.deposit(5000);
        a1.dispbal();
        a1.withdraw(1000);
        a1.dispbal();
    }
}