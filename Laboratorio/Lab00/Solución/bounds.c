#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) 
{
    struct bound_data res;
    res.is_upperbound = true, res.is_lowerbound = true, res.exists = false;

    for (size_t i = 0; i < length; i++)
    {
        if (value < arr[i]) 
        {
            res.is_upperbound = false;
        } 
        else if (value > arr[i]) 
        {
            res.is_lowerbound = false;
        }
        else if (value == arr[i]) 
        {
            res.exists = true;
            res.where = i;      // In this case, it takes the last occurrence.
        }
    }
    return res;
}

int main(void)
{
    int a[ARRAY_SIZE];
    for (size_t i = 0; i < ARRAY_SIZE; i++) 
    {
        printf("Ingrese el valor de la posicion %ld:\n", i);
        scanf("%d", &a[i]);
    }

    int value;
    printf("Ingrese el valor a comparar:\n");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    if (result.is_upperbound && result.exists) 
    {
        printf("El valor es un máximo y esta en la posicion %d\n", result.where);
    } 
    else if (result.is_upperbound)
    {
        printf("El valor es cota superior\n");

    }

    if (result.is_lowerbound && result.exists) 
    {
        printf("El valor es un mínimo y esta en la posicion %d\n", result.where);
    } 
    else if (result.is_lowerbound)
    {
        printf("El valor es cota inferior\n");

    }
    return EXIT_SUCCESS;
}