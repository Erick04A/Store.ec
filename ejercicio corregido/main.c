#include <stdio.h>
#include "operaciones.h"

int main() {
    int opcion;
    numProductos = 0;
    numClientes = 0;
    numFacturas = 0;

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Listar productos\n");
        printf("5. Ingresar cliente\n");
        printf("6. Editar cliente\n");
        printf("7. Consultar cliente\n");
        printf("8. Ver listado de clientes\n");
        printf("9. Adicionar compra de producto\n");
        printf("10. Facturar\n");
        printf("11. Buscar factura\n");
        printf("12. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresarProducto();
                break;
            case 2:
                editarProducto();
                break;
            case 3:
                eliminarProducto();
                break;
            case 4:
                listarProductos();
                break;
            case 5:
                ingresarCliente();
                break;
            case 6:
                editarCliente();
                break;
            case 7:
                consultarCliente();
                break;
            case 8:
                verListadoClientes();
                break;
            case 9:
                adicionarCompraProducto();
                break;
            case 10:
                facturar();
                break;
            case 11:
                buscarFactura();
                break;
            case 12:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
                break;
        }
    } while (opcion != 12);

    return 0;
}
