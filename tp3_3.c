#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>



struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
};

typedef struct Producto Producto ;


struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

typedef struct Cliente Cliente;


void  CargarClientes(int CantClientes, Cliente *cliente, char *TiposProductos);
void mostrar(Cliente *cliente);

int main(void){

    int CantClientes;
    char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};
    Cliente *cliente;


    

    printf("Cual es la cantidad de clientes que desea ingresar en el sistema (deve ser, como maximo 5)\n");
    scanf("%d",&CantClientes); 
    while (CantClientes > 5 || CantClientes <= 0) 
    {
        printf("La cantidad de cliente no deve superar a 6, ni ser negativa. Por favor intente nuevamente\n");
        printf("Cual es la cantidad de clientes que desea ingresar en el sistema (deve ser, como maximo 5)\n");
        scanf("%d",&CantClientes); 
    }
    
    cliente = (Cliente *) malloc(CantClientes * sizeof(Cliente));     // reservo la memoria dinamica para esa cantidad de clientes.

    CargarClientes(CantClientes, cliente, *TiposProductos);
    void mostrar(Cliente *cliente);

    free(cliente);

    return 0;
}

void  CargarClientes(int CantClientes, Cliente *cliente, char *TiposProductos){
    int NumProducto;
    char *Buff= (char*) malloc(100 * sizeof(char));
    char *Buff2 = (char*) malloc(100 * sizeof(char)); //(rand() %(4 - 0)+ 0 )
    printf("\nCargado de los %d Clientes\n",CantClientes);

    for (int i = 0; i < CantClientes; i++)
    {
        cliente[i].ClienteID = i +1;
        printf("Por favor, ingrese el nombre del Cliente: \n");
        fflush(stdin);
        gets(Buff);
        cliente[i].NombreCliente = (char*) malloc((strlen(Buff)+1) * sizeof(char));
        strcpy(cliente[i].NombreCliente, Buff);

        srand(time(NULL));
        cliente[i].CantidadProductosAPedir = rand()%(5-1)+1;

        cliente[i].Productos = (Producto*) malloc(cliente[i].CantidadProductosAPedir * sizeof(Producto)); 

        // de los Productos.
        for (int j = 0; j < cliente[i].CantidadProductosAPedir; j++)
        {
            cliente[i].Productos->ProductoID = j+1;
            cliente[i].Productos->Cantidad = rand() % (10 -1) + 1;
            NumProducto = (rand() %(4 - 0)+ 0 );
            Buff2 = TiposProductos[NumProducto];
            cliente[i].Productos->TipoProducto = (char *) malloc((strlen(Buff2)+1) * sizeof(char));
            strcpy(cliente[i].Productos->TipoProducto, Buff2);
            cliente[i].Productos->PrecioUnitario = rand()% (100 -10) + 10;
        }
    }
    
    free(Buff);
}

void mostrar(Cliente *cliente)
{
    printf("\n--------Clientes--------\n");
    for(int i=0; i<sizeof(cliente); i++)
    {
        printf("Cliente %d:\n", cliente[i].ClienteID);
        printf("\nNombre: %s", cliente[i].NombreCliente);
        printf("\nProductos solicitados: %d", cliente[i].CantidadProductosAPedir);
        for(int j=0; j<cliente[i].CantidadProductosAPedir; j++)
        {
            printf("\nCliente %s // Pedido %d",cliente[i].NombreCliente,j+1);
            printf("\nProducto: %s / ID: %d", cliente[i].Productos[j].TipoProducto, cliente[i].Productos[j].ProductoID);
            printf("\nPrecio untario: %d", cliente[i].Productos[j].PrecioUnitario);
            printf("\nCantidad %s que se solicito: %d\n", cliente[i].Productos->TipoProducto, cliente[i].Productos[j].Cantidad);
        }

        
        printf("\n");
    }
    free(cliente);
}