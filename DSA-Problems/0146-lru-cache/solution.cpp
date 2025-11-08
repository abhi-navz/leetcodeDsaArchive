class LRUCache {
  public:
    
    struct Node{
        int key, val;
        Node* next;
        Node* prev;
        
        Node(int k, int v){
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };
    
    Node* head;
    Node* tail;
    int capacity;
    unordered_map<int, Node*> mpp;
    
    
    
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
        
    }
    
    void addToHead(Node* node){
        Node* oldNext = head->next;
        
        head->next = node;
        node->prev = head;
        
        node->next =oldNext;
        oldNext ->prev = node;
    }
    
    void remove(Node* node){
        Node* oldPrev = node->prev;
        Node* oldNext = node->next;
        
        oldPrev->next = oldNext;
        oldNext->prev = oldPrev;
        
        
    }
    
    

    int get(int key) {
        
        if(mpp.find(key) == mpp.end()){
            return -1;
        }
        
        Node* n1 = mpp[key];
        remove(n1);
        addToHead(n1);
        
        return n1->val;
        
    }

        
    void put(int key, int value) {
        
        // if key already exist;
        if(mpp.find(key) != mpp.end()){
            Node* n1 = mpp[key];
            n1->val = value;
            remove(n1);
            addToHead(n1);
            return;
        }
        
        // if key doesn't exist;
        // create a node and add to head;
        
        Node* n1 = new Node(key, value);
        addToHead(n1);
        mpp[key] = n1;
        
        // check capacity
        
        if(mpp.size() > capacity){
            Node* lru = tail->prev;
            remove(lru);
            mpp.erase(lru->key);
            delete lru;
            
        }
   
    }
};
