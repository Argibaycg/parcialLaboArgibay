#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_gets.h"
#include "clientes.h"
#include "pedidos.h"

#define OK 0
#define ERROR -1
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000

int listarPedidosPendientesInforme(s_pedido pedidos[], s_cliente clientes[])
{
	int retorno = -1;
	int i;
	int j;
	int auxiliar;
	int indexCliente;
	int flag = 0;
	for (i = 0; i < CANTIDAD_PEDIDOS; i++)
	{
		if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
		{
			auxiliar = pedidos[i].idCliente;
			for(j = 0; j < CANTIDAD_CLIENTES; j++)
			{
				if(clientes[j].idCliente==auxiliar)
				{
					indexCliente = j;
				}
			}
			printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
			"ID Cliente: %d\n La direccion es: %s %d\n"
			"Los kilos a recolectar son: %d"
			"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
			clientes[indexCliente].idCliente,clientes[indexCliente].direccion,clientes[indexCliente].altura,
			pedidos[i].kilosRetirados);
			flag = 1;
			retorno = 0;
		}
	}
		if(flag == 0)
		{
			printf("No hay pedidos a listar.\n");
		}

	return retorno;
}

