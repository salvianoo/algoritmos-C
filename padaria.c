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

float mercadorias_precos[100];
int mercadorias_vendidas[100];

float faturamento_total = 0;
int length = sizeof(mercadorias_vendidas) / sizeof(int);

void setup_mercadorias_vendidas_precos() {
  srand(time(NULL));
  int i = 0;

  for (i = 0; i <= length; i++) {
    mercadorias_precos[i] = rand() % 40;

    mercadorias_vendidas[i] = rand() % 5;
  }
}

float faturamento_mensal() {
  int i = 0;

  for (i = 0; i <= length; i++) {
    faturamento_total +=
      mercadorias_precos[i] * mercadorias_vendidas[i];
  }

  return faturamento_total;
}

int main(int argc, const char *argv[]) {
  setup_mercadorias_vendidas_precos();

  printf("Faturamento mensal: R$ %g reais.\n" , faturamento_mensal());

  return 0;
}
