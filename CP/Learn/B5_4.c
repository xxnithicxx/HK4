#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
static int sum, prime[10], count = 0;

struct Arr
{
    int size;
    int a[18];
};

struct file
{
    struct Arr ar;
    char *filename;
};

void swap(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int checkPrime(int n)
{
    if (n == 2)
        return 1;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

void *thr1(void *ar)
{
    FILE *f = fopen("Input.txt", "r");
    if (f == NULL)
    {
        printf("Error opening file");
        return NULL;
    }

    struct Arr *a = (struct Arr *)ar;
    fscanf(f, "%d", &a->size);
    for (int i = 0; i < a->size; i++)
    {
        fscanf(f, "%d", &a->a[i]);
    }
    fclose(f);

    return NULL;
}

// tinh tong cac so nguyen to trong mang
void *thr2(void *ar)
{
    struct Arr *ap = (struct Arr *)ar;
    int s = 0;
    for (int i = 0; i < ap->size; i++)
    {
        if (checkPrime(ap->a[i]))
            s += ap->a[i];
    }
    sum = s;

    return NULL;
}

// Sap xep mang nguyen to tang dan
void *thr3(void *ar)
{
    struct Arr *ap = (struct Arr *)ar;
    // dua cac so nguyen to vao mang moi
    for (int i = 0; i < ap->size; i++)
    {
        if (checkPrime(ap->a[i]))
        {
            prime[count] = ap->a[i];
            count++;
        }
    }
    for (int i = 0; i < ap->size - 1; i++)
    {
        for (int j = count - 1; j > i; --j)
        {
            if (prime[j] < prime[j - 1])
                swap(&prime[j], &prime[j - 1]);
        }
    }

    return NULL;
}

// ghi file result
void *thr4(void *arf)
{
    FILE *fp;
    struct file *fi = (struct file *)arf;
    int i = 0;
    fp = fopen(fi->filename, "wb");
    // Ghi so phan tu cua mang
    fprintf(fp, "So phan tu mang: %d\n", fi->ar.size);
    for (int i = 0; i < fi->ar.size; i++)
    {
        fprintf(fp, "%d ", fi->ar.a[i]);
    }
    fprintf(fp, "\n");
    // Ghi ra file cac so nguyen to
    fprintf(fp, "Mang cac so nguyen to: \n");
    for (i = 0; i < fi->ar.size; i++)
    {
        if (checkPrime(fi->ar.a[i]))
            fprintf(fp, "%d ", fi->ar.a[i]);
    }
    fprintf(fp, "\n");
    // Tong cac so nguyen to
    fprintf(fp, "Tong cac so nguyen to: %d\n", sum);
    // Mang sap xep cac so nguyen to tang dan
    fprintf(fp, "Mang cac so nguyen to sap xep tang dan:\n");
    for (i = 0; i < count; i++)
    {
        fprintf(fp, "%d ", prime[i]);
    }
    fclose(fp);

    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t tid[4];
    int status, *pstatus = &status;
    struct Arr ar;

    pthread_create(&tid[0], NULL, thr1, (void *)&ar);
    if (pthread_join(tid[0], (void **)pstatus) == 0)
    {
        pthread_create(&tid[1], NULL, thr2, (void *)&ar);
        if (pthread_join(tid[1], (void **)pstatus) == 0)
        {
            pthread_create(&tid[2], NULL, thr3, (void *)&ar);
            if (pthread_join(tid[2], (void **)pstatus) == 0)
            {
                struct file fi;
                fi.ar = ar;
                fi.filename = argv[1];
                pthread_create(&tid[3], NULL, thr4, (void *)&fi);
                pthread_join(tid[3], (void **)pstatus);
            }
        }
    }
}