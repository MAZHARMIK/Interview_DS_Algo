/*        Scroll below to see JAVA code also        */
/*
    MY YOUTUBE VIDEO IN THIS QN : 
    Company Tags                : will update later
    Leetcode Link               : https://leetcode.com/problems/simple-bank-system
*/


/***************************************************************** C++ *****************************************************************/
// Approach (Simple Simulation)
//T.C. : O(n) for Bank(), O(1) for withdraw(), transfer() and deposit()
//S.C. : O(n) for storing balance for each object
class Bank {
public:
    vector<long long> balance;
    int n;

    Bank(vector<long long>& balance) {
        n = balance.size();
        this->balance = balance;
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 > n || account2 > n || balance[account1-1] < money) {
            return false;
        }

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }
    
    bool deposit(int account, long long money) {
        if(account > n)
            return false;
        
        balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || balance[account - 1] < money)
            return false;
        
        balance[account - 1] -= money;
        return true;
    }
};




/***************************************************************** JAVA *****************************************************************/
// Approach (Simple Simulation)
//T.C. : O(n) for Bank(), O(1) for withdraw(), transfer() and deposit()
//S.C. : O(n) for storing balance for each object
class Bank {
    private long[] balance;
    private int n;

    public Bank(long[] balance) {
        this.balance = balance;
        this.n = balance.length;
    }

    public boolean transfer(int account1, int account2, long money) {
        if (account1 > n || account2 > n || balance[account1 - 1] < money) {
            return false;
        }

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    public boolean deposit(int account, long money) {
        if (account > n) {
            return false;
        }

        balance[account - 1] += money;
        return true;
    }

    public boolean withdraw(int account, long money) {
        if (account > n || balance[account - 1] < money) {
            return false;
        }

        balance[account - 1] -= money;
        return true;
    }
}
