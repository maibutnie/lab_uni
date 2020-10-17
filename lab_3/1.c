#include <stdio.h>
#include <math.h>

int factorial(int n);
double get_row_element(int n);
double row_sum(double accuracy);

int main()
{
    double accuracy = 0;
    printf("Enter accuracy: ");
    scanf("%lf", &accuracy);
    if (accuracy < 0)
    {
        printf("Accuracy can be only positive!");
        return -1;
    }
    printf("%lf\n", row_sum(accuracy));

    return 0;
}


int factorial(int n)
{
    int ret = 1;
    for (int i = n; i > 0; i--)
        ret *= i;

    return ret;
}

double get_row_element(int n)
{
    return (1.0 / factorial(n));
}

double row_sum(double accuracy)
{
    double sum = 0;
    sum = get_row_element(1);
    for (int i = 2; fabs(get_row_element(i) - get_row_element(i - 1)) > accuracy; i++)
        sum += get_row_element(i);
    return sum;
}
