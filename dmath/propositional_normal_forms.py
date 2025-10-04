#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Propositional Logic Normal Forms Calculator
实现功能：输入命题公式的合式公式，求出公式的真值表，并输出该公式的主合取范式和主析取范式。

符号说明：
! 非 (¬)
& 与 (∧) 
| 或 (∨)
- 蕴含 (→)
+ 等价 (↔)
"""

import re
from itertools import product


class PropositionalFormula:
    def __init__(self, formula):
        self.formula = formula.strip()
        self.variables = self._extract_variables()
        self.variables_sorted = sorted(self.variables)
        
    def _extract_variables(self):
        """提取公式中的所有变量"""
        variables = set()
        for char in self.formula:
            if char.isalpha():
                variables.add(char)
        return variables
    
    def _evaluate_formula(self, assignment):
        """根据变量赋值计算公式的真值"""
        formula = self.formula
        
        # 处理蕴含 (A - B 等价于 !A | B)
        while '-' in formula:
            formula = self._handle_implication(formula)
        
        # 处理等价 (A + B 等价于 (A & B) | (!A & !B))
        while '+' in formula:
            formula = self._handle_equivalence(formula)
        
        # 替换逻辑符号为Python可识别的符号
        formula = formula.replace('!', ' not ')
        formula = formula.replace('&', ' and ')
        formula = formula.replace('|', ' or ')
        
        # 替换变量为具体值 - 使用字符级别的精确替换
        # 按变量名长度从长到短排序，避免短变量名被长变量名包含的问题
        sorted_vars = sorted(self.variables, key=len, reverse=True)
        for var in sorted_vars:
            # 手动实现单词边界检查，更兼容
            new_formula = ""
            i = 0
            while i < len(formula):
                if formula[i:i+len(var)] == var:
                    # 检查前后是否为单词边界
                    before_ok = (i == 0 or not formula[i-1].isalnum())
                    after_ok = (i + len(var) >= len(formula) or not formula[i+len(var)].isalnum())
                    if before_ok and after_ok:
                        new_formula += str(assignment[var])
                        i += len(var)
                    else:
                        new_formula += formula[i]
                        i += 1
                else:
                    new_formula += formula[i]
                    i += 1
            formula = new_formula
        
        try:
            return eval(formula)
        except:
            return False
    
    def _handle_implication(self, formula):
        """处理蕴含符号 A - B => (not A) or B"""
        # 找到最内层的蕴含表达式
        pos = formula.find('-')
        if pos == -1:
            return formula
            
        # 找到左操作数
        left_end = pos - 1
        while left_end >= 0 and formula[left_end] == ' ':
            left_end -= 1
            
        if formula[left_end] == ')':
            # 找到匹配的左括号
            paren_count = 1
            left_start = left_end - 1
            while left_start >= 0 and paren_count > 0:
                if formula[left_start] == ')':
                    paren_count += 1
                elif formula[left_start] == '(':
                    paren_count -= 1
                left_start -= 1
            left_start += 1
        else:
            # 单个变量或值
            left_start = left_end
            while left_start > 0 and (formula[left_start-1].isalnum() or formula[left_start-1] in 'TrueFals not'):
                left_start -= 1
        
        # 找到右操作数
        right_start = pos + 1
        while right_start < len(formula) and formula[right_start] == ' ':
            right_start += 1
            
        if right_start < len(formula) and formula[right_start] == '(':
            # 找到匹配的右括号
            paren_count = 1
            right_end = right_start + 1
            while right_end < len(formula) and paren_count > 0:
                if formula[right_end] == '(':
                    paren_count += 1
                elif formula[right_end] == ')':
                    paren_count -= 1
                right_end += 1
            right_end -= 1
        else:
            # 单个变量或值
            right_end = right_start
            while right_end < len(formula) - 1 and (formula[right_end+1].isalnum() or formula[right_end+1] in 'TrueFals not'):
                right_end += 1
        
        left_expr = formula[left_start:left_end+1].strip()
        right_expr = formula[right_start:right_end+1].strip()
        
        # A - B => (not A) or B
        new_expr = "( not ({}) or ({}))".format(left_expr, right_expr)
        
        return formula[:left_start] + new_expr + formula[right_end+1:]
    
    def _handle_equivalence(self, formula):
        """处理等价符号 A + B => (A and B) or (not A and not B)"""
        pos = formula.find('+')
        if pos == -1:
            return formula
            
        # 找到左操作数
        left_end = pos - 1
        while left_end >= 0 and formula[left_end] == ' ':
            left_end -= 1
            
        if formula[left_end] == ')':
            # 找到匹配的左括号
            paren_count = 1
            left_start = left_end - 1
            while left_start >= 0 and paren_count > 0:
                if formula[left_start] == ')':
                    paren_count += 1
                elif formula[left_start] == '(':
                    paren_count -= 1
                left_start -= 1
            left_start += 1
        else:
            # 单个变量或值
            left_start = left_end
            while left_start > 0 and (formula[left_start-1].isalnum() or formula[left_start-1] in 'TrueFals not'):
                left_start -= 1
        
        # 找到右操作数
        right_start = pos + 1
        while right_start < len(formula) and formula[right_start] == ' ':
            right_start += 1
            
        if right_start < len(formula) and formula[right_start] == '(':
            # 找到匹配的右括号
            paren_count = 1
            right_end = right_start + 1
            while right_end < len(formula) and paren_count > 0:
                if formula[right_end] == '(':
                    paren_count += 1
                elif formula[right_end] == ')':
                    paren_count -= 1
                right_end += 1
            right_end -= 1
        else:
            # 单个变量或值
            right_end = right_start
            while right_end < len(formula) - 1 and (formula[right_end+1].isalnum() or formula[right_end+1] in 'TrueFals not'):
                right_end += 1
        
        left_expr = formula[left_start:left_end+1].strip()
        right_expr = formula[right_start:right_end+1].strip()
        
        # A + B => (A and B) or (not A and not B)
        new_expr = "((({}) and ({})) or (( not ({})) and ( not ({}))))".format(left_expr, right_expr, left_expr, right_expr)
        
        return formula[:left_start] + new_expr + formula[right_end+1:]
    
    def generate_truth_table(self):
        """生成真值表"""
        n_vars = len(self.variables_sorted)
        truth_table = []
        
        # 生成所有可能的真值组合
        for values in product([False, True], repeat=n_vars):
            assignment = dict(zip(self.variables_sorted, values))
            result = self._evaluate_formula(assignment)
            truth_table.append((assignment, result))
        
        return truth_table
    
    def get_minterms_maxterms(self):
        """获取最小项和最大项"""
        truth_table = self.generate_truth_table()
        minterms = []  # 使公式为真的项
        maxterms = []  # 使公式为假的项
        
        for i, (assignment, result) in enumerate(truth_table):
            if result:
                minterms.append(i)
            else:
                maxterms.append(i)
        
        return minterms, maxterms
    
    def format_normal_forms(self):
        """格式化输出主析取范式和主合取范式"""
        minterms, maxterms = self.get_minterms_maxterms()
        
        # 主析取范式 (Principal Disjunctive Normal Form)
        if not minterms:  # 永假式
            pdnf = "0"
        elif len(minterms) == 2 ** len(self.variables_sorted):  # 永真式
            pdnf = "1"
        else:
            pdnf_terms = ["m{}".format(i) for i in minterms]
            pdnf = " ∨ ".join(pdnf_terms)
        
        # 主合取范式 (Principal Conjunctive Normal Form)
        if not maxterms:  # 永真式
            pcnf = "1"
        elif len(maxterms) == 2 ** len(self.variables_sorted):  # 永假式
            pcnf = "0"
        else:
            pcnf_terms = ["M{}".format(i) for i in maxterms]
            pcnf = " ∧ ".join(pcnf_terms)
        
        return "{} ; {}".format(pdnf, pcnf)


def main():
    """主函数"""
    try:
        # 读取输入
        formula_input = input().strip()
        
        if not formula_input:
            print("Error: Empty input")
            return
        
        # 创建公式对象并计算
        formula = PropositionalFormula(formula_input)
        result = formula.format_normal_forms()
        
        # 输出结果
        print(result)
        
    except EOFError:
        print("Error: No input provided")
    except Exception as e:
        print("Error: {}".format(e))


if __name__ == "__main__":
    main()
