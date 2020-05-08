#include <iostream>
#include<cstdlib>
#include <ctime>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
bool MCD(int, int);
int* llenado(int array[], int n);
int* simulacion(int array[], int n);
void imprimir(int [], int);
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
           	    int indice;
           	    cout<< " Ingrese un numero: "<<endl;
           	    cin>>indice;
           	    cout<<" El triangulo de pascal para el numero "<< indice<< " es: "<<endl;
           	    int matriz[indice][indice];
           	    cout<<1<<endl;
           	    for(int i=0; i< indice-1; i++){
           	    	if(i==0){
           	    		matriz[0][0]=1;
					   }
           	    	matriz[i][0]=1;
           	    	matriz[i][i+1]=1;
           	    	cout<<" "<<endl;
           	    	for(int j=0; j<i+2; j++){
           	    		matriz[i+1][j+1]=matriz[i][j]+matriz[i][j+1];
           	    		cout<<matriz[i][j]<<" ";
					}
					   cout<<endl;
				   }
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
				int* game;
				game=simulacion(array,size);
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


int* simulacion(int array[], int n){
	int puntosJugador1=0, puntosJugador2=0;
	int numeroSeleccionado, chooseNumber, chooseNumber1, turnos=1;
	int rondas=n/2;
	for(int i=1; i<= rondas; i++){
			cout<<"Jugador 1 escoger: ";
			cin>>chooseNumber;
			cout<<"Jugador 2 escoge: ";
			cin>>chooseNumber1;
			while(chooseNumber >= n){
				cout<<" El numero sobrepasa el limite"<<endl;
				cout<<" Ingrese un numero nuevo: "<<endl;
				cin>> chooseNumber;
			}
				while(chooseNumber1 >= n){
				cout<<" El numero sobrepasa el limite"<<endl;
				cout<<" Ingrese un numero nuevo: "<<endl;
				cin>> chooseNumber1;
			}
			while(chooseNumber==chooseNumber1){
				cout<<"Este numero ya ha sido seleccionado"<<endl;
				cout<<" Favor ingrese un numero nuevo: "<<endl;
				cin>>chooseNumber;
				cout<<endl;
			}
			
			while(chooseNumber1==chooseNumber){
				cout<<" Este numero ya ha sido seleccionado"<<endl;
				cout<<" Favor ingrese un numero nuevo: "<<endl;
				cin>>chooseNumber1;
				cout<<endl;
			}
			cout<<endl;
			cout<<" El jugador: "<<1<<" obtuvo: "<<array[chooseNumber]<<endl;
			puntosJugador1+=array[chooseNumber];
			turnos++;
			cout<<" El jugador: "<<2<<" obtuvo : "<<array[chooseNumber1]<<endl;
			puntosJugador2+=array[chooseNumber1];
			turnos++;
			cout<<" Ronda "<<i<< " Jugador 1: "<< puntosJugador1 << "  <->  "<< " Jugador 2: "<<puntosJugador2<<endl;
			cout<<endl;
		}
		
		if(puntosJugador1 == puntosJugador2){
			cout<<" Hubo un empate"<<endl;
			cout<<endl;
		}else if(puntosJugador1> puntosJugador2){
			cout<<" El jugador 1 gana con: "<< puntosJugador1 << " puntos"<<endl;
			cout<<endl;
		}else{
		cout<<" El jugador 2 gana con: "<< puntosJugador2 << " puntos"<<endl;	
		cout<<endl;
		}
		imprimir(array,n);

		
	}

	

	

	







