struct Node{
    int key;
    int value;
    Node *next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

class MyHashMap {
public:

    static const int prime = 10007;
    vector<Node *>map;


    int hash(int key){
        return key % prime;
    }


    MyHashMap() :  map(prime, nullptr) {}

    
    void put(int key, int value) {
        int hashKey = hash(key);
        Node *list = map[hashKey];
        
        Node *prev = nullptr;
        while(list){
           if(list->key == key){
              list->value = value;
              return;
           }
           prev = list;
           list = list->next;
        }

        Node *curr = new Node(key, value);
        
        if(prev){
          prev->next = curr;
        }
        else{
            map[hashKey] = curr;
        }
        
    }


    
    int get(int key) {
        int hashKey = hash(key);
        auto list = map[hashKey];
        while (list) {
            if (list->key == key) return list->value;
            list = list->next;
        }
        return -1;
    }

    void remove(int key) {
        int hashKey = hash(key);
        auto &list = map[hashKey];
        Node *prev = nullptr, *curr = list;

        while (curr) {
            if (curr->key == key) break;
            prev = curr;
            curr = curr->next;
        }

        if (!curr) return;  // Key not found

        if (!prev) {
            map[hashKey] = curr->next;
        } else {
            prev->next = curr->next;
        }

        delete curr;  // Free memory to avoid memory leaks
    }
};