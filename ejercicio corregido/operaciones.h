#define OPERACIONES_H

#define MAX_PRODUCTOS 100
#define MAX_NOMBRE_PRODUCTO 50
#define MAX_CLIENTES 100
#define MAX_CEDULA 11
#define MAX_NOMBRE_CLIENTE 50
#define MAX_FACTURAS 100

char inventario_nombres[MAX_PRODUCTOS][MAX_NOMBRE_PRODUCTO];
int inventario_cantidades[MAX_PRODUCTOS];
float inventario_precios[MAX_PRODUCTOS];
int numProductos;

char clientes_cedulas[MAX_CLIENTES][MAX_CEDULA];
char clientes_nombres[MAX_CLIENTES][MAX_NOMBRE_CLIENTE];
int numClientes;

char facturas_cedulas[MAX_FACTURAS][MAX_CEDULA];
char facturas_nombres[MAX_FACTURAS][MAX_NOMBRE_PRODUCTO];
int facturas_cantidades[MAX_FACTURAS];
float facturas_valores[MAX_FACTURAS];
int numFacturas;

void copiarCadena(char* destino, const char* origen);
int longitudCadena(const char* cadena);
int compararCadenas(const char* cadena1, const char* cadena2);
int revisaCedula(const char* cedula);
void ingresarProducto();
void editarProducto();
void eliminarProducto();
void listarProductos();
void ingresarCliente();
void editarCliente();
void consultarCliente();
void verListadoClientes();
void adicionarCompraProducto();
void facturar();
void buscarFactura();



