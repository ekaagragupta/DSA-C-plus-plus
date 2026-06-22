class MyHashMap {
public:
    vector<int> hash;

    MyHashMap() {
        hash.resize(1000001, -1);
    }

    void put(int key, int value) {
        hash[key] = value;
    }

    int get(int key) {
        return hash[key];
    }

    void remove(int key) {
        hash[key] = -1;
    }
};