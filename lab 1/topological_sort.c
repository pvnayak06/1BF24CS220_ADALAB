#include<stdio.h>


int main()
{
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int v[n][n],indeg[n],tp[n],check[n],k=0;
    printf("Enter the adjacency matrix:\n");
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&v[i][j]);

        }
        check[i]=0;
    }
    //count the 1s in each column and store in indeg
    for(int i = 0;i<n;i++){
        indeg[i]=0;
        for(int j=0;j<n;j++){
            indeg[i]+=v[j][i];
        }
    }
    while (k < n) {
        int found = 0;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0 && check[i] == 0) {
                check[i] = 1;
                tp[k++] = i + 1;
                for (int j = 0; j < n; j++) {
                    indeg[j] -= v[i][j];
                }
                found = 1;
            }
        }
        if (!found) break; /* cycle detected */
    }

    if (k < n) {
        printf("Graph has a cycle; topological ordering not possible\n");
    } else {
        printf("Topological order: ");
        for (int i = 0; i < n; i++) printf("%d ", tp[i]);
        printf("\n");
    }
    return 0;
    

}