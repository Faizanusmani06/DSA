class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> pqMin;
    priority_queue<int> pqMax;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int m = pqMax.size();
        int n = pqMin.size();
        if((m-n) < 1) {
            if(!pqMin.size() || pqMin.top() >= num)
                pqMax.push(num);
            else {
                int x = pqMin.top(); pqMin.pop();
                pqMin.push(num);
                pqMax.push(x);
            }
        }else {
            if(pqMax.top() <= num) {
                pqMin.push(num);
            }else {
                int x = pqMax.top(); pqMax.pop();
                pqMax.push(num);
                pqMin.push(x);

            }
        }
    }
    
    double findMedian() {
        int m = pqMax.size();
        int n = pqMin.size();

        if((m+n) % 2 != 0) return pqMax.top();
        else return (pqMax.top() + pqMin.top()) * 1.0 / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */