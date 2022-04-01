// https://leetcode.com/problems/invalid-transactions/

class Transaction {
    public:
    string name;
    string city;
    int amt;
    int time;
    Transaction(string name, string city, int amt, int time) {
        this->name = name;
        this->city = city;
        this->amt = amt;
        this->time = time;
    }
};

class Solution {
public:
    Transaction* decodeString(string t) {
        string name = "";
            int time = 0;
            int amt = 0;
            string city = "";
            int i = 0;
            // get the name
            while(i < t.length() && t[i] != ',') {
                name += t[i];
                i++;
            } i++; // to remove ,
            // get the time
            while(i < t.length() && t[i] != ',') {
                time = time * 10 + (t[i]-'0');
                i++;
            } i++; // to remove ,
            // get the amt
            while(i < t.length() && t[i] != ',') {
                amt = amt * 10 + (t[i]-'0');
                i++;
            } i++; // to remove ,
            // get the city
            while(i < t.length() && t[i] != ',') {
                city += t[i];
                i++;
            } i++; // to remove ,
            Transaction* trx = new Transaction(name, city, amt, time);
        return trx;
    }
    bool isValid(Transaction* trx, vector<Transaction*> list) {
        if (trx->amt > 1000) {
            return false;
        }
        for (Transaction* t: list) {
            if (abs(trx->time - t->time) <= 60 && trx->city != t->city) {
                return false;
            }
        }
        return true;
    }
    vector<string> invalidTransactions(vector<string>& transactions) {
        vector<string> result;
        map<string, vector<Transaction*>> m;
        int size = transactions.size();
        for (int index = 0; index < size; index++) {
            string t = transactions[index];
            Transaction* trx = decodeString(t);
            m[trx->name].push_back(trx);
        }
        
        for (string t: transactions) {
            Transaction* trx = decodeString(t);
            if (!isValid(trx, m[trx->name])) {
                result.push_back(t);
            }
        }
        
        return result;
    }
};