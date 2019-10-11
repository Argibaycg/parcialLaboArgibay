#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utn_gets.h"
#include "clientes.h"

#define OK 0
#define ERROR -1
#define CANTIDAD_CLIENTES 100
#define CANTIDAD_PEDIDOS 1000


int initIsEmptyClientes(s_cliente cliente[], int cantidad)
{
	int i;
	if(cliente != NULL && cantidad > 0)
	{
		for (i = 0; i < cantidad; i++)
		{
			cliente[i].isEmpty = 0;
		}
	}
	return 0;
}

int searchClienteEmpty(s_cliente cliente[], int cantidad)
{
	int retorno = ERROR;
	int i;
	if(cliente != NULL && cantidad > 0)
	{
		for (i = 0; i < cantidad; i++)
		{
			if (cliente[i].isEmpty == 0)
			{
				return i;
			}
		}
	}
	return retorno;
}

int altaCliente(s_cliente clientes[], int index,int idCliente)
{
	int retorno = -1;
	char buffer[1024];
	int auxiliar;
	int flag = 0;
	if (flag == 0)
	{
		if (utn_getString("Ingrese el nombre de la empresa: \n", "Nombre no valido.\n", buffer)== 0)
		{
			strcpy(clientes[index].nombreEmpresa, buffer);
		} else
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		if (utn_getCuil("Ingrese su CUIT xx-xxxxxxxx-x: \n", "Dato no valido.\n",buffer) == 0)
		{
			strcpy(clientes[index].cuitCliente, buffer);
		} else
		{
			flag = 1;
		}
	}
	if (flag == 0)
		{
			if (utn_getString("Ingrese la calle de la empresa: \n", "Calle no valido.\n", buffer)== 0)
			{
				strcpy(clientes[index].direccion, buffer);
			} else
			{
				flag = 1;
			}
		}
	if (flag == 0)
	{
		if (utn_getNumber(&auxiliar,12000,1,2,"Ingrese la altura de la calle:\n","Altura no valida")== 0)
		{
			clientes[index].altura = auxiliar;
		} else
		{
			flag = 1;
		}
	}
	if (flag == 0)
	{
		if (utn_getString("Ingrese la localidad: \n", "Localidad no valido.\n", buffer)== 0)
		{
			strcpy(clientes[index].localidad, buffer);
		} else
		{
			flag = 1;
		}
			}
	if (flag == 0)
	{
		clientes[index].isEmpty = 1;
		clientes[index].idCliente = idCliente;
		printf("El alta del cliente con id %d fue correcta.\n",clientes[index].idCliente);
		retorno = 0;
	} else
	{
		printf("No se pudo realizar el alta, algun campo incorrecto.\n");
	}

	return retorno;
}

int modificarCliente(s_cliente clientes[],int cantidad)
{
	int retorno = -1;
	int i;
	int idCliente;
	int auxiliar;
	int index;
	char buffer[1024];
	int opcion = 0;
	if(utn_getNumber(&idCliente, 60000, 0, 2, "Ingrese el id del cliente.\n",
											  "Dato no valido.\n")==0)
	{
		buscarClientePorId(clientes,idCliente,&index);
		for (i = 0; i < cantidad; i++)
			{
				if (clientes[i].idCliente == idCliente)
				{
					utn_getNumber(&opcion,2,1,2,"Ingrese 1 para modificar direccion 2 para modificar localidad"
												,"Ingreso no valido");
					switch (opcion) {
					case 1:
						if (utn_getString("Ingrese la calle de la empresa: \n", "Calle no valido.\n", buffer)== 0)
						{
							strcpy(clientes[index].direccion, buffer);
						} else
						{
							break;
						}
						if (utn_getNumber(&auxiliar,12000,1,2,"Ingrese la altura de la calle:\n","Altura no valida")== 0)
						{
							clientes[index].altura = auxiliar;
						} else
						{
							break;
						}
						break;
					case 2:
						if (utn_getString("Ingrese la localidad de la empresa: \n", "Localidad no valido.\n", buffer)== 0)
						{
							strcpy(clientes[index].localidad, buffer);
						} else
						{
							break;
						}
							;
						break;

					default:
					printf("No ingreso una opcion valida.");
						break;

					}
				}
			}

	}

	return retorno;
}

int buscarClientePorId(s_cliente clientes[], int idCliente,int *pUbicacionCliente)
{
	int retorno = -1;
	int i;
	for (i = 0; i != idCliente; i++)
	{
		if (clientes[i].idCliente == idCliente)
		{
			*pUbicacionCliente = i;
			retorno = 0;
		}
	}
	return retorno;
}

int listarClientes(s_cliente clientes[], int cantidad)
{
	int retorno = -1;
	int i;
	int flag = 0;
	for (i = 0; i < cantidad; i++)
	{
		if (clientes[i].isEmpty == 1)
		{
			printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n"
					"El nombre es: %s\n""El CUIT es: %s\n"
					"La direccion es: %s %d\nLa localidad es %s.\nEl id es: %d.\n"
					"-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
					clientes[i].nombreEmpresa, clientes[i].cuitCliente,
					clientes[i].direccion, clientes[i].altura,
					clientes[i].localidad, clientes[i].idCliente);
			retorno = 0;
			flag = 1;
		}
	}
		if(flag == 0)
		{
			printf("No hay clientes a listar.\n");
		}

	return retorno;
}

int bajaCliente(s_cliente clientes[])
{
	int retorno = -1;
	char buffer;
	int idClienteaux;
	int index;
	utn_getString("Desea dar de baja un cliente? s/n: ", "Opcion no valida",&buffer);
	if (buffer == 's')
	{
		buffer = 'e';
		utn_getNumber(&idClienteaux, 6000, 100, 2,"Ingrese el ID del cliente", "Ingreso invalido.");
	}
	utn_getString("Se dara de baja, continuar? s/n: ", "Opcion no valida",&buffer);
	if (buscarClientePorId(clientes,idClienteaux,&index) == 0 && buffer == 's')
	{
		clientes[index].isEmpty = 0;
	}

	return retorno;

}
