#include <stdio.h>
#include <math.h>

void scan (double* x, char* message);

double function(double x);
double right_rectangle_integral(double a, double b, double accuracy);
double count_integral(double a, double b, double n);

int main() 
{
    double a, b, accuracy;

    scan(&a, "Enter start point: ");
    scan(&b, "Enter end point: ");
    scan(&accuracy, "Enter accuracy: ");

    if ((b - a) <= 0)
    {
        printf("Negative or zero section not allowed! \n");
        return -1;
    }

    if (accuracy <= 0)
    {
        printf("Negative or zero accuracy not allowed! \n");
        return -1;
    }

    printf("%lf\n", right_rectangle_integral(a, b, accuracy));
}

void scan (double* x, char* message)
{
    printf("%s", message);
    scanf("%lf", x);
}

double function (double x)
{
    return log(x);
}

double count_integral(double a, double b, double n)
{
    double h = (b - a) / n;
    double sum = 0;

    for (int i = 1; (a + h * i) <= b; i ++)
        sum += function(a + h * i);

    return (h * sum);
}

double right_rectangle_integral(double a, double b, double accuracy) 
{
    double I0 = accuracy + 1; // First integral
    double I1 = 0; // For next integral (steps * 2)

    for (int n = 5; fabs(I1 - I0) > accuracy; n *= 2) // Take 5 measures for start
    {
        I0 = I1;
        I1 = count_integral(a, b, n);
    }

    return I1;
}
