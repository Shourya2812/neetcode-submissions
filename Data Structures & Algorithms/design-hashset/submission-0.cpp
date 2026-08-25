class MyHashSet {
private:
    static const int SIZE = 1000;
    vector<list<int>> table;

public:
    MyHashSet() {
        table.resize(SIZE);
    }

    void add(int key) {

        int index = key % SIZE;

        // Don't add duplicate
        for (int x : table[index]) {
            if (x == key)
                return;
        }

        table[index].push_back(key);
    }

    void remove(int key) {

        int index = key % SIZE;

        table[index].remove(key);
    }

    bool contains(int key) {

        int index = key % SIZE;

        for (int x : table[index]) {
            if (x == key)
                return true;
        }

        return false;
    }
};