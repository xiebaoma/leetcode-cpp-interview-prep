/**
 * xiebaoma
 * 2025-07-19
 */

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> removeSubfolders(vector<string> &folder)
    {
        // 1. 按字典序排序文件夹路径
        sort(folder.begin(), folder.end());
        // 2. 初始化结果向量，放入第一个文件夹
        vector<string> ans = {folder[0]};
        // 3. 遍历剩余的文件夹路径
        for (int i = 1; i < folder.size(); ++i)
        {
            // 4. 获取上一个结果文件夹及其长度
            string last_folder = ans.back();
            int pre = last_folder.size();
            // 5. 检查当前文件夹是否是上一个结果文件夹的子文件夹
            if (!(pre < folder[i].size() &&
                  last_folder == folder[i].substr(0, pre) &&
                  folder[i][pre] == '/'))
            {
                // 6. 如果不是子文件夹，添加到结果
                ans.push_back(folder[i]);
            }
        }
        // 7. 返回结果
        return ans;
    }
};