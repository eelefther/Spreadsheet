#include <stdio.h>
#include <windows.h>
#include <conio.h>

int i,j;   /* i and j will be used as the dimensions of the spreadsheet */

int row_sum (int t,int a[i][j+1]);
int column_sum (int t,int a[i][j+1]);

int row_product (int t,int a[i][j+1]);
int column_product (int t,int a[i][j+1]);

void row_average (int t,int a[i][j+1]);
void column_average (int t,int a[i][j+1]);

void row_median (int t,int a[i][j+1]);
void column_median (int t,int a[i][j+1]);

int row_minimum (int t, int a[i][j+1]);
int column_minimum (int t, int a[i][j+1]);

int row_maximum (int t, int a[i][j+1]);
int column_maximum (int t, int a[i][j+1]);


int main (void)
{
printf("Enter the 2 dimensions of the spreadsheet {rows columns}: ");
scanf("%d %d",&i,&j);

int a[i][j+1];                 /* add an extra column to the table */
printf("          ");

char b='A';                  /* print capital letters which define the columns of the spreadsheet */
for (int x=1;x<j+1;x++)
{
    printf("   %c   ",b);      /* give to the first column's elements the values 1 to j */
b++;}                          /* the values 1 to j define the lines of the spreadsheet */
puts("");
b='A';
for (int x=0;x<i;x++) a[x][0]=x+1;

 /* give to every element of the spreadsheet the value 0: */

int x=0,y=0;
for (x=0;x<i;x++)
   for (y=1;y<j+1;y++)
    a[x][y]=0;

/* print the table: */

for (x=0;x<i;x++)
   {for (y=0;y<j+1;y++)
printf("%7d",a[x][y]);
printf("\n");
}


int row,col,n=0;
char c,ins;

/* ask the user if he wants to add numbers on the spreadsheet: */
printf("\nDo you want to insert a number? If no press 'N', if yes press any other character: ");
ins=getch();

/* the user inserts a number and a cell's coordinates to put the number into */

while (ins!='N'){
printf("\n\nEnter the number you want to insert and the cell where you want it to be inserted {number rowcolumn}: ");
scanf("%d %d%c",&n,&row,&c);


/*  if there is no such cell ask the user to choose again numbers
           and coordinates until a correct choice is made   */
while ((row<1 || row>i || c<'A' || c>j+64))
{
    printf("\nWrong choice. Make sure you choose an existing row(1 to %d) and an existing column(A to %c): ",i,'A'+j-1);
    scanf("%d %d%c",&n,&row,&c);
}


  /*  covert the column's letter into an integer which
   corresponds to the column where the number will be inserted  */
col=c-63;


a[row-1][col-1]=n;   /* insert the number in the chosen cell */
system ("cls");    /* clear the screen */

/* print the table with the new element and the columns' letters*/

printf("          ");
for (int x=1;x<j+1;x++)
{
    printf("   %c   ",b);
b++;}
puts("");
b='A';

for (x=0;x<i;x++)
   {for (y=0;y<j+1;y++)
printf("%7d",a[x][y]);
printf("\n");}

/* ask the user if he wants to insert another number on the table */

printf("\nDo you want to insert another number? If no press 'N', if yes press any other character: ");
ins=getch();
}

/* when all the numbers have been inserted, give to the user the choice to continue or stop */

char con;

printf("\nDo you want to continue? If no press <ESC>, if yes press any other character: ");
con=getch();

if (con==27) return 0; /* end the program and return 0, if <ESC> is pressed */


else while (con!=27)
{

int choice=0, num1=0,num2=0,out=0;
unsigned char rc='\0',letter='\0',num='\0';

/* print the menu */
printf("\n\n1.Sum\n2.Product\n3.Average\n4.Median\n5.Minimum\n6.Maximum\n\n");


printf("Choose one the functions 1 to 6: "); /* the user chooses a function */
scanf("%d",&choice);

/*  if the number chosen does not represent a function, ask the user
      to choose again until a correct choice is made  */

while (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5 && choice!=6)
{printf("This choice is not correct.Please choose between 1,2,3,4,5 or 6: ");
scanf("%d",&choice);}

/* the user chooses to apply the function to a row or a column */

printf("\nPlease choose if you want the function %d to be applied to a row or a column. Write {r or c}: ",choice);
rc=getch();


/* if the choice is wrong, ask the user to choose again */

if (rc!='r' && rc!='c')
{
while (rc!='r' && rc!='c')

{
    printf("\nThis choice is not correct. Choose between 'r'(row) or 'c'(column): ");
    rc=getch();
}
}

 /*  if the choice is 'r', ask the user to select a row
   until the number of an existing row is inserted  */

if (rc=='r')
{
    printf("\n\nWrite the number of the row to which you want the function to be applied: ");
    num=getch();
    num1=num-49;

    while (num1<0 || num1>=i)
    {
        printf("\nThis choice is not correct. Please write the number of an existing row(1 to %d): ",i);
        num=getch();
        num1=num-49;
    }
}

 /*  if the choice is 'c', the ask the user to select a column
   until the letter of an existing column is inserted  */

if (rc=='c')
{
    printf("\n\nWrite the letter of the column to which you want the function to be applied: ");
    letter=getch();

    while (letter<'A' || letter>j+65)
    {
        printf("\nThis choice is not correct. Please write the letter of an existing column(A to %c): ",'A'+j);
        letter=getch();
    }
}

 /*  convert the inserted letter into an integer
   which corresponds to the chosen column */

num2=letter-64;


system("cls");   /* clear the screen */


/* print the table again */

printf("          ");

for (int x=1;x<j+1;x++)
{
    printf("   %c   ",b);
b++;}
puts("");
b='A';

for (x=0;x<i;x++)
   {for (y=0;y<j+1;y++)
printf("%7d",a[x][y]);
printf("\n");}


int e=7*(j+1);  /* the length of each table's row */

CONSOLE_SCREEN_BUFFER_INFO coninfo;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
GetConsoleScreenBufferInfo(hConsole, &coninfo);
coninfo.dwCursorPosition.Y -= 1;    /* move the cursor up one line */
coninfo.dwCursorPosition.X += e+5; /* move the cursor to the right the length of the row and leave 5 spaces */
SetConsoleCursorPosition(hConsole, coninfo.dwCursorPosition);



/* apply the chosen function to the chosen row or column */


if (choice==1 && rc=='r')
{
    out = row_sum(num1,a);
    printf("%d",out);
}


if (choice==1 && rc=='c')
{
    out=column_sum(num2,a);
    printf("%d",out);
}


if (choice==2 && rc=='r')
{
    out = row_product(num1,a);
    printf("%d",out);
}


if (choice==2 && rc=='c')
{
    out = column_product(num2,a);
    printf("%d",out);
}


if (choice==3 && rc=='r')
{
    row_average(num1,a);
}


if (choice==3 && rc=='c')
{
    column_average(num2,a);
}


if (choice==4 && rc=='r')
{
    row_median(num1,a);
}


if (choice==4 && rc=='c')
{
    column_median(num2,a);
}


if (choice==5 && rc=='r')
{
    out = row_minimum(num1,a);
    printf("%d",out);
}


if (choice==5 && rc=='c')
{
    out = column_minimum(num2,a);
    printf("%d",out);
}


if (choice==6 && rc=='r')
{
    out = row_maximum(num1,a);
    printf("%d",out);
}


if (choice==6 && rc=='c')
{
    out = column_maximum(num2,a);
    printf("%d",out);
}

printf("\n\nDo you want to continue? If no press <ESC>, if yes press any other character: ");
con=getch(); /* end the program and return 0, if <ESC> is pressed */

}

return 0;
}



int row_sum (int t,int a[i][j+1])   /* calculate the sum of one row's elements */
{
   int s=0;
   for (int x=1;x<j+1;x++)
        s+=a[t][x];    /* add to s all of the row's numbers */

   return s;   /* return the integer s */
}


int column_sum (int t,int a[i][j+1])   /* calculate the sum of one column's elements */
{
    int s=0;
    for (int x=0;x<i;x++)
        s+=a[x][t];     /* add to s all of the column's numbers */

    return s;   /* return the integer s */
}


int row_product (int t,int a[i][j+1])    /* calculate the product of one row's elements */
{
   int p=a[t][1];     /* give p the value of the first element */
   for (int x=2;x<j+1;x++)
        p=p*a[t][x];   /* multiply p with all the other row's numbers */

   return p;   /* return the integer p */
}


int column_product (int t,int a[i][j+1])    /* calculate the product of one column's elements */
{
   int p=a[0][t];      /* give p the value of the first element */
   for (int x=1;x<i;x++)
        p=p*a[x][t];   /* multiply p with all the other column's numbers */

   return p;   /* return the integer p */
}


void row_average (int t,int a[i][j+1])    /* calculate the average of one row's elements */
{
    double avg=0,h=0;

    /* h is a decimal number */

    h=row_sum(t,a)/1.0;   /* h is equal to the sum of the row's elements */

/* the average is the sum divided by the number of the row's elements */
    avg=h/j;

printf("%.3lf",avg);

/*  this function prints the result
  it does not return a value  */

}


void column_average (int t,int a[i][j+1])    /* calculate the average of one column's elements */
{
    double avg=0,h=0;

    /* h is a decimal number */

    h=column_sum(t,a)/1.0; /* h is equal to the sum of the column's elements */

/* the average is the sum divided by the number of the column's elements*/
    avg=h/i;

printf("%.3lf",avg);

/*  this function prints the result
  it does not return a value  */

}


void row_median (int t,int a[i][j+1])     /* calculate the median of one row's elements */
{
int m[j];
int f,b,c;
double med=0;

/* give to the table m the elements of the row t */

for (int x=1;x<j+1;x++)
m[x-1]=a[t][x];


/* classify the numbers of the table m in increasing order */

for (f=0;f<j;f++)
{
    for(b=0;b<j-1;b++)
    {
        if(m[b]>m[b+1])
        {
            c=m[b+1];
            m[b+1]=m[b];
            m[b]=c;
        }
    }
}


/* if the elements' number is odd, the median is the middle number */

if (j%2!=0)
    med=m[(j+1)/2-1];


/* if the elements' number is even, the median is the half of the
       sum of the 2 numbers that are in the middle*/

else
    med=(m[j/2]+m[j/2-1])/2.0;

printf("%.3lf",med);

/*  this function prints the result
  it does not return a value  */

}


void column_median (int t,int a[i][j+1])    /* calculate the median of one column's elements*/
{
int m[i];
int f,b,c;
double med=0;

/* give to the table m the numbers of the column t */

for (int x=0;x<i;x++)
m[x]=a[x][t];


/* classify the numbers of the table m in increasing order */

for (f=0;f<i;f++)
{
    for(b=0;b<i-1;b++)
    {
        if(m[b]>m[b+1])
        {
            c=m[b+1];
            m[b+1]=m[b];
            m[b]=c;
        }
    }
}

/* if the elements' number is odd the median is the middle number */

if (i%2!=0)
    med=m[(i-1)/2];


/* if the elements' number is even the median is the half of the
       sum of the 2 numbers that are in the middle*/

else
    med=(m[i/2]+m[i/2-1])/2.0;

printf("%.3lf",med);

/*  this function prints the result
  it does not return a value  */

}


int row_minimum (int t, int a[i][j+1])   /* Find the minimum of one row's elements */
{
int x=1,min=0,h;

h=a[t][1]; /* give to h the value of the first element of the row */

while (x<j+1)

/* when a smaller number than h is found in the row,
give to h this value and to min the value of h  */

{if (a[t][x]<h) {h=a[t][x]; min=h;}
else x++;}

/* if min is still 0, the minimum is the first element of the row */
if(min==0) min=a[t][1];


/* return the integer min */

return min;
}


int column_minimum (int t, int a[i][j+1])   /* Find the minimum of one column's elements */
{
int x=0,min=0,h;

h=a[0][t];  /* give to h the value of the first element of the column */

while (x<i)

/* when a smaller number than h is found in the column,
give to h this value and to min the value of h  */

{if (a[x][t]<h) {h=a[x][t]; min=h;}
else x++;}

/* if min is still 0, the minimum is the first element of the column */
if(min==0) min=a[0][t];


/* return the integer min */

return min;
}


int row_maximum (int t, int a[i][j+1])    /* Find the maximum of one row's elements */
{
int x=1,max=0,h;

h=a[t][1];   /* give to h the value of the first element of the row */

while (x<j+1)

/* when a bigger number than h is found in the row,
give to h this value and to max the value of h  */

{if (a[t][x]>h) {h=a[t][x]; max=h;}
else x++;}

/* if max is still 0, the maximum is the first element of the row */
if(max==0) max=a[t][1];


/* return the integer max */

return max;
}


int column_maximum (int t, int a[i][j+1])    /* Find the maximum of one column's elements */
{
int x=0,max=0,h;

h=a[0][t];   /* give to h the value of the first element of the column */

while (x<i)

/* when a bigger number than h is found in the column,
give to h this value and to max the value of h  */

{if (a[x][t]>h) {h=a[x][t]; max=h;}
else x++;}

/* if max is still 0, the maximum is the first element of the column */
if(max==0) max=a[0][t];


/* return the integer max */

return max;
}





