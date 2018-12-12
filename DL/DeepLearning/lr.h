#ifndef LR_H
#define LR_H

typedef struct{
    int N;
    int n_in;
    int n_out;
    double **w;
    double *b;
}LogisticRegression;

void LR_construct(LogisticRegression*,int,int,int);
void LR_destruct(LogisticRegression*);
void LR_train(LogisticRegression*,int*,int*,double);
void LR_softmax(LogisticRegression*,double*);
void LR_predict(LogisticRegression*,int*,double*);

#endif