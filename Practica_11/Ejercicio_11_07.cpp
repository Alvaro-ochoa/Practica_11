/*Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 7
Problema planteado: Promedio de calificaciones por estudiante*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
// Función para calcular el promedio de las calificaciones de un estudiante
double calcularPromedio(const vector<double>& calificaciones) 
{
    double suma = 0.0;
    for (double calificacion : calificaciones) 
    {
        suma += calificacion;
    }
    return (calificaciones.size() > 0) ? suma / calificaciones.size() : 0.0;
}

// Función para procesar el archivo de calificaciones y generar el archivo de promedios
void calcularPromedios(const string& archivoEntrada, const string& archivoSalida) 
{
    ifstream archivoLeer(archivoEntrada);
    ofstream archivoEscribir(archivoSalida);
    string linea;
    if (archivoLeer.is_open() && archivoEscribir.is_open()) 
    {
        while (getline(archivoLeer, linea)) 
        {
            stringstream ss(linea);
            string nombreEstudiante;
            vector<double> calificaciones;
            double calificacion;
            ss >> nombreEstudiante;  
            while (ss >> calificacion) 
            {
                calificaciones.push_back(calificacion);
            }
            double promedio = calcularPromedio(calificaciones);
            archivoEscribir << nombreEstudiante << " " << promedio << endl;
        }
        archivoLeer.close();
        archivoEscribir.close();
    } 
    else 
    {
        cout << "No se pudo abrir uno de los archivos." << endl;
    }
}

int main() 
{
    string archivoEntrada = "calificaciones.txt";  // Archivo de entrada con las calificaciones
    string archivoSalida = "promedios.txt";  // Archivo de salida con los promedios
    calcularPromedios(archivoEntrada, archivoSalida);
    cout << "El archivo 'promedios.txt' ha sido generado con los promedios de los estudiantes." << endl;
    return 0;
}
