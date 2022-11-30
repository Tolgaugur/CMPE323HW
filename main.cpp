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
    std::cout << "[ ";
    for (const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void displayStruct(const std::vector<idProfit> &vec)
{
    for (auto &elem : vec)
    {
        std::cout << "Task portion ID: " << elem.id << " having length " << elem.taskLength << " hour(s) has a profit of " << elem.profit << " TL." << std::endl;
    }
}

void fillVectors(std::vector<int> &payments, std::vector<double> &taskLengths, std::vector<int> &ids, int taskLengthInHr)
{
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
    std::sort(idProfitVec.begin(), idProfitVec.end(), [](const idProfit &a, const idProfit &b)
              { return a.profit > b.profit; });
}

void maxProfit(const std::vector<idProfit> idProfitVec, const std::vector<int> ids, double taskLength)
{
    int totalGain = 0;
    int dayCount = 0;

    int length = taskLength * 2;

    bool isTaskDone = false;
    bool isNegative = false;

    // until taskLength is 0 get the max profit task
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
}

int main()
{
    double taskLength;
    std::cout << "Enter the assigned total task length (in half-hour(s)): ";
    std::cin >> taskLength;

    int taskLengthInHalfHours = taskLength * 2;

    std::vector<int> payments;
    std::vector<double> taskLengths;
    std::vector<int> ids;
    std::vector<idProfit> idProfit;

    fillVectors(payments, taskLengths, ids, taskLengthInHalfHours);
    calculateProfits(payments, taskLengths, ids, idProfit, taskLengthInHalfHours);

    std::cout << std::endl;

    sortProfits(idProfit, taskLengthInHalfHours);
    displayStruct(idProfit);

    maxProfit(idProfit, ids, taskLength);

    return 0;
}