#include <VExercise2.h>
#include <cstdint>
int main() {
  VExercise2 model;
  // Check the logic betweent bits 1 3 8 10
  // check the output on bit 15 of the output
  for(int j=0; j<16; j++){
    model.init = (1 << j);
    model.eval();
    uint16_t val = (model.out >> 0) & 1;
    uint16_t bit10 = (model.out >> 10) & 1;
    uint16_t bit8 = (model.out >> 8) & 1;
    uint16_t bit3 = (model.out >> 3) & 1;
    uint16_t bit1 = (model.out >> 1) & 1;
    uint16_t out = bit10 ^ bit8 ^ bit3 ^ bit1;
    if(val != out){
      return 1;
    }
  }
}
