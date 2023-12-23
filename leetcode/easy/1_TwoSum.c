#include <stdio.h>
#include <stdlib.h>


//Classic O(n^2)
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int i, j ;
    *returnSize = 2;
    int *result= (int*)malloc(*returnSize * sizeof(int));

    for(i=0; i<numsSize; i++) 
    {
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[i]+nums[j]==target)
            {
                result[0] = i ;
                result[1] = j ; 
                return result ; 
            }
        }
    }
    *returnSize = 0;
    free(result);
    return NULL;
}

//Advenced 0(n^2), (optimisé pour compilateur ?)
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize -1; i++) {
        int num1 = nums[i];
        for (int j = i +1 ; j < numsSize; j++) {
            int num2 = nums[j];
            if ((num1+num2) == target) {
                result[0] = i;
                result[1] = j;

                *returnSize = 2;
                return result;
            }
        }
    }
    return 0;
}

//Quicksort


//Two Sum Table de hachage (HashTable)

#define HASH_MOD (10000)
#define HASH_TABLE_SIZE (HASH_MOD*2)
#define END_IDX (-1)
typedef struct {
  int val;
  short idx;
  short next_idx;
} ht_t;

#define HASH(val) (abs(val) % HASH_MOD)

int* twoSum(int* nums, const int n, const int target, int* ans_len) {
    ht_t ht[HASH_TABLE_SIZE];
    memset(ht, 0, sizeof(ht));
    int* ans = malloc(2 * sizeof(int));
    *ans_len = 2;
    int collisions_num = 0;
    int idx;
    for (int i = 0; i < n; ++i) {
        ans[0] = i;
        const int num = nums[i];
        const int rest = target - num;
        const int rest_hash_idx = HASH(rest);
        if (ht[rest_hash_idx].next_idx) {
            /* potentially found... let's check */
            idx = rest_hash_idx;
            do {
                if (ht[idx].val == rest) {
                ans[1] = ht[idx].idx;
                return ans;
                }
                idx = ht[idx].next_idx;
            } while (idx != END_IDX); /* loop over collisions */
        }
        /* add num to hash table */
        const int num_hash_idx = HASH(num);
        if (ht[num_hash_idx].next_idx) {
            /* collision */
            idx = HASH_MOD + collisions_num++;
            ht[idx].next_idx = ht[num_hash_idx].next_idx;
            ht[num_hash_idx].next_idx = idx;
        } else {
            /* add a new element */
            idx = num_hash_idx;
            ht[num_hash_idx].next_idx = END_IDX;
        }
        ht[idx].val = num;
        ht[idx].idx = i;
  }  /* loop over nums[] */

  // for (ans[0] = 1; ans[0] < n; ++ans[0]) {
  //   const int remainder = target - nums[ans[0]];
  //   for (ans[1] = 0; ans[1] < ans[0]; ++ans[1]) {
  //     if (remainder == nums[ans[1]]) return ans;
  //   }  // j-loop
  // }  // i-loop
  return ans;
}