/*Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 9
Problema planteado: Cifrado de un archivo de texto (Cifrado César)*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// Función para cifrar el texto usando el cifrado César con desplazamiento de 3
char cifrarCaracter(char c, int desplazamiento)
{
    if (isalpha(c)) 
    {
        // Verificamos si el carácter es una letra mayúscula o minúscula
        char base = (isupper(c)) ? 'A' : 'a';
        return (c - base + desplazamiento) % 26 + base; 
    }
    return c; 
}

// Función para cifrar el contenido de un archivo
void cifrarArchivo(const string& archivoEntrada, const string& archivoSalida, int desplazamiento) 
{
    ifstream archivoLeer(archivoEntrada);
    ofstream archivoEscribir(archivoSalida);
    string linea;
    if (archivoLeer.is_open() && archivoEscribir.is_open()) 
    {
        while (getline(archivoLeer, linea)) 
        {
            for (char& c : linea) {
                c = cifrarCaracter(c, desplazamiento);  
            }
            archivoEscribir << linea << endl; 
        }
        archivoLeer.close();
        archivoEscribir.close();
        cout << "El archivo cifrado se ha guardado en: " << archivoSalida << endl;
    } 
    else 
    {
        cout << "No se pudo abrir uno de los archivos." << endl;
    }
}

int main() 
{
    string archivoEntrada = "mensaje.txt";  
    string archivoSalida = "mensaje_cifrado.txt"; 
    int desplazamiento = 3; 
    cifrarArchivo(archivoEntrada, archivoSalida, desplazamiento);
    return 0;
}

