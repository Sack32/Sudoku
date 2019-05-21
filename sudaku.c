#include<stdio.h>
#include <stdlib.h>
int check(int n[10][10]);
int check2(int n[10][10]);

main()
{
int sud[10][10],row,col,i,j,n,count,s,t;
int ran[10][10],x,y,a,b,c,d,e,ovr;
char comp='n';
time_t po;
 /* Intializes random number generator */
   srand((unsigned) time(&po));

for(i=0;i<10;i++){
for(j=0;j<10;j++){
ran[i][j]=0;
}
}

for(i=1;i<30;i++){


    a=((rand() % 9)+1);
    b=((rand() % 9)+1);
do{
    c=((rand() % 9)+1);



        ran[a][b]=c;
   }while (check2(ran)==0);
}


for(i=0;i<10;i++){
for(j=0;j<10;j++){
sud[i][j]=ran[i][j];
}
}

while(comp!='y'){

system("cls");
printf("You can enter 0 to remove the number\n");
for(i=0;i<10;i++){
for(j=0;j<10;j++){
if (sud[i][j]==0){printf("  ");} else printf("%d ",sud[i][j]);
}
printf("\n");
}
printf("\n");


while(count!=0){
ovr=0;
do{

do{

        printf("Enter the column you want to enter  \n");
        scanf("%d",&row);
        if (row>9||row<1)printf("Enter a number between 1 and 9 you dumbass!!!\n");

}while(row>9||row<1);

do{

        printf("Enter the row you want to enter  \n");
        scanf("%d",&col);
        if (col>9||col<1)printf("Enter a number between 1 and 9!!!\n");


}while(col>9||col<1);


if(ran[col][row]!=0){
        printf("You cant enter there!!!\n");
        ovr=1;
}else{ovr=0;}
}while (ovr==1);





do{

        printf("Enter the number you want to enter  \n");
        scanf("%d",&n);
        if (n>9||n<0)printf("Enter a number between 0 and 9!!!\n");

}while(n>9||n<0);


sud[col][row]=n;

system("cls");
printf("Complete the puzzle\n");
for(i=0;i<10;i++){
for(j=0;j<10;j++){
if (sud[i][j]==0){printf("  ");} else printf("%d ",sud[i][j]);
}
printf("\n");
}
printf("\n");
count=0;
for(i=1;i<10;i++){
for(j=1;j<10;j++){
if (sud[i][j]==0)count++;
}
}

}

printf("your sudoku is complete do u want to enter?(y/n)\n");
comp=getch();
if (comp!='y'||comp!='Y')count=1;

}
if (check(sud)==0) {printf("Your answer is incorrect.\n GAMEOVER\nLOSER!!!!");}
else {printf("Your answer is correct.\nYOU WIN!!!!!");}
}














int check(int n[][10])
{
int i,j,k,l,m,p;
for(k=1;k<10;k++){
for(i=1;i<10;i++){
for(j=i+1;j<10;j++){
if(j!=i){
if (n[k][i]==n[k][j]) {
        printf("row = %d, column = %d and row = %d, column =%d are same numbers. You cant have same numbers in a row dumbass!!!\n ",k,i,k,j);
        return 0;}
}
}
}
}
for(k=1;k<10;k++){
for(i=1;i<10;i++){
for(j=i;j<10;j++){
if(j!=i){
if (n[i][k]==n[j][k])
{

 printf("row = %d, column = %d and row = %d, column =%d are same numbers. You cant have same numbers ina a single column! \n",i,k,j,k);
 return 0;
}
}
}
}
}


for(i=1;i<10;i=i+3){
for(j=1;j<10;j=j+3){
for(m=i;m<i+3;m++){
for(p=j;p<j+3;p++){
for(k=i;k<i+3;k++){
for(l=j;l<j+3;l++){

if(k!=m&&l!=p){
if (n[k][l]==n[m][p])
{

 printf("row = %d, column = %d and row = %d, column =%d are same numbers. You cant have same numbers in a 3x3 box. \n",k,l,m,p);
 return 0;
}
}
}
}
}
}
}
}



return 1;
}


int check2(int n[][10])
{
int i,j,k,l,m,p;
for(k=1;k<10;k++){
for(i=1;i<10;i++){
for(j=i+1;j<10;j++){
if(j!=i){
if (n[k][i]==n[k][j]&&n[k][i]!=0) {

        return 0;}
}
}
}
}
for(k=1;k<10;k++){
for(i=1;i<10;i++){
for(j=i;j<10;j++){
if(j!=i){
if (n[i][k]==n[j][k]&&n[i][k]!=0)
{


 return 0;
}
}
}
}
}


for(i=1;i<10;i=i+3){
for(j=1;j<10;j=j+3){
for(m=i;m<i+3;m++){
for(p=j;p<j+3;p++){
for(k=i;k<i+3;k++){
for(l=j;l<j+3;l++){

if(k!=m&&l!=p){
if (n[k][l]==n[m][p]&&n[k][l]!=0)
{


 return 0;
}
}
}
}
}
}
}
}
}



