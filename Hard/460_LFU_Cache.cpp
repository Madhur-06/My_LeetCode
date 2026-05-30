/*
Problem: 460. LFU Cache
Link: https://leetcode.com/problems/lfu-cache/
Difficulty: Hard


Approach:
1. Store key-value pairs along with frequency count using hash maps.
2. Update the frequency of a key during get or existing key update in put.
3. Remove the least frequently used key when capacity is full.
4. Insert new keys with frequency one and maintain the minimum frequency.


Time Complexity: Get -> O(1), Put -> O(1)
Space Complexity: O(capacity)
*/

class LFUCache {

    int capacity;
    int minFreq;

    // Step 1: Store key-value pairs along with frequency count using hash maps
    unordered_map<int,pair<int,int>> keyVal;
    unordered_map<int,list<int>> freqList;
    unordered_map<int,list<int>::iterator> pos;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }
    
    int get(int key) {

        // Step 2: Update the frequency of a key during get or existing key update in put
        if(keyVal.find(key) == keyVal.end())
            return -1;

        freqList[keyVal[key].second].erase(pos[key]);

        keyVal[key].second++;

        freqList[keyVal[key].second].push_back(key);
        pos[key] = --freqList[keyVal[key].second].end();

        if(freqList[minFreq].empty())
            minFreq++;

        return keyVal[key].first;
    }
    
    void put(int key, int value) {

        if(!capacity)
            return;

        // Step 2: Update the frequency of a key during get or existing key update in put
        if(keyVal.find(key) != keyVal.end()) {

            keyVal[key].first = value;

            freqList[keyVal[key].second].erase(pos[key]);

            keyVal[key].second++;

            freqList[keyVal[key].second].push_back(key);
            pos[key] = --freqList[keyVal[key].second].end();

            if(freqList[minFreq].empty())
                minFreq++;

            return;
        }

        // Step 3: Remove the least frequently used key when capacity is full
        if(keyVal.size() == capacity) {

            int delKey = freqList[minFreq].front();

            keyVal.erase(delKey);
            pos.erase(delKey);
            freqList[minFreq].pop_front();
        }

        // Step 4: Insert new keys with frequency one and maintain the minimum frequency
        keyVal[key] = {value,1};

        freqList[1].push_back(key);
        pos[key] = --freqList[1].end();

        minFreq = 1;
    }
};



/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
