#ifndef SPACE_H
#define SPACE_H

#include "size.h"

typedef struct tData {
    unsigned char aux_bdata1[IMG_SIZE_ITER];
    unsigned char aux_bdata2[IMG_SIZE_ITER];
    unsigned char aux_bdata3[IMG_SIZE_ITER];
    unsigned char aux_bdata4[IMG_SIZE_ITER];
    unsigned char aux_bdata5[IMG_SIZE_ITER];

    float aux_fdata1[IMG_SIZE_ITER];
    float aux_fdata2[IMG_SIZE_ITER];
    float aux_fdata3[IMG_SIZE_ITER];
    float aux_fdata4[IMG_SIZE_ITER];

    double aux_ddata1[IMG_SIZE_ITER];

    double ddata1[IMG_SIZE];
    double ddata2[IMG_SIZE];
    double ddata3[IMG_SIZE];
    double ddata4[IMG_SIZE];
    double ddata5[IMG_SIZE];

    int idata1[IMG_SIZE];
    int idata2[IMG_SIZE];
    int idata3[IMG_SIZE];

    float TOA_fdata[IMG_SIZE_ITER*6];
};

//Reserva de datos

#endif