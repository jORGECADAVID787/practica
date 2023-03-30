 #include <iostream>
#include <string>
#include <vector>

using namespace std;

// Estructura para almacenar información de cada artículo
struct Articulo {
    string nombre;
    string tipo;
    double precio;
};

// Función para mostrar los artículos disponibles agrupados por tipo
void mostrarArticulos(vector<Articulo>& articulos) {
    string tipoActual = "";
    for (Articulo& articulo : articulos) {
        if (tipoActual != articulo.tipo) {
            tipoActual = articulo.tipo;
            cout << "\n" << tipoActual << ":\n";
        }
        cout << "- " << articulo.nombre << " ($" << articulo.precio << ")\n";
    }
}

// Función para comprar un artículo y agregarlo al carrito de compras
void comprarArticulo(vector<Articulo>& articulos, vector<Articulo>& carrito) {
    mostrarArticulos(articulos);
    cout << "\nIngrese el nombre del artículo que desea comprar: ";
    string nombreArticulo;
    cin >> nombreArticulo;
    for (Articulo& articulo : articulos) {
        if (articulo.nombre == nombreArticulo) {
            carrito.push_back(articulo);
            cout << "\nArtículo agregado al carrito de compras.\n";
            break;
        }
    }
    cout << "\n¿Desea comprar otro artículo? (s/n): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 's') {
        comprarArticulo(articulos, carrito);
    }
}

// Función para calcular el total de la compra y ofrecer opciones de pago o cancelación
void pagar(vector<Articulo>& carrito) {
    double total = 0;
    for (Articulo& articulo : carrito) {
        total += articulo.precio;
    }
    cout << "\nTotal de la compra: $" << total << "\n";
    cout << "\n¿Desea pagar ahora? (s/n): ";
    char respuesta;
    cin >> respuesta;
    if (respuesta == 's') {
        cout << "\nPago exitoso.\n";
        carrito.clear();
    } else {
        cout << "\nCompra cancelada.\n";
        carrito.clear();
    }
}

int main() {
   // Inicializar lista de artículos disponibles
    vector<Articulo> Articulos = {
        {"Camisa", "Ropa", 25.000},
        {"Pantalón", "Ropa", 49.000},
        {"Zapatos", "Calzado", 59.000},
        {"Sneakers", "Calzado", 100.000},
        {"Gorra", "Accesorios", 20.000},
        {"Bufanda", "Accesorios", 14.000}
    };
    // Inicializar carrito de compras vacío
    vector<Articulo> carrito;

    // Menú principal
    while (true) {
        cout << "\nMenu principal:\n";
        cout << "1. Comprar artículo\n";
        cout << "2. Pagar\n";
        cout << "3. Salir\n";
        cout << "\nIngrese la opción deseada: ";
        int opcion;
        cin >> opcion;
        switch (opcion) {
            case 1:
                comprarArticulo(Articulos, carrito);
                break;
            case 2:
                if (carrito.empty()) {
cout << "\nEl carrito de compras está vacío.\n";
} else {
pagar(carrito);
}
break;
case 3:
cout << "\n¡Gracias por su visita!\n";
return 0;
default:
cout << "\nOpción inválida. Intente de nuevo.\n";
break;
}
}
return 0;
}