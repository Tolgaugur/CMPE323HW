#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void display(const std::vector<T> &vec)
{
    for (auto &row : vec)
    {
        for (auto &col : row)
        {
            std::cout << col << "\t";
        }
        std::cout << std::endl;
    }
}

int unboundedKnapsack(const std::vector<int> &payment, const std::vector<float> &taskPortion, float totalTaskInHours)
{
    int n = payment.size();
    int n2 = taskPortion.size();

    int totalSize = n + n2;

    std::vector<std::vector<int>> dp(n, std::vector<int>(totalSize + 1, 0));

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 0;
    }

    for (int c = 0; c < totalSize + 1; c++)
    {
        dp[0][c] = int(c / taskPortion[0]) * payment[0];
    }

    int i, j;

    for (i = 1; i < n; i++)
    {
        for (j = 0; j < totalSize + 1; j++)
        {
            if (taskPortion[i] <= j)
            {
                dp[i][j] = std::max(dp[i - 1][j], payment[i - 1] + dp[i][j - taskPortion[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    display(dp);

    return dp[i][j];
}

int main()
{
    // std::vector<float> taskPortion = {0.5, 1, 1.5, 2, 2.5};
    // std::vector<int> payment = {100, 500, 800, 900, 1000};
    float totalTaskInHours = 8;
    std::vector<float> taskPortion = {1.0, 3.0, 4.0, 5.0};
    std::vector<int> payment = {15, 50, 60, 90};

    std::cout << unboundedKnapsack(payment, taskPortion, totalTaskInHours);

    return 0;
}