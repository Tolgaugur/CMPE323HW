# CMPE323 Homework
## What was our aim? 
	
  Our aim was to generate a most profitable plan on daily basis to complete the given **N**
hour’s length task assigned to a worker an to compute how many days it takes to complete the assigned task with using dynamic programming approach. We first created a polynomial-time iterative algorithm to maximize the profit. Then we implemented the algorithm using c++. And tested it with some edge cases. Finally, we analyzed our algorithm’s time complexity and made descriptive comments about what we have done.

## Dyamic Programming Steps
**<a id="1">1</a>-** We first characterized the structure of an optimal solution by dividing the problem into subproblems. 
  -  A tasks portion, can be combined with the smaller task portions, according to their payment values and their portion lengths.
  -  For each day, only one portion of the task can be completed in only one working slot.
  
**<a id="2">2</a>.-** Then, we defined the value of an optimal solution iteratively.
  - We get the portion length as an input. Then, evaluated how many portion ID will be there by multiplying the portion length value by 2.
  - After considering how many portion IDs we will have, we get a payment value for each portion ID accordingly.
  - We computed each payment per half-hour values by portion IDs.
  - Then, we sorted each value by descending order in a vector.

**<a id="3">3</a>-** We computed the value of the optimal solution. 
  - We selected the most profitable portion length payment according to the sorted vector that we made in [Step 2](#2) 
  - Then, we subtracted the portion length from the inputted portion length as much as we can. If the most profitable portion length exceeds the remaining portion length, it will skip out to the next most profitable portion length value in the vector that can be subtracted from the remaining portion length.
  - For each subtraction operation that is done, it will increment the day count by one for the reason that is considered at [Step 1](#1)

**4-** Lastly, we constructed an optimal solution from the computed information in [Step 3](#3).
  - We outputted the required day to complete the most profitable completion of the assigned task and the task portions with their IDs to complete the task by daily basis.

---
This homework is completed by collaboration with [@Tolgaugur](https://github.com/Tolgaugur) and [@zeNn-G](https://github.com/zeNn-G)
