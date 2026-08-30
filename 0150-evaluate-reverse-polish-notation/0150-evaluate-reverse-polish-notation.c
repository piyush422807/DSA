#include <stdlib.h>

int evalRPN(char** tokens, int tokensSize) {
    int stack[tokensSize];
    int top = 0;

    for (int i = 0; i < tokensSize; i++) {
        char op = tokens[i][0];

        
        if ((op == '+' || op == '-' || op == '*' || op == '/') && tokens[i][1] == '\0') {
            top--; 
            if (op == '+') stack[top - 1] += stack[top];
            if (op == '-') stack[top - 1] -= stack[top];
            if (op == '*') stack[top - 1] *= stack[top];
            if (op == '/') stack[top - 1] /= stack[top];
        } else {
            stack[top++] = atoi(tokens[i]);
        }
    }

    return stack[0];
}