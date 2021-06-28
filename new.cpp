#include <bits/stdc++.h>
using namespace std;

class Txid
{
public:
    string tx_id;   //given transactions
    vector<string> parent_transactions;
    int fee;   //transaction fee
    int weight;  //transaction weight
};
typedef int MyCustomType;
set<string> given_tx_id; 
string str = "mempool.csv";
double mweight = 4000000.0;   //mweight = maximum weight given



pair<string, Txid *> createTxid(vector<string> &row){
    auto ans = new Txid();
    ans->tx_id = row[0];
    ans->fee = stoi(row[1]);
    ans->weight = stoi(row[2]);
    vector<string> a;
    for (int i = 3; i < row.size(); i++)
    {
        a.push_back(row[i]);
    }
    ans->parent_transactions = a;
    return {row[0], ans};
}

void readCSV(string str, unordered_map<string, Txid *> &mp)
{
    ifstream fin(str);
    vector<string> rw;
    string temp, line, word;
    getline(fin, line);
    while (getline(fin, line))
    {
        rw.clear();
        stringstream s(line);
        while (getline(s, word, ','))
        {
            rw.push_back(word); 
        }
        pair<string, Txid *> a = createTxid(rw);
        mp[a.first] = a.second;
    }
    fin.close();
    cout << "No of given Txid(transactions): " << mp.size() << endl;
}

bool isValidTxid(Txid *trans, set<string> &given_tx_set)
{
    for (auto parent : trans->parent_transactions)
    {
        if (given_tx_set.find(parent) == given_tx_set.end())
            return false;
    }
    return true;
}
void wOutput(vector<string> &given_tx_vector, string fn)
{
    ofstream rfile(fn);
    for (auto s : given_tx_vector)
        rfile << s << endl;
    rfile.close();
}


int main(){
#ifndef ONLINE_JUDGE
    // for getting input to input.txt
    freopen("input.txt", "r", stdin);
    // for getting output to output.txt
    freopen("output.txt", "w", stdout);
#endif

    unordered_map<string, Txid *> mp;
    readCSV(str, mp);
    set<pair<float, Txid *>, greater<pair<float, Txid *>>> tx_set; 
    set<string> given_tx_set;                                                 
    vector<string> given_tx_vector;                                           
    for (auto a : mp)
    {
        tx_set.insert({(float)a.second->fee / (float)a.second->weight, a.second});
    }
    double currBlockWeight = 0.0;
    int totalFee = 0;
    while (!tx_set.empty() && currBlockWeight < mweight)
    {
        bool found = false;
        for (auto itr = tx_set.begin(); itr != tx_set.end(); itr++)
        {
            Txid *curr_tx = (*itr).second;
            int currFee = curr_tx->fee;
            int currWeight = curr_tx->weight;
            if (isValidTxid(curr_tx, given_tx_set) && (currBlockWeight + currWeight) <= mweight)
            {
                currBlockWeight += currWeight;
                given_tx_set.insert(curr_tx->tx_id);
                given_tx_vector.push_back(curr_tx->tx_id);
                totalFee = totalFee+currFee;
                tx_set.erase(itr);
                found = true;
                break;
            }
        }
        if (!found)
            break;
    }
    cout << "Number of txid in final block : " << given_tx_set.size() << "\n";
    cout << "Total fee  : " << totalFee<<"\n";
    cout << "Weight of Block : " << currBlockWeight<<"\n";
    double perct=(currBlockWeight/mweight)*100.0;
    cout<<"Weight of given block in percentage is : "<<perct<<" %"<<"\n";
    cout<<"\n";
    wOutput(given_tx_vector, "block.txt");
    return 0;
}