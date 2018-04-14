#include<conio.h>
#include<stdio.h>

int s[9][9];

void solves(int,int);

int checkrow(int row,int num)
{
  int column;

    for(column=0;column<9;column++)
    {
        if(s[row][column]==num)
        return 0 ;
    }
    return 1;

}

int checkcolumn(int column,int num)
{
  int row;

   for(row=0;row<9;row++)
   {
        if(s[row][column]==num)
        return 0;
   }
   return 1;

}

int checkgrid(int row,int column,int num)
{
  row=(row/3)*3 ;
  column=(column/3)*3;
  int r,c;
  for(r=0;r<3;r++)
  {
    for(c=0;c<3;c++)
    {
         if(s[row+r][column+c]==num)
            return 0;
    }
  }
  return 1;

}
void fill(int row,int column,int num)
{
   if(num!=0)
    s[row][column]=num;

    return ;
}

void display()
 {
   int row,column;
    printf("SLOVED s :\n");
    printf("-----------------\n");
    for(row=0;row<9;row++)
     {
       for(column=0;column<9;column++)
       {
          printf("%d ",s[row][column]);
       }
       printf("\n");
     }
    printf("-----------------\n");

  getch();
 }
void solves(int row,int column)
{
    int a,b,c;

    if(row>8)
      display();

    if(s[row][column]!=0)

    {
        if(column<8)
          solves(row,column+1);
        else
          solves(row+1,0);
    }

    else
    {
        int ctr;

         for(ctr=1;ctr<=9;ctr++)
          {
              a=checkrow(row,ctr);
              b=checkcolumn(column,ctr);
              c=checkgrid(row,column,ctr);

            if(a==1&& b==1 && c==1)
             {

              s[row][column]=ctr;
              if(column<8)
                 solves(row,column+1);
              else
                 solves(row+1,0);
             }
          }
         s[row][column]=0;
    }

}
int main()
{
  int row,column,num;

  for (row=0;row<9;row++)
    {
        for(column=0;column<9;column++)
          {
            s[row][column]=0;
          }
    }

   do
   {
     printf("Enter position :\n");
     scanf("%d%d",&row,&column);
     printf("Enter value : \n");
     scanf("%d",&num);
     fill(row-1,column-1,num);

   }while(row!=11 && column!=11);

         solves(0,0);
}
