#include <stdio.h>
#include <stdlib.h>
#define N 10

void ReadMatrixVector(float [][N], float [][N]);
void ShowMatrix(float [][N], int, int);
void ShowVector(float []);
void TransposedMatrix(float [][N], float [][N]);
void MatrixMultiplier(float [][N], float [][N], float [][N], int, int, int);
void Inverse2x2(float [][N],float [][N]);


int main()
{
    float X[N][N], Y[N][N], T[N][N], R[N][N], I[N][N], A[N][N], M[N][N];
    ReadMatrixVector(X, Y);

    printf("\nMatriz X:\n");
    ShowMatrix(X, 10, 2);

    printf("\nVetor Y:\n");
    ShowMatrix(Y, 10, 1);

    TransposedMatrix(X, T);

    MatrixMultiplier(T, X, R, 2, 10, 2);

    Inverse2x2(R, I);

    MatrixMultiplier(I, T, A, 2, 2, 10);
    MatrixMultiplier(A, Y, M, 2, 10, 1);

    printf("\n\nAnswer:\n");
    ShowMatrix(M, 2, 1);

    return 0;
}








void ReadMatrixVector(float X[][N], float Y[][N])
{
    int i;
    for (i=0; i<10; i++)
    {
        printf("Coordionate X[%i]: ", i);
        scanf("%f", &X[i][0]);
        X[i][1] = 1;
        printf("Coordinate Y[%i]: ", i);
        scanf("%f", &Y[i][0]);
        printf("\n");
    }
}

void ShowMatrix(float X[][N],int l,int c){
    int i, j;

    for (i=0; i<l; i++){
        for (j=0; j<c; j++){
           printf("%.1f\t", X[i][j]);
        }
        printf("\n");
    }
}

void ShowVector(float Y[]){
    int i;

    for (i=0; i<10; i++){
        printf("%.1f\t", Y[i]);
    }
}

void TransposedMatrix(float X[][N], float T[][N]){
    int l,c;

    for (l=0; l<10; l++){
        for (c=0; c<2; c++){
            T[c][l] = X[l][c];
        }
    }
}

void MatrixMultiplier(float A[][N], float B[][N], float R[][N], int l1, int c1, int c2){
    int i, j, k;
    // numero de colunas 1 == numero de linhas 2
    for (i=0; i<l1; i++){
        for (j=0; j<c2; j++){
            R[i][j] = 0;
            for (k=0; k<c1; k++){
                R[i][j] += A[i][k] * B[k][j]; // A[0][1] * B[1][0] + A[0][2] * B[2][0]...
            }
        }
    }
}

void Inverse2x2(float A[][N],float R[][N]){
    float det;

    det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    R[0][0] = A[1][1] / det;
    R[0][1] = - A[0][1] / det;
    R[1][0] = - A[1][0] / det;
    R[1][1] = A[0][0] / det;
}

