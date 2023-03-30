#include <iostream>
#include <string>
#include <list>

using namespace std;

// Definición de la clase Articulo
class Articulo {
public:
    string tipo;
    string nombre;
    int id;
    float precio;
    int disponibilidad;
};

// Definición de la clase Coordinador
class Coordinador {
public:
    void agregar_articulo(list<Articulo>& articulos);
    void modificar_articulo(list<Articulo>& articulos);
    void eliminar_articulo(list<Articulo>& articulos);
};

// Función para buscar un artículo por su id
list<Articulo>::iterator buscar_articulo_por_id(list<Articulo>& articulos, int id) {
    for (auto it = articulos.begin(); it != articulos.end(); ++it) {
        if (it->id == id) {
            return it;
        }
    }
    return articulos.end();
}

// Implementación de las funciones de la clase Coordinador
void Coordinador::agregar_articulo(list<Articulo>& articulos) {
    Articulo articulo;
    cout << "Ingrese el tipo de articulo: ";
    cin >> articulo.tipo;
    cout << "Ingrese el nombre del articulo: ";
    cin >> articulo.nombre;
    cout << "Ingrese el id del articulo: ";
    cin >> articulo.id;
    cout << "Ingrese el precio del articulo: ";
    cin >> articulo.precio;
    cout << "Ingrese la disponibilidad del articulo: ";
    cin >> articulo.disponibilidad;
    articulos.push_back(articulo);
    cout << "Articulo agregado exitosamente." << endl;
}

void Coordinador::modificar_articulo(list<Articulo>& articulos) {
int id;
cout << "Ingrese el id del articulo que desea modificar: ";
cin >> id;
auto it = buscar_articulo_por_id(articulos, id);
if (it != articulos.end()) {
cout << "Ingrese el tipo de articulo: ";
cin >> it->tipo;
cout << "Ingrese el nombre del articulo: ";
cin >> it->nombre;
cout << "Ingrese el precio del articulo: ";
cin >> it->precio;
cout << "Ingrese la disponibilidad del articulo: ";
cin >> it->disponibilidad;
cout << "Articulo modificado exitosamente." << endl;
}
else {
cout << "No se encontró un articulo con ese id." << endl;
}
}

void Coordinador::eliminar_articulo(list<Articulo>& articulos) {
int id;
cout << "Ingrese el id del articulo que desea eliminar: ";
cin >> id;
auto it = buscar_articulo_por_id(articulos, id);
if (it != articulos.end()) {
articulos.erase(it);
cout << "Articulo eliminado exitosamente." << endl;
}
else {
cout << "No se encontró un articulo con ese id." << endl;
}
}

// Función para imprimir todos los artículos
void imprimir_articulos(list<Articulo>& articulos) {
for (auto it = articulos.begin(); it != articulos.end(); ++it) {
cout << "Tipo: " << it->tipo << endl;
cout << "Nombre: " << it->nombre << endl;
cout << "ID: " << it->id << endl;
cout << "Precio: " << it->precio << endl;
cout << "Disponibilidad: " << it->disponibilidad << endl;
cout << endl;
}
}

int main() {
list<Articulo> articulos;
Coordinador coordinador;
int opcion = 0;
while (opcion != 4) {
cout << "MENU" << endl;
cout << "1. Agregar articulo" << endl;
cout << "2. Modificar articulo" << endl;
cout << "3. Eliminar articulo" << endl;
cout << "4. Salir" << endl;
cout << "Ingrese una opcion: ";
cin >> opcion;
cout << endl;
switch (opcion) {
case 1:
coordinador.agregar_articulo(articulos);
break;
case 2:
coordinador.modificar_articulo(articulos);
break;
case 3:
coordinador.eliminar_articulo(articulos);
break;
case 4:
cout << "Adios!" << endl;
break;
default:
cout << "Opcion invalida." << endl;
break;
}
imprimir_articulos(articulos);
}
return 0;
}


