#include <iostream>
#include<cstdlib>
#include <ctime>
using std::cin;
using std::cout;
using std::endl;
bool MCD(int, int);
int* llenado(int array[], int n);
void imprimir(int [], int);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
long * pascal(int fila);
int main(int argc, char** argv) {
	
	int opcion;
	cout<< " Ingrese una opcion: "
	<<" \n 1. Numero FI" 
	<<" \n 2. Triangulo de pascal" 
	<<" \n 3. Simulacion Juego" 
	<<" \n 4. salir "<<endl;
	cin>>opcion;
	 switch (opcion) {
	 	case 1: {
	 		int contadorFi=0;
	 		int inputNumber;
	 		cout<<"Ingrese un numero: ";
	 		cin>>inputNumber;
	 		bool confirmacion=false;
	 		for(int i=1; i<=inputNumber; i++){
	 			confirmacion = MCD(inputNumber,i);
					if( confirmacion == true){
						contadorFi++;
					}
			 }
		
			cout<< " El numero fi de tu numero ingresado es: "<< contadorFi<<endl;
		
	
			break;
		 }
           case 2:{
           	    //Lectura d la fila a calcular


  
			break;
		   }
            
           case 3:{
           		int size;
				cout<< " Ingrese tam del arreglo: ";
				cin>>size;
				while(size<=1 || size%2==1){
					cout<<" Solo se permiten numeros pares: "<<endl;
					cout<<" Ingrese un nuevo numero: "<<endl;
					cin>>size;
				}
				int array[size];
				int *punti;
				punti=llenado(array,size);
				imprimir(array,size);
			break;
		   }
		   
		   case 4:{
		   	exit(0);
			break;
		   }
                          
           default:
           		cout<<"Opcion incorrecta";
                break;
      }
	 	
	 return 0;
}

bool MCD(int numerador, int denominador){
	if((numerador>denominador) && denominador!=0){
		int residuo = numerador % denominador;
		MCD(denominador,residuo);
		
	}else{
		if(numerador==1){
			return true;
		}else{
			return false;
		}
	}
	
}

int* llenado(int array[], int n){
	srand((unsigned)time(0));
	 array[n];
	for(int i=0;i< n;i++){
		array[i]=-50 + rand() % (50+1 - (-50));

		}
	
	return array;
}

void imprimir(int array[], int n){

	cout<<" El arreglo utilizado fue: "<<endl;
	for(int i=0;i< n;i++){
		cout<<"["<<array[i]<<"]";
		}
		
		cout<<endl;
}
	







