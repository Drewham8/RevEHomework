#include <stdio.h>

/* Create a function called swap, which will take two arguments.  The
 * function's job is to swap the values of two integer variables.
 *
 * I didn't give you the prototype, as coming up with the proper
 * pointer syntax for this is part of the exercise.  Look at how swap
 * is being called to get a clue about what the prototype should be.
 */

int main(int argc, char **argv)
{
    int num1, num2;

    printf("Enter two integers: ");
    scanf("%i%i", &num1, &num2);

    swap(&num1, &num2);

    printf("num1 = %i, num2 = %i\n", num1, num2);

    return 0;
}

void swap(int *a, int *b)
{

  int temp;
  temp = *a;
  *a = *b;
  *b = temp;

}
