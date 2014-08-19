// By Penguin, 2014.08
//
// Genereate Fibonacci
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

const char* const short_options = "ha:s:";

const struct option long_options[] = {
  {"help", 0, NULL, 'h'},
  {"all", 1, NULL, 'a'},
  {"specify", 1, NULL, 's'},
  {NULL, 0, NULL, 0}
};

void generate_fibonacci(unsigned int n);
long long fibonacci(unsigned int n);

void print_usage(void)
{
  printf("Generate Fibonacci:\n");
  printf("-h   -help     Display help info\n");
  printf("-a n -all      Display all the fibonacci data from 0 to n\n");
  printf("-s n -specify  Display the nth fibonacci data\n");
}

int main(int argc, char *argv[])
{
  int option;
  unsigned int n;

  do {
    option = getopt_long(argc, argv, short_options, long_options, NULL);
    switch(option)
    {
      case 'h':
        print_usage();
	      break;

      case 'a':
	      n = atoi(optarg);
        generate_fibonacci(n);
        break;

      case 's':
    	  n = atoi(optarg);
	      printf("fibonacci n: %lld\n", fibonacci(n));
	      break;

      case -1:
	      break;
    
      defaule:
	      printf("Unsupported option %c\n", option);
	      break;
    } 
  } while(option != -1);


  return 0;
}

void generate_fibonacci(unsigned int n)
{
  long long *f_array;
  unsigned int i;

  f_array = malloc(sizeof(long long) * (n+1));
  memset(f_array, 0, sizeof(long long) * (n+1));

  f_array[0] = 0;
  f_array[1] = 1;

  for (i = 2; i < n + 1; i++)
  {
    f_array[i] = f_array[i - 1] + f_array[i - 2];
  }

  printf("fibonacci:");
  for (i = 0; i < n + 1; i++)
  {
    printf(" %lld", f_array[i]);
  }
  printf("\n");
}

// This will be very slow when n > 45
long long fibonacci(unsigned int n)
{
  long long ret;
  if (n == 0)
  {
    ret = 0;
    return ret;
  }
  else if (n == 1)
  {
    ret = 1;
    return ret;
  }
  else
  {
    ret = fibonacci(n - 1) + fibonacci(n - 2);
  }

  return ret;
}
