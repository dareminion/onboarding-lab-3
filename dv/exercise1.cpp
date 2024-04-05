#include <VExercise1.h>
#include <stdio.h>
#include <iostream>

int main() {
  int i,j;
  uint8_t out;
  VExercise1 model;
  // Tests case 0 and 3
  for (i=0; i <=255; i++){
    model.a = i;
    for (j=0; j<=255; j++){
      model.b = j;
      model.op = 0; // Tests xor
      model.eval();
      uint8_t test = model.a ^ model.b;
      if (out != test){
        printf("I failed 0\n");
        std::cout << (int)out << std::endl;
        std::cout << (i ^ j) << std::endl;
        std::cout << i << std::endl << j << std::endl;
        return 1;
      }
      model.op = 3; // Test not and
      model.eval();
      if (out != (uint8_t)(~(i & j))){
        printf("I failed 3\n");
        std::cout << (int)model.out << std::endl;
        std::cout << ~(i & j) << std::endl;
        std::cout << i << std::endl << j << std::endl;
        return 1;
      }
      model.op = 2; // mod test
      model.eval();
      if (j != 0){
        if (model.out != (uint8_t)(i % j)){
        printf("I failed 2");

        return 1;
      }
      }
      model.op = 1;
      model.a = i;
      model.b = j;
      model.eval();
      if (model.out != (uint8_t)(i << j)){
        printf("I failed 1");
        return 1;
      }
    }
  }
  return 0;
}

