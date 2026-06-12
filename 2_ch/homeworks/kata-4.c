#include <stdio.h>

//  retorna 1 se x == y, 0 caso contrário. 
int float_eq(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31;
    unsigned sy = uy >> 31;

    return ((!(ux <<1)) & (!(uy << 1)))
           || !(ux ^ uy)
        //    ((sx & sy) | (!sx & !sy)) & !(ux ^ yx)
           
        //    & !(ux ^ yx)) // caso em que os bits de sinal são iguais 
        //    || (sx & sy) // caso em que os bits de sinal são diferentes
}

 
    // return (!((ux << 1) | (uy << 1)))  /* ambos zero        */
    //     || (sx & !sy)                  /* x negativo, y positivo */
    //     || (!sx & !sy & ((ux - uy) >> 31))  /* ambos positivos */
    //     || ((sx & sy) & ((uy - ux) >> 31)); /* ambos negativos */
// }


int main(void)
{

    return (0);
}