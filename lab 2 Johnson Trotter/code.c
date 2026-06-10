#include<stdio.h>

int findlargestmobile(int val[],int dir[],int n){
    int max_mobile=-1;
    int max_mob_index=-1;
    for(int i =0;i<n;i++){
        if(dir[i]==-1 && i>0){
            if(val[i]>val[i-1]&&val[i]>max_mobile){
                max_mob_index=i;
                max_mobile=val[max_mob_index];
                
            }
        }
        if(dir[i]==1 && i<n-1){
            if(val[i]>val[i+1] && val[i]>max_mobile){
                max_mob_index=i;
                max_mobile=val[max_mob_index];
            }
        }
    }
    return max_mob_index;
}
void swap(int *a , int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void main(){
    int n,target_index;
    printf("enter the number of elements : ");
    scanf("%d",&n);
    int val[n],dir[n];
    for(int i=0;i<n;i++){
        val[i]=i+1;
        dir[i]=-1;
    }
    while(1){
        //printf permutaion
        for(int i=0;i<n;i++)
            printf("%d ",val[i]);
        printf("\n");
    int max_mob_index= findlargestmobile(val,dir,n);
    if(max_mob_index==-1)
        break;
    target_index=max_mob_index+dir[max_mob_index];
    int max_val=val[max_mob_index];
    
    swap(&val[max_mob_index],&val[target_index]);
    swap(&dir[max_mob_index],&dir[target_index]);

    //if larger change dir
    
    for(int i=0;i<n;i++){
        if(val[i]>max_val)
            dir[i]=-1*dir[i];
    }
}
}