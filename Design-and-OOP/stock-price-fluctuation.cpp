class StockPrice {
//attempt 1 : i mean first test case was solved . the second not really.
private:
    int curr_stock;
    vector<pair<int,int>> a;
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        this->curr_stock = price;
        int n = this->a.size();
        for(int i= 0 ; i < n; i ++){
            if(this->a[i].first==timestamp){
                this->a[i].second = price;
                return;
            }
        }
        this->a.push_back({timestamp,price}); 
    }
    
    int current() {
        return this->curr_stock;
    }
    int maximum() {
        int n = this->a.size();
        int mx = -1;
        for(int i= 0 ; i < n; i ++){
            if(this->a[i].second>=mx){
                mx = this->a[i].second;
            }
        }
        return mx;
    }
    
    int minimum() {
        int n = this->a.size();
        int mx = INT_MAX;
        for(int i= 0 ; i < n; i ++){
            if(this->a[i].second<=mx){
                mx = this->a[i].second;
            }
        }
        return mx;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */


class StockPrice 
// well i learned about set and multisert , today
// which is the opposite of priority queue;
public:
    map<int, int> recent;
    multiset<int> count;
    StockPrice() {
    }
    void update(int timestamp, int price) {
        if(recent.find(timestamp) != recent.end()){
            count.erase(count.find(recent[timestamp]));
        }
        recent[timestamp] = price;
        count.insert(price); 
    }
    
    int current() {
        return recent.rbegin()->second;
    }
    int maximum() {
        return *count.rbegin();
    }
    
    int minimum() {
        return *count.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
