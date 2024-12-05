/*Materia: Programación I, Paralelo 1
Autor: Alvaro Alejandro Ochoa Segales
Fecha creación: 03/12/2024
Número de ejercicio: 2
Problema planteado: Contador de palabras en un archivo  */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
int contarpalabras(const string& nombreArchivo);
vector<string> ingresarTextos(int cantidad);
void guardarTextosEnArchivo(const vector<string>& textos, const string& nombreArchivo);
int main()
{
    int cantidad;
    cout << "Ingrese la cantidad de textos:";
    cin >> cantidad;
    cin.ignore();
    vector<string> textos = ingresarTextos(cantidad);
    string nombreArchivo = "textos.txt";
    guardarTextosEnArchivo(textos, nombreArchivo);
    cout << "El archivo tiene " << contarpalabras(nombreArchivo) << " palabras";
    return 0;
}
vector<string> ingresarTextos(int cantidad) 
{
    vector<string> textos (cantidad);
    for(int i = 0; i < cantidad; i++)
    {
        getline(cin, textos[i]);
    } 
    return textos;
}
// funcion para guardar texto del archivo 
void guardarTextosEnArchivo(const vector<string>& nombres, const string& nombreArchivo) 
{
    ofstream archivo(nombreArchivo);
    for(string n : nombres)
    {
        archivo << n << endl;
    }
    archivo.close();
}
//Funcion para contar las palabras en el archivo
int contarpalabras(const string& nombreArchivo) 
{
    ifstream archivoLeer(nombreArchivo);
    string linea;
    int palabras = 0;
    while(getline(archivoLeer, linea))
    {
        for(int i = 0; i < linea.length(); i++)
        {
            if(linea[i] == ' ') palabras++;
        }
        palabras++;
    }
    archivoLeer.close();
    return palabras;
}