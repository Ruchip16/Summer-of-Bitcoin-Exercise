# Summer-of-Bitcoin-Exercise

## Problem Statement:
  Bitcoin miners construct blocks by selecting a set of transactions from their mempool. Each transaction in the mempool:
- includes a fee which is collected by the miner if that transaction is included in a block
- has a weight, which indicates the size of the transaction
- may have one or more parent transactions which are also in the mempool

The miner selects an ordered list of transactions which have a combined weight below the maximum block weight.

Here, the total weight of transactions in a block must not exceed **4,000,000 weight.** 
*Assume that there is no coinbase transaction.*

### Note: A transaction may only appear in a block if all of its parents appear earlier in the block.

### To find : Maximum profit of a bitcoin miner

### Approach: My Intuition behind this problem:-

After doing a lot of brainstorming, I was able to connect this given problem with the 0/1 Knapsack Problem of Dynamic Programming but there were some errors and testcases where it failed hence I implemented it using Fractional Knapsack method in greedy approach

As we know, the conditions for applying fractional knapsack are:

1) In Fractional Knapsack we are not allowed to break items, we either take the whole item or discard it

   In Fractional Knapsack, we can break items for maximizing the total value of knapsack.
   
2) When we have to provide an Optimal Output. Eg:- Max Profit, Min Loss, largest value or a lowest value etc.

We have to fill our Knapsack in such a way that we have maximum profit & weight should be equal to the capacity of the knapsack 

**Steps to get the maximum profit of the knapsack:**

According to knapsack problem, we have to include that objects which have maximum profit 

1] I have used a set & I check if all the parent transactions are already present in the block or not. 

2] If above step is true, we include the transaction and update fee and weight and erase it from current set else we go to next higher transaction.


Now the question is but **Why we are applying Greedy Approach here?**

1) We have a choice of selecting a particular transaction I'd in such a way that it yields us the maximum total fee.

2) In this problem we have to obtain an optimal output i.e. the maximum total fee.

### Why particularly we are applying the 0/1 Knapsack approach?

1) In the knapsack problem we are given with 2 lists first one is the weight list of all items and secondly the profit list of all items. Similarly, here we  are given the weight column of all transaction ID's in the dataset which we'll be converting into the weight list and secondly the fee column which we'll be converting into the fee list.

So, 

1) Weight list of fractional Knapsack problem is equivalent to the weight list of all transaction ID's.

Profit list of fractional Knapsack problem is equivalent to the fee list of all transaction IDs.

2) Here weight of Knapsack bag is equivalent to 4,000,000 weight which we don't have to exceed.

3) Thirdly, in the fractional knapsack problem we have to find the maximum profit here we have to find the maximum total fee obtained.

### Approach 1:-  Recursion 

The Naive approach which I could think off here is through basic recursion, we can simply check if the selected transaction_id(txid) gives the maximum fee if it gives we 
select it else we have to find another maximum output i.e we can check if next iteration gives us or not and it continues until we reach the max fee

Consider In the following recursion tree, Knapsack() refers 
to knapSack(). 
The recursion tree is for following sample inputs.
wt[] = {1, 1, 1}, W = 2, val[] = {10, 20, 30}

![knapsack](https://user-images.githubusercontent.com/72685035/122101392-dc51cd80-ce31-11eb-8b73-90527fdd457a.png)

### Pseudo recursive code for given problem would be :

    knapSack(i, w)
    {
    
    if(weight==0 || parent_txids==0 ) return 0;
   
    if(txid[parent_txids] > W){
   
       knapSack(weight, fee, W, parent_txids);                                                                 // if parent transactions > given weight of knapsack
     }
   
    else if(txids[parent_txids] <= W){                                                                         // if parent transactions < given weight of knapsack 
   
      max(fee[parent_txids] + knapSack(weight,fee,W-weight[parent_txids],parent_txids), 
      knapSack(weight, fee, W, parent_txids)
    
    }
    W = knapSack(weight,fee,W,len(weight))
                                                                                                                            // W = maximum block weight
    }

### Time Complexity of Recursive Code would be : O(2^n)

### Space Complexity : O(1)

### Approach 2:- Fractional KnapSack (Greedy Approach)
As discussed above, we can implement this using **Greedy approach** classic problem **'Fractional KnapSack problem'**

Here is the output file :

![image](https://user-images.githubusercontent.com/72685035/123551998-d2b15980-d791-11eb-84a9-4eb62cd4b935.png)

### Code is in Fractional Knapsack.cpp & output in output.txt 
### Time Complexity : O(N^2)
### Space Complexity : O(1)

### References : geeksforgeeks
https://www.geeksforgeeks.org/fractional-knapsack-problem/
