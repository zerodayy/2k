#include<stdio.h>
#include<time.h>
#include<string.h>

#define max_levels 6

void menu(void);
int function_1(int);

char levels[max_levels][300] =
{
  {"Hello World"},
  {"example 2"},
  {"another one"},
  {"I feel like"},
  {"you know where"},
  {"i am going with this"}
};
int i;

// Typing Game by zerodayy

int main ()
{
  int option,res;
  printf("### Wellcome to the typing game ###\n");
  printf("select dificulity level:\n");
  do
  {
    menu();
    scanf("%d",&option);
    if (option == 0)
      return 0;
    while ((option > max_levels) || (option < 0))
    {
      printf("non valid option\n select again:");
      scanf("%d",&option);
    }
    res = function_1(option);
    if (res < 0)
    {
      printf("Game over\n Press 0 to exit\n");
    }
  } while (1);
  return 0;
}

void menu()
{
  for (i=1; i<=max_levels; i++)
    printf("Level %d\n",i);
}

function_1(int option)
{
  char text[300];
  char text1[20];
  time_t t1,t2;
  int t3;
  printf("For this challenge you have to write:\n%s",levels[option]);
  printf("\nPress enter when ready\n");
  scanf("%s",text1);
  t1 = time(NULL);
  scanf("%s",text);
  t2 = time(NULL);
  if (strcmp(text,levels[option])!=0)
  {
    printf("You made a mistake\n");
    return -1;
  }
  else
  {
    t3 = t2 - t1;
    printf("you finished in %d seconds\n",t3);
    return 1;
  }
}
