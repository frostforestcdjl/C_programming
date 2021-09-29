#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#define MAXSIZE 100
#define KDRK "\x1B[0;37m"
#define KRED "\x1B[0;31m"
#define KGRN "\x1B[0;32m"
#define KYEL "\x1B[0;33m"
#define KBLU "\x1B[0;34m"
#define KCYN "\x1B[0;36m"
main()
{
    int run = 1;
    while (run == 1) {
        printf(KYEL"Hello world!\n");
        int n, k;
        printf(KYEL"What size of the campfire you want? (n = int)\n");
        scanf("%d", &n);
        printf(KBLU"How long of the %dx%d campfire you want to see? (k = int)\n", n, n);
        scanf("%d", &k);
        assert(n >= 1 && n <= 100 && k > 0);

        printf(KGRN"Set your initial campfire:\n");
        int from = 0, to = 1;
        bool life[2][MAXSIZE][MAXSIZE];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int temp;
                scanf("%d", &temp);
                life[from][i][j] = (temp == 1);
            }

        for (int iter = 0; iter < k; iter++) {
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    int neighbor = 0;
                    for (int dx = -1; dx <= 1; dx++)
                        for (int dy = -1; dy <= 1; dy++)
                            if (!(dx == 0 && dy == 0)) {
                                int x = i + dx;
                                int y = j + dy;
                                if (x >= 0 && x < n && y >= 0 && y < n && life[from][x][y])
                                    neighbor++;
                            }
                            if (life[from][i][j])
                                life[to][i][j] = (neighbor == 2 || neighbor == 3);
                            else
                                life[to][i][j] = (neighbor == 3);
                }
            from = (from == 1)? 0:1;
            to = (to == 1)? 0:1;
            
            printf(KCYN"--- time %d---\n", iter+1);
            for (int i = 0; i< n; i++)
                for (int j = 0; j < n; j++) {
                    if (j == n - 1) {
                        if (life[from][i][j] == 1)
                            printf(KRED"火\n");
                        else
                            printf(KDRK"碳\n");
                    }
                    else {
                        if (life[from][i][j] == 1)
                            printf(KRED"火 ");
                        else
                            printf(KDRK"碳 ");
                    }
                }
        }

        
        printf("Do you want to continue? (y:1/n:0)");
        scanf("%d", &run);
        assert(run == 1 || run == 0);
    }
}
