#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <sstream>
#include <cctype>

using namespace std;

class PropositionalFormula {
private:
    string formula;
    set<char> variables;
    vector<char> variables_sorted;
    
    // 提取公式中的所有变量
    void extractVariables() {
        variables.clear();
        for (char c : formula) {
            if (isalpha(c)) {
                variables.insert(c);
            }
        }
        variables_sorted.assign(variables.begin(), variables.end());
        sort(variables_sorted.begin(), variables_sorted.end());
    }
    
    // 处理蕴含符号 A - B => (not A) or B
    string handleImplication(string formula) {
        size_t pos = formula.find('-');
        if (pos == string::npos) {
            return formula;
        }
        
        // 找到左操作数
        int left_end = pos - 1;
        while (left_end >= 0 && formula[left_end] == ' ') {
            left_end--;
        }
        
        int left_start;
        if (left_end >= 0 && formula[left_end] == ')') {
            // 找到匹配的左括号
            int paren_count = 1;
            left_start = left_end - 1;
            while (left_start >= 0 && paren_count > 0) {
                if (formula[left_start] == ')') {
                    paren_count++;
                } else if (formula[left_start] == '(') {
                    paren_count--;
                }
                left_start--;
            }
            left_start++;
        } else {
            // 单个变量或值
            left_start = left_end;
            while (left_start > 0 && (isalnum(formula[left_start-1]) || 
                   formula.substr(left_start-1, 5) == "False" || 
                   formula.substr(left_start-1, 4) == "True" || 
                   formula.substr(left_start-1, 3) == "not")) {
                left_start--;
            }
        }
        
        // 找到右操作数
        int right_start = pos + 1;
        while (right_start < formula.length() && formula[right_start] == ' ') {
            right_start++;
        }
        
        int right_end;
        if (right_start < formula.length() && formula[right_start] == '(') {
            // 找到匹配的右括号
            int paren_count = 1;
            right_end = right_start + 1;
            while (right_end < formula.length() && paren_count > 0) {
                if (formula[right_end] == '(') {
                    paren_count++;
                } else if (formula[right_end] == ')') {
                    paren_count--;
                }
                right_end++;
            }
            right_end--;
        } else {
            // 单个变量或值
            right_end = right_start;
            while (right_end < formula.length() - 1 && (isalnum(formula[right_end+1]) || 
                   formula.substr(right_end+1, 5) == "False" || 
                   formula.substr(right_end+1, 4) == "True" || 
                   formula.substr(right_end+1, 3) == "not")) {
                right_end++;
            }
        }
        
        string left_expr = formula.substr(left_start, left_end - left_start + 1);
        string right_expr = formula.substr(right_start, right_end - right_start + 1);
        
        // 去除前后空格
        left_expr.erase(0, left_expr.find_first_not_of(" "));
        left_expr.erase(left_expr.find_last_not_of(" ") + 1);
        right_expr.erase(0, right_expr.find_first_not_of(" "));
        right_expr.erase(right_expr.find_last_not_of(" ") + 1);
        
        // A - B => (not A) or B
        string new_expr = "( not (" + left_expr + ") or (" + right_expr + "))";
        
        return formula.substr(0, left_start) + new_expr + formula.substr(right_end + 1);
    }
    
    // 处理等价符号 A + B => (A and B) or (not A and not B)
    string handleEquivalence(string formula) {
        size_t pos = formula.find('+');
        if (pos == string::npos) {
            return formula;
        }
        
        // 找到左操作数
        int left_end = pos - 1;
        while (left_end >= 0 && formula[left_end] == ' ') {
            left_end--;
        }
        
        int left_start;
        if (left_end >= 0 && formula[left_end] == ')') {
            // 找到匹配的左括号
            int paren_count = 1;
            left_start = left_end - 1;
            while (left_start >= 0 && paren_count > 0) {
                if (formula[left_start] == ')') {
                    paren_count++;
                } else if (formula[left_start] == '(') {
                    paren_count--;
                }
                left_start--;
            }
            left_start++;
        } else {
            // 单个变量或值
            left_start = left_end;
            while (left_start > 0 && (isalnum(formula[left_start-1]) || 
                   formula.substr(left_start-1, 5) == "False" || 
                   formula.substr(left_start-1, 4) == "True" || 
                   formula.substr(left_start-1, 3) == "not")) {
                left_start--;
            }
        }
        
        // 找到右操作数
        int right_start = pos + 1;
        while (right_start < formula.length() && formula[right_start] == ' ') {
            right_start++;
        }
        
        int right_end;
        if (right_start < formula.length() && formula[right_start] == '(') {
            // 找到匹配的右括号
            int paren_count = 1;
            right_end = right_start + 1;
            while (right_end < formula.length() && paren_count > 0) {
                if (formula[right_end] == '(') {
                    paren_count++;
                } else if (formula[right_end] == ')') {
                    paren_count--;
                }
                right_end++;
            }
            right_end--;
        } else {
            // 单个变量或值
            right_end = right_start;
            while (right_end < formula.length() - 1 && (isalnum(formula[right_end+1]) || 
                   formula.substr(right_end+1, 5) == "False" || 
                   formula.substr(right_end+1, 4) == "True" || 
                   formula.substr(right_end+1, 3) == "not")) {
                right_end++;
            }
        }
        
        string left_expr = formula.substr(left_start, left_end - left_start + 1);
        string right_expr = formula.substr(right_start, right_end - right_start + 1);
        
        // 去除前后空格
        left_expr.erase(0, left_expr.find_first_not_of(" "));
        left_expr.erase(left_expr.find_last_not_of(" ") + 1);
        right_expr.erase(0, right_expr.find_first_not_of(" "));
        right_expr.erase(right_expr.find_last_not_of(" ") + 1);
        
        // A + B => (A and B) or (not A and not B)
        string new_expr = "(((" + left_expr + ") and (" + right_expr + ")) or (( not (" + left_expr + ")) and ( not (" + right_expr + "))))";
        
        return formula.substr(0, left_start) + new_expr + formula.substr(right_end + 1);
    }
    
    // 字符串替换函数
    string replaceAll(string str, const string& from, const string& to) {
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return str;
    }
    
    // 变量替换 - 使用精确的单词边界检查
    string replaceVariable(string formula, char var, bool value) {
        string var_str(1, var);
        string value_str = value ? "true" : "false";
        string new_formula = "";
        
        for (int i = 0; i < formula.length(); i++) {
            if (i < formula.length() && formula[i] == var) {
                // 检查前后是否为单词边界
                bool before_ok = (i == 0 || !isalnum(formula[i-1]));
                bool after_ok = (i + 1 >= formula.length() || !isalnum(formula[i+1]));
                if (before_ok && after_ok) {
                    new_formula += value_str;
                } else {
                    new_formula += formula[i];
                }
            } else {
                new_formula += formula[i];
            }
        }
        return new_formula;
    }
    
    // 评估逻辑表达式
    bool evaluateExpression(string expr) {
        // 简单的递归下降解析器
        return parseOr(expr, 0).first;
    }
    
    // 解析或表达式
    pair<bool, int> parseOr(const string& expr, int pos) {
        auto left = parseAnd(expr, pos);
        pos = left.second;
        
        while (pos < expr.length()) {
            // 跳过空格
            while (pos < expr.length() && expr[pos] == ' ') pos++;
            
            if (pos + 2 < expr.length() && expr.substr(pos, 2) == "or") {
                pos += 2;
                while (pos < expr.length() && expr[pos] == ' ') pos++;
                auto right = parseAnd(expr, pos);
                left.first = left.first || right.first;
                pos = right.second;
            } else {
                break;
            }
        }
        
        return make_pair(left.first, pos);
    }
    
    // 解析与表达式
    pair<bool, int> parseAnd(const string& expr, int pos) {
        auto left = parseNot(expr, pos);
        pos = left.second;
        
        while (pos < expr.length()) {
            // 跳过空格
            while (pos < expr.length() && expr[pos] == ' ') pos++;
            
            if (pos + 3 < expr.length() && expr.substr(pos, 3) == "and") {
                pos += 3;
                while (pos < expr.length() && expr[pos] == ' ') pos++;
                auto right = parseNot(expr, pos);
                left.first = left.first && right.first;
                pos = right.second;
            } else {
                break;
            }
        }
        
        return make_pair(left.first, pos);
    }
    
    // 解析非表达式
    pair<bool, int> parseNot(const string& expr, int pos) {
        // 跳过空格
        while (pos < expr.length() && expr[pos] == ' ') pos++;
        
        if (pos + 3 < expr.length() && expr.substr(pos, 3) == "not") {
            pos += 3;
            while (pos < expr.length() && expr[pos] == ' ') pos++;
            auto result = parsePrimary(expr, pos);
            return make_pair(!result.first, result.second);
        } else {
            return parsePrimary(expr, pos);
        }
    }
    
    // 解析基本表达式
    pair<bool, int> parsePrimary(const string& expr, int pos) {
        // 跳过空格
        while (pos < expr.length() && expr[pos] == ' ') pos++;
        
        if (pos < expr.length() && expr[pos] == '(') {
            pos++; // 跳过 '('
            auto result = parseOr(expr, pos);
            pos = result.second;
            // 跳过空格
            while (pos < expr.length() && expr[pos] == ' ') pos++;
            if (pos < expr.length() && expr[pos] == ')') {
                pos++; // 跳过 ')'
            }
            return make_pair(result.first, pos);
        } else if (pos + 4 <= expr.length() && expr.substr(pos, 4) == "true") {
            return make_pair(true, pos + 4);
        } else if (pos + 5 <= expr.length() && expr.substr(pos, 5) == "false") {
            return make_pair(false, pos + 5);
        }
        
        // 如果无法解析，返回false
        return make_pair(false, pos + 1);
    }
    
    // 根据变量赋值计算公式的真值
    bool evaluateFormula(const map<char, bool>& assignment) {
        string formula_copy = formula;
        
        // 处理蕴含
        while (formula_copy.find('-') != string::npos) {
            formula_copy = handleImplication(formula_copy);
        }
        
        // 处理等价
        while (formula_copy.find('+') != string::npos) {
            formula_copy = handleEquivalence(formula_copy);
        }
        
        // 替换逻辑符号
        formula_copy = replaceAll(formula_copy, "!", " not ");
        formula_copy = replaceAll(formula_copy, "&", " and ");
        formula_copy = replaceAll(formula_copy, "|", " or ");
        
        // 替换变量为具体值 - 按长度从长到短排序
        vector<char> sorted_vars = variables_sorted;
        sort(sorted_vars.begin(), sorted_vars.end(), [](char a, char b) {
            return string(1, a).length() > string(1, b).length();
        });
        
        for (char var : sorted_vars) {
            formula_copy = replaceVariable(formula_copy, var, assignment.at(var));
        }
        
        try {
            return evaluateExpression(formula_copy);
        } catch (...) {
            return false;
        }
    }
    
    // 生成所有可能的真值组合
    vector<pair<map<char, bool>, bool>> generateTruthTable() {
        vector<pair<map<char, bool>, bool>> truth_table;
        int n_vars = variables_sorted.size();
        
        // 生成所有可能的真值组合 - 与Python的product([False, True], repeat=n_vars)一致
        for (int i = 0; i < (1 << n_vars); i++) {
            map<char, bool> assignment;
            for (int j = 0; j < n_vars; j++) {
                // Python的product是按最右边变量变化最快的方式
                // 所以最右边的变量对应最低位
                assignment[variables_sorted[n_vars - 1 - j]] = (i >> j) & 1;
            }
            bool result = evaluateFormula(assignment);
            truth_table.push_back(make_pair(assignment, result));
        }
        
        return truth_table;
    }
    
public:
    PropositionalFormula(const string& input_formula) : formula(input_formula) {
        // 去除前后空格
        formula.erase(0, formula.find_first_not_of(" "));
        formula.erase(formula.find_last_not_of(" ") + 1);
        extractVariables();
    }
    
    // 获取最小项和最大项
    pair<vector<int>, vector<int>> getMintermsMaxterms() {
        auto truth_table = generateTruthTable();
        vector<int> minterms, maxterms;
        
        for (int i = 0; i < truth_table.size(); i++) {
            if (truth_table[i].second) {
                minterms.push_back(i);
            } else {
                maxterms.push_back(i);
            }
        }
        
        return make_pair(minterms, maxterms);
    }
    
    // 格式化输出主析取范式和主合取范式
    string formatNormalForms() {
        auto minterms_maxterms = getMintermsMaxterms();
        vector<int> minterms = minterms_maxterms.first;
        vector<int> maxterms = minterms_maxterms.second;
        
        string pdnf, pcnf;
        int total_combinations = 1 << variables_sorted.size();
        
        // 主析取范式 (Principal Disjunctive Normal Form)
        if (minterms.empty()) {  // 永假式
            pdnf = "0";
        } else if (minterms.size() == total_combinations) {  // 永真式
            pdnf = "1";
        } else {
            vector<string> pdnf_terms;
            for (int i : minterms) {
                pdnf_terms.push_back("m" + to_string(i));
            }
            pdnf = "";
            for (int i = 0; i < pdnf_terms.size(); i++) {
                if (i > 0) pdnf += " ∨ ";
                pdnf += pdnf_terms[i];
            }
        }
        
        // 主合取范式 (Principal Conjunctive Normal Form)
        if (maxterms.empty()) {  // 永真式
            pcnf = "1";
        } else if (maxterms.size() == total_combinations) {  // 永假式
            pcnf = "0";
        } else {
            vector<string> pcnf_terms;
            for (int i : maxterms) {
                pcnf_terms.push_back("M" + to_string(i));
            }
            pcnf = "";
            for (int i = 0; i < pcnf_terms.size(); i++) {
                if (i > 0) pcnf += " ∧ ";
                pcnf += pcnf_terms[i];
            }
        }
        
        return pdnf + " ; " + pcnf;
    }
};

int main() {
    try {
        string formula_input;
        getline(cin, formula_input);
        
        if (formula_input.empty()) {
            cout << "Error: Empty input" << endl;
            return 1;
        }
        
        PropositionalFormula formula(formula_input);
        string result = formula.formatNormalForms();
        
        cout << result << endl;
        
    } catch (const exception& e) {
        cout << "Error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cout << "Error: Unknown error occurred" << endl;
        return 1;
    }
    
    return 0;
}
