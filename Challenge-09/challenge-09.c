
#include <stdio.h>
#define ROWS 5
#define COLS 8
void initializeSeats(int s[ROWS][COLS]);
void displaySeats(int s[ROWS][COLS]);
int bookSeat(int s[ROWS][COLS],int r,int c);
int cancelSeat(int s[ROWS][COLS],int r,int c);
int reserveGroup(int s[ROWS][COLS],int n);
void displayReport(int s[ROWS][COLS]);
int main()
{
int s[ROWS][COLS],ch,r,c,n;
initializeSeats(s);
do
{
printf("\n1.Display\n2.Book\n3.Cancel\n4.Group\n5.Report\n6.Exit\n");
printf("Choice: ");
scanf("%d",&ch);
switch(ch)
{
case 1: displaySeats(s); break;
case 2:
printf("Row and seat: ");
scanf("%d%d",&r,&c);
printf(bookSeat(s,r,c)?"Booked!\n":"Failed!\n");
break;
case 3:
printf("Row and seat: ");
scanf("%d%d",&r,&c);
printf(cancelSeat(s,r,c)?"Cancelled!\n":"Failed!\n");
break;
case 4:
printf("Group size: ");
scanf("%d",&n);
printf(reserveGroup(s,n)?"Reserved!\n":"Failed!\n");
break;
case 5: displayReport(s); break;
case 6: printf("Goodbye!\n"); break;
default: printf("Invalid choice!\n");
}
}while(ch!=6);
return 0;
}
void initializeSeats(int s[ROWS][COLS])
{
int i,j;
for(i=0;i<ROWS;i++)
for(j=0;j<COLS;j++)
s[i][j]=0;
}
void displaySeats(int s[ROWS][COLS])
{
int i,j;
for(i=0;i<ROWS;i++)
{
for(j=0;j<COLS;j++)
printf("%d ",s[i][j]);
printf("\n");
}
printf("0=Free 1=Booked\n");
}
int bookSeat(int s[ROWS][COLS],int r,int c)
{
if(r<1||r>5||c<1||c>8||s[r-1][c-1]==1)
return 0;
s[r-1][c-1]=1;
return 1;
}
int cancelSeat(int s[ROWS][COLS],int r,int c)
{
if(r<1||r>5||c<1||c>8||s[r-1][c-1]==0)
return 0;
s[r-1][c-1]=0;
return 1;
}
int reserveGroup(int s[ROWS][COLS],int n)
{
int i,j,k,free;
if(n<2||n>8) return 0;
for(i=0;i<ROWS;i++)
for(j=0;j<=COLS-n;j++)
{
free=1;
for(k=0;k<n;k++)
if(s[i][j+k]==1) free=0;
if(free)
{
for(k=0;k<n;k++)
s[i][j+k]=1;
printf("Row %d, Seat %d\n",i+1,j+1);
return 1;
}
}
return 0;
}
void displayReport(int s[ROWS][COLS])
{
int i,j,b=0,count[ROWS]={0},max=0;
for(i=0;i<ROWS;i++)
for(j=0;j<COLS;j++)
if(s[i][j]==1)
{
b++;
count[i]++;
}
printf("Booked: %d\nFree: %d\n",b,40-b);
printf("Occupancy: %.2f%%\n",b*100.0/40);
for(i=0;i<ROWS;i++)
if(count[i]>max) max=count[i];
printf("Busiest row(s): ");
for(i=0;i<ROWS;i++)
if(count[i]==max) printf("%d ",i+1);
printf("\n");
}
