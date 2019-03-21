#include <stdio.h>

/* this function takes no arguments, and returns an integer read 
 * from stdin
 */
int get_int()
{
    int var;

    scanf("%i", &var);

    return var;
}


/* Write a definition for main that reads in integers until the same
 * number is typed twice in a row.
 *
 * Modify the program so that it runs until the same number is typed
 * three times.
 *
 * Modify the program so that it first asks "How many in a row?" and
 * then run until a number is repeated that many times.
 *
 * ex:  expecting 3 in a row, the program would terminate after the
 * following sequence
 *        1 2 4 5 5 2 12 5 5 7 11 11 3 3 3
 *
 * Note: you don't need to store every value you've seen.
 */
int main(int argc, char **argv)
{

}
