#include <stdio.h>

int main(void){
	float capTanque, consuKmPorLitro, valorLitro, quilometragemTotal;
	char tipoCombustivel;
	
	printf("Informe a capacidade do tanque em litros: ");
	scanf("%f", &capTanque);
	printf("Informe o tipo de combust�vel: ");
	scanf("%c", &tipoCombustivel);
	printf("Informe a dist�ncia por litro (km/h) do carro: ");
	scanf("%f", &consuKmPorLitro);
	printf("Informe o valor do litro de combust�vel: ");
	scanf("%f", &valorLitro);
	printf("informe a dist�ncia total: ");
	scanf("%f", quilometragemTotal);
	
	float reserva = capTanque * 0.1;
	printf("\n\nReserva: %.2f", reserva);
	
	float litrosRestantes = capTanque - reserva;
	float autonomia = litrosRestantes * consuKmPorLitro;
	printf("\nAutonomia: %.2f km", autonomia);
	
	float custoTotal = capTanque * valorLitro;
	printf("\nCusto total para abastecimento: R$%.2f", custoTotal);
	
	if(quilometragemTotal <= autonomia){
		printf("A viagem pode ser realizada sem reabastecimento.");
		float custoTrecho = (quilometragemTotal / consuKmPorLitro)*valorLitro;
		printf("\nCusto totalde combust�vel no trecho: R$%.2f", custoTrecho);
	}else {
		printf("Haver� necessidade de reabastecimento!");
	}
	
	return 0;
}
