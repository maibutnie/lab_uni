#include <stdio.h>
#include <math.h>

void scan (double* x, char* message);

double d_abs(double x);
double function (double x);
double simpson_integral(double a, double b, double accuracy);

int main() 
{
    double a, b, accuracy;

    scan(&a, "Enter start point: ");
    scan(&b, "Enter end point: ");
    scan(&accuracy, "Enter accuracy: ");

    if ((b - a) <= 0)
    {
        printf("Negative or zero section not allowed!");
        return -1;
    }

    if (accuracy <= 0)
    {
        printf("Negative or zero accuracy not allowed!");
        return -1;
    }

    printf("%lf\n", simpson_integral(a, b, accuracy));
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
    double h = (b - a) / (2 * n);
    double sum2 = 0;
    double sum4 = 0;
    double sum = 0;

    for (int i = 1; i <= 2 * n - 1; i += 2)
    {
        sum4 += function(a + h * i);
        sum2 += function(a + h * (i + 1));
    }

    sum = function(a) + 4 * sum4 + 2 * sum2 - function(b);

    return ((h / 3) * sum);
}

double simpson_integral(double a, double b, double accuracy) 
{
    double I0 = accuracy + 1; // First integral
    double I1 = 0; // For next integral (steps * 2)

    for (int n = 2; fabs(I1 - I0) > accuracy; n *= 2)
    {
  
        I0 = I1;
        I1 = count_integral(a, b, n);
    }

    return I1;
}
