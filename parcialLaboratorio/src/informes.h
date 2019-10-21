
#ifndef INFORMES_H_
#define INFORMES_H_

int listarPedidoPendientes(s_pedido pedidos[], s_cliente clientes[]);

int listarCantidadPedidosPendientes(s_pedido pedidos[], s_cliente clientes[]);
int listarPedidosCompletos(s_pedido pedidos[], s_cliente clientes[]);
int clienteConMasPedidosPendientes(s_pedido pedidos[], s_cliente clientes[]);
int clienteConMasPedidosCompletados(s_pedido pedidos[], s_cliente clientes[]);
int menuInformes(s_pedido pedidos[], s_cliente clientes[]);
int clienteConMasPedidos(s_pedido pedidos[], s_cliente clientes[]);
int listarClienteQueMasReciclo(s_pedido pedidos[], s_cliente clientes[]);
int listarClienteQueMenosReciclo(s_pedido pedidos[], s_cliente clientes[]);
int listarPedidosCompletosConInformacion(s_pedido pedidos[], s_cliente clientes[]);
int clientesConMasDeMilKilosProcesados(s_pedido pedidos[], s_cliente clientes[]);
int clientesConMenosDeCienKilosProcesados(s_pedido pedidos[], s_cliente clientes[]);
int listarPedidosPendientesPorLocalidad(s_pedido pedidos[], s_cliente clientes[]);
int cantidadDeKilosPPProcesadoPorCliente(s_pedido pedidos[], s_cliente clientes[]);
int cantidadDeKilosProcesadosAEleccion(s_pedido pedidos[], s_cliente clientes[]);

#endif /* INFORMES_H_ */
