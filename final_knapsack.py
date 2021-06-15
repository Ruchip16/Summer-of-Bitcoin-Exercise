import pandas as pd

df = pd.read_csv('mempool.csv')

dd = df.drop(['tx_id','fee','weight'], axis = 1)


parent_list = []

print(type(dd.values[0][0]))
q = dd.values[1]
print(type(q[0]))


for i in dd.values:
    v = str(type(i[0]))

    if v[8:] != "float'>":
        parent_list.extend(i)


# print(parent_list)

# ---------------------------------- This is the Transaction id list ---------------------------------------------------
c = df['tx_id']
# print(c)
# ----------------------------------------------------------------------------------------------------------------------

# ------------------------------------This is the Weight List ---------------------------------------------------
weight = df['weight']
print(weight)
#-----------------------------------------------------------------------------------------------------------------


#------------------------------------- This is the Fee List----------------------------------------------------------
fees = df['fee']
print(fees)
#---------------------------------------------------------------------------------------------------------------------

def printknapSack(weight, fee ,W, parent_txid):
    K = [[0 for w in range(W + 1)]
            for i in range(parent_txid + 1)]
             
    # Build table K[][] in bottom
    # up manner
    for i in range(len(parent_txid) + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif weight[i - 1] <= w:
                K[i][w] = max(fee[i - 1]
                  + K[i - 1][w - weight[i - 1]],
                               K[i - 1][w])
            else:
                K[i][w] = K[i - 1][w]
 
    # stores the result of Knapsack
    res = K[parent_txid][W]
    print(res)
     
    w = W
    for i in range(parent_txid, 0, -1):
        if res <= 0:
            break
        # either the result comes from the
        # top (K[i-1][w]) or from (val[i-1]
        # + K[i-1] [w-wt[i-1]]) as in Knapsack
        # table. If it comes from the latter
        # one/ it means the item is included.
        if res == K[i - 1][w]:
            continue
        else:
 
            # This item is included.
            print(weight[i - 1])
             
            # Since this weight is included
            # its value is deducted
            res = res - fee[i - 1]
            w = w - weight[i - 1]




weight = weight
fee = fees
W = 4000000
profit = printknapSack(weight,fee,W,len(weight))
print(profit)
     
printknapSack(weight, fee,W, len(weight))
