#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_gets.h"
#include "pedidos.h"

#define OK 0
#define ERROR -1
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000


int initIsEmptyPedidos(s_pedido pedidos[], int cantidad)
{
	int i;
	if(pedidos != NULL && cantidad > 0)
	{
		for (i = 0; i < cantidad; i++)
		{
			pedidos[i].isEmpty = 0;
		}
	}
	return 0;
}

int searchPedidoEmpty(s_pedido pedidos[], int cantidad)
{
	int retorno = ERROR;
	int i;
	if(pedidos != NULL && cantidad > 0)
	{
		if(pedidos != NULL && cantidad > 0)
		{
			for (i = 0; i < cantidad; i++)
			{
				if (pedidos[i].isEmpty == 0)
				{
					return i;
				}
			}
		}
	}
	return retorno;
}

int listarPedidosPendientes(s_pedido pedidos[], int cantidad)
{
	int retorno = -1;
	int i;
	int flag = 0;
	for (i = 0; i < cantidad; i++)
	{
		if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
		{
			printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
					"ID pedido: %d\n"
					"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
					pedidos[i].idPedido);
			retorno = 0;
			flag = 1;
		}
	}
		if(flag == 0)
		{
			printf("No hay pedidos a listar.\n");
		}

	return retorno;
}

int altaDePedido(s_pedido pedidos[],int index, int idPedido)
{
	int retorno = -1;
	int auxiliar;
	int flag = 0;

	if (flag == 0)
	{
		if (utn_getNumber(&auxiliar,2000,100,2,"Ingrese id cliente:\n","Id no fue ingresado correctamente\n")== 0)
		{
			pedidos[index].idCliente = auxiliar;
		} else
		{
			flag = 1;
		}
		if (utn_getNumber(&auxiliar,10000,100,2,"Ingrese Cantidad de kilos a retirar entre sin coma 100-1000:\n",
												"Fuera de rango valido\n")== 0)
		{
			pedidos[index].kilosRetirados = auxiliar;
		} else
		{
			flag = 1;
		}
	if (flag == 0)
		{
			pedidos[index].isEmpty = 1;
			pedidos[index].idPedido = idPedido;
			pedidos[index].estado = 0;
			retorno = 0;
		}
	}

	return retorno;
}

int buscarPedidoPorId(s_pedido pedidos[], int idPedido,int *pUbicacionPedido)
{
	int retorno = -1;
	int i;
	for (i = 0; i != idPedido; i++)
	{
		if (pedidos[i].idPedido == idPedido)
		{
			*pUbicacionPedido = i;
			retorno = 0;
		}
	}
	return retorno;
}

int procesarResiduos(s_pedido pedidos[])
{

	int index;
	int idPedido;
	int auxHPDE;
	int auxLDPE;
	int auxPP;
	int auxKilosRetirados;
	int flag = 0;

	if(utn_getNumber(&idPedido, 60000, 0, 2, "Ingrese el id del cliente.\n",
												  "Dato no valido.\n")==0)
	{

		buscarPedidoPorId(pedidos,idPedido,&index);
		auxKilosRetirados = pedidos[index].kilosRetirados;
		printf("La cantidad de kilos para procesar en este pedido es: %d\n", pedidos[index].kilosRetirados);
		utn_getNumber(&auxHPDE,1000,10,2,"CUantos kilos se procesan como HPDE?\n","Ingreso Invalido.\n");
		if(auxHPDE > pedidos[index].kilosRetirados)
		{
			printf("No podemos procesar mas que lo que tenemos.\n");
			flag = 1;
		}else if(auxHPDE <= 0)
		{
			printf("No puede ser cero.\n");
			flag = 1;
		}else
		{
			pedidos[index].kilosHDPE = auxHPDE;
			auxKilosRetirados = auxKilosRetirados - auxHPDE;
			printf("Quedan %d kilos para seguir procesando.\n", auxKilosRetirados);
		}
		utn_getNumber(&auxLDPE,1000,10,2,"CUantos kilos se procesan como LDPE?.\n","Ingreso Invalido.\n");
		if(auxLDPE > pedidos[index].kilosRetirados)
		{
			printf("No podemos procesar mas que lo que tenemos.\n");
			flag = 1;
		}else if(auxLDPE <= 0)
		{
			printf("No puede ser cero.\n");
			flag = 1;
		}else
		{
			pedidos[index].kilosLDPE = auxLDPE;
			auxKilosRetirados = auxKilosRetirados - auxLDPE;
			printf("Quedan %d kilos para seguir procesando.\n", auxKilosRetirados);
		}
		utn_getNumber(&auxPP,1000,10,2,"CUantos kilos se procesan como HPDE?\n","Ingreso Invalido.\n");
		if(auxPP > pedidos[index].kilosRetirados)
		{
			printf("No podemos procesar mas que lo que tenemos.\n");
			flag = 1;
		}else if(auxPP <= 0)
		{
			printf("No puede ser cero.\n");
			flag = 1;
		}else
		{
			pedidos[index].kilosPP = auxPP;
			auxKilosRetirados = auxKilosRetirados - auxPP;
			printf("Quedan %d kilos para seguir procesando.\n", auxKilosRetirados);
		}
		if(flag==0)
		{
			pedidos[index].estado = 1;
		}
	}

	return 0;
}
