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
			{"Pepsico","23-22333444-0","mitre",1230,"avellaneda",130,1},
			{"Terrabusi","22-22444444-0","belgrano",123,"varela",132,1},
			{"Pertutti","23-22333444-0","zeballos",234,"avellaneda",133,1},
			{"Savant","22-22444444-0","lacarra",65,"gerli",134,1},
			{"Tregar","22-22444333-0","alsina",1000,"lanus",131,1}
	};
	s_pedido pedidos[CANTIDAD_PEDIDOS] = {
			{1000,0,0,0,1020,132,0,1},
			{200,100,200,300,1021,134,1,1},
			{233,0,0,0,1022,131,0,1},
			{100,0,0,0,1023,133,0,1},
			{600,200,0,0,1024,133,1,1},
			{233,0,0,0,1025,131,0,1},
			{0,0,50,50,1026,132,1,1},
			{900,0,0,0,1027,130,0,1}
	};

	int idCliente = CANTIDAD_CLIENTES;
	int idPedido = CANTIDAD_PEDIDOS;
	int opcion = 0;
	int indexCliente;
	int indexPedido;
	int auxIdParaAlta;

	//initIsEmptyClientes(clientes,CANTIDAD_CLIENTES);
	//initIsEmptyPedidos(pedidos,CANTIDAD_PEDIDOS);
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
						break;
					case 3:
						listarClientes(clientes,CANTIDAD_CLIENTES);
						bajaCliente(clientes);
						;
						break;
					case 4:
						ordenarClientesPorId(clientes,CANTIDAD_CLIENTES);
						listarClientes(clientes,CANTIDAD_CLIENTES);
						if(bucarClienteExistente(clientes,CANTIDAD_CLIENTES, &auxIdParaAlta)==0)
						{
					    indexPedido = searchPedidoEmpty(pedidos,CANTIDAD_PEDIDOS);
						if(altaDePedido(pedidos,indexPedido,idPedido,auxIdParaAlta)==0)
					    {
						idPedido++;
					    }
						}else
						{
							printf("No existe el cliente con ese id para recolectar.\n");
						}
						break;
					case 5:
						if(listarPedidosPendientes(pedidos,CANTIDAD_PEDIDOS)==0)
						{
						procesarResiduos(pedidos);
						}
						break;
					case 6:ordenarPedidosPorId(pedidos,CANTIDAD_PEDIDOS);
					listarCantidadPedidosPendientes(pedidos,clientes);
						break;
					case 7:ordenarPedidosPorId(pedidos,CANTIDAD_PEDIDOS);
						listarPedidoPendientes(pedidos,clientes);
						break;
					case 8:ordenarPedidosPorId(pedidos,CANTIDAD_PEDIDOS);
						listarPedidosCompletos(pedidos,clientes);
						break;
					case 9:
						printf("Gracias por usar el programa.\n");
						break;
					default:
						printf("No ingreso una opcion valida.");
						break;
					}
				} while (opcion != 9);

	return OK;
}
