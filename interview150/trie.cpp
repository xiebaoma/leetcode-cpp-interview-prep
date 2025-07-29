/**
 * xiebaoma
 * 2025-07-29
 */

#include <string>
#include <unordered_map>
using namespace std;

class TrieNode
{
public:
    // 当前节点的所有子节点
    unordered_map<char, TrieNode *> children;
    // 是否为一个单词的结尾
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    // 插入单词
    void insert(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    // 查找是否存在完整单词
    bool search(string word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (!node->children.count(c))
            {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    // 查找是否存在某个前缀
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char c : prefix)
        {
            if (!node->children.count(c))
            {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }

    // 析构函数释放内存
    ~Trie()
    {
        clear(root);
    }

private:
    void clear(TrieNode *node)
    {
        for (auto &pair : node->children)
        {
            clear(pair.second);
        }
        delete node;
    }
};
