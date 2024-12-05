/*Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 3
Problema planteado: Almacenamiento de registros de estudiantes*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
struct Estudiante 
{
    string nombre;
    int edad;
    double promedio;
};
vector<Estudiante> ingresarEstudiantes(int cantidad) 
{
    vector<Estudiante> estudiantes(cantidad);
    for (int i = 0; i < cantidad; i++) 
    {
        cout << "Ingresa los datos del estudiante " << (i + 1) << ":\n";
        cout << "Nombre: ";
        cin.ignore();  
        getline(cin, estudiantes[i].nombre);
        cout << "Edad: ";
        cin >> estudiantes[i].edad;
        cout << "Promedio de calificaciones: ";
        cin >> estudiantes[i].promedio;
        cout << endl;
    }
    return estudiantes;
}
void guardarEstudiantesEnArchivo(const vector<Estudiante>& estudiantes, const string& nombreArchivo) 
{
    ofstream archivo(nombreArchivo);

    if (archivo.is_open()) 
    {
        for (const Estudiante& estudiante : estudiantes) 
        {
            archivo << estudiante.nombre << endl;
            archivo << estudiante.edad << endl;
            archivo << estudiante.promedio << endl;
        }
        archivo.close();
    } 
    else 
    {
        cout << "No se pudo abrir el archivo para guardar los registros." << endl;
    }
}
// Función para leer los registros de los estudiantes desde el archivo y mostrarlos
void leerEstudiantesDesdeArchivo(const string& nombreArchivo) 
{
    ifstream archivoLeer(nombreArchivo);
    string nombre;
    int edad;
    double promedio;

    if (archivoLeer.is_open()) 
    {
        cout << "\nDatos de los estudiantes registrados:\n";
        cout << "\n";
        cout << "Nombre                Edad   Promedio\n";
        cout << "\n";
        while (getline(archivoLeer, nombre)) 
        {
            archivoLeer >> edad;
            archivoLeer >> promedio;
            archivoLeer.ignore(); 
            // Mostramos la información de los estudiantes
            cout << nombre;
            int espacios_nombre = 20 - nombre.length();
            for (int i = 0; i < espacios_nombre; i++) 
            {
                cout << " "; 
            }
            cout << edad;
            int espacios_edad = 6 - to_string(edad).length();
            for (int i = 0; i < espacios_edad; i++) 
            {
                cout << " "; 
            }
            cout << promedio << endl;
        }
        archivoLeer.close();
    } 
    else 
    {
        cout << "No se pudo abrir el archivo para leer los registros." << endl;
    }
}
int main() 
{
    int cantidad;
    cout << "¿Cuántos estudiantes deseas registrar? ";
    cin >> cantidad;
    vector<Estudiante> estudiantes = ingresarEstudiantes(cantidad);
    string nombreArchivo = "estudiantes.txt";
    guardarEstudiantesEnArchivo(estudiantes, nombreArchivo);
    leerEstudiantesDesdeArchivo(nombreArchivo);
    return 0;
}

