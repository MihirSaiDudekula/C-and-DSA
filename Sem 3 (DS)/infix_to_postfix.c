#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

int priority(char x) {
    if (x == '(') {
        return 0;
    } else if (x == '+' || x == '-') {
        return 1;
    } else if (x == '/' || x == '*') {
        return 2;
    } else {
        // Default priority for other characters (handle differently if needed)
        return -1;
    }
}

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int main() {
    char exp[100], *e, x, postfix[100];
    int pos = 0; // Position tracker for the postfix expression
    printf("Enter the infix expression: ");
    scanf("%s", exp);
    e = exp;

    while (*e != '\0') {
        if (isalnum(*e)) {
            postfix[pos++] = *e;
        } else if (*e == '(') {
            push(*e);
        } else if (*e == ')') {
            while ((x = pop()) != '(') {
                postfix[pos++] = x;
            }
        } else { // Operator encountered
            while (priority(stack[top]) >= priority(*e)) {
                postfix[pos++] = pop();
            }
            push(*e);
        }
        e++;
    }

    while (top != -1) {
        postfix[pos++] = pop();
    }
    postfix[pos] = '\0'; // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);

    return 0;
}


// Pointer-based Iteration (*e):

//     Advantages:
//         Pointer-based traversal is efficient, especially when dealing with strings and characters.
//         Avoids the need to use an index variable explicitly.
//         Allows direct manipulation of the pointer to move through characters, making the code concise.

// char exp[] = "3 + 4 * (5 - 2)";
// char *e = exp; // Initialize pointer

// while (*e != '\0') {
//     // Process characters using *e
//     printf("%c ", *e); // Example: Print current character
//     e++; // Move to the next character
// }
