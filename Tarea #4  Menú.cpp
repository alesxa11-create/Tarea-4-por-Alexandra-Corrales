#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Estructura para guardar datos de un producto
struct Producto {
    string nombre;
    float precio;
    char categoria; // A=Alimentos, R=Ropa, T=Tecnología
};

// Vector para guardar productos
vector<Producto> productos;

// Funcion para pausar la pantalla
void pausa() {
    cout << "\nPresione ENTER para continuar...";
    cin.ignore();
    cin.get();
}

// Función para agregar un producto (usa string, float, char)
void agregarProducto() {
    Producto p;
    cout << "Ingrese el nombre del producto: ";
    cin.ignore(); 
    getline(cin, p.nombre);

    cout << "Ingrese el precio: ";
    cin >> p.precio;

    cout << "Ingrese la categoria (A=Alimentos, R=Ropa, T=Tecnologia): ";
    cin >> p.categoria;

    productos.push_back(p);
    cout << "Producto agregado correctamente.\n";
}

// Mostrar todos los productos (usa for)
void mostrarProductos() {
    if (productos.empty()) {
        cout << "No hay productos registrados.\n";
        return;
    }

    cout << "\n--- Lista de productos ---\n";
    for (int i = 0; i < productos.size(); i++) {
        cout << i + 1 << ". " << productos[i].nombre
             << " | Precio: ¢" << productos[i].precio
             << " | Categoria: " << productos[i].categoria << endl;
    }
}

// Calcular promedio de precios (usa acumulador y contador)
void calcularPromedio() {
    if (productos.empty()) {
        cout << "No hay productos para calcular.\n";
        return;
    }

    float suma = 0;
    int contador = 0;

    for (int i = 0; i < productos.size(); i++) {
        suma += productos[i].precio;
        contador++;
    }

    float promedio = suma / contador;
    cout << "El precio promedio de los productos es: ¢" << promedio << endl;
}

// Contar productos según precio (usa if else, contador)
void contarPorPrecio() {
    if (productos.empty()) {
        cout << "No hay productos registrados.\n";
        return;
    }

    int baratos = 0, caros = 0;
    for (int i = 0; i < productos.size(); i++) {
        if (productos[i].precio < 5000)
            baratos++;
        else
            caros++;
    }

    cout << "Productos baratos (< ¢5000): " << baratos << endl;
    cout << "Productos caros (= ¢5000): " << caros << endl;
}

// Para imprimir(menú)
int main() {
    int opcion;

    do {
        cout << "\n====== MENU PRINCIPAL ======\n";
        cout << "1. Agregar producto\n";
        cout << "2. Mostrar productos\n";
        cout << "3. Calcular promedio de precios\n";
        cout << "4. Contar productos caros/baratos\n";
        cout << "0. Salir\n";
        cout << "============================\n";
        cout << "Elija una opción: ";
        cin >> opcion;

        if (opcion == 1) agregarProducto();
        else if (opcion == 2) mostrarProductos();
        else if (opcion == 3) calcularPromedio();
        else if (opcion == 4) contarPorPrecio();
        else if (opcion == 0) cout << "Saliendo del programa...\n";
        else cout << "Opcion invalida.\n";

        if (opcion != 0) pausa();
    } while (opcion != 0);

    return 0;
}

