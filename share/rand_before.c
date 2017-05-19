#define BASE {3,3,0,0,3,3,3,3,3,3,0,0,3,3}		// result of rate
//#define SORT {0,1,1,2,2,2,3,3,3,4,5,5,6,6}
#define SORT {0,1,1,1,1,1,2,2,3,3,3,4,4,4}		//
#define RATE {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1} // rate

#define ADJUST 0
#define SELECT_NUM 10			// number of rand
#define NEED_PRINT_NUMBER 0

#include "stdio.h"
#include "stdlib.h"
#include <string.h>

#define ONE_MAX 14
#define NUM_MAX 4782969
#define SEL_MAX 10

typedef struct _ONE{
    unsigned char n[ONE_MAX];
}ONE;

//int comp[14];
//int comp1[14];

void generateData(ONE * data)
{
    int n[ONE_MAX];
    int i = 0;
    int j = 0;
    for(n[0] = 0; n[0] < 3; n[0]++)
    for(n[1] = 0; n[1] < 3; n[1]++)
    for(n[2] = 0; n[2] < 3; n[2]++)
    for(n[3] = 0; n[3] < 3; n[3]++)
    for(n[4] = 0; n[4] < 3; n[4]++)
    for(n[5] = 0; n[5] < 3; n[5]++)
    for(n[6] = 0; n[6] < 3; n[6]++)
    for(n[7] = 0; n[7] < 3; n[7]++)
    for(n[8] = 0; n[8] < 3; n[8]++)
    for(n[9] = 0; n[9] < 3; n[9]++)
    for(n[10] = 0; n[10] < 3; n[10]++)
    for(n[11] = 0; n[11] < 3; n[11]++)
    for(n[12] = 0; n[12] < 3; n[12]++)
    for(n[13] = 0; n[13] < 3; n[13]++)
    {
        for(j = 0; j < ONE_MAX; j++)
	{
            data[i].n[j] = n[j];
	    if(data[i].n[j] == 2)
                data[i].n[j] = 3;
	}
	i++;
    }
}

int compare(int *co, int *co1, ONE *data)
{
    int i = 0;
    int j = 0;
    for(i = 0; i < NUM_MAX; i++)
    {
	int result = 0;
	for(j = 0; j < ONE_MAX; j++)
	{
	    if(data[i].n[j] != co[j])
	    {
		result++;
	    }
	    if(result > (co1[j] + ADJUST))
	    {
		data[i].n[0] = 2;
		break;
	    }
	}
    }
}

int select_num(ONE* data)
{
    srand48((int)time(0));
    srand48(lrand48());

    int sel = SELECT_NUM;
    int j = 0;
    int print = 1;

    printf("begin to select >>>>>>>>>>\n");
    while(sel > 0)
    {
        long lIndex = lrand48() % NUM_MAX;
	if(lIndex < 0 || lIndex >= NUM_MAX)
	{
	    printf("error index: %ld\r\n", lIndex);
	    continue;
	}
	if(data[lIndex].n[0] != 2)
	{
	    for(j = 0; j < ONE_MAX; j++)
	    {
		printf("%d\r\n", data[lIndex].n[j]);
	    }
	    
		printf("\r\n-----------\r\n");
	    if(NEED_PRINT_NUMBER == 1)
	        printf("\t-%ld\t-%d-\r\n", lIndex + 1, print++);
            else
	        printf("\r\n");
	    data[lIndex].n[0] = 2;
	    sel--;
	}
    }
}

int print_all(ONE* data)
{
    int print = 1;
    int i = 0;
    int j = 0;

    for(i = 0; i < NUM_MAX; i++)
    {
	if(data[i].n[0] != 2)
	{
	    for(j = 0; j < ONE_MAX; j++)
	    {
		printf("%d", data[i].n[j]);
	    }
	    if(NEED_PRINT_NUMBER == 1)
	        printf("\t-%d\t-%d-\r\n", i + 1, print++);
            else
	        printf("\r\n");
	}
    }
}

int main()
{
    int comp[14] = BASE;
    int comp1[14] = SORT;
   
    int i = 0;
    int j = 0;
    ONE *alldata = NULL;
    
    alldata = (ONE *) malloc (sizeof(ONE) * NUM_MAX);
    
    generateData(alldata);
    compare(comp, comp1, alldata);
    print_all(alldata);
    select_num(alldata);

    free(alldata);
}



