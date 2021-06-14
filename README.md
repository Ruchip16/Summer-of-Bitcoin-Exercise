# Summer-of-Bitcoin-Exercise

## Problem Statement:
  Bitcoin miners construct blocks by selecting a set of transactions from their mempool. Each transaction in the mempool:
- includes a fee which is collected by the miner if that transaction is included in a block
- has a weight, which indicates the size of the transaction
- may have one or more parent transactions which are also in the mempool

The miner selects an ordered list of transactions which have a combined weight below the maximum block weight.

Here, the total weight of transactions in a block must not exceed **4,000,000 weight.** 
*Assume that there is no coinbase transaction.*

**Note** : A transaction may only appear in a block if all of its parents appear earlier in the block.

**To find**: Maximum total fee

**Approach** : My Intuition behind this problem:-

After doing a lot of brainstorming, I was able to connect this given problem with the 0/1 Knapsack Problem of Dynamic Programming.

As we know, in the problems we apply dynamic programming if 2 of these conditions meet:-

1) In 0/1 KnapSack we either include whole object or discard it there is no in between like Fractional KnapSack

2) When we have to provide an Optimal Output. Eg:- Max Profit, Min Loss, largest value or a lowest value etc.

In the actual 0/1 Knapsack problem we are given a knapsack (bag) having capacity W. A list of items which have their respective weight and profit value. So, we have to fill the knapsack(bag) in such a way that our bag is almost filled closest to its maximum capacity(W) and we are obtain the maximum profit.

Lets take an example : We are given a knapsack of lets say capacity(w=6) having different  objects which has profit & weight
- object 1 -> profit = 10 , weight = 1
- object 2 -> profit = 12 , weight = 2 & so on...

We have to fill our Knapsack in such a way that we have maximum profit & weight should be equal to the capacity of the knapsack 

**Steps to get the maximum profit of the knapsack:**

According to knapsack problem, we have to include that objects which have maximum profit 

1] If weight of current transaction ID < the Maximum Weight 
then we can either include that particular ID or we'll not include depending on whether that item will be a part of maximum profit item or not.

2] Otherwise, if the weight of current item is >=  maximum weight we'll surely not include it.

Similar is our given problem statement.

Now the question is but **Why we are applying Dynamic Programming here?**

1) We have a choice of selecting a particular transaction I'd in such a way that it yields us the maximum total fee.

2) In this problem we have to obtain an optimal output i.e. the maximum total fee.

Why particularly we are applying the 0/1 Knapsack approach?

1) In the knapsack problem we are given with 2 lists first one is the weight list of all items and secondly the profit list of all items. Similarly, here we  are given the weight column of all transaction ID's in the dataset which we'll be converting into the weight list and secondly the fee column which we'll be converting into the fee list.

So, 

Weight list of 0/1 Knapsack problem is equivalent to the weight list of all transaction ID's.

Profit list of 0/1 Knapsack problem is equivalent to the fee list of all transaction IDs.

2) Here weight of Knapsack bag is equivalent to 4,000,000 weight which we don't have to exceed.

3) Thirdly, in the 0/1 knapsack problem we have to find the maximum profit here we have to find the maximum total fee obtained.

There are total 3 ways of applying the 0/1 Knapsack approach to this problem

Approach 1:-  Recursion 

The Naive approach which I could think off here is through basic recursion, we can simply check if the selected transaction_id(txid) gives the maximum fee if it gives we 
select it else we have to find another maximum output i.e we can check if next iteration gives us or not and it continues until we reach the max fee

**PseudoCode:** Pseudo recursive code for given problem would be :

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

**Time Complexity of Recursive Code would be : O(2^n)**

**Space Complexity : O(1)**

Approach 2:- Memoization (Top Down Dynamic Programming) 
As discussed above, we can implement this using **Dynamic programming** classic problem **'0/1 KnapSack problem'**
KnapSack problem can be implemented using Top Down & Bottom Up approach. I have implemented using Top Down approach. 



Approach 3:- Tabulation (Bottom Up Dynamic Programming)




