#include <stdio.h>

int binary_search (int* num, int target, int left, int right){
    if(left == right){
        return -1;
    }
    if(target == num[(right+left)/2]){
        return 0;
    }
    else if(target < num[(right+left)/2]){
        binary_search(num, target, left, (right+left)/2);
    }
    else if(target > num[(right+left)/2]){
        binary_search(num, target, (right+left)/2 + 1, right);
    }
}

int main()
{
    int num[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    printf("input your target:");
    int target;
    scanf("%d", &target);
    int ret = binary_search(num, target, 0, sizeof(num)/sizeof(int)-1);
    if(ret == 0){
        printf("target found\n");
    }
    else{
        printf("target not found\n");
    }
    return 0;
}

