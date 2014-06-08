//hunkarpurtul
//04.12.2014

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void setZero(int**, int*);
void putMine(int**, int*, int*);
void showField(int**, int*);

int main()
{
    int size, mineSize, count;
    int **mineField;

    printf("Please enter mineField size: ");
    scanf("%d", &size);
    printf("How many mines?: ");
    scanf("%d", & mineSize);

    if(mineSize >= size*size)
     {
                printf("Too much mine !!!");
                system("pause");
                return 0;       
     }

    mineField = (int**) malloc(sizeof(int*) * size);
     if(mineField == 0)
     {
         printf("Unexpected problem !!!");
         system("pause");
         return 0;         
     }
 
     for(count = 0; count < size; count++)
     {
       mineField[count] = (int*) malloc(sizeof(int) * size);    
     }
 
     setZero(mineField, &size);
     putMine(mineField, &mineSize, & size);
     showField(mineField, & size);

    system("pause");
    free(mineField);
    return 0;
}



void setZero(int** field, int* size)
{
     int count, count2;
     for(count = 0; count < *size; count++)
      for(count2 = 0; count2 < *size; count2++)
              field[count][count2] = 0;    
}

void putMine(int** field, int* mineSize, int* fieldSize)
{
     int x, y, count;
     srand(time(NULL));
     for(count = 0; count < *mineSize; count++)
        {
              x = rand() % *fieldSize;
              y = rand() % *fieldSize;
              if(field[x][y] >= 100)
                {
                      count--;
                      continue;         
                }
          
              field[x][y] = 100;
               if(x > 0)
                   field[x-1][y]++;  
               if(x < *fieldSize-1)
                   field[x+1][y]++;
               if(y > 0)
                   field[x][y-1]++;
               if(y < *fieldSize-1)
                   field[x][y+1]++;
        }
 
}

void showField(int** field, int* size)
{
     int count, count2;
     for(count = 0; count < *size; count++)
     {
          for(count2 = 0; count2 < *size; count2++)
            {
                  if(field[count][count2] < 100)
                     printf("%3d", field[count][count2]);
                  else   printf("%3c", 'M');
            }
          printf("\n");
     } 
}
