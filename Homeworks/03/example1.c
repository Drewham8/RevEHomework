#include <stdio.h>

struct Account {
    long long int number;
    double balance;
};

void deposit(struct Account *a, double amt)
{
  (*a).balance += amt;
  printf("  in deposit: %f\n", (*a).balance);
}

int main(int argc, char **argv)
{
    struct Account acct;    

    acct.number = 1;
    acct.balance = 0.0;

    printf("before deposit: %f\n", acct.balance);
    deposit(&(acct), 100);

    printf("after deposit: %f\n", acct.balance);
}
