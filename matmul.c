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
  size_t i, k;
  size_t end = ((coreid + 1) * lda) / ncores;

  for (i = (coreid * lda) / ncores; i < end; i++) {
    for (k = 0; k < lda; k++) {
      data_t elem_a = A[i*lda + k];
      C[i*lda] += elem_a * B[k*lda];
      C[i*lda + 1] += elem_a * B[k*lda + 1];
      C[i*lda + 2] += elem_a * B[k*lda + 2];
      C[i*lda + 3] += elem_a * B[k*lda + 3];
      C[i*lda + 4] += elem_a * B[k*lda + 4];
      C[i*lda + 5] += elem_a * B[k*lda + 5];
      C[i*lda + 6] += elem_a * B[k*lda + 6];
      C[i*lda + 7] += elem_a * B[k*lda + 7];
      C[i*lda + 8] += elem_a * B[k*lda + 8];
      C[i*lda + 9] += elem_a * B[k*lda + 9];
      C[i*lda + 10] += elem_a * B[k*lda + 10];
      C[i*lda + 11] += elem_a * B[k*lda + 11];
      C[i*lda + 12] += elem_a * B[k*lda + 12];
      C[i*lda + 13] += elem_a * B[k*lda + 13];
      C[i*lda + 14] += elem_a * B[k*lda + 14];
      C[i*lda + 15] += elem_a * B[k*lda + 15];
      C[i*lda + 16] += elem_a * B[k*lda + 16];
      C[i*lda + 17] += elem_a * B[k*lda + 17];
      C[i*lda + 18] += elem_a * B[k*lda + 18];
      C[i*lda + 19] += elem_a * B[k*lda + 19];
      C[i*lda + 20] += elem_a * B[k*lda + 20];
      C[i*lda + 21] += elem_a * B[k*lda + 21];
      C[i*lda + 22] += elem_a * B[k*lda + 22];
      C[i*lda + 23] += elem_a * B[k*lda + 23];
      C[i*lda + 24] += elem_a * B[k*lda + 24];
      C[i*lda + 25] += elem_a * B[k*lda + 25];
      C[i*lda + 26] += elem_a * B[k*lda + 26];
      C[i*lda + 27] += elem_a * B[k*lda + 27];
      C[i*lda + 28] += elem_a * B[k*lda + 28];
      C[i*lda + 29] += elem_a * B[k*lda + 29];
      C[i*lda + 30] += elem_a * B[k*lda + 30];
      C[i*lda + 31] += elem_a * B[k*lda + 31];
    }
  }
}

