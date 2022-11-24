#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
void display(const vector<T> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << "\t";
        cout << endl;
    }
}

int main()
{
    int taskHalf = 5;
    int taskHour = 5;
    vector<double> taskPortionPayment = {100, 500, 800, 900, 1000};

    vector<vector<double>> table(taskHalf, vector<double>(taskHour, 0.0));

    for (int i = 0; i < taskHalf; i++)
    {
        table[i][i] = taskPortionPayment[i];
    }

    for (int i = 0; i < taskHalf; i++)
    {
        for (int j = i + 1; j < taskHalf; j++)
        {
            double max = 0;
            for (int k = i; k < j; k++)
            {
                double payment = table[i][k] + table[k + 1][j];

                if (payment > max)
                    max = payment;
            }
            table[i][j] = max;
        }
    }

    vector<vector<double>> idTable(taskHalf, vector<double>(taskHour, 0.0));

    for (int i = 0; i < taskHalf; i++)
    {
        idTable[i][i] = i + 1;
    }

    for (int i = 0; i < taskHalf; i++)
    {
        for (int j = i + 1; j < taskHalf; j++)
        {
            double max = 0;
            for (int k = i; k < j; k++)
            {
                double payment = table[i][k] + table[k + 1][j];

                if (payment > max)
                    max = payment;
                idTable[i][j] = k + 1;
            }
        }
    }

    int day = 1;
    int i = 0;
    int j = taskHalf - 1;
    while (i < j)
    {
        cout << "On day " << day << " do task with id " << idTable[i][j] << endl;
        i = idTable[i][j];
        day++;
    }

    cout << " Most profitable completion of the task takes " << day << " days " << endl;

    return 0;
}