

#ifndef CLIENTES_H_
#define CLIENTES_H_

typedef struct{
	char nombreEmpresa[100];
	char cuitCliente[16];
	char direccion[100];
	int altura;
	char localidad[200];
	int idCliente;
	int isEmpty;
}s_cliente;


int initIsEmptyClientes(s_cliente cliente[], int cantidad);
int searchClienteEmpty(s_cliente cliente[], int cantidad);
int altaCliente(s_cliente clientes[], int index,int idCliente);
int buscarClientePorId(s_cliente clientes[], int idCliente,int *pUbicacionCliente);
int modificarCliente(s_cliente clientes[],int cantidad);
int listarClientes(s_cliente clientes[], int cantidad);
int bajaCliente(s_cliente clientes[]);

#endif /* CLIENTES_H_ */
