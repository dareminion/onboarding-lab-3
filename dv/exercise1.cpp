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
      if (model.out != test){
        printf("I failed 0\n");
        std::cout << (int)out << std::endl;
        std::cout << (test) << std::endl;
        std::cout << i << std::endl << j << std::endl;
        return 1;
      }
      model.op = 3; // Test not and
      model.eval();
      uint8_t test3 = (~(model.a & model.b));
      if (model.out != test3){
        printf("I failed 3\n");
        std::cout << (int)model.out << std::endl;
        std::cout << test3 << std::endl;
        std::cout << i << std::endl << j << std::endl;
        return 1;
      }
      model.op = 2; // mod test
      model.eval();
      if (j != 0){
        uint8_t test2 = model.a % model.b;
        if (model.out != test2){
        printf("I failed 2");
        std::cout << (int)model.out << std::endl;
        std::cout << test2 << std::endl;
        std::cout << i << std::endl << j << std::endl;
        return 1;
      }
      }
      model.op = 1;
      model.a = i;
      model.b = j;
      model.eval();
      
      if (j >= 32){
        uint8_t test1 = (i << j);
        if (model.out){
        printf("random test fails\n");
        printf("model output  ");
        std::cout << (int)model.out << std::endl;
        printf("test output  ");
        std::cout << (int)test1 << std::endl;
        printf("i  ");
        std::cout << i << std::endl;
        printf("j  ");
        std::cout << j << std::endl;
        printf("model.out is %d", model.out);
        return 1;
      }
      }
      else if (j < 32){
        uint8_t test1 = (i << j);
        if (model.out != test1){
          printf("I failed 1");
          std::cout << (int)model.out << std::endl;
          std::cout << (int)test1 << std::endl;
          std::cout << (int)i << std::endl << (int)j << std::endl;
          return 1;
        }
      }
    }
  }
  return 0;
}


