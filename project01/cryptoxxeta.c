#include <stdint.h>
#include <string.h>
#include <stdio.h>
//   #define DELTA 0x9e3779b9
//   #define MX (((z>>5^y<<2) + (y>>3^z<<4)) ^ ((sum^y) + (key[(p&3)^e] ^ z)))

// void btea(uint32_t *v, int n, uint32_t const key[4]) {
//     uint32_t y, z, sum;
//     unsigned p, rounds, e;
//     if (n > 1) {          /* Coding Part */
//       rounds = 6 + 52/n;
//       sum = 0;
//       z = v[n-1];
//       do {
//         sum += DELTA;
//         e = (sum >> 2) & 3;
//         for (p=0; p<n-1; p++) {
//           y = v[p+1]; 
//           z = v[p] += MX;
//         }
//         y = v[0];
//         z = v[n-1] += MX;
//       } while (--rounds);
//     } else if (n < -1) {  /* Decoding Part */
//       n = -n;
//       rounds = 6 + 52/n;
//       sum = rounds*DELTA;
//       y = v[0];
//       do {
//         e = (sum >> 2) & 3;
//         for (p=n-1; p>0; p--) {
//           z = v[p-1];
//           y = v[p] -= MX;
//         }
//         z = v[n-1];
//         y = v[0] -= MX;
//       } while ((sum -= DELTA) != 0);
//     }
//   }

#define  MX (z>>5^y<<2) + (y>>3^z<<4)^(sum^y) + (k[p&3^e]^z);
long btea(long* v, long n, long* k)
{     unsigned long z=v[n-1], y=v[0], sum=0, e, DELTA=0x9e3779b9; 
       long p, q ;  
     if (n > 1) {          /* 加密过程 */
       q = 6 + 52/n;
      while (q-- > 0){
        sum += DELTA;  
             e = (sum >> 2) & 3;
     for (p=0; p<n-1; p++)
          y = v[p+1],z = v[p] += MX;
          y = v[0];
          z = v[n-1] += MX;}
           return 0 ;
    } else if (n < -1) {          /* 解密过程 */
           n = -n;   
          q = 6 + 52/n;  
          sum = q*DELTA ;
        while (sum != 0) { 
          e = (sum >> 2) & 3;
           for (p=n-1; p>0; p--) 
            z = v[p-1], y = v[p] -= MX;
               z = v[n-1]; y = v[0] -= MX;
               sum -= DELTA; 
                }
       return 0;
      }  return 1; }
void main(int argc, char const *argv[])
{
  char *a="helloo";
  char *key="hh";
  long * dat =(long *) a;
  printf("%s\n", a);
  btea(atol(a),2,atol(key));
  printf("%s\n", a);
}