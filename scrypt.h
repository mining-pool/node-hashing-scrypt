#ifndef SCRYPTN_H
#define SCRYPTN_H
#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

void scrypt_256(const char* input, char* output, uint32_t N, uint32_t R, uint32_t P, uint32_t len);

#ifdef __cplusplus
}
#endif

#endif
