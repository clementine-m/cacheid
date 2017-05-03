#include <stdio.h>

#define cpuid(ina,inc,a,b,c,d) \
  asm("cpuid" \
      : "=a" (a), "=b" (b), "=c" (c), "=d" (d) \
      : "a" (ina), "c" (inc) \
      );


int main(){
  /* Output registers */
  unsigned long eax,ebx,ecx,edx;

  /* Input EAX = 4 for cache information */
  int eax_in = 4;

  /* Input ECX */
  int ecx_in;

  /*
   * Prints diverse cache information for each cache level
   */
  for(ecx_in=0; ecx_in<4; ecx_in++){
    cpuid(eax_in, ecx_in,eax,ebx,ecx,edx);

    /*
     * Level
     * EAX, bits 07-05
     * Starts at 1
     */
    unsigned long level = (eax & ~(~0ul << 3) << 5) >> 5;
    printf("\n-- Level: %lu ", level);

    /*
     * Cache type
     * EAX, bits 04-00
     */
    unsigned long type = (eax & ~(~0ul << 4) << 0) >> 0;
    switch(type){
      case 1:
        printf("(data cache)\n");
        break;
      case 2:
        printf("(instruction cache)\n");
        break;
      case 3:
        printf("(unified cache)\n");
        break;
      default:
        printf("null\n");
        break;
    }

    /*
     * Inclusiveness
     * EDX, bit 1
     */
    long int inclusiveness = ((edx & 1 << 1) != 0);
    switch(inclusiveness){
      case 0:
        printf("Not inclusive of lower cache levels\n");
        break;
      case 1:
        printf("Inclusive of lower cache levels\n");
        break;
      default:
        printf("null\n");
        break;
    }

    /*
     * Complex addressing
     * EDX, bit 2
     */
    long int addressing = ((edx & 1 << 2) != 0);
    printf("Cache addressing: ");
    switch(addressing){
      case 0:
        printf("direct mapped cache\n");
        break;
      case 1:
        printf("complex addressing\n");
        break;
      default:
        printf("null\n");
        break;
    }

    /*
     * Line size
     * EBX, bits 11-00
     * Add one to the return value to get the result.
     */
    unsigned long line_size = (ebx & ~(~0ul << 12) << 0) >> 0;
    printf("Line size: %lu\n", line_size+1);

    /*
     * Ways of associativity
     * EBX, bits 31-22
     * Add one to the return value to get the result.
     */
    unsigned long ways = (ebx & ~(~0ul << 10) << 22) >> 22;
    printf("Number of ways: %lu\n", ways+1);

    /*
     * Number of sets
     * ECX, bits 31-22
     * Add one to the return value to get the result.
     */
    unsigned long sets = (ecx & ~(~0ul << 31) << 0) >> 0;
    printf("Number of sets: %lu\n", sets+1);

    /* Raw results */
    printf("Raw results:\n");
    printf("0x%08x 0x%02x: eax=0x%08lx ebx=0x%08lx ecx=0x%08lx edx=0x%08lx\n",eax_in,ecx_in,eax,ebx,ecx,edx);
  }

  return 0;
}
