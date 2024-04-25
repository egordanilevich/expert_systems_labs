#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

// Define the initial state of working memory and the target state
set<string> workingMemory = {"L", "M", "N"};
set<string> targetState = {"gool"};

// Initialize an empty conflict memory
vector<int> conflictMemory;

// Initialize a variable to keep track of the steps
int step = 0;

// Define the set of rules
unordered_map<string, string> rules = {
    {"CH", "C"},
    {"IK", "D"},
    {"LM", "E"},
    {"N", "F"},
    {"O", "F"},
    {"C", "A"},
    {"D", "A"},
    {"E", "B"},
    {"F", "B"},
    {"A", "gool"},
    {"B", "gool"}
};

// Define a function to apply rules to the working memory
set<string> applyRules(const set<string>& wm) {
    set<string> newFacts;
    for (const auto& rule : rules) {
        bool canApplyRule = true;
        for (char antecedent : rule.first) {
            if (wm.find(string(1, antecedent)) == wm.end()) {
                canApplyRule = false;
                break;
            }
        }
        if (canApplyRule) {
            newFacts.insert(rule.second);
        }
    }
    return newFacts;
}

int main() {
    while (workingMemory != targetState) {
        step++;
        set<string> newFacts = applyRules(workingMemory);
        if (newFacts.empty()) {
            // If no new facts can be derived, add a conflict
            conflictMemory.push_back(step);
            if (conflictMemory[0] == step - 1) {
                break;
            }
        } else {
            // Add new facts to working memory
            workingMemory.insert(newFacts.begin(), newFacts.end());
            conflictMemory.clear();
        }

        cout << "Step " << step << "\tWorking memory: ";
        for (const string& fact : workingMemory) {
            cout << fact << " ";
        }
        cout << "\tConflict memory: ";
        for (const int& conflict : conflictMemory) {
            cout << conflict << " ";
        }
        cout << "\tRule used: " << step << endl;
    }

    if (workingMemory == targetState) {
        cout << "Target state reached in " << step << " steps." << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
