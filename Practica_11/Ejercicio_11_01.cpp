/*Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 1
Problema planteado: Escritura y lectura básica de archivos */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
vector<string> ingresarNombres(int cantidad) 
{
    vector<string> nombres(cantidad);
    cin.ignore(); 
    for (int i = 0; i < cantidad; i++) 
    {
        cout << "Ingresa el nombre " << (i + 1) << ": ";
        getline(cin, nombres[i]);  
    }
    return nombres;
}
// Función para guardar los nombres en un archivo de texto
void guardarNombresEnArchivo(const vector<string>& nombres, const string& nombreArchivo) 
{
    ofstream archivo(nombreArchivo);  
    if (archivo.is_open()) {
        for (const string& nombre : nombres)
        {
            archivo << nombre << endl;  
        }
        archivo.close();  
    } 
    else 
    {
        cout << "No se pudo abrir el archivo para guardar los nombres." << endl;
    }
}

// Función para leer los nombres desde el archivo y mostrarlos en la consola
void leerNombresDesdeArchivo(const string& nombreArchivo) 
{
    ifstream archivoLeer(nombreArchivo); 
    if (archivoLeer.is_open()) 
    {
        string nombre;
        while (getline(archivoLeer, nombre)) 
        {
            cout << nombre << endl;  
        }
        archivoLeer.close(); 
    } 
    else 
    {
        cout << "No se pudo abrir el archivo para leer los nombres." << endl;
    }
}

int main() 
{
    int cantidad;
    cout << "¿Cuántos nombres deseas ingresar? ";
    cin >> cantidad;
    vector<string> nombres = ingresarNombres(cantidad);
    string nombreArchivo = "nombres.txt";
    guardarNombresEnArchivo(nombres, nombreArchivo);
    cout << "\nLos nombres guardados en el archivo son:\n";
    leerNombresDesdeArchivo(nombreArchivo);
    return 0;
}

