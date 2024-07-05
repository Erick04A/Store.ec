#include <stdio.h>
#include "operaciones.h"

void copiarCadena(char* destino, const char* origen) {
    while ((*destino++ = *origen++))
        ;
}

int longitudCadena(const char* cadena) {
    int len = 0;
    while (*cadena++) {
        len++;
    }
    return len;
}

int compararCadenas(const char* cadena1, const char* cadena2) {
    while (*cadena1 && (*cadena1 == *cadena2)) {
        cadena1++;
        cadena2++;
    }
    return *(unsigned char*)cadena1 - *(unsigned char*)cadena2;
}

int revisaCedula(const char* cedula) {
    int len = 0;
    while (*cedula++) {
        len++;
    }
    if (len != 10) return 0;
    while (*cedula) {
        if (*cedula < '0' || *cedula > '9') return 0;
        cedula++;
    }
    return 1;
}

void ingresarProducto() {
    if (numProductos < MAX_PRODUCTOS) {
        printf("Ingresar nombre del producto: ");
        scanf(" %[^\n]", inventario_nombres[numProductos]);

        printf("Ingresar cantidad del producto: ");
        scanf("%d", &inventario_cantidades[numProductos]);

        printf("Ingresar precio del producto: ");
        scanf("%f", &inventario_precios[numProductos]);

        numProductos++;
    } else {
        printf("Inventario lleno.\n");
    }
}

void editarProducto() {
    char nombreEditar[MAX_NOMBRE_PRODUCTO];
    printf("Ingresar nombre del producto a editar: ");
    scanf(" %[^\n]", nombreEditar);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (compararCadenas(inventario_nombres[i], nombreEditar) == 0) {
            encontrado = 1;
            printf("Editar cantidad del producto (anterior: %d): ", inventario_cantidades[i]);
            scanf("%d", &inventario_cantidades[i]);

            printf("Editar precio del producto (anterior: %.2f): ", inventario_precios[i]);
            scanf("%f", &inventario_precios[i]);
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void eliminarProducto() {
    char nombreEliminar[MAX_NOMBRE_PRODUCTO];
    printf("Ingresar nombre del producto a eliminar: ");
    scanf(" %[^\n]", nombreEliminar);

    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (compararCadenas(inventario_nombres[i], nombreEliminar) == 0) {
            encontrado = 1;
            for (int j = i; j < numProductos - 1; j++) {
                copiarCadena(inventario_nombres[j], inventario_nombres[j + 1]);
                inventario_cantidades[j] = inventario_cantidades[j + 1];
                inventario_precios[j] = inventario_precios[j + 1];
            }
            numProductos--;
            printf("Producto eliminado.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
    }
}

void listarProductos() {
    if (numProductos > 0) {
        printf("Lista de productos:\n");
        for (int i = 0; i < numProductos; i++) {
            printf("Nombre: %s\n", inventario_nombres[i]);
            printf("Cantidad: %d\n", inventario_cantidades[i]);
            printf("Precio: %.2f\n", inventario_precios[i]);
            printf("\n");
        }
    } else {
        printf("No hay productos en el inventario.\n");
    }
}

void ingresarCliente() {
    if (numClientes < MAX_CLIENTES) {
        printf("Ingresar cedula del cliente: ");
        scanf(" %[^\n]", clientes_cedulas[numClientes]);

        while (!revisaCedula(clientes_cedulas[numClientes])) {
            printf("Cedula incorrecta. Ingresar cedula del cliente: ");
            scanf(" %[^\n]", clientes_cedulas[numClientes]);
        }

        printf("Ingresar nombre del cliente: ");
        scanf(" %[^\n]", clientes_nombres[numClientes]);

        numClientes++;
    } else {
        printf("Registro de clientes lleno.\n");
    }
}

void editarCliente() {
    char cedulaEditar[MAX_CEDULA];
    printf("Ingresar cedula del cliente a editar: ");
    scanf(" %[^\n]", cedulaEditar);

    int encontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (compararCadenas(clientes_cedulas[i], cedulaEditar) == 0) {
            encontrado = 1;
            printf("Editar nombre del cliente (anterior: %s): ", clientes_nombres[i]);
            scanf(" %[^\n]", clientes_nombres[i]);
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }
}

void consultarCliente() {
    char cedulaConsultar[MAX_CEDULA];
    printf("Ingresar cedula del cliente a consultar: ");
    scanf(" %[^\n]", cedulaConsultar);

    int encontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (compararCadenas(clientes_cedulas[i], cedulaConsultar) == 0) {
            encontrado = 1;
            printf("Nombre del cliente: %s\n", clientes_nombres[i]);
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente no encontrado.\n");
    }
}

void verListadoClientes() {
    if (numClientes > 0) {
        printf("Lista de clientes:\n");
        for (int i = 0; i < numClientes; i++) {
            printf("Cedula: %s\n", clientes_cedulas[i]);
            printf("Nombre: %s\n", clientes_nombres[i]);
            printf("\n");
        }
    } else {
        printf("No hay clientes registrados.\n");
    }
}

void adicionarCompraProducto() {
    char cedulaCliente[MAX_CEDULA];
    printf("Ingresar cedula del cliente: ");
    scanf(" %[^\n]", cedulaCliente);

    int clienteEncontrado = 0;
    for (int i = 0; i < numClientes; i++) {
        if (compararCadenas(clientes_cedulas[i], cedulaCliente) == 0) {
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente no encontrado. Ingrese los datos del cliente primero.\n");
        return;
    }

    char nombreProducto[MAX_NOMBRE_PRODUCTO];
    printf("Ingresar nombre del producto: ");
    scanf(" %[^\n]", nombreProducto);

    int productoEncontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (compararCadenas(inventario_nombres[i], nombreProducto) == 0) {
            productoEncontrado = 1;

            int cantidadComprar;
            printf("Ingresar cantidad a comprar: ");
            scanf("%d", &cantidadComprar);

            if (cantidadComprar > inventario_cantidades[i]) {
                printf("Cantidad insuficiente en inventario.\n");
                return;
            }

            inventario_cantidades[i] -= cantidadComprar;

            copiarCadena(facturas_cedulas[numFacturas], cedulaCliente);
            copiarCadena(facturas_nombres[numFacturas], nombreProducto);
            facturas_valores[numFacturas] = cantidadComprar * inventario_precios[i];
            facturas_cantidades[numFacturas] = cantidadComprar;
            numFacturas++;

            printf("Compra anadida.\n");
            return;
        }
    }

    if (!productoEncontrado) {
        printf("Producto no encontrado.\n");
    }
}

void facturar() {
    printf("Facturas:\n");
    for (int i = 0; i < numFacturas; i++) {
        printf("Cedula: %s\n", facturas_cedulas[i]);
        printf("Producto: %s\n", facturas_nombres[i]);
        printf("Cantidad: %d\n", facturas_cantidades[i]);
        printf("Valor: %.2f\n", facturas_valores[i]);
        printf("\n");
    }
}

void buscarFactura() {
    char cedulaBuscar[MAX_CEDULA];
    printf("Ingresar cedula del cliente para buscar factura: ");
    scanf(" %[^\n]", cedulaBuscar);

    int encontrado = 0;
    for (int i = 0; i < numFacturas; i++) {
        if (compararCadenas(facturas_cedulas[i], cedulaBuscar) == 0) {
            encontrado = 1;
            printf("Factura:\n");
            printf("Cedula: %s\n", facturas_cedulas[i]);
            printf("Producto: %s\n", facturas_nombres[i]);
            printf("Cantidad: %d\n", facturas_cantidades[i]);
            printf("Valor: %.2f\n", facturas_valores[i]);
            printf("\n");
        }
    }

    if (!encontrado) {
        printf("Factura no encontrada.\n");
    }
}

