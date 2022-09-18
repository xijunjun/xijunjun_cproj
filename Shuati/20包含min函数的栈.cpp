#include<assert.h>
//推荐写法，每次都记录当前位置最小值，未优化空间
class Solution {
public:
    stack<int>sta1,sta2;
    void push(int value) {
        sta2.push(sta2.empty()?value:std::min(value,sta2.top()));
        sta1.push(value);
    }
    void pop() {
        assert(!sta1.empty());
        sta2.pop();
        sta1.pop();
    } 
    int top() {
        assert(!sta1.empty());
        return sta1.top();
    }
    int min() {
        assert(!sta1.empty());
        return sta2.top();
    }
};
//优化空间
class Solution {
public:
    stack<int>sta1,sta2;
    void push(int value) {
        if(sta2.empty()||value<=sta2.top())
            sta2.push(value);
        sta1.push(value);
    }
    void pop() {
        if(sta2.top()==sta1.top())
            sta2.pop();
        sta1.pop();
    }
    int top() {
        return sta1.top();
    }
    int min() {
        return sta2.top();
    }
};

