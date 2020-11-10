#include <stdio.h>

int main()
{
    int a[] = {1, 2};
    char *ptr = (char *)a;
    for (int i = 0; i < 8; i++)
    {
        printf("%d \n", ptr[i]);
    }
}
