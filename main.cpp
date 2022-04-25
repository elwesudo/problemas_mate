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

int mostrar(){
	int i=1;
	ifstream archivo;
	archivo.open("nombres.txt");
	string contenido;
	if(not(archivo.eof())){
		while(getline(archivo, contenido)){
			cout<<i<<".-"<<contenido<<endl;
			i++;
		}
		archivo.close();
	}else{
		cout<<"El archivo está vacío\n";
		return 0;
	}
	return i;
}

void editar(int i,bool borrar=false){
	ifstream archivo2;
	ofstream archivo;
	archivo2.open("nombres.txt");
	int num;
	string nombre="", contenido, linea;
	cout<<"Ingrese el número de la variable a editar: ";
	cin>>num;
	if(num>i){
		cout<<"Se ha ingresado un número no válido\n";
		return;
	}
	if(borrar==false){
		cout<<"Ingrese el nuevo nombre: ";
		cin.ignore();
		getline(cin,nombre);
	}
	i=1;
	while(getline(archivo2, linea)){
		if(i==num){
			contenido += nombre;
		}else{
			contenido += linea;
		}
		contenido += "\n";
		i++;
	}
	archivo.open("nombres.txt");
	archivo<<contenido;
}

void menu(){
	int opcion, i;
	cout<<"Selecciona una opción\n";
	cout<<"1.-Guardar un nombre\n";
	cout<<"2.-Ver lista de nombres\n";
	cout<<"3.-Editar un nombre\n";
	cout<<"4.-Borrar un nombre\n";
	cin>>opcion;
	if(opcion==1){
		guardar();
	}
	else if(opcion==2){
		mostrar();
	}
	else if(opcion==3){
		i=mostrar();
		if(i==0){
			cout<<"Por lo que no se puede editar ningún nombre\n";
		}else{
			editar(i);
		}	
		mostrar();
	}
	else if(opcion==4){
		if(mostrar()==1){
			cout<<"Por lo que no se puede borrar ningún nombre\n";
		}else{
			editar(i,true);
		}
		mostrar();
	
	}
}

int main(){
	menu(); 
}
