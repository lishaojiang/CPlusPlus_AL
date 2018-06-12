class MyHashSet 
{
public:
    int* m_iArray;
    int m_iHashValue;
    int FindKey(int key)
    {
        int iKeyA = key;
        key = key % m_iHashValue;
        while(m_iArray[key] > 0 && m_iArray[key] != iKeyA)
        {
            key = (key+1) % m_iHashValue;  
        }
        return key;
    }
    /** Initialize your data structure here. */
    MyHashSet() 
    {
        m_iHashValue = 9973;
        m_iArray = new int[10000];
        memset(m_iArray,0,10000 * sizeof(int));
    }
    
    void add(int key) 
    {
        int iKeyA = FindKey(key);
        if(m_iArray[iKeyA]==0)
        {
            m_iArray[iKeyA]= key;
        }
    }
    
    void remove(int key) 
    {
        int iKeyA = FindKey(key);
        m_iArray[iKeyA]=0;   
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) 
    {
        int iKeyA = FindKey(key);
        if(m_iArray[iKeyA]==0)
        {
            return false;
        }
        return true;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */