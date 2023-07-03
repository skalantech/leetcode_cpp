#include <iostream>
#include <vector>

class sorting
{
    public:
        void bubbleSort(int a[], int size);
        void selectionSort(int a[], int size);
        void insertionSort(int a[], int size);
        void merge(int a[], int indexCero , int indexMidle, int size);
        void mergeSort(int a[], int indexCero , int size);
        friend void printArray(int a[], int size);
};

void swap(int* a, int* b)
    {
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }

void sorting::bubbleSort(int a[], int size)
{
    for(int i=0; i<size; ++i)
        for(int j=0; j<size-i;++j)
        {
            if(a[j]>a[j+1])
                swap(&a[j], &a[j+1]);
        }
}

void sorting::selectionSort(int a[], int size)
{
    for(int i=0; i<size-1; i++)
    {    
        int minIndex=i;
        for(int j=i+1; j<size; j++)
        {
            if(a[j]<a[minIndex])
                minIndex=j;
        }
        swap(&a[minIndex], &a[i]);
    }
}

void sorting::insertionSort(int a[], int size)
{
    for(int i=1; i<size; i++) {
        int key=a[i];
        int j=i-1;
        while(key<a[j] && j>=0) {
            a[j+1]=a[j];
            --j;
        }
        a[j+1]=key;
    }
}

void sorting::merge(int a[], int indexCero , int indexMidle, int size)
{
    int p=indexCero;
    int q=indexMidle;
    int r=size;

    int n1=q-p+1;
    int n2=r-q;

    std::vector<int> L, M;

    for(int i=0; i<n1; i++)
        L.push_back(a[p+i]);
    for(int j=0; j<n2; j++)
        M.push_back(a[q+1+j]);

    int i,j,k;
    i=0;
    j=0;
    k=p;

    while(i<n1 && j<n2)
    {
        if(L[i]<=M[j])
        {
            a[k]=L[i];
            i++;
        }
        else
        {
            a[k]=M[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }

    while(j<n2)
    {
        a[k]=M[j];
        j++;
        k++;
    }
}

void sorting::mergeSort(int a[], int indexCero , int size)
{
    int l=indexCero;
    int r=size;
    if(l<r)
    {
        int m=l+(r-l)/2;

        mergeSort(a, l , m);
        mergeSort(a, m+1 , r);

        merge(a, l, m, r);
    }
}

void printArray(int a[], int size)
{
    for(int i=0; i<size; i++)
        std::cout<<a[i]<< ", ";
    std::cout<<std::endl;
}

int main()
{
    int data[] {9,8,7,6,5,4,3,2,1,0};
    int size = sizeof(data)/sizeof(int);
    std::cout<<size<<'\n';
    
    sorting s;
    s.mergeSort(data, 0, size-1);
    printArray(data, size);
    
    return 0;
}