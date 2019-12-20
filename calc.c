# Add & Subtract Calculator

/* Author : Youssef Dahab
File name: calc.c */

#include <stdio.h>
#include <string.h>

#define N 80

char a[N], b[N], res[N + 1];

void add(const char a[], const char b[], char res[])
{
  int i, j;             /*loop counters*/
  int temp = 0;         /*used to calculate carry digit*/
  int carry_digit = 0;
  int front_zeros = 0;

  /*do addition if strlen(a) = strlen(b)*/
  if (strlen(a) == strlen(b))                          
  {
    for (i = strlen(a) - 1; i >= 0; i--)
    {
      temp = (a[i] - '0') + (b[i] - '0') + carry_digit;
      res[i] = ((a[i] - '0') + (b[i] - '0') + carry_digit) % 10 + '0';
      carry_digit = temp / 10;
    }

    /*addition only ends when carry digit = 0
    res[0] = carry digit and move other array elements by offset of 1 since carry digit is missing*/
    if (carry_digit != 0)
    {
      for (i = strlen(a); i > 0; i--) res[i] = res[i - 1];
      res[0] = carry_digit + '0';
    }
  }


  /*do addition if strlen(a) > strlen(b)*/
  if (strlen(a) > strlen(b))                          
  {
    /*move elements of b[] to res[]*/
    for (i = 1, j = strlen(b) - 1; j >= 0; i++, j-- )
    {
      res[strlen(a) - i] = b[j];
    }
    

    /*fill up zeros until you reach the first non zero element in res[]*/
    for (i = 0; i < strlen(a) - strlen(b); i++)
    {
      res[i] = '0';
    }
    
    
    /*addition - now a[] and res[] are of the same length*/ 
    for (i = strlen(a) - 1; i >= 0; i--)
    {
      temp = (a[i] - '0') + (res[i] - '0') + carry_digit;
      res[i] = ((a[i] - '0') + (res[i] - '0') + carry_digit) % 10 + '0';
      carry_digit = temp / 10;
    }


    /*addition only ends when carry digit = 0
    res[0] = carry digit and move other array elements by offset of 1 to append carry digit*/
    if (carry_digit != 0)
    {
      for (i = strlen(a); i > 0; i--)
      {
        res[i] = res[i - 1];
      }
      res[0] = carry_digit + '0';
    }
  }

  
/*do addition if strlen(a) < strlen(b)*/
  if (strlen(a) < strlen(b))                          
  {
    /*move elements of a[] to res[]*/
    for (i = 1, j = strlen(a) - 1; j >= 0; i++, j-- )
    {
      res[strlen(b) - i] = a[j];
    }
    

    /*fill up zeros until you reach the first non zero element in res[]*/
    for (i = 0; i < strlen(b) - strlen(a); i++)
    {
      res[i] = '0';
    }
    
    
    /*addition - now b[] and res[] are of the same length*/ 
    for (i = strlen(b) - 1; i >= 0; i--)
    {
      temp = (b[i] - '0') + (res[i] - '0') + carry_digit;
      res[i] = ((b[i] - '0') + (res[i] - '0') + carry_digit) % 10 + '0';
      carry_digit = temp / 10;
    }


    /*addition only ends when carry digit = 0
    res[0] = carry digit and move other array elements by offset of 1 to append carry digit*/
    if (carry_digit != 0)
    {
      for (i = strlen(b); i > 0; i--)
      {
        res[i] = res[i - 1];
      }
      res[0] = carry_digit + '0';
    }
  }


  /*remove front zeros*/
  for (i = 0; i < strlen(res); i++)
  {
    if (res[i] == '0') front_zeros += 1;
    else break;
  }

  if (front_zeros < strlen(res)) for (i = 0; i < front_zeros; i++) res[i] = ' ';

  else if (front_zeros == strlen(res))
  {
    res[strlen(res) - 1] = '0';
    for (i = 0; i < strlen(res) - 1; i++) res[i] = ' ';
  }
}


void sub(const char a[], const char b[], char res[])
{
  int i, j;                 /*loop counters*/
  int a_is_greater = 0;     /*determine if a > b or a < b*/
  int carry_digit = 0;
  int front_zeros = 0;


  if (strlen(a) == strlen(b))
  {
    /*determine if a > b or a < b*/
    for (i = 0; i < strlen(a); i++)
    {
      if (a[i] > b[i])
      {
        a_is_greater = 1;
        break;
      }
      else if (a[i] < b[i]) break;
    }


    /*subtraction if a > b*/
    if (a_is_greater == 1)
    {
      for (i = strlen(a) - 1; i >= 0; i--)
      {
        if (a[i] < b[i])
        {
          res[i] = ((a[i] -'0') + 10 - (b[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 1;  
        }
        
        else if (a[i] > b[i])
        {
          res[i] = ((a[i] -'0') + 10 - (b[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 0;
        }
        
        else res[i] = ((a[i] -'0') + 10 - (b[i] - '0') - carry_digit) % 10 + '0';
      }
    }

    
    /*subtraction if a < b*/
    else if (a_is_greater == 0)
    {
      for (i = strlen(a) - 1; i >= 0; i--)
      {
        if (b[i] > a[i])
        {
          res[i] = ((b[i] -'0') + 10 - (a[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 0;  
        }
        
        else if (b[i] < a[i])
        {
          res[i] = ((b[i] -'0') + 10 - (a[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 1;
        }
        
        else res[i] = ((b[i] -'0') + 10 - (a[i] - '0') - carry_digit) % 10 + '0';
      }
    }
  }
/****************************************************************************************/
  else if (strlen(a) > strlen(b))
  {
    /*move elements of b[] to res[]*/
    for (i = 1, j = strlen(b) - 1; j >= 0; i++, j-- )
    {
      res[strlen(a) - i] = b[j];
    }
    
    /*fill up zeros until you reach the first non zero element in res[]*/
    for (i = 0; i < strlen(a) - strlen(b); i++)
    {
      res[i] = '0';
    }


    /*determine if a > b or a < b*/
    for (i = 0; i < strlen(a); i++)
    {
      if (a[i] > res[i])
      {
        a_is_greater = 1;
        break;
      }
      else if (a[i] < res[i]) break;
    }


    /*subtraction if a > b where b is stored in res*/
    if (a_is_greater == 1)
    {
      for (i = strlen(a) - 1; i >= 0; i--)
      {
        if (a[i] < res[i])
        {
          res[i] = ((a[i] -'0') + 10 - (res[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 1;  
        }
        
        else if (a[i] > res[i])
        {
          res[i] = ((a[i] -'0') + 10 - (res[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 0;
        }
        
        else res[i] = ((a[i] -'0') + 10 - (res[i] - '0') - carry_digit) % 10 + '0';
      }
    }

    /*subtraction if a < b where a is stored in res*/
    else if (a_is_greater == 0)
    {
      for (i = strlen(a) - 1; i >= 0; i--)
      {
        if (res[i] > a[i])
        {
          res[i] = ((res[i] -'0') + 10 - (a[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 0;  
        }
        
        else if (res[i] < a[i])
        {
          res[i] = ((res[i] -'0') + 10 - (a[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 1;
        }
        
        else res[i] = ((res[i] -'0') + 10 - (a[i] - '0') - carry_digit) % 10 + '0';
      }
    }
  }
/********************************************************************************************/
  else if (strlen(a) < strlen(b))
  {
    /*move elements of a[] to res[]*/
    for (i = 1, j = strlen(a) - 1; j >= 0; i++, j-- )
    {
      res[strlen(b) - i] = a[j];
    }
    
    /*fill up zeros until you reach the first non zero element in res[]*/
    for (i = 0; i < strlen(b) - strlen(a); i++)
    {
      res[i] = '0';
    }

    /*determine if a > b or a < b*/
    for (i = 0; i < strlen(res); i++)
    {
      if (res[i] > b[i])
      {
        a_is_greater = 1;
        break;
      }
      else if (res[i] < b[i]) break;
    }


    /*subtraction if a > b where a is stored in res*/
    if (a_is_greater == 1)
    {
      for (i = strlen(res) - 1; i >= 0; i--)
      {
        if (res[i] < b[i])
        {
          res[i] = ((res[i] -'0') + 10 - (b[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 1;  
        }
        
        else if (res[i] > b[i])
        {
          res[i] = ((res[i] -'0') + 10 - (b[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 0;
        }
        
        else res[i] = ((res[i] -'0') + 10 - (b[i] - '0') - carry_digit) % 10 + '0';
      }
    }

    /*subtraction if a < b where a is stored in res*/
    else if (a_is_greater == 0)
    {

      for (i = strlen(res) - 1; i >= 0; i--)
      {
        if (b[i] < res[i])
        {
          res[i] = ((b[i] -'0') + 10 - (res[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 1;  
        }
        
        else if (b[i] > res[i])
        {
          res[i] = ((b[i] -'0') + 10 - (res[i] - '0') - carry_digit) % 10 + '0';
          carry_digit = 0;
        }
        
        else res[i] = ((b[i] -'0') + 10 - (res[i] - '0') - carry_digit) % 10 + '0';
      }
    } 
  }


  if (a_is_greater == 1)
  {
    /*remove front zeros from res*/
      for (i = 0; i < strlen(res); i++)
      {
        if (res[i] == '0') front_zeros += 1;
        else break;
      }
      
      if (front_zeros < strlen(res)) for (i = 0; i < front_zeros; i++) res[i] = ' ';
      else if (front_zeros == strlen(res))
      {
        res[strlen(res) - 1] = '0';
        for (i = 0; i < strlen(res) - 1; i++) res[i] = ' ';
      }
  }

  else if (a_is_greater == 0)
  {
    /*remove front zeros from res*/
      for (i = 0; i < strlen(res); i++)
      {
        if (res[i] == '0') front_zeros += 1;
        else break;
      }

      /*append negative sign to res*/
      if (front_zeros == 0)
      {
        for (i = strlen(res); i > 0; i--) res[i] = res[i - 1];
        res[0] = '-';
      }

      if (front_zeros < strlen(res)) 
      {
        for (i = 0; i < front_zeros - 1; i++) res[i] = ' ';
        res[front_zeros - 1] = '-';
      }

      if (front_zeros == strlen(res))
      {
        res[strlen(res) - 1] = '0';
        for (i = 0; i < strlen(res) - 1; i++) res[i] = ' ';
      }
  }
}

int main()
{
  char op;
  scanf("%s %s %c", a, b, &op);

  switch (op)
  {
  case '+': add(a, b, res); break;
  case '-': sub(a, b, res);
  }
  
  char buf[20];

  int l1 = strlen(a), l2 = strlen(b), l3 = strlen(res);
  int m = l1 > l2 ? l1 : l2;
  m = m > l3 ? m : l3;

  sprintf(buf, "%%  %ds\n%%  %ds\n%%  %ds\n", m, m, m);
  printf(buf, a, b, res);

  return 0;
}
