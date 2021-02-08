// Aluno: Douglas Mateus Soares Cândido da Silva
// Matrícula: 20190020243 

#include <iostream> 
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <bits/stdc++.h> 
#include <fstream> 
#include <locale.h> 

using namespace std;

// Algorithm Insertion-Sort
int *insertion_sort(int array[], int n) {
	
	int j, k, i;
	
	for(j = 1; j < n; j++) {
		
		k = array[j];
		
		i = j - 1;
		
		while(i >= 0 and array[i] > k) {
			
			array[i + 1] = array[i];
			
			i = i - 1;
			
		}
		
		array[i + 1] = k;
		
	}
	
	return array;
	
}

// Algorithm Merge-Sort
void merge(int array[], int s, int m, int e, int vetorAux[]) {

    int esq = s;

    int dir = m;

    for (int i = s; i < e; ++i) {

        if ((esq < m) and ((dir >= e) or (array[esq] < array[dir]))) {

            vetorAux[i] = array[esq];

            ++esq;

        }

        else {

            vetorAux[i] = array[dir];

            ++dir;

        }

    }

    for (int i = s; i < e; ++i) {

        array[i] = vetorAux[i];

    }

}

int *merge_sort(int array[], int s, int e, int vetorAux[]) {
	
	int m;
	
	if((e - s) < 2) {
		
		return array;
		
	} 
	else {
		
		m = floor(((s + e) / 2));
		
		merge_sort(array, s, m, vetorAux);
		
		merge_sort(array, m, e, vetorAux);
		
		merge(array, s, m, e, vetorAux);
		
	}
	
	return array;
	
}

int *MergeSort(int array[], int n) { 

    int vetorAux[n];

    merge_sort(array, 0, n, vetorAux);

}

// Algorithm Quick-Sort

int *quick_sort(int array[], int s, int e) {
	
	int i, j, pivo, aux;
	
	i = s;
	
	j = e - 1;
	
	pivo = array[(s + e) / 2];
	
	while(i <= j) {
		
		while(array[i] < pivo && i < e) {
			
			i++;
			
		}
		
		while(array[j] > pivo && j > s) {
			
			j--;
			
		}
		
		if(i <= j) {
			
			aux = array[i];
			
			array[i] = array[j];
			
			array[j] = aux;
			
			i++;
			
			j--;
			
		}
		
	}
	
	if(j > s)
		quick_sort(array, s, j + 1);
	if(i < e)
		quick_sort(array, i, e);
		
	return array;
		
}

int main() {
	
	setlocale(LC_ALL,"");
	
	cout << "UFRN - CERES" << endl;
	cout << "Bacharelado em Sistemas de Informacao" << endl;
	cout << "Aluno: Douglas Mateus Soares Candido da Silva" << endl;
	cout << "Matricula: 20190020243" << endl;
	cout << "Disciplina: Estrutura de Dados" << endl;
	cout << "Professor: Joao Paulo" << endl;
	
	cout << endl;
	
	cout << "Atividade Pratica 1." << endl;
	
	cout << endl;
	
	srand(time(NULL));
	
	clock_t start, end; 
	
	int operacao;
	
	do{
		
		int n;
	
		cout << "Digite a quantidade de posicoes do vetor:" << endl;
	
		cin >> n;
	
		int vetor[n];
	
		for(int i = 0; i < n; i++) {
		
			vetor[i] =  rand();
		
		}
	
		cout << endl;
		
		cout << "Vetor: " << endl;
	
		cout << endl;
		
		for(int i = 0; i < n; i ++) {
		
			cout << vetor[i] << " ";	
			
		}
		
		cout << endl;
	
		cout << endl;
		
		cout << "Qual algoritmo de ordenacao deve ser utilizado? Digite 1 para Insertion Sort ou 2 para Merge Sort ou 3 para Quick Sort ou 4 para sair." << endl;
		
		cin >> operacao;
	
		if(operacao == 1) {
			
			// Insertion-Sort ------------------------------------------------
			
			ofstream MyFile("tempo_execucao_insertion_sort.txt", ios_base::app);
				
			start = clock(); 
			
			int *vetor_ordenado_insertion_sort = insertion_sort(vetor, n);
			
			end = clock(); 
			
			double tempo = double(end - start) / double(CLOCKS_PER_SEC);
				
			cout << endl;
				
			cout << "Vetor ordenado pelo algoritmo Insertion-Sort: " << endl;
			
			cout << endl;
				
			for(int j = 0; j < n; j++) {
				
				cout << vetor_ordenado_insertion_sort[j] << " ";
					
			}
							
			cout << endl;
			
			cout << endl;
			
			cout << "Tempo de Execucao: " << fixed << tempo << setprecision(5);
			cout << " s." << endl;
			
			MyFile << n << " " << tempo << endl;
			
			MyFile.close();
		
			// ----------------------------------------------------------------
			
		} 
		
		else if(operacao == 2) {
			
			// Merge-Sort -----------------------------------------------------
		
			ofstream MyFile("tempo_execucao_merge_sort.txt", ios_base::app);
			
			start = clock(); 
		
			int *vetor_ordenado_merge_sort = MergeSort(vetor, n);
			
			end = clock(); 
			
			double tempo = double(end - start) / double(CLOCKS_PER_SEC);
			
			cout << endl;
		
			cout << "Vetor ordenado pelo algoritmo Merge-Sort: " << endl;
			
			cout << endl;
			
			for(int i = 0; i < n; i++) {
		
				cout << vetor_ordenado_merge_sort[i] << " ";
			
			}
			
			cout << endl;
			
			cout << endl;
			
			cout << "Tempo de execucao: " << fixed << tempo << setprecision(5);
			cout << " s." << endl;
			
			MyFile << n << " " << tempo << endl;
			
			MyFile.close();
		
			// -----------------------------------------------------------------
			
		}
	
		else if (operacao == 3) {
			
			// Quick-Sort -----------------------------------------------------
			
			ofstream MyFile("tempo_execucao_quick_sort.txt", ios_base::app);
			
			start = clock(); 
		
			int *vetor_ordenado_quick_sort = quick_sort(vetor, 0, n);
			
			end = clock(); 
			
			double tempo = double(end - start) / double(CLOCKS_PER_SEC);
			
			cout << endl;
		
			cout << "Vetor ordenado pelo algoritmo Quick-Sort: " << endl;
			
			cout << endl;
			
			for(int i = 0; i < n; i++) {
		
				cout << vetor_ordenado_quick_sort[i] << " ";
			
			}
		
			cout << endl;
			
			cout << endl;
			
			cout << "Tempo de execucao: " << fixed << tempo << setprecision(5);
			cout << " s." << endl;
			
			MyFile << n << " " << tempo << endl;
			
			MyFile.close();
	
			// -----------------------------------------------------------------	
			
		}
		
		cout << endl;
		
		system("pause");
		system("cls");
		
	} while(operacao != 4);
	
	return 0;
	
}


