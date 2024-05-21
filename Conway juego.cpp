#include <iostream>
#include <fstream>

using namespace std;
//definimos constantes con el tamanio max y min de la matriz que leera del txt.
const int Maxfil=100;
const int Maxcol=100;


//Funcion para leer el archivo.
void cargar(string archivo,int filas,int columnas,int cuadricula[Maxfil][Maxcol]){
           ifstream archivo("archivo.txt");
           if(archivo.is_open()){
           	archivo>>filas>>columnas;
           	if(filas>Maxfil||columnas>Maxcol){
           		cout<<"el nuumero se exede del tamanio maximno\n";
			   }
			   for(int i=0;i<filas;i++){
			   	 for(int j=0;j<columnas;j++){
			   	 	 archivo>>cuadricula[i][j];
					}
			   }
		   }
            archivo.close();
            else{
            	cout<<"Error\n";
			}
	
}
//funcion para mostrar la cuadricula 
void mostrarCuadricula(int cuadricula[Maxfil][Maxcol],int filas,int columnas){
	 for(int i=0;i<filas;i++){
	 	for(int j=0;j<columnas;j++){
	 		cout<<(cuadricula[i][j] '0' '.')<<" ";
		 }
		  cout<<"\n";
	 }
	
	
}
//esat funbcion nos permite contar la cantidad de celulas vivias
void ContarCelulasvivas(int  cuadricula[Maxfil][Maxcol],int filas,int columnas){
	int contadorviv=0;
	 for(int i=0;i<filas;i++){
	 	for(int j=0;j<columnas;j++){
	 		contadorviv=contadorviv+cuadricula[i][j];
		 }
	 }
	return contadorviv;
	
}
 // funcion para la cantidad de 
void rondas(int cuadricula[Maxfil][Maxcol],int columnas,int filas){
	 int nuevcuadricula[Maxfil][Maxcol]={0};
	          for(int i=0;i<filas;i++){
	          	for(int j=0;j<columnas;j++){
	          		int vivas=0;
	          		for(int x=-1;x<=1;x++){
	          			for(int y=-1;y<=1;y++){
	          				 if(x==0 && y==0){
	          				 	int ni= i+x;
	          				 	int nj =j+y;
	          				 	  if(ni>=0 && ni<filas && nj >=0 && nj<columnas){
	          				 	  	         vivas=vivas+cuadricula[ni][nj];
									 } 
							   }
						  }
						        //Esta expresión implementa la lógica de actualización de una célula en la cuadrícula
						       nuevacuadricula[i][j]=(cuadricula[i][j]==1 && (vivas==2 || vivas==3)) || (cuadricula[i][j]==0 && vivas==3) ? 1 : 0
					  }
				  }
				        //aqui hacemos ncomo el intercambio de cuadriculas
				      for(int i=0;i<filas;i++){
				      	 for(intr j=0;j<columnas;j++){
				      	 	  cuadricula[i][j]=nuevacuadricula[i][j];
				      	 	  
						   }
					  }
			  }
	
}
int main(){
	const char* archivo="archivo.txt";
	int filas,columnas,generaciones;
	//Solicita al usuario el número de generaciones a simular.
	cout<<"ingrese la num de generaciones a simular";
	cin>>generaciones;
	cuadricula[Maxfil][Maxcol]={0};
	//Carga la configuración inicial desde el archivo.
	cargar(archivo,filas,columnas,cuadricula);
	//Simula el juego por el número de generaciones especificado, mostrando la cuadrícula y contando las células vivas en cada generación.
	for(int i=0;i<generaciones;i++){
		cout<<"Generacion"<<i+1<<" \n";
		mostrarCuadricula(cuadricula,filas,columnas);
		cout<<"Celulas vivas"<<ContarCelulasvivas(cuadricula,filas,columnas)<<"\n";
		rondas(cuadricula,columnas,filas);
		 }
	return 0;
}
