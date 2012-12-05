/* Exercício para Entrega (Individual) Data: 04/12/2012 */
/* • Uma padaria trabalha com 100 mercadorias diferentes identificadas pelos
 * números de 1 a 100. */
/* • O dono da padaria anota a quantidade de cada mercadoria vendida durante o
 * mês. Ele tem uma tabela que indica, para cada mercadoria, o preço de venda. */
/* • Desenvolva um sistema para calcular o faturamento mensal da padaria. */
/* – A tabela de preços é fornecida seguida pelos números das mercadorias e
 * as quantidades vendidas. */
/* – Quando uma mercadoria não tiver nenhuma venda, é informado o valor zero no
 * lugar da quantidade. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float products_prices[100];
int products_sold[100];
int length = sizeof(products_sold) / sizeof(int);

void read_prices_products_from_a_file(char *name_of_file) {
  FILE *in = fopen(name_of_file, "rt");
  char buffer[100];

  int i = 0;
  for (i = 0; i < length; i++) {
    fgets(buffer, 20, in);
    products_prices[i] = atoi(buffer);
  }

  fclose(in);
}

void generate_random_values_for_products_sold(int max_value) {
  int i = 0;
  srand(time(NULL));

  for (i = 0; i < length; i++) {
    products_sold[i] = rand() % max_value;
  }
}

float billing_of_month() {
  float total_billing = 0;
  int i = 0;

  for (i = 0; i < length; i++) {
    total_billing += products_prices[i] * products_sold[i];
  }

  return total_billing;
}

int main(int argc, const char *argv[]) {
  char *file = "lista_precos.txt";
  read_prices_products_from_a_file(file);

  generate_random_values_for_products_sold(5);

  printf("Faturamento mensal: R$ %g reais.\n" , billing_of_month());

  return 0;
}
