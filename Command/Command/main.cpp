//
//  main.cpp
//  Command Design Pattern (Bank Account)
//
//  Created by Alexander Poletajev on 27/01/24.
//

#include <iostream>
#include <vector>
#include <sstream>

struct BankAccount {
    
    int balance{0};
    int overdraft_limit{-500};
    
    bool withdraw(int amount) {
        if (balance - amount >= overdraft_limit)
        {
            balance -= amount;
            std::cout << "withdrawing " << amount
            << ", balance is now " << balance << std::endl;
            return true;
        }
        else
        {
            std::cout << "withdrawing " << amount
            << " failed due to insufficient funds, balance is still " << balance << std::endl;
            return false;
        }
    }
    
    void deposit(int amount) {
        balance += amount;
        std::cout << "depositing " << amount << ", balance is now " << balance << std::endl;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& obj) {
        os << "balance is " << obj.balance << std::endl;
        return os;
    }
};

struct Command {
    bool succeeded{false};
    virtual void call() = 0;
    virtual void undo() = 0;
};

struct BankAccountCommand : Command {
    BankAccount& account;
    enum Action{deposit, withdraw} action;
    int amount{0};
    
    BankAccountCommand(BankAccount& account, Action action, int amount) : account(account), action(action), amount(amount){}
    
    virtual void call() override {
        
        switch (action) {
            case withdraw:
                succeeded = account.withdraw(amount);
                break;
            case deposit:
                account.deposit(amount);
                succeeded = true;
                break;
        }
    }
    
    virtual void undo() override {
        
        if (!succeeded)
            return;
        
        switch (action) {
            case withdraw:
                account.deposit(amount);
                break;
            case deposit:
                account.withdraw(amount);
                succeeded = true;
                break;
        }
    }
};


int main(int argc, const char * argv[]) {

    BankAccount account;
    std::vector<BankAccountCommand> commands
    {
        BankAccountCommand(account, BankAccountCommand::deposit, 100),
        BankAccountCommand(account, BankAccountCommand::deposit, 200),
        BankAccountCommand(account, BankAccountCommand::deposit, 300),
        BankAccountCommand(account, BankAccountCommand::withdraw, 10000),
    };
    
    for (auto& cmd : commands)
        cmd.call();
    
    for (auto it = commands.rbegin(); it != commands.rend(); ++it)
        it->undo();
    
    return 0;
}
