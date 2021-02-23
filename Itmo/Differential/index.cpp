#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <climits>

double f(double x, double y);
double runge_kutta(double x, double y, double h, std::function<double(double, double)> func);
void print_function(std::vector<double> x, std::vector<double> y);
double predictor(double x, double y, double h, double x_min2, double y_min2, double x_min3, double y_min3, double x_min4, double y_min4, std::function<double(double, double)> func);
double corrector(double x_plus1, double y_plus1, double h, double x, double y, double x_min1, double y_min1, double x_min2, double y_min2, std::function<double(double, double)> func);
double adams(double x, double y, double x_min1, double y_min1, double x_min2, double y_min2, double x_min3, double y_min3, double h, std::function<double(double, double)> func);
double integral(std::function<double(double)> func, double a, double b, int n);
double sequential_approximations(double y0, double y, double x);
double factorial(double n);
double sequential_approximation_precision(std::function<double(double, double)> func, std::vector<double> x, std::vector<double> y, double n, double h);

int main()
{
    double y0 = 1;
    int left_range_bound = 0;
    int right_range_bound = 1;
    double h = 0.1;
    std::vector<double> x;
    std::vector<double> y_runge;
    std::vector<double> y_predictor(11);
    std::vector<double> y_corrector(11);
    std::vector<double> y_adams(11);
    std::vector<double> y_sequential(11);

    for (double i = left_range_bound; i <= right_range_bound; i += h)
    {
        x.push_back(i);
        y_runge.push_back(y0);
        double y_next = runge_kutta(i, y0, h, f);
        y0 = y_next;
    }

    y_predictor[0] = y_runge[0];
    y_predictor[1] = y_runge[1];
    y_predictor[2] = y_runge[2];
    y_predictor[3] = y_runge[3];
    y_corrector[0] = y_runge[0];
    y_corrector[1] = y_runge[1];
    y_corrector[2] = y_runge[2];
    y_corrector[3] = y_runge[3];
    y_adams[0] = y_runge[0];
    y_adams[1] = y_runge[1];
    y_adams[2] = y_runge[2];
    y_adams[3] = y_runge[3];
    y_sequential[0] = 1;

    for (int i = 4; i < x.size(); i++)
    {
        y_predictor[i] = predictor(x[i - 1], y_predictor[i - 1], h, x[i - 2], y_predictor[i - 2], x[i - 3], y_predictor[i - 3], x[i - 4], y_predictor[i - 4], f);
    }

    for (int i = 3; i < x.size(); i++)
    {
        y_corrector[i] = corrector(x[i], y_predictor[i], h, x[i - 1], y_predictor[i - 1], x[i - 2], y_predictor[i - 2], x[i - 3], y_predictor[i - 3], f);
    }

    for (int i = 4; i < x.size(); i++)
    {
        y_adams[i] = adams(x[i - 1], y_adams[i - 1], x[i - 2], y_adams[i - 2], x[i - 3], y_adams[i - 3], x[i - 4], y_adams[i - 4], h, f);
    }

    for (int i = 1; i < x.size(); i++)
    {
        y_sequential[i] = sequential_approximations(1, y_sequential[i - 1], x[i - 1]);
    }

    std::cout << "Runge\n";
    print_function(x, y_runge);
    std::cout << "Predictor\n";
    print_function(x, y_predictor);
    std::cout << "Corrector\n";
    print_function(x, y_corrector);
    std::cout << "Adams\n";
    print_function(x, y_adams);
    std::cout << "Sequential approximation\n";
    print_function(x, y_sequential);
    std::cout << "Precision of approximation\n";
    std::cout << sequential_approximation_precision(f, x, y_sequential, 11, h) << "\n";

    return 1;
}

void print_function(std::vector<double> x, std::vector<double> y)
{
    std::cout << "X Y\n";
    for (int i = 0; i < x.size(); i++)
    {
        std::cout << x[i] << " " << y[i] << "\n";
    }
}

double f(double x, double y)
{
    return y * cos(x);
}

double runge_kutta(double x, double y, double h, std::function<double(double, double)> func)
{
    double k1 = func(x, y);
    double k2 = func(x + h / 2, y + h * k1 / 2);
    double k3 = func(x + h / 2, y + h * k2 / 2);
    double k4 = func(x + h, y + h * k3);

    return y + h / 6 * (k1 + 2 * k2 + 2 * k3 + k4);
}

double predictor(double x, double y, double h, double x_min2,
                 double y_min2, double x_min3, double y_min3,
                 double x_min4, double y_min4, std::function<double(double, double)> func)
{
    return y + h / 24 * (55 * func(x, y) - 59 * func(x_min2, y_min2) + 37 * func(x_min3, y_min3) - 9 * func(x_min4, y_min4));
}

double corrector(double x_plus1, double y_plus1, double h,
                 double x, double y, double x_min1, double y_min1,
                 double x_min2, double y_min2, std::function<double(double, double)> func)
{
    return y + h / 24 * (9 * func(x_plus1, y_plus1) - 19 * func(x, y) - 5 * func(x_min1, y_min1) + func(x_min2, y_min2));
}

double adams(double x, double y, double x_min1, double y_min1,
             double x_min2, double y_min2, double x_min3, double y_min3,
             double h, std::function<double(double, double)> func)
{
    double delta_f = func(x, y) - func(x_min1, y_min1);
    double delta_2f = func(x, y) - 2 * func(x_min1, y_min1) + func(x_min2, y_min2);
    double delta_3f = func(x, y) - 3 * func(x_min1, y_min1) + 3 * func(x_min2, y_min2) - func(x_min3, y_min3);

    return y + h * y + h * h / 2 * delta_f + 5 / 12 * h * h * h * delta_2f + 3 / 8 * h * h * h * h * delta_3f;
}

double integral(std::function<double(double)> func, double a, double b, int n)
{
    double step = (b - a) / n;
    double area = 0.0;

    for (int i = 0; i < n; i++)
    {
        area += func(a + (i + 0.5) * step) * step;
    }

    return area;
}

double sequential_approximations(double y0, double y, double x)
{
    return y0 +
           integral([y](double x) -> double { return y * cos(x); }, 0, x, 100);
}

double sequential_approximation_precision(std::function<double(double, double)> func,
                                          std::vector<double> x, std::vector<double> y,
                                          double n, double h)
{
    double func_max = INT64_MIN;
    double func_der_max = INT64_MIN;

    for (int i = 0; i < x.size(); i++)
    {
        double current_func_value = abs(func(x[i], y[i]));
        double current_func_der_value = abs(cos(x[i]));

        if (func_max < current_func_der_value)
        {
            func_max = current_func_der_value;
        }

        if (func_der_max < current_func_der_value)
        {
            func_der_max = current_func_der_value;
        }
    }

    return pow(func_der_max, n) * func_max * pow(h, n + 1) / factorial(n + 1);
}

double factorial(double n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}