#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "minunit.h"

int tests_run = 0;
int length = 0;

void read_prices_products_from_a_file(char *name_of_file, float *prices) {
  FILE *in = fopen(name_of_file, "rt");
  char buffer[100];

  int i = 0;
  for (i = 0; i < length; i++) {
    fgets(buffer, 20, in);
    prices[i] = atof(buffer);
  }

  fclose(in);
}

void generate_random_values_of_products_sold(int max_value, int *products_sold) {
  int i = 0;
  srand(time(NULL));

  for (i = 0; i < length; i++) {
    products_sold[i] = rand() % max_value;
  }
}

float billing_of_month(float *products_prices, int *products_sold) {
  float total_billing = 0;
  int i = 0;

  for (i = 0; i < length; i++) {
    total_billing += products_prices[i] * products_sold[i];
  }

  return total_billing;
}

static char * test_length_of_products_sold() {
  length = sizeof(int[100]) / sizeof(int);
  mu_assert("error, length != 100", length == 100);
  return 0;
}

static char * test_billing_of_month() {
  float prices[100];
  int   sold[100];
  length = sizeof(sold) / sizeof(int);

  char *file = "lista_precos.txt";
  read_prices_products_from_a_file(file, prices);

  int i = 0;
  for (i = 0; i < length; i++) {
    sold[i] = 1;
  }

  mu_assert("error, billing_of_month != 485.899780",
      billing_of_month(prices, sold) == 485.899790);

  return 0;
}

static char * all_tests() {
  mu_run_test(test_length_of_products_sold);
  /* mu_run_test(test_billing_of_month); */

  return 0;
}

int main(int argc, char **argv) {
  char *result = all_tests();
  if (result != 0) {
    printf("%s\n", result);
  }
  else {
    printf("ALL TESTS PASSED\n");
  }
  printf("Tests run: %d\n", tests_run);

  return result != 0;
}

/* int main(int argc, const char *argv[]) { */
/*   float prices[100]; */
/*   int   sold[100]; */
/*   length = sizeof(sold) / sizeof(int); */
/*  */
/*   char *file = "lista_precos.txt"; */
/*   read_prices_products_from_a_file(file, prices); */
/*  */
/*   int i = 0; */
/*   for (i = 0; i < length; i++) { */
/*     sold[i] = 1; */
/*   } */
/*  */
/*   printf("Faturamento mensal: R$ %f reais.\n", billing_of_month(prices, sold)); */
/*  */
/*   return 0; */
/* } */
