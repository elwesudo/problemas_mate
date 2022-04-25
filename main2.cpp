#include <iostream> //No hace falta que lo explique
#include <string> //Libreria para las cadenas
#include <fstream> //Libreria para el manejo de archivos

using namespace std; //Pss tampoco vdd

void guardar(){
	fstream archivo; //se declara el objeto archivo el cual vamos a utilizar para guardar datos en un archivo
	string nombre; //se declara la cadena nombre 
	archivo.open("nombres.txt", ios::app); //ios::app es el modo en el que va a abrir el archivo en este caso
	cout<<"Escribe tu nombre : ";		//si no está creado lo crea y si ya está escribe en el al final
	cin.ignore(); //se ignora el cin para poder manipularlo
	getline(cin, nombre); //se ejecuta el cin anterior pero en un modo en el que se lee toda la linea contando los espacios
	archivo<<nombre<<endl; //escribe en el archivo;
	archivo.close();	//cierra el archivo;
}

void mostrar(){
	int i=1;
	ifstream archivo; //se declara el objeto archivo que se va a utilizar para leer el archivo
	archivo.open("nombres.txt"); //se abre el archivo
	string contenido;
	if(not(archivo.eof())){ //si el archivo no está vacío
		while(getline(archivo, contenido)){ //lee las lineas y las guarda en la variable contenido
			cout<<i<<".-"<<contenido<<endl; //y las imprime una por una
			i++;
		}
		archivo.close(); //cierra el archivo
	}else{ //si no tiene nada escrito
		cout<<"El archivo está vacío\n"; //muestra mensaje de error
	}
}

void menu(){
	int opcion;
	cout<<"Selecciona una opción\n";
	cout<<"1.-Guardar un nombre\n";
	cout<<"2.-Ver lista de nombres\n";
	cin>>opcion;
	if(opcion==1){
		guardar(); 
	}
	else if(opcion==2){
		mostrar();
	}else{
		cout<<"Opción inválida\n";
	}
}

int main(){
	menu(); 
}
