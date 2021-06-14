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

**To find**: Maximum Weight of the block

**Approach** : 1] Brute-Force

We can implement this problem using Recursion by simply checking the 

**PseudoCode:** Pseudo recursive code for given example would be :


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


2] We can implement this problem using **Dynamic programming** classic problem **'0/1 KnapSack problem'**
KnapSack problem can be implemented using Top Down & Bottom Up approach. I have implemented using Top Down approach. 

Lets take an example : We are given a knapsack of lets say capacity(w=6) having different  objects which has profit & weight
- object 1 -> profit = 10 , weight = 1
- object 2 -> profit = 12 , weight = 2 & so on...

We have to fill our Knapsack in such a way that we have maximum profit & weight should be equal to the capacity of the knapsack 

In 0/1 KnapSack we either include whole object or discard it there is no in between like Fractional KnapSack

*Steps to get the maximum profit of the knapsack* : 

1] Calculate profit/weight ratio, we will include that object which has maximum profit/weight 

2] So, 0/1 means 0 means discard the object , 1 means include the object 
*Note* : We have to include that objects which have maximum profit

