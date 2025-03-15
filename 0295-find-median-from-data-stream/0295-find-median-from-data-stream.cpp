class MedianFinder {
public:

    priority_queue<int>maxHeap;
    priority_queue< int, vector<int>, greater<> >minHeap;

    MedianFinder() {
        /*  
          1 2  3  4 5
          left container : increasing order and right container : ascending order

          max and min heaps;
          left -> max Heap, right -> min Heap;

          lets say we give first prefernce to max Heap ,
          if(maxHeap.size() != minHeap.size()) return maxHeap.top();

          // balance funtion, like balances the height <= 1   
        
        */
        
    }

    void addNum(int num) {

        minHeap.push(num);
        int ele = minHeap.top();
        minHeap.pop();

        maxHeap.push(ele);

        if(maxHeap.size() - 1 > minHeap.size()){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }
        return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */