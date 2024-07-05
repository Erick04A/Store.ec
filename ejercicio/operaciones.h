#define MAX_PRODUCTOS 100
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100
#define MAX_NOMBRE_PRODUCTO 50
#define MAX_NOMBRE_CLIENTE 50
#define MAX_CEDULA 11 
#define MAX_FECHA 20

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
void verListadoFacturas();

void cargarDatos();
void guardarDatos();
