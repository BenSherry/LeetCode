#pragma once

#include <vector>
#include <iostream>

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        size_ = 0;
        
    }
    
    void push(int x) {
        data_.push_back(x);
        size_++;
        if (size_ == 1)
        {
            min_ = x;
        }
        else
        {
            if (x < min_)
            {
                min_ = x;
            }
        }
        mins_.push_back(min_);

    }
    
    void pop() {
        if (size_ > 0)
        {
            size_ --;
            data_.pop_back();
            mins_.pop_back();
            if (size_ >= 1)
            {
                min_ = mins_[size_ -1];
            }
        }
        
    }
    
    int top() {
        return data_[size_-1];
        
    }
    
    int getMin() {
        return mins_[size_ -1];
        
    }

private:
    int min_;
    int size_;
    std::vector<int> data_;
    std::vector<int> mins_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */