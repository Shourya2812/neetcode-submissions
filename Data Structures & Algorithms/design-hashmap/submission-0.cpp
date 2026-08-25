class MyHashMap {
private:
    static const int SIZE = 10000;

    vector<list<pair<int, int>>> table;

public:
    MyHashMap() {
        table.resize(SIZE);
    }

    void put(int key, int value) {

        int index = key % SIZE;

        for (auto& p : table[index]) {

            if (p.first == key) {
                // Key already exists → update value
                p.second = value;
                return;
            }
        }

        // Key doesn't exist → insert
        table[index].push_back({key, value});
    }

    int get(int key) {

        int index = key % SIZE;

        for (auto& p : table[index]) {

            if (p.first == key) {
                return p.second;
            }
        }

        return -1;
    }

    void remove(int key) {

        int index = key % SIZE;

        for (auto it = table[index].begin();
             it != table[index].end();
             ++it) {

            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }
};