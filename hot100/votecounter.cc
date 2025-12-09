#include <unordered_set>
using namespace std;

class VoteCounter {
private:
    struct Node {
        int count;
        unordered_set<string> persons;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    unordered_map<string, Node*> mp;  // person -> node
    Node* head; // smallest count
    Node* tail; // largest count

    Node* insertAfter(Node* node, int count) {
        Node* newNode = new Node(count);
        newNode->prev = node;
        if (node) {
            newNode->next = node->next;
            if (node->next) node->next->prev = newNode;
            node->next = newNode;
        }
        if (!tail || tail == node) tail = newNode;
        if (!head) head = newNode;
        return newNode;
    }

    Node* insertBefore(Node* node, int count) {
        Node* newNode = new Node(count);
        newNode->next = node;
        if (node) {
            newNode->prev = node->prev;
            if (node->prev) node->prev->next = newNode;
            node->prev = newNode;
        }
        if (!head || head == node) head = newNode;
        if (!tail) tail = newNode;
        return newNode;
    }

    void removeNodeIfEmpty(Node* node) {
        if (!node || !node->persons.empty()) return;
        if (node == head) head = head->next;
        if (node == tail) tail = tail->prev;
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;
        delete node;
    }

public:
    VoteCounter() : head(nullptr), tail(nullptr) {}

    // 票数加一
    void inc(const string &person) {
        if (!mp.count(person)) {
            // 新的人，票数变为 1
            if (!head || head->count > 1) {
                head = insertBefore(head, 1);
                if (!tail) tail = head;
            }
            head->persons.insert(person);
            mp[person] = head;
            return;
        }

        Node* node = mp[person];
        int c = node->count;

        Node* nextNode;
        if (!node->next || node->next->count > c + 1) {
            nextNode = insertAfter(node, c + 1);
        } else {
            nextNode = node->next;
        }

        nextNode->persons.insert(person);
        mp[person] = nextNode;

        node->persons.erase(person);
        removeNodeIfEmpty(node);
    }

    // 票数减一（不能减到负数）
    void dec(const string &person) {
        if (!mp.count(person)) return;

        Node* node = mp[person];
        int c = node->count;

        if (c == 1) {
            // 删除这个人（不再记录 0）
            node->persons.erase(person);
            mp.erase(person);
            removeNodeIfEmpty(node);
            return;
        }

        // c > 1
        Node* prevNode;
        if (!node->prev || node->prev->count < c - 1) {
            prevNode = insertBefore(node, c - 1);
        } else {
            prevNode = node->prev;
        }

        prevNode->persons.insert(person);
        mp[person] = prevNode;

        node->persons.erase(person);
        removeNodeIfEmpty(node);
    }

    // 得到票数最多的人
    string getMax() {
        if (!tail || tail->persons.empty()) return "";
        return *tail->persons.begin();
    }

    // 票数最少的人
    string getMin() {
        if (!head || head->persons.empty()) return "";
        return *head->persons.begin();
    }
};
