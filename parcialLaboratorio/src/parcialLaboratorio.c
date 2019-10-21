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
			{"Telefonica","30-11223344-5","Lima",1234,"CABA",1,1},
			{"DATASOFT","30-44556677-6","Corrientes",2547,"CABA",2,1},
			{"NESTLE","30-88995521-9","cucha cucha",555,"LANUS",3,1},
			{"TERRABUSI","30-56781423-5","rocha",784,"QUILMES",4,1},
			{"DIA","31-54581253-3","Mitre",750,"AVELLANEDA",5,1},
			{"QUILMES","30-51485759-6","rocha",741,"QUILMES",6,1}
	};
	s_pedido pedidos[CANTIDAD_PEDIDOS] = {
			{1000,200,145,230,1,1,1,1},
			{800,210,45,30,2,1,1,1},
			{100,0,0,0,3,2,0,1},
			{300,0,0,0,4,2,0,1},
			{1500,500,150,270,5,3,1,1},
			{750,100,50,70,6,4,1,1},
			{200,0,0,0,7,1,0,1},
			{30,10,5,3,8,5,1,1},
			{456,0,0,0,9,6,0,1}
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
					printf("9) INFORMES\n");
					printf("10) SALIR\n");
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
					case 9: menuInformes(pedidos, clientes);
						break;
					case 10:
						printf("Gracias por usar el programa.\n");
						break;
					default:
						printf("No ingreso una opcion valida.");
						break;
					}
				} while (opcion != 10);

	return OK;
}
