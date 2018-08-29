#include <stdio.h>
#include <float.h>
#include <limits.h>


int main(){

    int i = INT_MAX;
    float f = FLT_MAX;
    double d = DBL_MAX;
    long long ll = LONG_MAX;
    printf("%s%d%s%d", "INT_MAX: ", i, ", size of int: ", sizeof(int));
    printf("%s%f%s%d", "\nFLT_MAX: ", f, ", size of float: ", sizeof(float));
    printf("%s%lf%s%d", "\nDBL_MAX: ", d, ", size of double: ", sizeof(double));
}