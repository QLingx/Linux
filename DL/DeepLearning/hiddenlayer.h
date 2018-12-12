#ifndef HIDDENLAYER_H
#define HIDDENLAYER_H

typedef struct{
    int N;
    int n_in;
    int n_out;
    double **w;
    double *b;
}HiddenLayer

void HL_construct(HiddenLayer*,int,int,int,double**,double*);
void HL_destruct(HiddenLayer*);
double HL_output(HiddenLayer*,int*,double*,double);
void HL_sample_h_given_v(HiddenLayer*,int*,int*);

#endif



