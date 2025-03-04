#include <stdio.h>
#include <string.h>

void infixTOprefix(char infix[], char prefix[]);
int precedency(char c);
void reverseString(char str[]);

int main() 
{
  char infix[100], prefix[100];  
  printf("Enter infix expression: ");
  scanf("%s", infix);  

  infixTOprefix(infix, prefix);  

  printf("Prefix Expression: %s\n", prefix);
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


void reverseString(char str[]) 
{
  int n = strlen(str);
  for (int i = 0; i < n / 2; i++) 
  {
    char temp = str[i];
    str[i] = str[n - i - 1];
    str[n - i - 1] = temp;
  }
}


void infixTOprefix(char infix[], char prefix[]) 
{
  int ps_tos = 0, op_tos = -1;
  char op_stack[100];
  reverseString(infix);
  for (int i = 0; i < strlen(infix); i++) 
  { 
    char c = infix[i];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
    {
      prefix[ps_tos++] = c;
    } 
    else if (c == ')') 
    {
      op_stack[++op_tos] = c;
    } 
    else if (c == '(') 
    {
      while (op_tos >= 0 && op_stack[op_tos] != ')') 
      {
        prefix[ps_tos++] = op_stack[op_tos--];
      }
      if (op_tos >= 0) 
      {
                op_tos--;  // Remove ')' from stack
      }
    } 
    else 
    {  
      while (op_tos >= 0 && precedency(op_stack[op_tos]) > precedency(c)) 
      {
        prefix[ps_tos++] = op_stack[op_tos--];
      }
        op_stack[++op_tos] = c;
    }
  }
  while (op_tos >= 0) 
  {  
    prefix[ps_tos++] = op_stack[op_tos--];
  }
  prefix[ps_tos] = '\0';  // Null-terminate the prefix string
  reverseString(prefix);
}
