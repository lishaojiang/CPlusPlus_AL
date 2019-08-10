class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() 
    {
        m_iMin = INT_MAX;
        m_kDeque.clear();
    }
    
    void push(int x) 
    {
        m_kDeque.push_back(x);
        if(x < m_iMin)
        {
            m_iMin = x;
        }
    }
    
    void pop() {
        if(!m_kDeque.empty())
        {
            m_kDeque.pop_back();
        }
        deque<int> kTemp;
        int iMin = INT_MAX;
        while(!m_kDeque.empty())
        {
            kTemp.push_front(m_kDeque.back());
            if(m_kDeque.back() < iMin)
            {
                iMin = m_kDeque.back();
            }
            m_kDeque.pop_back();

        }
        m_kDeque = kTemp;
        m_iMin = iMin;

    }
    
    int top() {
        if(!m_kDeque.empty())
        {
            return m_kDeque.back();
        }
        return 0;
    }
    
    int getMin() {
        return m_iMin;
    }
private:
    deque<int> m_kDeque;
    int m_iMin;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};