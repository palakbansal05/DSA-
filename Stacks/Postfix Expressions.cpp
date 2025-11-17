 // Time Complexitinty: O(n)
 // Space Complexity: O(n)

class Solution{
public:
    int evaluatePostfix(const string& expression) {
        stack<int> s; // Stack to hold operands
        istringstream iss(expression);
        string token;

        while (iss >> token) {
            // If the token is an operator, pop two operands and apply the operator
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int operand2 = s.top(); s.pop();
                int operand1 = s.top(); s.pop();
                int result;

                if (token == "+") {
                    result = operand1 + operand2;
                } else if (token == "-") {
                    result = operand1 - operand2;
                } else if (token == "*") {
                    result = operand1 * operand2;
                } else if (token == "/") {
                    result = operand1 / operand2;
                }
                s.push(result); // Push the result back onto the stack
            } 
            // If the token is an operand, convert it to integer and push onto the stack
            else {
                s.push(stoi(token));
            }
        }
        return s.top(); // The final result is the only element left in the stack
    }
};