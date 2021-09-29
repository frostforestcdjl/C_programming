#include <stdio.h>
#include <assert.h>
main()
{
    int run = 1;
    while (run == 1) {
        double x;
        printf("Input the power of x:");
        scanf("%lf", &x);

        double e = 1.0;

        int n;
        printf("Input the last tern:");
        scanf("%d", &n);
        
        double term = 1.0;

        for (int i = 1; i <= n; i++) {
            term *= (x/i);
            e += term;
        }

        printf("%.20f\n", e);

        printf("Do you want to input another x? (1:yes, 0:no)");
        scanf("%d", &run);
        assert(run == 1 || run == 0);
    }
}
