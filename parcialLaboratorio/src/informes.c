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

/** \brief lista los pedidos pendientes
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listarPedidoPendientes(s_pedido pedidos[], s_cliente clientes[])
{
	int retorno = ERROR;
	int i;
	int j;
	int auxiliar;
	int indexCliente;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
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
				"CUIT: %s\nLa direccion es: %s %d\n"
				"Los kilos a recolectar son: %d\n"
				"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
				clientes[indexCliente].cuitCliente,clientes[indexCliente].direccion,clientes[indexCliente].altura,
				pedidos[i].kilosRetirados);
				flag = 1;
				retorno = OK;
			}
		}
			if(flag == 0)
			{
				printf("No hay pedidos a listar.\n");
			}
	}
	return retorno;
}

/** \brief lista los pedidos completos
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listarPedidosCompletos(s_pedido pedidos[], s_cliente clientes[])
{
	int retorno = ERROR;
	int i;
	int j;
	int auxiliar;
	int indexCliente;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 1)
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
				"CUIT: %s\nLa direccion es: %s %d\n"
				"La cantidad de HDPE procesado es: %d\n""La cantidad de LDPE procesado es: %d\n"
				"La cantidad de PP procesado es: %d\n"
				"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
				clientes[indexCliente].cuitCliente,clientes[indexCliente].direccion,clientes[indexCliente].altura,
				pedidos[i].kilosHDPE,pedidos[i].kilosLDPE,pedidos[i].kilosPP);
				flag = 1;
				retorno = OK;
			}
		}
			if(flag == 0)
			{
				printf("No hay pedidos a listar.\n");
			}
	}

	return retorno;
}

/** \brief lista los clientes con la cantidad de pedidos pendientes
* \param list clientes[]
* \param list pedidos[]
*
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
*
*/
int listarCantidadPedidosPendientes(s_pedido pedidos[], s_cliente clientes[])
{
	int retorno = ERROR;
	int i;
	int cantidadPendientes;
	int auxiliar;
	int indexCliente;
	int control;
	int flag = 0;
	if(pedidos != NULL && clientes != NULL)
	{
		for (i = 0; i < CANTIDAD_PEDIDOS; i++)
		{
			control = auxiliar;
			if (pedidos[i].isEmpty == 1 && pedidos[i].estado == 0)
			{
				auxiliar = pedidos[i].idCliente;
				contadorPedidosPendientes(pedidos,auxiliar,&cantidadPendientes);
				indexCliente = buscarClientePorId(clientes,auxiliar);
				if(control != auxiliar)
				{
				printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
			    "El nombre es: %s\n""El CUIT es: %s\n"
			    "La direccion es: %s %d\nLa localidad es %s.\nEl id es: %d.\n"
			    "La cantidad de pedidos pendientes es: %d\n"
			    "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
		        clientes[indexCliente].nombreEmpresa, clientes[indexCliente].cuitCliente,
			    clientes[indexCliente].direccion, clientes[indexCliente].altura,
			    clientes[indexCliente].localidad, clientes[indexCliente].idCliente,cantidadPendientes);
			    cantidadPendientes = 0;
			    flag = 1;
			    retorno = OK;
				}

			}
		}
			if(flag == 0)
			{
				printf("No hay pedidos a listar.\n");
			}
	}
	return retorno;
}

