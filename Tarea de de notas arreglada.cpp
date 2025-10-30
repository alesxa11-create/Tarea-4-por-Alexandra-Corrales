#include <iostream>
#include <string>
using namespace std;

string nombre[3];
float notas[3];

// Inicializa los arreglos
void inicializar()
{
    for (int x = 0; x < 3; x++)
    {
        notas[x] = 0;
        nombre[x] = "";
    }
    cout << "Arreglos inicializados correctamente.\n";
}

// Imprime todos los estudiantes
void imprimir()
{
    cout << "\n=== LISTA DE ESTUDIANTES ===\n";
    for (int x = 0; x < 3; x++)
    {
        cout << "Estudiante: " << nombre[x]
             << " | Nota: " << notas[x] << "\n";
    }
    cout << "============================\n";
}

// Solicita los datos de los estudiantes
void SolicitaDatos()
{
    for (int x = 0; x < 3; x++)
    {
        cout << "Ingrese el nombre del estudiante " << x + 1 << ": ";
        cin >> nombre[x];
        cout << "Ingrese la nota: ";
        cin >> notas[x];
    }
}

//Busca un estudiante por nombre
void Buscar()
{
    string nuevonombre = "";
    cout << "\nIngrese el nombre que desea buscar: ";
    cin >> nuevonombre;

    for (int x = 0; x < 3; x++)
    {
        if (nuevonombre == nombre[x])
        {
            cout << "El estudiante existe.\n";
            cout << "Nombre: " << nombre[x] << " | Nota: " << notas[x] << "\n";
            return; // termina la función si lo encuentra
        }
    }

    // Si el ciclo termina sin encontrarlo:
    cout << "El estudiante NO existe.\n";
}

//Actualiza los datos de un estudiante existente
void Actualizar()
{
    string nombreBuscar;
    cout << "\nIngrese el nombre del estudiante a actualizar: ";
    cin >> nombreBuscar;

    for (int x = 0; x < 3; x++)
    {
        if (nombreBuscar == nombre[x])
        {
            cout << "Estudiante encontrado: " << nombre[x] << "\n";
            cout << "Ingrese el nuevo nombre: ";
            cin >> nombre[x];
            cout << "Ingrese la nueva nota: ";
            cin >> notas[x];

            cout << "Datos actualizados correctamente.\n";
            return;
        }
    }

// Si no se encuentra el nombre
    cout << "El estudiante no se encontró. No se actualizó nada.\n";
}

//Menú principal
void menu()
{
    int opcion;
    do
    {
        cout << "\n===== MENÚ PRINCIPAL =====\n";
        cout << "1. Inicializar arreglos\n";
        cout << "2. Ingresar datos\n";
        cout << "3. Mostrar estudiantes\n";
        cout << "4. Buscar estudiante\n";
        cout << "5. Actualizar estudiante\n";
        cout << "0. Salir\n";
        cout << "==========================\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            inicializar();
            break;
        case 2:
            SolicitaDatos();
            break;
        case 3:
            imprimir();
            break;
        case 4:
            Buscar();
            break;
        case 5:
            Actualizar();
            break;
        case 0:
            cout << "?? Saliendo del programa...\n";
            break;
        default:
            cout << "??  Opción inválida, intente nuevamente.\n";
        }

    } while (opcion != 0);
}

//Función principal
int main()
{
    menu();
    return 0;
}

