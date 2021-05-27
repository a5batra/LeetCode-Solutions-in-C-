//
// Created by Ankit Batra on 5/27/21.
//

/* A binary expression tree is a kind of binary tree used to represent arithmetic expressions.
 * Each node of a binary expression tree has either zero or two children.
 * Leaf nodes (nodes with 0 children) correspond to operands (numbers), and internal nodes
 * (nodes with 2 children) correspond to the operators '+' (addition), '-' (subtraction), '*' (multiplication), and '/' (division).
 * For each internal node with operator o, the infix expression that it represents is (A o B), where A is the expression
 * the left subtree represents and B is the expression the right subtree represents.
 * You are given a string s, an infix expression containing operands, the operators described above, and
 * parentheses '(' and ')'.
 * Return any valid binary expression tree, which its in-order traversal reproduces s after omitting
 * the parenthesis from it (see examples below).
 * Please note that order of operations applies in s.
 * That is, expressions in parentheses are evaluated first, and multiplication and division happen before
 * addition and subtraction.
 * Operands must also appear in the same order in both s and the in-order traversal of the tree. */

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int precedence(char c) {
        switch(c) {
            case '+': return 1;
            case '-': return 1;
            case '*': return 2;
            case '/': return 2;
        }
        return -1;
    }
    bool hasHigherPrecedence(char first, char second) {
        return precedence(first) >= precedence(second);
    }
    string infixToPostfix(string s) {
        string postfix = "";
        stack<char> st;

        for (char& c : s) {
            if (isdigit(c)) postfix += c;
            else if (c == '(') st.push(c);
            else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else {
                while (!st.empty() && hasHigherPrecedence(st.top(), c) && st.top() != '(') {
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while (!st.empty()) {
            postfix += st.top();
            st.pop();
        }
        return postfix;
    }
    Node* expTree(string s) {
        Node* root = nullptr;
        string postfix = infixToPostfix(s);

        stack<Node*> st;
        for (char& c : postfix) {
            if (isdigit(c)) st.push(new Node(c));
            else {
                Node* right = st.top();
                st.pop();
                Node* left = st.top();
                st.pop();
                st.push(new Node(c, left, right));
            }
        }

        return st.top();

    }
};

