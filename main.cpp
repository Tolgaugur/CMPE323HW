#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void display(const std::vector<T> &vec)
{
    std::cout << "[ ";
    for (const auto &elem : vec)
        std::cout << elem << " ";
    std::cout << "]" << std::endl;
}

void unboundedKnapsack(const std::vector<float> &payment, std::vector<float> &halfPayments, std::vector<int> &days, int portion)
{
    int i = 0, max = 0, c = 0;

    int total = 0;
    int lastElement;

    // max elements index in halfPayments

    while (portion > 0)
    {
        max = *std::max_element(halfPayments.begin(), halfPayments.end());
        int index = std::distance(halfPayments.begin(), std::max_element(halfPayments.begin(), halfPayments.end()));
        lastElement = index + 1;

        days[i] = lastElement;

        halfPayments[index] = 0;
        portion -= lastElement;

        i++;
        c++;
        total += payment[lastElement - 1];

        std::cout << "Day " << c << " : " << days[i - 1] << " task portion(s) with payment value " << payment[lastElement - 1] << " TL" << std::endl;
    }
}

void fillPaymentVector(std::vector<float> &payments, int portion)
{
    float hour = 0.5;

    for (int i = 0; i < portion; i++)
    {
        int payment;

        std::cout << "Enter the payment value (in TL) for task portion ID " << i + 1 << " having length " << hour << " hour(s): ";
        std::cin >> payment;
        payments.push_back(payment);
        hour += 0.5;
    }
}

void fillHalfPaymentVector(std::vector<float> &halfPayments, const std::vector<float> &payments, int portion)
{
    for (int i = 0; i < portion; i++)
    {
        int half;
        half = payments[i] / (i + 1);

        halfPayments.push_back(half);
    }
}

int main()
{
    std::vector<float> halfPayments;
    std::vector<float> payments;
    std::vector<int> days = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int portion;
    float taskLength;

    std::cout << "Enter the assigned total task length (in half-hour(s)): ";
    std::cin >> taskLength;

    portion = taskLength * 2;

    fillPaymentVector(payments, portion);
    fillHalfPaymentVector(halfPayments, payments, portion);

    unboundedKnapsack(payments, halfPayments, days, portion);

    return 0;
}