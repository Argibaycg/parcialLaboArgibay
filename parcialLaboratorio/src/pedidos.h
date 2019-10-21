
#ifndef PEDIDOS_H_
#define PEDIDOS_H_

typedef struct{
	int kilosRetirados;
	int kilosHDPE;
	int kilosLDPE;
	int kilosPP;
	int idPedido;
	int idCliente;
	int estado;
	int isEmpty;
}s_pedido;


int initIsEmptyPedidos(s_pedido pedidos[], int cantidad);
int searchPedidoEmpty(s_pedido pedidos[], int cantidad);
int altaDePedido(s_pedido pedidos[],int index, int idPedido, int idCliente);
int listarPedidosPendientes(s_pedido pedidos[], int cantidad);
int buscarPedidoPorId(s_pedido pedidos[], int idPedido,int *pUbicacionPedido);
int procesarResiduos(s_pedido pedidos[]);
void ordenarPedidosPorId(s_pedido pedidos[], int cantidad);
void contadorPedidosPendientes(s_pedido pedidos[], int idCliente, int* cantidadPendientes);
void contadorPedidosProcesado(s_pedido pedidos[], int idCliente, int* cantidadProcesado);
void contadorPedidos(s_pedido pedidos[], int idCliente, int* cantidadProcesado);
void contadorKilosProcesados(s_pedido pedidos[], int idCliente, int* kilosProcesado);
int bucarPedidoExistente(s_pedido pedidos[], int cantidad, int* idParaAlta);

#endif /* PEDIDOS_H_ */
