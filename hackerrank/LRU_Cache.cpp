#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

// LRU Cache with DLL(Doubly linked list)
struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    public:
    LRUCache(int capacity){
        Cache::tail = NULL; // LRU node
        Cache::head = NULL; // MRU node
        Cache::cp = capacity;
    }
    void set(int key, int value){
        if (Cache::mp.find(key) == Cache::mp.end()){ // key not in cache
            Node* newNode = new Node(key, value);              
            if (Cache::mp.size() == Cache::cp){ // cache is full                
                Node* tmp = Cache::mp[Cache::tail->key];
                Cache::mp.erase(Cache::tail->key); // remove LRU node
                if (Cache::mp.size() == 0){
                    Cache::tail = newNode;
                }
                else if (Cache::mp.size() == 1){
                    newNode->next = Cache::head;
                    newNode->next->prev = newNode;
                    Cache::tail = Cache::head;
                    Cache::tail->next = NULL;                
                }
                else{
                    newNode->next = Cache::head;
                    newNode->next->prev = newNode;
                    Cache::tail = Cache::tail->prev;
                    Cache::tail->next = NULL;
                }
                Cache::head = newNode;
                Cache::mp[key] = newNode; // update MRU node
                delete tmp;
            }            
            else{
                if (Cache::mp.size() == 0){
                    Cache::head = newNode;
                    Cache::tail = newNode;
                }
                else if (Cache::mp.size() == 1){
                    Cache::head = newNode;
                    Cache::head->next = Cache::tail;
                    Cache::tail->prev = Cache::head;
                }
                else{
                    newNode->next = Cache::head;
                    newNode->next->prev = newNode;
                    Cache::head = newNode;
                }
                Cache::mp[key] = newNode; // update MRU node
            }
        }
        else{
            Cache::mp[key]->value = value;
            if (Cache::mp.size() == 1 || mp[key] == Cache::head) return;
            Cache::mp[key]->prev->next = Cache::mp[key]->next;
            Cache::mp[key]->next = Cache::head;
            if (Cache::mp[key] == Cache::tail){
                Cache::tail = Cache::mp[key]->prev;                 
            }
            Cache::head->prev = Cache::mp[key];
            Cache::head = Cache::mp[key];
            Cache::head->prev = NULL;          
        }
    }
    int get(int key) {
        if (Cache::mp.find(key) == Cache::mp.end())
            return -1;
        else 
            return Cache::mp[key]->value;
    } 
};

int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
/*
sample intput:
500000 644
get 3
get 19
get 8
set 1 1195
set 5 1404
get 6
set 15 1020
set 7 1010
get 8
set 7 1628
set 16 1498
get 11
get 14
get 19
get 8
set 12 267
set 19 125
get 8
set 15 1241
set 8 1936
get 1
set 17 1162
set 13 151
get 19
get 20
get 14
get 16
get 7
set 2 1305
set 12 287
set 9 160
get 16
get 17
set 5 1524
set 16 81
set 4 312
set 9 89
set 19 1306
set 18 1041
set 16 237
get 8
set 11 387
get 1
get 8
set 7 1733
set 1 1652
get 17
get 8
set 20 1992
set 5 1290
set 13 270
set 3 1236
set 5 1441
set 15 743
set 19 165
get 18
get 17
set 16 193
set 14 1146
get 1
get 9
set 9 831
set 5 444
set 3 302
set 12 1973
get 19
set 14 117
get 10
get 13
set 5 1916
get 13
set 12 199
set 15 280
get 10
set 16 1188
get 12
set 6 946
get 1
set 13 1788
set 12 1816
get 13
set 17 1984
get 4
get 15
set 5 501
get 8
get 10
set 2 1088
set 7 336
get 7
set 10 182
get 10
set 17 1944
get 6
set 2 211
set 10 861
get 3
get 19
get 13
*/
