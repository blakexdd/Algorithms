#include <iostream>
#include <vector>

class EquationSolver
{
public:
    static std::vector<double> gaussian(std::vector<std::vector<double>> A, std::vector<double> b)
    {
        int currentProcessingDimension = 0;
        int eps = 0.0001;

        while (currentProcessingDimension < A.size())
        {
            int rowWithMaxElementIdx = findIndexOfRowWithMaxElementForCurrentDimension(A,
                                                                                       A[currentProcessingDimension][currentProcessingDimension],
                                                                                       currentProcessingDimension, eps);
            swapRows(A, b, rowWithMaxElementIdx, currentProcessingDimension);
            normalizeEquations(A, b, currentProcessingDimension, eps);

            currentProcessingDimension++;
        }
        printEquationSystem(A, b);

        return backPropagation(A, b, currentProcessingDimension);
    }

    static std::vector<double> thomas(std::vector<std::vector<double>> A, std::vector<double> b)
    {
        std::vector<double> AComputed(A.size());
        std::vector<double> BComputed(A.size());

        thomasFrontStep(A, b, AComputed, BComputed);
        return thomasBackwardsStep(A, b, AComputed, BComputed);
    }

private:
    static int findIndexOfRowWithMaxElementForCurrentDimension(std::vector<std::vector<double>> A,
                                                               double currentMaxElement, int currentProcessingDimension, double eps)
    {
        int index = currentProcessingDimension;
        double max = currentMaxElement;

        for (int i = currentProcessingDimension + 1; i < A.size(); i++)
        {
            double nextMax = abs(A[i][currentProcessingDimension]);

            if (nextMax > max)
            {
                max = nextMax;
                index = i;
            }
        }

        return index;
    }

    static void swapRows(std::vector<std::vector<double>> &A, std::vector<double> &b, int index,
                         int currentProcessingDimension)
    {
        for (int i = 0; i < A.size(); i++)
        {
            swap(&A[currentProcessingDimension][i], &A[index][i]);
        }
        swap(&b[currentProcessingDimension], &b[index]);
    }

    static void normalizeEquations(std::vector<std::vector<double>> &A, std::vector<double> &b,
                                   int currentProcessingDimension, double eps)
    {
        for (int i = currentProcessingDimension; i < A.size(); i++)
        {
            double temp = A[i][currentProcessingDimension];

            // skip for zero coefficient
            if (abs(temp) < eps)
                continue;

            for (int j = 0; j < A.size(); j++)
                A[i][j] = A[i][j] / temp;

            b[i] = b[i] / temp;

            // skip self distraction
            if (i == currentProcessingDimension)
                continue;

            for (int j = 0; j < A.size(); j++)
                A[i][j] = A[i][j] - A[currentProcessingDimension][j];

            b[i] = b[i] - b[currentProcessingDimension];
        }
    }

    static void swap(double *a, double *b)
    {
        double *temp = a;
        a = b;
        b = temp;
    }

    static std::vector<double> backPropagation(std::vector<std::vector<double>> A,
                                               std::vector<double> b, int currentProcessingDimension)
    {
        std::vector<double> x(A.size());

        for (currentProcessingDimension = A.size() - 1; currentProcessingDimension >= 0; currentProcessingDimension--)
        {
            x[currentProcessingDimension] = b[currentProcessingDimension];
            for (int i = 0; i < currentProcessingDimension; i++)
                b[i] = b[i] - A[i][currentProcessingDimension] * x[currentProcessingDimension];
        }
        return x;
    }

    static void printEquationSystem(std::vector<std::vector<double>> A, std::vector<double> b)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A.size(); j++)
            {
                std::cout << A[i][j] << "*x" << j;
                if (j < A.size() - 1)
                    std::cout << " + ";
            }
            std::cout << " = " << b[i] << std::endl;
        }
        return;
    }

    static void thomasFrontStep(std::vector<std::vector<double>> A, std::vector<double> b,
                                std::vector<double> &AComputed, std::vector<double> &BComputed)
    {
        double y = A[0][0];
        AComputed[0] = -A[0][1] / y;
        BComputed[0] = b[0] / y;

        for (int i = 1; i < A.size() - 1; i++)
        {
            y = A[i][i] + A[i][i - 1] * AComputed[i - 1];
            AComputed[i] = -A[i][i + 1] / y;
            BComputed[i] = (b[i] - A[i][i - 1] * BComputed[i - 1]) / y;
        }
    }

    static std::vector<double> thomasBackwardsStep(std::vector<std::vector<double>> A, std::vector<double> b,
                                                   std::vector<double> &AComputed, std::vector<double> &BComputed)
    {
        int dimmension = A.size() - 1;
        std::vector<double> x(dimmension + 1);

        x[dimmension] = (b[dimmension] - A[dimmension][dimmension - 1] * BComputed[dimmension - 1]) /
                        (A[dimmension][dimmension] + A[dimmension][dimmension - 1] * AComputed[dimmension - 1]);

        for (int i = dimmension - 1; i >= 0; i--)
        {
            x[i] = AComputed[i] * x[i + 1] + BComputed[i];
        }

        return x;
    }
};

int main()
{
    int n;
    std::cout << "Dimension=";
    std::cin >> n;
    std::vector<std::vector<double>> A(n, std::vector<double>(n));
    std::vector<double> b(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << "A[" << i << "][" << j << "]=";
            std::cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << "b[" << i << "]=";
        std::cin >> b[i];
    }

    std::cout << "Gaussian method\n";
    std::vector<double> xGaussian = EquationSolver::gaussian(A, b);

    for (int i = 0; i < xGaussian.size(); i++)
    {
        std::cout << "x[" << i << "]=" << xGaussian[i] << std::endl;
    }

    std::cout << "\n";

    std::cout << "Thomas method\n";
    std::vector<double> xThomas = EquationSolver::thomas(A, b);
    for (int i = 0; i < xThomas.size(); i++)
    {
        std::cout << "x[" << i << "]=" << xThomas[i] << std::endl;
    }
}