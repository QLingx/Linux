#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "lr.h"

void LR_construct(LogisticRegression* lr,int N,int n_in,int n_out){
    lr->N = N;
    lr->n_in = n_in;
    lr->n_out = n_out;

    lr->w = (double **)malloc(sizeof(double*) * n_out);
    lr->w[0] = (double*)malloc(sizeof(double) * n_in * n_out);
    for(int i = 0;i < n_out;i++){
        lr->w[i] = lr->w[0] + i * n_in;
    }
    lr->b = (double*)malloc(sizeof(double) * n_out);

    for(int i = 0;i < n_out;i++){
        for(int j = 0;j < n_in;j++){
            lr->w[i][j] = 0;
        }
        lr->b[i] = 0;
    }
}
void LR_destruct(LogisticRegression* lr){
    free(lr->w[0]);
    free(lr->w);
    free(lr->b);
}

void LR_train(LogisticRegression* lr,int* x,int* y,double rate){
    double *p_y_given_x = (double*)malloc(sizeof(double) * lr->n_out);
    double *dy = (double*)malloc(sizeof(double) * lr->n_out);

    for(int i = 0;i < lr->n_out;i++){
        p_y_given_x[i] = 0;
        for(int j = 0;j < lr->n_in;j++){
            p_y_given_x[i] += lr->w[i][j] * x[j];
        }
        p_y_given_x[i] += lr->b[i];
    }
    LR_softmax(lr,p_y_given_x);

    for(int i = 0;i < lr->n_out;i++){
        dy[i] = y[i] - p_y_given_x[i];
        for(int j = 0;j < lr->n_in;j++){
            lr->w[i][j] += rate * dy[i] * x[j] / lr->N;
        }
        lr->b[i] += rate * dy[i] / lr->N;
    }
    free(p_y_given_x);
    free(dy);
}

void LR_softmax(LogisticRegression* lr,double* x){
    double max = 0.0;
    double sum = 0.0;

    for(int i = 0;i < lr->n_out;i++){
        if(max < x[i]){
            max = x[i];
        }
    }
    for(int i = 0;i < lr->n_out;i++){
        x[i] = exp(x[i]-max);
        sum += x[i];
    }
    for(int i = 0;i < lr->n_out;i++){
        x[i] /= sum;
    }
}

void LR_predict(LogisticRegression* lr,int* x,double* y){
    for(int i = 0;i < lr->n_out;i++){
        y[i] = 0;
        for(int j = 0;j < lr->n_in;j++){
            y[i] += lr->w[i][j] * x[j];
        }
        y[i] += lr->b[i];
    }

    LR_softmax(lr,y);
}

void test_lr(){
    double learning_rate = 0.1;
    int n_epochs = 500;

    int train_N = 6;
    int test_N = 2;
    int n_in = 6;
    int n_out = 2;

    int train_X[6][6] = {
        {1,1,1,0,0,0},
        {1,0,1,0,0,0},
        {1,1,1,0,0,0},
        {0,0,1,1,1,0},
        {0,0,1,1,0,0},
        {0,0,1,1,1,0}
    };

    int train_Y[6][2] = {
        {1,0},
        {1,0},
        {1,0},
        {0,1},
        {0,1},
        {0,1}
    };

    LogisticRegression classifier;
    LR_construct(&classifier,train_N,n_in,n_out);

    for(int epoch = 0;epoch < n_epochs;epoch++){
        for(int i = 0;i < train_N;i++){
            LR_train(&classifier,train_X[i],train_Y[i],learning_rate);
        }
    }

    int test_X[2][6] = {
        {1,0,1,0,0,0},
        {0,0,1,1,1,0}
    };

    double test_Y[2][2];

    for(int i = 0;i < test_N;i++){
        LR_predict(&classifier,test_X[i],test_Y[i]);
        for(int j = 0;j < n_out;j++){
            printf("%f ",test_Y[i][j]);
        }
        printf("\n");
    }

    LR_destruct(&classifier);
}

int main(){
    test_lr();
    return 0;
}