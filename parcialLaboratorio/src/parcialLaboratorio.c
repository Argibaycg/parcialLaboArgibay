#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_gets.h"
#include "clientes.h"
#include "pedidos.h"
#include "informes.h"

#define OK 0
#define ERROR -1
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000

int main(void) {



	s_cliente clientes[CANTIDAD_CLIENTES] = {
			{"Pepsico","23-22333444-0","mitre",234,"avellaneda",130,1},
			{"Terrabusi","22-22444444-0","belgrano",123,"varela",131,1}
	};
	s_pedido pedidos[CANTIDAD_PEDIDOS];

	int idCliente = CANTIDAD_CLIENTES;
	int idPedido = CANTIDAD_PEDIDOS;
	int opcion = 0;
	int indexCliente;
	int indexPedido;

	//initIsEmptyClientes(clientes,CANTIDAD_CLIENTES);
	initIsEmptyPedidos(pedidos,CANTIDAD_PEDIDOS);
	do {
					__fpurge(stdin);
					printf("1) ALTA CLIENTE\n");
					printf("2) MODIFICAR DATOS DE CLIENTE\n");
					printf("3) BAJA DE CLIENTE\n");
					printf("4) CREAR PEDIDO DE RECOLECCION\n");
					printf("5) PROCESAR RESIDUOS\n");
					printf("6) IMPRIMIR CLIENTES\n");
					printf("7) IMPRIMIR PEDIDOS PENDIENTES\n");
					printf("8) IMPRIMIR PEDIDOS PROCESADOS\n");
					printf("9) SALIR\n");
					utn_getInt(&opcion);
					switch (opcion) {
					case 1:
						indexCliente = searchClienteEmpty(clientes,CANTIDAD_CLIENTES);
						if(altaCliente(clientes,indexCliente,idCliente)==0)
						{
						idCliente++;
						}
						break;
					case 2:modificarCliente(clientes,CANTIDAD_CLIENTES);
							;
						break;
					case 3:
						listarClientes(clientes,CANTIDAD_CLIENTES);
						bajaCliente(clientes);
						;
						break;
					case 4:
						listarClientes(clientes,CANTIDAD_CLIENTES);
					    indexPedido = searchPedidoEmpty(pedidos,CANTIDAD_PEDIDOS);
						if(altaDePedido(pedidos,indexPedido,idPedido)==0)
					    {
						idPedido++;
					    }
						break;
					case 5:
						if(listarPedidosPendientes(pedidos,CANTIDAD_PEDIDOS)==0)
						{
						procesarResiduos(pedidos);
						}
						break;
					case 6:listarClientes(clientes,CANTIDAD_CLIENTES);
						break;
					case 7:listarPedidosPendientesInforme(pedidos,clientes);
						break;
					case 8:
						;
						break;
					case 9:
						;
						break;
					default:
						printf("No ingreso una opcion valida.");
						break;
					}
				} while (opcion != 9);

	return OK;
}
