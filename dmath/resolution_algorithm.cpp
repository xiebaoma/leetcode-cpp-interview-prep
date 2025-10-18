#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>

using namespace std;

// Class representing a literal (variable or its negation)
class Literal {
public:
    string variable;
    bool negated;
    
    Literal(const string& var, bool neg = false) : variable(var), negated(neg) {}
    
    // String representation
    string toString() const {
        return (negated ? "!" : "") + variable;
    }
    
    // Get negation of this literal
    Literal negate() const {
        return Literal(variable, !negated);
    }
    
    // Check if this literal is complementary to another
    bool isComplement(const Literal& other) const {
        return variable == other.variable && negated != other.negated;
    }
    
    // Operators for set operations
    bool operator<(const Literal& other) const {
        if (variable != other.variable) {
            return variable < other.variable;
        }
        return negated < other.negated;
    }
    
    bool operator==(const Literal& other) const {
        return variable == other.variable && negated == other.negated;
    }
};

// Class representing a clause (disjunction of literals)
class Clause {
public:
    set<Literal> literals;
    
    Clause() {}
    
    Clause(const vector<Literal>& lits) {
        for (const auto& lit : lits) {
            literals.insert(lit);
        }
    }
    
    // Add a literal to the clause
    void addLiteral(const Literal& lit) {
        literals.insert(lit);
    }
    
    // Check if clause is empty
    bool isEmpty() const {
        return literals.empty();
    }
    
    // Check if clause contains complementary literals
    bool containsComplementaryLiterals() const {
        for (const auto& lit1 : literals) {
            for (const auto& lit2 : literals) {
                if (lit1.isComplement(lit2)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    // String representation
    string toString() const {
        if (literals.empty()) {
            return "□";  // Empty clause
        }
        
        string result = "(";
        bool first = true;
        for (const auto& lit : literals) {
            if (!first) result += " | ";
            result += lit.toString();
            first = false;
        }
        result += ")";
        return result;
    }
    
    // Operator for set operations
    bool operator<(const Clause& other) const {
        return literals < other.literals;
    }
    
    bool operator==(const Clause& other) const {
        return literals == other.literals;
    }
};

// Class representing a CNF formula
class CNFFormula {
public:
    set<Clause> clauses;
    
    CNFFormula() {}
    
    // Add a clause to the formula
    void addClause(const Clause& clause) {
        if (!clause.containsComplementaryLiterals()) {
            clauses.insert(clause);
        }
    }
    
    // String representation
    string toString() const {
        if (clauses.empty()) {
            return "True";
        }
        
        string result;
        bool first = true;
        for (const auto& clause : clauses) {
            if (!first) result += " & ";
            result += clause.toString();
            first = false;
        }
        return result;
    }
};

// Utility function to trim whitespace
string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    if (first == string::npos) return "";
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

// Split string by delimiter
vector<string> split(const string& str, char delimiter) {
    vector<string> tokens;
    stringstream ss(str);
    string token;
    
    while (getline(ss, token, delimiter)) {
        tokens.push_back(trim(token));
    }
    
    return tokens;
}

// Parse formula string to CNF format
CNFFormula parseFormula(const string& formulaStr) {
    CNFFormula cnf;
    
    // Split into clauses by '&'
    vector<string> clauseStrings = split(formulaStr, '&');
    
    for (string clauseStr : clauseStrings) {
        clauseStr = trim(clauseStr);
        
        // Remove outer parentheses if present
        if (clauseStr.front() == '(' && clauseStr.back() == ')') {
            clauseStr = clauseStr.substr(1, clauseStr.length() - 2);
        }
        
        // Split by '|' to get literals
        vector<string> literalStrings = split(clauseStr, '|');
        Clause clause;
        
        for (string litStr : literalStrings) {
            litStr = trim(litStr);
            
            if (litStr.front() == '!') {
                // Negated literal
                string var = trim(litStr.substr(1));
                clause.addLiteral(Literal(var, true));
            } else {
                // Positive literal
                clause.addLiteral(Literal(litStr, false));
            }
        }
        
        cnf.addClause(clause);
    }
    
    return cnf;
}

// Resolve two clauses
Clause* resolveClauses(const Clause& clause1, const Clause& clause2) {
    // Find complementary literals
    for (const auto& lit1 : clause1.literals) {
        for (const auto& lit2 : clause2.literals) {
            if (lit1.isComplement(lit2)) {
                // Found complementary literals, perform resolution
                Clause* resolvent = new Clause();
                
                // Add all literals from clause1 except lit1
                for (const auto& lit : clause1.literals) {
                    if (!(lit == lit1)) {
                        resolvent->addLiteral(lit);
                    }
                }
                
                // Add all literals from clause2 except lit2
                for (const auto& lit : clause2.literals) {
                    if (!(lit == lit2)) {
                        resolvent->addLiteral(lit);
                    }
                }
                
                return resolvent;
            }
        }
    }
    
    return nullptr;
}

// Resolution algorithm
bool resolutionAlgorithm(const CNFFormula& cnf) {
    set<Clause> clauses = cnf.clauses;
    
    while (true) {
        set<Clause> newClauses;
        vector<Clause> clauseList(clauses.begin(), clauses.end());
        
        // Resolve all clause pairs
        for (size_t i = 0; i < clauseList.size(); i++) {
            for (size_t j = i + 1; j < clauseList.size(); j++) {
                Clause* resolvent = resolveClauses(clauseList[i], clauseList[j]);
                if (resolvent != nullptr) {
                    if (resolvent->isEmpty()) {
                        // Got empty clause, formula is unsatisfiable
                        delete resolvent;
                        return false;
                    }
                    newClauses.insert(*resolvent);
                    delete resolvent;
                }
            }
        }
        
        // If no new clauses produced, algorithm terminates
        bool hasNewClauses = false;
        for (const auto& clause : newClauses) {
            if (clauses.find(clause) == clauses.end()) {
                hasNewClauses = true;
                break;
            }
        }
        
        if (!hasNewClauses) {
            break;
        }
        
        // Add new clauses to the set
        for (const auto& clause : newClauses) {
            clauses.insert(clause);
        }
    }
    
    // No empty clause derived, formula is satisfiable
    return true;
}

int main() {
    string input;
    getline(cin, input);
    
    if (input.empty()) {
        return 0;
    }
    
    try {
        // Parse formula
        CNFFormula cnf = parseFormula(input);
        
        // Run resolution algorithm
        bool isSatisfiable = resolutionAlgorithm(cnf);
        
        // Output result
        cout << (isSatisfiable ? "YES" : "NO") << endl;
        
    } catch (...) {
        cout << "NO" << endl;  // Default output NO on error
    }
    
    return 0;
}
