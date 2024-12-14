#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 50000
#define PRINT_LIMIT 200

int array[ARRAY_SIZE]; // Array global
double tempos[7];      // Array para armazenar os tempos de execução dos métodos de ordenação

// Funções do programa
void preencherArray();
void imprimirArray();
void bubbleSort();
void insertionSort();
void selectionSort();
void heapSort();
void quickSort();
void mergeSort();
void shellSort();
void imprimirTempos();
void executarTodosMetodos();
void exibirMenu();

// Implementações das funções de ordenação e utilitárias
int main() {
    int opcao;
    preencherArray(); // Preenche o array com números aleatórios ao iniciar

    do {
        exibirMenu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                preencherArray();
                printf("Array preenchido com numeros aleatorios.\n");
                break;
            case 2:
                bubbleSort();
                break;
            case 3:
                insertionSort();
                break;
            case 4:
                selectionSort();
                break;
            case 5:
                heapSort();
                break;
            case 6:
                quickSort();
                break;
            case 7:
                mergeSort();
                break;
            case 8:
                shellSort();
                break;
            case 11:
                imprimirTempos();
                break;
            case 12:
                executarTodosMetodos();
                break;
            case 13:
                imprimirArray();
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}

// Função para preencher o array com números aleatórios
void preencherArray() {
    srand(time(NULL));
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = rand() % 10000;
    }
}

// Função para imprimir o array
void imprimirArray() {
    printf("Array: ");
    for (int i = 0; i < PRINT_LIMIT; i++) {
        printf("%d ", array[i]);
    }
    printf("... ");
    for (int i = ARRAY_SIZE - PRINT_LIMIT; i < ARRAY_SIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Funções de ordenação
void bubbleSort() {
    clock_t start = clock();
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    tempos[0] = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Bubble Sort concluido.\n");
}

void insertionSort() {
    clock_t start = clock();
    for (int i = 1; i < ARRAY_SIZE; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
    tempos[1] = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Insertion Sort concluido.\n");
}

void selectionSort() {
    clock_t start = clock();
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < ARRAY_SIZE; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
    tempos[2] = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Selection Sort concluido.\n");
}

void heapify(int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && array[left] > array[largest])
        largest = left;
    if (right < n && array[right] > array[largest])
        largest = right;
    if (largest != i) {
        int temp = array[i];
        array[i] = array[largest];
        array[largest] = temp;
        heapify(n, largest);
    }
}

void heapSort() {
    clock_t start = clock();
    for (int i = ARRAY_SIZE / 2 - 1; i >= 0; i--)
        heapify(ARRAY_SIZE, i);
    for (int i = ARRAY_SIZE - 1; i > 0; i--) {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(i, 0);
    }
    tempos[3] = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Heap Sort concluido.\n");
}

int partition(int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] < pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

void quickSortRec(int low, int high) {
    if (low < high) {
        int pi = partition(low, high);
        quickSortRec(low, pi - 1);
        quickSortRec(pi + 1, high);
    }
}

void quickSort() {
    clock_t start = clock();
    quickSortRec(0, ARRAY_SIZE - 1);
    tempos[4] = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Quick Sort concluido.\n");
}

void merge(int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = array[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = array[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRec(int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSortRec(l, m);
        mergeSortRec(m + 1, r);
        merge(l, m, r);
    }
}

void mergeSort() {
    clock_t start = clock();
    mergeSortRec(0, ARRAY_SIZE - 1);
    tempos[5] = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Merge Sort concluido.\n");
}

void shellSort() {
    clock_t start = clock();
    for (int gap = ARRAY_SIZE / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < ARRAY_SIZE; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
    tempos[6] = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Shell Sort concluido.\n");
}

void imprimirTempos() {
    const char *metodos[7] = {"Bubble Sort", "Insertion Sort", "Selection Sort", "Heap Sort", "Quick Sort", "Merge Sort", "Shell Sort"};
    for (int i = 0; i < 7; i++) {
        printf("%s: %.5f segundos\n", metodos[i], tempos[i]);
    }
}

void executarTodosMetodos() {
    bubbleSort();
    insertionSort();
    selectionSort();
    heapSort();
    quickSort();
    mergeSort();
    shellSort();
}

void exibirMenu() {
    printf("\nMenu:\n");
    printf("01 - Preencher o array com numeros aleatorios\n");
    printf("02 - Ordenar o array pelo metodo Bubble Sort\n");
    printf("03 - Ordenar o array pelo metodo Insertion Sort\n");
    printf("04 - Ordenar o array pelo metodo Selection Sort\n");
    printf("05 - Ordenar o array pelo metodo Heap Sort\n");
    printf("06 - Ordenar o array pelo metodo Quick Sort\n");
    printf("07 - Ordenar o array pelo metodo Merge Sort\n");
    printf("08 - Ordenar o array pelo metodo Shell Sort\n");
    printf("11 - Imprimir resultados dos metodos de ordenacao executados\n");
    printf("12 - Executar todos os metodos de ordenacao\n");
    printf("13 - Imprimir o array\n");
    printf("00 - Encerrar o programa\n");
}
