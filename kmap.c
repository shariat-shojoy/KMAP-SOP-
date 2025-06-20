#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>




Color color[]={RED,BLUE,GREEN,YELLOW,PURPLE,ORANGE,BROWN,MAROON,WHITE,GOLD};

int main(void)
{
    

    char col[2][4]={
                    {'a','a','A','A'},
                    {'b','B','B','b'}
                };
    char row[2][4]={
                {'c','c','C','C'},
                {'d','D','D','d'}
            };
    char * res=(char *)malloc(150*sizeof(char));

    int mat[4][4];
    char checked[4][4];
    int index=0;
    //printf("%d %c",index,res[0]);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d",&mat[i][j]);
            if(mat[i][j]==1){
                checked[i][j]='u';
            }else{
                checked[i][j]='0';
            }
        }
        
    }
    int lool=0;
    int ind[16]={0};
    int ***group = (int ***)malloc(16 * sizeof(int **));
    
    // symetry check

 
     
    if(mat[0][0]==1 && mat[0][3]==1 && mat[3][0]==1 && mat[3][3]==1){
        if((mat[0][1]==0 && mat[1][0]==0)||(mat[0][2]==0 && mat[1][3]==0) || (mat[3][1]==0 && mat[2][0]==0) || (mat[3][2]==0 && mat[2][3]==0)){
            checked[0][0]='c'+lool;
            checked[0][3]='c'+lool;
            checked[3][0]='c'+lool;
            checked[3][3]='c'+lool;
           
            printf("group lool=%d\n",lool);
            printf("(0,0) (0,3) \n(3,0) (3,3)\n");
            group[lool] = (int **)malloc(4 * sizeof(int *));
            for(int q=0;q<4;q++){
                group[lool-1][q] = (int *)malloc(2 * sizeof(int));
            }
            group[lool][0][0]=0;
            group[lool][0][1]=0;
            group[lool][1][0]=0;
            group[lool][1][1]=3;
            group[lool][2][0]=3;
            group[lool][2][1]=0;
            group[lool][3][0]=3;
            group[lool][3][1]=3;
            ind[lool]=4;
            res[index++]=row[1][0];
            res[index++]=col[1][3];
            res[index++]='+';
            lool++;
        }
    } 


    // upper line
    int left=0,right=0;
    int sup=0,sdown=0;
//---------------------------------------------- upper line------------
//printf("upper line start\n");
for(int j=0;j<4;j++){
    int flg=0;
    if(mat[0][j]==1 && checked[0][j]=='u' && mat[3][j]==1){
        left=j;
        right=j;
        //printf("for:%d,%d\n",0,j);
        while (left-1>=0 && mat[0][left-1]==1 && mat[3][left-1]==1)
        {
            left--;
        }
        while (right+1<=3 && mat[0][right+1]==1 && mat[3][right+1]==1)
        {
            right++;
        }
        int up_l=left,dwn_l=left,up_r=right,dwn_r=right;

        while (up_l-1>=0 && mat[0][up_l-1]==1)
        {
            up_l--;
        }
        while (up_r+1<=3 && mat[0][up_r+1]==1)
        {
            up_r++;
        }
        while (dwn_l-1>=0 && mat[3][dwn_l-1]==1)
        {
            dwn_l--;
        }
        while (dwn_r+1<=3 && mat[3][dwn_r+1]==1)
        {
            dwn_r++;
        }
        
        // handling 3
        if(up_r-up_l==2){
            if(j==0){
                up_r--;
            }else{
                up_l++;
            }
           /*  if(checked[0][up_l]=='u'){
                up_r--;
            }else{
                up_l++;
            } */
        }
        if(dwn_r-dwn_l==2){
            if(j==0){
                dwn_r--;
            }else{
                dwn_l++;
            }
            /* if(checked[3][dwn_l]=='u'){
                dwn_r--;
            }else{
                dwn_l++;
            } */
        }
        if(right-left==2){
            if(j==0){
                right--;
            }else{
                left++;
            }
            
        }

         /* printf("for:%d,%d\n",0,j);
         printf("l %d\n",left);
        printf("r %d\n",right);
        printf("ul %d ,%d ,%d ,%d \n",up_l,up_r,dwn_l,dwn_r);  */
        
        
        int dif_up=up_r-up_l+1;
        int dif_dwn=dwn_r-dwn_l+1;
         //printf("dup %d\n",dif_up);
        //printf("dup %d\n",dif_dwn); 
       
        /* if(up_l==left && up_r==right){
            if(left==right && mat[3][left]==0){
                flg=0;
            }
        } */
             if(dif_up<dif_dwn){
                /* printf("dup %d\n",dif_up);
                printf("dup %d\n",dif_dwn); */
                for(int i=up_l;i<=up_r;i++){
                    if(mat[1][i]==0){
                        flg=1;
                        break;
                    }
                }
            }else if(dif_up>dif_dwn){
               // printf("dup %d\n",dif_up);
                for(int i=dwn_l;i<=dwn_r;i++){
                    if(mat[2][i]==0){
                        flg=1;
                        break;
                    }
                }
            }else{
                for(int i=dwn_l;i<=dwn_r;i++){
                    if(mat[2][i]==0 || mat[1][i]==0){
                        flg=1;
                        break;
                    }
                }
            }
        
        
        }

        if(flg){

            int flag2=1;
            for(int i=left;i<=right;i++){
                if(mat[3][i]==0){
                    flag2=0;
                    break;
                }
            }
            if(flag2){
                for(int i=left;i<=right;i++){
                    checked[0][i]='c'+lool;
                    checked[3][i]='c'+lool;

                }
                group[lool] = (int **)malloc(2*(right-left+1) * sizeof(int *));
                ind[lool]=2*(right-left+1);
                for(int q=0;q<2*(right-left+1);q++){
                    group[lool][q] = (int *)malloc(2 * sizeof(int));
                }
                
                printf("group lool=%d\n",lool);
                int f_index=0;
                for(int i=left;i<=right;i++){
                   printf("(%d,%d) ",0,i);
                   group[lool][f_index][0]=0;
                   group[lool][f_index][1]=i;
                   f_index++;
                }
                printf("\n");
                for(int i=left;i<=right;i++){
                   printf("(%d,%d) ",3,i);
                   group[lool][f_index][0]=3;
                   group[lool][f_index][1]=i;
                   f_index++;
                }
                printf("\n");
                char r_t1=row[0][left];
                char r_t2=row[1][left];
                
                for(int i=left;i<right;i++){
                    if(r_t1!=row[0][i+1]){
                        r_t1='0';
                    }
                    if(r_t2!=row[1][i+1]){
                        r_t2='0';
                    }
                }
               // printf("r_t1=%c r_t2=%c %d\n",r_t1,r_t2,index);
                if(r_t1!='0'){
                    res[index++]=r_t1;
                }
                if(r_t2!='0'){
                    res[index++]=r_t2;
                }
                res[index++]='b';
                res[index++]='+';

               /*  for(int i=0;i<index;i++){
                    
                   printf("%c",res[i]);
                }
                printf("\n"); */

                lool++;
            }
    }
   
}

//printf("upper line end\n");
// upper line end----------------------------------

int left1=0,right1=0;
int sup1=0,sdown1=0;
// lower line start--------------------------------
//printf("lower line start\n");
for(int j=0;j<4;j++){
    int flg=0;
    if(mat[3][j]==1 && checked[3][j]=='u' && mat[0][j]==1){
        left1=j;
        right1=j;
        while (left1-1>=0 && mat[3][left1-1]==1 && mat[0][left1-1]==1)
        {
            left1--;
        }
        while (right1+1<=3 && mat[3][right1+1]==1 && mat[0][right1+1]==1)
        {
            right1++;
        }
        int up_l=left1,dwn_l=left1,up_r=right1,dwn_r=right1;

        while (up_l-1>=0 && mat[3][up_l-1]==1)
        {
            up_l--;
        }
        while (up_r+1<=3 && mat[3][up_r+1]==1)
        {
            up_r++;
        }
        while (dwn_l-1>=0 && mat[0][dwn_l-1]==1)
        {
            dwn_l--;
        }
        while (dwn_r+1<=3 && mat[0][dwn_r+1]==1)
        {
            dwn_r++;
        }
        
        // handling 3
        if(up_r-up_l==2){
            if(j==0){
                up_r--;
            }else{
                up_l++;
            }
        }
        if(dwn_r-dwn_l==2){
            if(j==0){
                dwn_r--;
            }else{
                dwn_l++;
            }
        }
        if(right1-left1==2){
            if(j==0){
                right1--;
            }else{
                left1++;
            }
        }
        /* printf("l %d\n",left);
        printf("r %d\n",right);
        printf("ul %d ,%d ,%d ,%d \n",up_l,up_r,dwn_l,dwn_r);  
        */
        int dif_up=up_r-up_l+1;
        int dif_dwn=dwn_r-dwn_l+1;
        /* printf("dup %d\n",dif_up);
        printf("dup %d\n",dif_dwn); */
       
        /* if(up_l==left1 && up_r==right1){
            if(left1==right1 && mat[0][left1]==0){
                flg=0;
            }
        } */
             if(dif_up<dif_dwn){
                /* printf("dup %d\n",dif_up);
                printf("dup %d\n",dif_dwn); */
                for(int i=up_l;i<=up_r;i++){
                    if(mat[2][i]==0){
                        flg=1;
                        break;
                    }
                }
            }else if(dif_up>dif_dwn){
                for(int i=dwn_l;i<=dwn_r;i++){
                    if(mat[1][i]==0){
                        flg=1;
                        break;
                    }
                }
            }else{
                for(int i=dwn_l;i<=dwn_r;i++){
                    if(mat[2][i]==0 || mat[1][i]==0){
                        flg=1;
                        break;
                    }
                }
            }
            
        }

         if(flg){

            int flag2=1;
            for(int i=left1;i<=right1;i++){
                if(mat[0][i]==0){
                    flag2=0;
                    break;
                }
            }
            if(flag2){
                for(int i=left1;i<=right1;i++){
                    checked[3][i]='c'+lool;
                    checked[0][i]='c'+lool;

                }
                group[lool] = (int **)malloc(2*(right1-left1+1) * sizeof(int *));
                ind[lool] = 2*(right1-left1+1);
                for(int i=0;i<2*(right1-left1+1);i++){
                    group[lool][i] = (int *)malloc(2 * sizeof(int));
                }
                printf("group lool=%d\n",lool);
                int s_index=0;
                for(int i=left1;i<=right1;i++){
                   printf("(%d,%d) ",3,i);
                   group[lool][s_index][0]=3;
                   group[lool][s_index][1]=i;
                   s_index++;
                }
                printf("\n");
                for(int i=left1;i<=right1;i++){
                   printf("(%d,%d) ",0,i);
                   group[lool][s_index][0]=0;
                   group[lool][s_index][1]=i;
                   s_index++;
                }
                printf("\n");

                char r_t1=row[0][left];
                char r_t2=row[1][left];
                
                for(int i=left;i<right;i++){
                    if(r_t1!=row[0][i+1]){
                        r_t1='0';
                    }
                    if(r_t2!=row[1][i+1]){
                        r_t2='0';
                    }
                }
               // printf("r_t1=%c r_t2=%c %d\n",r_t1,r_t2,index);
                if(r_t1!='0'){
                    res[index++]=r_t1;
                }
                if(r_t2!='0'){
                    res[index++]=r_t2;
                }
                res[index++]='b';
                res[index++]='+';

              /*   for(int i=0;i<index;i++){
                    
                   printf("%c",res[i]);
                }
                printf("\n"); */

                
                lool++;
            }
            }
        }



//printf("lower line end\n");
// lower line end----------------------------------

// left side start--------------------------------
//printf("left side start\n");
for(int i=0;i<4;i++){
    int flg2=0;
    if(mat[i][0]==1 && checked[i][0]=='u' && mat[i][3]==1){
      //  printf("for %d %d\n",i,0);
sup=i;
sdown=i;
while (sup-1>=0 && mat[sup-1][0]==1 && mat[sup-1][3]==1)
{
    sup--;
}
while (sdown+1<=3 && mat[sdown+1][0]==1 && mat[sdown+1][3]==1)
{
    sdown++;
}
int l_up=sup,l_dwn=sdown,r_up=sup,r_dwn=sdown;

while (l_up-1>=0 && mat[l_up-1][0]==1)
{
    l_up--;
}
while (l_dwn+1<=3 && mat[l_dwn+1][0]==1)
{
    l_dwn++;
}
while (r_up-1>=0 && mat[r_up-1][3]==1)
{
    r_up--;
}
while (r_dwn+1<=3 && mat[r_dwn+1][3]==1)
{
    r_dwn++;
}

// handling 3
if(l_dwn-l_up==2){
    if(i==0){
        l_dwn--;
    }else{
        l_up++;
    }
}
if(r_dwn-r_up==2){
    if(i==0){
        r_dwn--;
    }else{
        r_up++;
    }
}
if(sdown-sup==2){
    if(i==0){
        sdown--;
    }else{
        sup++;
    }
}

 /* printf("for:%d,%d\n",j,0);
 printf("l %d\n",sup);
printf("r %d\n",sdown);
printf("ul %d ,%d ,%d ,%d \n",l_up,l_dwn,r_up,r_dwn);   */

int dif_lft=l_dwn-l_up+1;
int dif_rght=r_dwn-r_up+1;
// printf("dup %d\n",dif_lft);
//printf("dup %d\n",dif_rght); 

/* if(l_up==sup && l_dwn==sdown){
    if(sup==sdown && mat[sup][3]==0){
        flg2=0;
    }
  }
    else */ if(dif_lft<dif_rght){
        /* printf("dup %d\n",dif_up);
        printf("dup %d\n",dif_dwn); */
        for(int i=l_up;i<=l_dwn;i++){
            if(mat[i][1]==0){
                flg2=1;
                break;
            }
        }
    }else if(dif_lft>dif_rght){
        for(int i=r_up;i<=r_dwn;i++){
            if(mat[i][2]==0){
                flg2=1;
                break;
            }
        }
    }else{
        for(int i=l_up;i<=l_dwn;i++){
            if(mat[i][1]==0 || mat[i][2]==0){
                flg2=1;
                break;
            }
        }
    }
    
}



if(flg2){

    int flag2=1;
    for(int i=sup;i<=sdown;i++){
        if(mat[i][3]==0){
            flag2=0;
            break;
        }
    }
    if(flag2){
        for(int i=sup;i<=sdown;i++){
            checked[i][0]='c'+lool;
            checked[i][3]='c'+lool;

        }
        group[lool] = (int **)malloc(2*(sdown-sup+1) * sizeof(int *));
            ind[lool] = 2*(sdown-sup+1);
        for(int i=0;i<2*(sdown-sup+1);i++){
            group[lool][i] = (int *)malloc(2 * sizeof(int));
        }
        int t_index=0;
        printf("group lool=%d\n",lool);
        for(int i=sup;i<=sdown;i++){
           printf("(%d,%d) ",i,0);
           group[lool][t_index][0]=i;
           group[lool][t_index][1]=0;
           t_index++;
           printf("(%d,%d) ",i,3);
           group[lool][t_index][0]=i;
           group[lool][t_index][1]=3;
           t_index++;
        }
        printf("\n");
        /* for(int i=sup;i<=sdown;i++){
           printf("(%d,%d) ",i,3);
        }
        printf("\n"); */
        // edited 7-6-2025
        char c_t1=col[0][sup];
        char c_t2=col[1][sup];

       //  printf("c_t1=%c c_t2=%c %d %d\n",c_t1,c_t2,sup,sdown);
        for(int i=sup;i<sdown;i++){
            if(c_t1!=col[0][i+1]){
                c_t1='0';
            }
            if(c_t2!=col[1][i+1]){
                c_t2='0';
            }
        }
       // printf("c_t1=%c c_t2=%c %d\n",c_t1,c_t2,index);
         res[index++]='d';
        if(c_t1!='0'){
            res[index++]=c_t1;
        }
        if(c_t2!='0'){
            res[index++]=c_t2;
        }
        
        res[index++]='+';

        /* for(int i=0;i<index;i++){
           printf("%c",res[i]);
        }
        printf("\n"); */




        
        lool++;
    }
}



}


//printf("left side end\n");
// left side end--------------------------------
// right side start--------------------------------
//printf("right side start\n");
for(int i=0;i<4;i++){
    int flg2=0;
    if(mat[i][3]==1 && checked[i][3]=='u' && mat[i][0]==1){
     //   printf("for %d %d\n",i,3);
   sup1=i;
   sdown1=i;
while (sup1-1>=0 && mat[sup1-1][0]==1 && mat[sup1-1][3]==1)
{
    sup1--;
}
while (sdown1+1<=3 && mat[sdown1+1][0]==1 && mat[sdown1+1][3]==1)
{
    sdown1++;
}
int l_up=sup1,l_dwn=sdown1,r_up=sup1,r_dwn=sdown1;

while (l_up-1>=0 && mat[l_up-1][0]==1)
{
    l_up--;
}
while (l_dwn+1<=3 && mat[l_dwn+1][0]==1)
{
    l_dwn++;
}
while (r_up-1>=0 && mat[r_up-1][3]==1)
{
    r_up--;
}
while (r_dwn+1<=3 && mat[r_dwn+1][3]==1)
{
    r_dwn++;
}

// handling 3
if(l_dwn-l_up==2){
    if(i==0){
        l_dwn--;
    }else{
        l_up++;
    }
}
if(r_dwn-r_up==2){
    if(i==0){
        r_dwn--;
    }else{
        r_up++;
    }
}
if(sdown1-sup1==2){
    if(i==0){
        sdown1--;
    }else{
        sup1++;
    }
}
int dif_lft=l_dwn-l_up+1;
int dif_rght=r_dwn-r_up+1;
/* if(l_up==sup1 && l_dwn==sdown1){
    if(sup1==sdown1 && mat[sup1][3]==0){
        flg2=0;
    }
} */
     if(dif_lft<dif_rght){
        /* printf("dup %d\n",dif_up);
        printf("dup %d\n",dif_dwn); */
        for(int i=l_up;i<=l_dwn;i++){
            if(mat[i][1]==0){
                flg2=1;
                break;
            }
        }
    }else if(dif_lft>dif_rght){
        for(int i=r_up;i<=r_dwn;i++){
            if(mat[i][2]==0){
                flg2=1;
                break;
            }
        }
    }else{
        for(int i=l_up;i<=l_dwn;i++){
            if(mat[i][1]==0 || mat[i][2]==0){
                flg2=1;
                break;
            }
        }
    }
    


if(flg2){

    int flag2=1;
    for(int i=sup1;i<=sdown1;i++){
        if(mat[i][3]==0){
            flag2=0;
            break;
        }
    }
    if(flag2){
        for(int i=sup1;i<=sdown1;i++){
            checked[i][0]='c'+lool;
            checked[i][3]='c'+lool;

        }
        printf("group lool=%d\n",lool);

        group[lool] = (int **)malloc(2*(sdown1-sup1+1) * sizeof(int *));
            ind[lool] = 2*(sdown1-sup1+1);
        for(int i=0;i<2*(sdown1-sup1+1);i++){
            group[lool][i] = (int *)malloc(2 * sizeof(int));
        }

        int fo_index=0;
        for(int i=sup1;i<=sdown1;i++){
           printf("(%d,%d) ",i,0);
           group[lool][fo_index][0]=i;
           group[lool][fo_index][1]=0;
           fo_index++;
           printf("(%d,%d) ",i,3);
           group[lool][fo_index][0]=i;
           group[lool][fo_index][1]=3;
           fo_index++;
        }
        printf("\n");
        /* for(int i=sup;i<=sdown;i++){
           printf("(%d,%d) ",i,3);
        }
        printf("\n"); */

        char c_t1=col[0][sup1];
        char c_t2=col[1][sup1];
       // printf("c_t1=%c c_t2=%c %d\n",c_t1,c_t2,sup);
        for(int i=sup1;i<sdown1;i++){
            if(c_t1!=col[0][1+i]){
                c_t1='0';
            }
            if(c_t2!=col[1][i+1]){
                c_t2='0';
            }
        }
      //  printf("c_t1=%c c_t2=%c %d\n",c_t1,c_t2,sup);
       // printf("r_t1=%c r_t2=%c %d\n",r_t1,r_t2,index);
       res[index++]='d';
        if(c_t1!='0'){
            res[index++]=c_t1;
        }
        if(c_t2!='0'){
            res[index++]=c_t2;
        }
        
        res[index++]='+';

        for(int i=0;i<index;i++){
       //    printf("%c",res[i]);
        }
       // printf("\n");
        
        lool++;
    }
}
    }
}

//printf("right side end\n");


// right side end--------------------------------


 
    for (int i = 0; i <4; i++)
    {
        for (int j = 0; j < 4; j++)
        {   
        
        
           // printf("for %d %d %d\n",i,j,flg);

            


         
            // genjam----------------
        
            
            // flag part------------
            
            // my main --------------
            if(mat[i][j]==1 && checked[i][j]=='u'){
                int h=1,v=1,up=i,d=i,l=j,r=j;
                while (up-1>=0 && mat[up-1][j]==1)
                {
                    up--;
                    h++;

                }
                while (d+1<=3 && mat[d+1][j]==1)
                {
                    d++;
                    h++;

                }
                while (l-1>=0 && mat[i][l-1]==1)
                {
                    l--;
                    v++;

                }
                while (r+1<=3 && mat[i][r+1]==1)
                {
                    r++;
                    v++;

                } 
               // printf("for i=%d j=%d\n",i,j );
               // printf("up=%d d=%d l=%d r=%d v=%d h=%d \n",up,d,l,r,v,h);
               
                        
               if(v==3 && h==2){
                 if(up<i){
                    if(l<j){
                        if(mat[up][j-1]==0){
                            v=1;
                            r=j;
                            l=j;
                        }
                    }else{
                        if(mat[up][j+1]==0){
                            v=1;
                            r=j;
                            l=j;
                        }
                    }
                 }else{
                    if(l<j){
                        if(mat[i+1][j-1]==0){
                            v=1;
                            r=j;
                            l=j;
                        }
                    }else{
                        if(mat[i+1][j+1]==0){
                            v=1;
                            r=j;
                            l=j;
                        }
                    }
                 }
               }
               if(h==3 && v==2){
                 if(l<j){
                    if(up<i){
                        if(mat[i-1][l]==0){
                            
                            h=1;
                            d=i;
                            up=i;
                        }
                    }else{
                        if(mat[i+1][l]==0){
                            if(checked[i][l]=='u'){
                            h=1;
                            d=i;
                            up=i;
                            }else{
                                v=1;
                                r=j;
                                l=j;
                            }
                            
                        }
                    }
                 }else{
                    if(up<i){
                        if(mat[i-1][l+1]==0){
                            h=1;
                            d=i;
                            up=i;
                        }
                    }else{
                        if(mat[i+1][l+1]==0){
                            if(checked[i][l+1]=='u'){
                            h=1;
                            d=i;
                            up=i;
                            }else{
                                v=1;
                                r=j;
                                l=j;
                            }
                            
                        }
                    }
                 }
               }

               if(v==3){
                if(l<j){
                    l++;
                    v--;
                    //printf("l=%d\n",l);
                }else{
                    r--;
                    v--;
                    //printf("r=%d\n",r);
                }
               }
               if(h==3){
                if(up<i){
                    up++;
                    h--;
                    
                }else{
                    d--;
                    h--;
                   // printf("d=%d\n",d);
                }
               }
               
                if(h==2 && up<i && v==2 && r>j && mat[up][r]==0){
                up++;
               }
               if(h==2 && v==2 &&  r>j && d>i && mat[d][r]==0 ){
                if(checked[d-1][r]=='u'){
                    if(r+1<=3){
                        if(mat[d-1][r+1]==0){
                            d--;
                        }else{
                            r--;
                        }
                        
                    }else{
                        d--;
                    }
                    
                }else{
                    r--;
                }
               }
               if(h==2 && v==2 &&  l<j && up<i && mat[up][l]==0 ){
                up++;
               } 
               if(h==2 && v==2 &&  l<j && d>i && mat[d][l]==0 ){
                l++;
               } 

               
               
               
                    int mx=0;
                    int depth=0;
                    int x1=l,y1=up,x2=r,y2=d;
                   // printf("up=%d d=%d l=%d r=%d v=%d h=%d \n",up,d,l,r,v,h);

                   // modified in 21-6-25
                for(int a=up;a<=d;a++){
                    depth++;
                    int len=0;
                    for(int b=l;b<=r;b++){
                        if(mat[a][b]==0 ){
                            r=b-1;
                            if(len*depth>mx){
                                mx=len*depth;
                                x2=r;
                                y2=a;
                            }
                            break;
                        }else if(mat[a][b]==1 && b==r){
                            len++;
                            if(len*depth>mx){
                            x2=b;
                            y2=a;
                            }
                        }else{
                            len++;
                        }
                    }
                    

                    
                }
                printf("group lool=%d\n",lool);

                group[lool] = (int **)malloc((y2-y1+1)*(x2-x1+1) * sizeof(int *));
                ind[lool] = (y2-y1+1)*(x2-x1+1);
                for(int i=0;i<(y2-y1+1)*(x2-x1+1);i++){
                group[lool][i] = (int *)malloc(2 * sizeof(int));
                }
                int fi_index=0;
                for(int a1=y1;a1<=y2;a1++){
                    for(int b1=x1;b1<=x2;b1++){
                        checked[a1][b1]='c'+lool;
                        printf("(%d,%d) ",a1,b1);
                        group[lool][fi_index][0]=a1;
                        group[lool][fi_index][1]=b1;
                        fi_index++;
    
                    }
                    printf("\n");
                }
               // printf("x1=%d x2=%d y1=%d y2=%d\n",x1,x2,y1,y2);
                char r_t1=row[0][x1];
                char r_t2=row[1][x1];
                char c_t1=col[0][y1];
                char c_t2=col[1][y1];
               // printf("%c %c",col[0][y2],col[1][y1]);
               // printf("r_t1=%c r_t2=%c \n",r_t1,r_t2);
               // printf("c_t1=%c c_t2=%c \n",c_t1,c_t2);
               //  printf("c_t1=%c c_t2=%c %d\n",c_t1,c_t2,sup);
                 for(int m=y1;m<y2;m++){
                   // printf("%c \n",col[m+1][0]);
                 if(c_t1!=col[0][m+1]){
                    c_t1='0';
                 }
                if(c_t2!=col[1][m+1]){
                 c_t2='0';
                  }
                }
                
     //   printf("r_t1=%c r_t2=%c %d\n",r_t1,r_t2,index);
              for(int mm=x1;mm<x2;mm++){
                 if(r_t1!=row[0][mm+1]){
                     r_t1='0';
                 }
                if(r_t2!=row[1][mm+1]){
                     r_t2='0';
                 }
                }
   // printf("r_t1=%c r_t2=%c \n",r_t1,r_t2);
   // printf("c_t1=%c c_t2=%c \n",c_t1,c_t2);

             if(c_t1!='0'){
                res[index++]=c_t1;
            }
            if(c_t2!='0'){
                res[index++]=c_t2;
            }
            if(r_t1!='0'){
                res[index++]=r_t1;
             }
             if(r_t2!='0'){
                res[index++]=r_t2;
             }
             
             
        
             res[index++]='+';

        for(int mm=0;mm<index;mm++){
          // printf("%c",res[mm]);
        }
       // printf("\n");
                
        lool++;

                //printf("x1=%d y1=%d x2=%d y2=%d\n",x1,y1,x2,y2);


            }
        }
    
    }
    
    char ans_str[index-1];
    for(int i=0;i<index-1;i++){
        printf("%c",res[i]);
        ans_str[i]=res[i];
        
    }
    printf("\n");
  //  strcpy(ans_str, res);
    
  printf("groups: \n");
  int group_ind=0;
  while(ind[group_ind]!=0){
    printf("group number: %d\n",group_ind);
    for(int i=0;i<ind[group_ind];i++){
        printf("%d,%d \n",group[group_ind][i][0],group[group_ind][i][1]);
    }
    group_ind++;
  }

InitWindow(800, 800, "Matrix Renderer");
SetTargetFPS(60);


    // --- 3) Main loop: draw grid + matrix values + result string ---
   
while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);


        DrawRectangleLines(200,200,400,400,WHITE);
        DrawLine(300, 200, 300, 600, WHITE);
        DrawLine(400, 200, 400, 600, WHITE);
        DrawLine(500, 200, 500, 600, WHITE);
        DrawLine(200, 300, 600, 300, WHITE);
        DrawLine(200, 400, 600, 400, WHITE);
        DrawLine(200, 500, 600, 500, WHITE);

        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                DrawText(TextFormat("%d", mat[j][i]), 200+40 + i*100, 200+30 + j*100, 40, WHITE);
            }
        }

        int drawing_ind=0;
        int color_index=0;
        int liner=2;
        while(ind[drawing_ind]!=0){
            

            for(int i=0;i<ind[drawing_ind];i++){
                DrawRectangleLinesEx((Rectangle){200+liner+group[drawing_ind][i][1]*100,200+liner+group[drawing_ind][i][0]*100,100-liner*2,100-liner*2},5,color[color_index]);
            }
            drawing_ind++;
            color_index++;
            liner+=5;
        }

        
        
        DrawText(TextFormat("%s", ans_str), 200, 700, 40, WHITE);

        // Draw each cell
        
        EndDrawing();
    }

    // --- 4) Cleanup ---
    CloseWindow();
     free(res);
    return 0;
}
