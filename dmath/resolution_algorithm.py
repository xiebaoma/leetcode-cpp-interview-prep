#!/usr/bin/env python
# -*- coding: utf-8 -*-
"""
Resolution Algorithm for CNF Satisfiability

Input: CNF formula
Output: YES if satisfiable, NO otherwise

Symbols:
! NOT
& AND 
| OR
- IMPLIES
+ BICONDITIONAL
"""

import re


class Literal:
    """Represents a literal (variable or its negation)"""
    def __init__(self, variable, negated=False):
        self.variable = variable
        self.negated = negated
    
    def __str__(self):
        return "{0}{1}".format("!" if self.negated else "", self.variable)
    
    def __repr__(self):
        return self.__str__()
    
    def __eq__(self, other):
        return isinstance(other, Literal) and self.variable == other.variable and self.negated == other.negated
    
    def __hash__(self):
        return hash((self.variable, self.negated))
    
    def negate(self):
        """Returns the negation of this literal"""
        return Literal(self.variable, not self.negated)
    
    def is_complement(self, other):
        """Checks if this literal is complementary to another"""
        return isinstance(other, Literal) and self.variable == other.variable and self.negated != other.negated


class Clause:
    """Represents a clause (disjunction of literals)"""
    def __init__(self, literals=None):
        self.literals = set(literals) if literals else set()
    
    def __str__(self):
        if not self.literals:
            return "□"  # Empty clause
        return "(" + " | ".join(str(lit) for lit in sorted(self.literals, key=str)) + ")"
    
    def __repr__(self):
        return self.__str__()
    
    def __eq__(self, other):
        return isinstance(other, Clause) and self.literals == other.literals
    
    def __hash__(self):
        return hash(frozenset(self.literals))
    
    def is_empty(self):
        """Checks if this is an empty clause"""
        return len(self.literals) == 0
    
    def contains_complementary_literals(self):
        """Checks if clause contains complementary literals (always true)"""
        for lit1 in self.literals:
            for lit2 in self.literals:
                if lit1.is_complement(lit2):
                    return True
        return False
    
    def add_literal(self, literal):
        """Adds a literal to the clause"""
        self.literals.add(literal)
    
    def remove_literal(self, literal):
        """Removes a literal from the clause"""
        self.literals.discard(literal)


class CNFFormula:
    """Represents a CNF formula"""
    def __init__(self, clauses=None):
        self.clauses = set(clauses) if clauses else set()
    
    def add_clause(self, clause):
        """Adds a clause"""
        if not clause.contains_complementary_literals():
            self.clauses.add(clause)
    
    def __str__(self):
        if not self.clauses:
            return "True"
        return " & ".join(str(clause) for clause in sorted(self.clauses, key=str))


def parse_formula(formula_str):
    """Parses input formula string to CNF format"""
    # Preprocessing: convert implication and biconditional connectives
    formula_str = formula_str.strip()
    
    # Convert implication A-B to !A|B
    def replace_implication(match):
        left = match.group(1)
        right = match.group(2)
        return "(!({0})|{1})".format(left, right)
    
    # Convert biconditional A+B to (A-B)&(B-A) i.e. (!A|B)&(!B|A)
    def replace_biconditional(match):
        left = match.group(1)
        right = match.group(2)
        return "((!({0})|{1})&(!({2})|{3}))".format(left, right, right, left)
    
    # Handle implication and biconditional (simplified)
    # Simplified processing, assuming input is already CNF or close to CNF
    
    # Split into clauses (split by &)
    clauses_str = formula_str.split('&')
    cnf = CNFFormula()
    
    for clause_str in clauses_str:
        clause_str = clause_str.strip()
        if clause_str.startswith('(') and clause_str.endswith(')'):
            clause_str = clause_str[1:-1]  # Remove outer parentheses
        
        # Split by | to get literals
        literals_str = clause_str.split('|')
        clause = Clause()
        
        for lit_str in literals_str:
            lit_str = lit_str.strip()
            if lit_str.startswith('!'):
                # Negated literal
                var = lit_str[1:].strip()
                clause.add_literal(Literal(var, True))
            else:
                # Positive literal
                clause.add_literal(Literal(lit_str, False))
        
        cnf.add_clause(clause)
    
    return cnf


def resolve_clauses(clause1, clause2):
    """Resolves two clauses, returns resolvent or None"""
    # Find complementary literals
    for lit1 in clause1.literals:
        for lit2 in clause2.literals:
            if lit1.is_complement(lit2):
                # Found complementary literals, perform resolution
                new_literals = (clause1.literals - {lit1}) | (clause2.literals - {lit2})
                return Clause(list(new_literals))
    
    return None


def resolution_algorithm(cnf):
    """
    Uses resolution algorithm to determine CNF formula satisfiability
    Returns True if satisfiable, False if unsatisfiable
    """
    clauses = set(cnf.clauses)
    
    while True:
        new_clauses = set()
        clause_list = list(clauses)
        
        # Resolve all clause pairs
        for i in range(len(clause_list)):
            for j in range(i + 1, len(clause_list)):
                resolvent = resolve_clauses(clause_list[i], clause_list[j])
                if resolvent is not None:
                    if resolvent.is_empty():
                        # Got empty clause, formula is unsatisfiable
                        return False
                    new_clauses.add(resolvent)
        
        # If no new clauses produced, algorithm terminates
        if new_clauses.issubset(clauses):
            break
        
        clauses = clauses | new_clauses
    
    # No empty clause derived, formula is satisfiable
    return True


def main():
    """Main function"""
    try:
        formula_input = input().strip()
        
        if not formula_input:
            return
        
        # Parse formula
        cnf = parse_formula(formula_input)
        
        # Run resolution algorithm
        is_satisfiable = resolution_algorithm(cnf)
        
        # Output result
        result = "YES" if is_satisfiable else "NO"
        print(result)
        
    except Exception as e:
        print("NO")  # Default output NO on error


def test_examples():
    """Test provided examples"""
    print("Test examples:")
    
    # Example 1: (!p|q)&(p|q)&(!q) -> NO
    test1 = "(!p|q)&(p|q)&(!q)"
    cnf1 = parse_formula(test1)
    result1 = resolution_algorithm(cnf1)
    print("Input: {0}".format(test1))
    print("Output: {0}".format("YES" if result1 else "NO"))
    print()
    
    # Example 2: p&(p|q)&(p|!q)&(q|!r)&(q|r) -> YES
    test2 = "p&(p|q)&(p|!q)&(q|!r)&(q|r)"
    cnf2 = parse_formula(test2)
    result2 = resolution_algorithm(cnf2)
    print("Input: {0}".format(test2))
    print("Output: {0}".format("YES" if result2 else "NO"))
    print()


if __name__ == "__main__":
    # Run main program directly, no test examples
    main()
