#include <iostream>
#include <vector>
#include <algorithm>

struct idProfit
{
    int id;
    double taskLength;
    double profit;
};

template <typename T>
void display(const std::vector<T> &vec)
{
    //! Time complexity: O(n)
    std::cout << "[ ";
    for (const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void displayStruct(const std::vector<idProfit> &vec)
{
    //! Time complexity: O(n)
    for (auto &elem : vec)
    {
        std::cout << "Task portion ID: " << elem.id << " having length " << elem.taskLength << " hour(s) has a profit of " << elem.profit << " TL." << std::endl;
    }
}

void fillVectors(std::vector<int> &payments, std::vector<double> &taskLengths, std::vector<int> &ids, int taskLengthInHr)
{
    //! Time complexity: O(n)

    float hour = 0.5;
    int payment;

    for (int i = 0; i < taskLengthInHr; i++)
    {
        int id = i + 1;

        std::cout << "Enter the payment value (in TL) for task portion ID " << id << " having length " << hour << " hour(s): ";
        std::cin >> payment;

        payments.push_back(payment);
        taskLengths.push_back(hour);
        ids.push_back(id);

        hour += 0.5;
    }
}

void calculateProfits(const std::vector<int> payments, const std::vector<double> taskLengths, const std::vector<int> ids, std::vector<idProfit> &idProfitVec, int taskLengthInHr)
{
    //! Time complexity: O(n)
    for (int i = 0; i < taskLengthInHr; i++)
    {
        double profit = (double)payments[i] / (i + 1);

        idProfit idprofitstruct;
        idprofitstruct.id = ids[i];
        idprofitstruct.taskLength = taskLengths[i];
        idprofitstruct.profit = profit;

        idProfitVec.push_back(idprofitstruct);
    }
}

void sortProfits(std::vector<idProfit> &idProfitVec, int taskLengthInHr)
{
    //! Time complexity: O(nlogn)
    std::sort(idProfitVec.begin(), idProfitVec.end(), [](const idProfit &a, const idProfit &b)
              { return a.profit > b.profit; });
}

void maxProfit(const std::vector<idProfit> idProfitVec, const std::vector<int> ids, double taskLength)
{
    //! Time Complexity: O(n)

    int totalGain = 0;
    int dayCount = 0;

    int length = taskLength * 2;

    bool isTaskDone = false;
    bool isNegative = false;

    while (taskLength > 0)
    {
        for (int i = 0; i < length; i++)
        {
            if (idProfitVec[i].taskLength <= taskLength)
            {
                totalGain += idProfitVec[i].profit;
                taskLength -= idProfitVec[i].taskLength;
                isTaskDone = true;

                std::cout << "On day " << dayCount + 1 << " do the task with ID: " << idProfitVec[i].id << std::endl;
                break;
            }
        }

        if (isTaskDone)
        {
            dayCount++;
            isTaskDone = false;
        }
        else
        {
            isNegative = true;
            break;
        }
    }

    std::cout << "\nThe most profitable completion of the assigned task takes " << dayCount << " day(s)." << std::endl;
}

int main()
{
    double taskLength;
    std::cout << "Enter the assigned total task length (in half-hour(s)): ";
    std::cin >> taskLength;

    int taskLengthInHalfHours = taskLength * 2;

    std::vector<int> payments;       //! Vector to store the payment values
    std::vector<double> taskLengths; //! Vector to store the task lengths
    std::vector<int> ids;            //! Vector to store the task portion IDs
    std::vector<idProfit> idProfit;  //! Vector to store the task portion IDs, task lengths and profits

    fillVectors(payments, taskLengths, ids, taskLengthInHalfHours);                //! Fill the vectors with the given values
    calculateProfits(payments, taskLengths, ids, idProfit, taskLengthInHalfHours); //! Calculate the profits for each task portion

    std::cout << std::endl;

    sortProfits(idProfit, taskLengthInHalfHours); //! Sort the profits in descending order

    // displayStruct(idProfit);

    maxProfit(idProfit, ids, taskLength); //! Find the most profitable completion of the assigned task

    return 0;
}

//* Total time complexity: O(nlogn)