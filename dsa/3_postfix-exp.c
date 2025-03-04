#include <stdio.h>
#include <string.h>

void infixTOpostfix(char infix[], char post_stack[]);
int precedency(char c);

int main() {
    char infix[100], postfix[100];  
    printf("Enter infix expression: ");
    scanf("%s", infix);  

    infixTOpostfix(infix, postfix);  

    printf("Postfix Expression: %s\n", postfix);
    printf("\n-----------------------------------\n");
    printf("Programmed By Rabin Acharya.\n");
    return 0;
}

int precedency(char c) {
    if (c == '$')
        return 4;
    else if (c == '/' || c == '*')
        return 3;
    else if (c == '+' || c == '-')
        return 2;
    else
        return 1;
}

void infixTOpostfix(char infix[], char post_stack[]) {
    int ps_tos = 0, op_tos = -1;
    char op_stack[100];

    for (int i = 0; i < strlen(infix); i++) { 
        char c = infix[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            post_stack[ps_tos++] = c;
        } 
        else if (c == '(') {
            op_stack[++op_tos] = c;
        } 
        else if (c == ')') {
            while (op_tos >= 0 && op_stack[op_tos] != '(') {
                post_stack[ps_tos++] = op_stack[op_tos--];
            }
            if (op_tos >= 0) {
                op_tos--;  // Remove '(' from stack
            }
        } 
        else {  
            while (op_tos >= 0 && precedency(op_stack[op_tos]) >= precedency(c)) {
                post_stack[ps_tos++] = op_stack[op_tos--];
            }
            op_stack[++op_tos] = c;
        }
    }

    while (op_tos >= 0) {  
        post_stack[ps_tos++] = op_stack[op_tos--];
    }

    post_stack[ps_tos] = '\0';  // Null-terminate the postfix string
}


