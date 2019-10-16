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


int initIsEmptyClientes(s_cliente clientes[], int cantidad)
{
	int i;
	if(clientes != NULL && cantidad > 0)
	{
		for (i = 0; i < cantidad; i++)
		{
			clientes[i].isEmpty = 0;
		}
	}
	return OK;
}

int searchClienteEmpty(s_cliente clientes[], int cantidad)
{
	int retorno = ERROR;
	int i;
	if(clientes != NULL && cantidad > 0)
	{
		for (i = 0; i < cantidad; i++)
		{
			if (clientes[i].isEmpty == 0)
			{
				return i;
			}
		}
	}
	return retorno;
}

int altaCliente(s_cliente clientes[], int index,int idCliente)
{
	int retorno = ERROR;
	char buffer[1024];
	int auxiliar;
	strcpy(clientes[index].localidad,"");
	int flag = 0;
	if(clientes!= NULL)
	{
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
			retorno = OK;
		} else
		{
			printf("No se pudo realizar el alta, algun campo incorrecto.\n");
		}
	}

	return retorno;
}

int modificarCliente(s_cliente clientes[],int cantidad)
{
	int retorno = ERROR;
	int i;
	int idCliente;
	int auxiliar;
	int index;
	char buffer[1024];
	int opcion = 0;
	if(clientes != NULL && cantidad > 0)
	{
		if(utn_getNumber(&idCliente, 60000, 0, 2, "Ingrese el id del cliente.\n",
												  "Dato no valido.\n")==0)
		{
			index = buscarClientePorId(clientes,idCliente);
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

	}

	return retorno;
}

int buscarClientePorId(s_cliente clientes[], int idCliente)
{
	int retorno = -1;
	int i;
	if(clientes != NULL)
	{
		for (i = 0; i != idCliente; i++)
		{
			if (clientes[i].idCliente == idCliente)
			{
				return i;
			}
		}
	}
	return retorno;
}

int listarClientes(s_cliente clientes[], int cantidad)
{
	int retorno = ERROR;
	int i;
	int flag = 0;
	if(clientes != NULL && cantidad > 0)
	{
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
				retorno = OK;
				flag = 1;
			}
		}
			if(flag == 0)
			{
				printf("No hay clientes a listar.\n");
			}
	}
	return retorno;
}

int bajaCliente(s_cliente clientes[])
{
	int retorno = ERROR;
	char buffer;
	int idClienteaux;
	int index;
	if(clientes != NULL)
	{
		utn_getString("Desea dar de baja un cliente? s/n: ", "Opcion no valida",&buffer);
		if (buffer == 's')
		{
			buffer = 'e';
			utn_getNumber(&idClienteaux, 6000, 100, 2,"Ingrese el ID del cliente", "Ingreso invalido.");
		}else
		{
			printf("No se dara de baja ningun cliente.\n");
			return retorno;
		}
		utn_getString("Se dara de baja, continuar? s/n: ", "Opcion no valida",&buffer);
		index = buscarClientePorId(clientes,idClienteaux);
		if (buffer == 's')
		{
			clientes[index].isEmpty = 0;
			retorno = OK;
		}else
		{
			printf("No se dio de baja ningun cliente.\n");
			return retorno;
		}
	}

	return retorno;

}

int bucarClienteExistente(s_cliente clientes[], int cantidad, int* idParaAlta)
{
	int retorno = ERROR;
	int i;
	int auxiliarIdCliente;
	if(clientes != NULL && cantidad > 0)
	{
		if (utn_getNumber(&auxiliarIdCliente,2000,100,2,"Ingrese id cliente:\n","Id no fue ingresado correctamente\n")== 0)
			{
				for (i = 0; i < cantidad; i++)
				{
					if (clientes[i].idCliente == auxiliarIdCliente)
					{
						*idParaAlta = auxiliarIdCliente;
						retorno = OK;
					}
				}
			}
	}
	return retorno;
}

void ordenarClientesPorId(s_cliente clientes[],  int cantidad)
{
    int i;
    s_cliente auxiliarCliente;
    int s = 1;
    if(clientes != NULL && cantidad > 0)
    {
		while(s)
		{
			s = 0;
			for (i = 1; i < cantidad; i++)
			{
				if (clientes[i].idCliente < clientes[i - 1].idCliente)
				{
					auxiliarCliente = clientes[i];
					clientes[i] = clientes[i - 1];
					clientes[i - 1] = auxiliarCliente;
					s = 1;
				}
			}
		}
    }
}

