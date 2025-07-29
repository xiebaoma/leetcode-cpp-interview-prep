/**
 * xiebaoma
 * 2025-07-29
 */

#include <string>
#include <set>
#include <vector>
using namespace std;

struct TrieNode
{
    vector<TrieNode *> childs;
    bool isEnd;
    TrieNode()
    {
        childs = vector<TrieNode *>(26, nullptr);
        isEnd = false;
    }
};

void insert(TrieNode *root, string &word)
{
    TrieNode *node = root;
    for (char c : word)
    {
        if (node->childs[c - 'a'] == nullptr)
        {
            node->childs[c - 'a'] = new TrieNode();
        }
        node = node->childs[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary
{
public:
    WordDictionary()
    {
        trie = new TrieNode();
    }

    void addWord(string word)
    {
        insert(trie, word);
    }

    bool search(string word)
    {
        return dfs(word, 0, trie);
    }

    bool dfs(string &word, int index, TrieNode *node)
    {
        if (index == word.size())
        {
            return node->isEnd;
        }
        char c = word[index];
        if (c >= 'a' && c <= 'z')
        {
            TrieNode *temp = node->childs[c - 'a'];
            if (temp != nullptr && dfs(word, index + 1, temp))
            {
                return true;
            }
        }
        else if (c == '.')
        {
            for (TrieNode *child : node->childs)
            {
                if (child != nullptr && dfs(word, index + 1, child))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    TrieNode *trie;
};
