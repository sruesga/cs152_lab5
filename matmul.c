// See LICENSE for license details.

#include "dataset.h"
#include "util.h"
#include <stddef.h>

void matmul(const size_t coreid, const size_t ncores, const size_t lda,  const data_t A[], const data_t B[], data_t C[])
{
  size_t i, j, k;

  for (i = 0; i < lda; i++) {
    for (j = coreid; j < lda; j += ncores) {
      data_t sum = 0;
      for (k = 0; k < lda; k++)
        sum += A[j*lda + k] * B[k*lda + i];
      C[i + j*lda] = sum;
    }
  }
}

void matmul_opt(const size_t coreid, const size_t ncores, const size_t lda,  const data_t A[], const data_t B[], data_t C[])
{
  size_t i, j, k;
  size_t end = ((coreid + 1) * lda) / ncores;

  for (i = (coreid * lda) / ncores; i < end; i++) {
    for (k = 0; k < lda; k++) {
      data_t elem_a = A[i*lda + k];
         C[i*lda + j] += elem_a * B[k*lda + j];
         C[i*lda + j + 1] += elem_a * B[k*lda + j + 1];
         C[i*lda + j + 2] += elem_a * B[k*lda + j + 2];
         C[i*lda + j + 3] += elem_a * B[k*lda + j + 3];
         C[i*lda + j + 4] += elem_a * B[k*lda + j + 4];
         C[i*lda + j + 5] += elem_a * B[k*lda + j + 5];
         C[i*lda + j + 6] += elem_a * B[k*lda + j + 6];
         C[i*lda + j + 7] += elem_a * B[k*lda + j + 7];
         C[i*lda + j + 8] += elem_a * B[k*lda + j + 8];
         C[i*lda + j + 9] += elem_a * B[k*lda + j + 9];
         C[i*lda + j + 10] += elem_a * B[k*lda + j + 10];
         C[i*lda + j + 11] += elem_a * B[k*lda + j + 11];
         C[i*lda + j + 12] += elem_a * B[k*lda + j + 12];
         C[i*lda + j + 13] += elem_a * B[k*lda + j + 13];
         C[i*lda + j + 14] += elem_a * B[k*lda + j + 14];
         C[i*lda + j + 15] += elem_a * B[k*lda + j + 15];
         C[i*lda + j + 16] += elem_a * B[k*lda + j + 16];
         C[i*lda + j + 17] += elem_a * B[k*lda + j + 17];
         C[i*lda + j + 18] += elem_a * B[k*lda + j + 18];
         C[i*lda + j + 19] += elem_a * B[k*lda + j + 19];
         C[i*lda + j + 20] += elem_a * B[k*lda + j + 20];
         C[i*lda + j + 21] += elem_a * B[k*lda + j + 21];
         C[i*lda + j + 22] += elem_a * B[k*lda + j + 22];
         C[i*lda + j + 23] += elem_a * B[k*lda + j + 23];
         C[i*lda + j + 24] += elem_a * B[k*lda + j + 24];
         C[i*lda + j + 25] += elem_a * B[k*lda + j + 25];
         C[i*lda + j + 26] += elem_a * B[k*lda + j + 26];
         C[i*lda + j + 27] += elem_a * B[k*lda + j + 27];
         C[i*lda + j + 28] += elem_a * B[k*lda + j + 28];
         C[i*lda + j + 29] += elem_a * B[k*lda + j + 29];
         C[i*lda + j + 30] += elem_a * B[k*lda + j + 30];
         C[i*lda + j + 31] += elem_a * B[k*lda + j + 31];
    }
  }
}

