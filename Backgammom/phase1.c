#include<stdio.h>

int main()
{
    int a[13];
    int b[13];
    int a_bar=0;
    int b_bar=0;
    int R1,R2;
    char player;
    int canmove;
    int R1_moved=0;
    int R2_moved=0;
    int S1=0;
    int S2=0;
    int D1=0;
    int D2=0;
    int i;
    int j;
    char c1;
    char d1;
    char c2;
    char d2;

    printf("Fill A's Home:\n");
    for(i=12;i>=1;i--)
        scanf("%d",&a[i]);
    printf("Fill B's Home:\n");
    for(i=12;i>=1;i--)
        scanf("%d",&b[i]);
    printf("Roll the dice:\n");
    scanf("%d%d",&R1,&R2);
        if(R1!=R2 || R1==R2)
        {
            for(i=1;i<=12;i++)
            {
              //  printf("%d\n",i);
                if(a[i]>0&&R1_moved==0&&R2_moved==0)
                {
                    canmove=i;
                    if(canmove+R1<=12&&R1_moved==0)
                    {
                    if(a[canmove+R1]==-1)
                    {
                        a[i]=a[i]-1;
                        a[canmove+R1]=1;
                        b_bar-=1;
                        R1_moved=1;
                        c1='A';
                        S1=13-i;
                        D1=13-(canmove+R1);
                        d1='A';
                    //    printf("aaya\n");
                    }
                    }
                    if(canmove+R1>12&&R1_moved==0)
                    {
                            if(b[25-(canmove+R1)]==-1)
                            {
                                a[i]=a[i]-1;
                                b[25-(canmove+R1)]=1;
                                b_bar-=1;
                                R1_moved=1;
                                c1='A';
                                S1=13-i;
                                D1=(canmove+R1)-12;
                                d1='B';
                            }
                    }
                    if(canmove+R2<=12&&R2_moved==0)
                    {
                    if(a[canmove+R2]==-1)
                    {
                        a[i]=a[i]-1;
                        a[canmove+R2]=1;
                        b_bar+=1;
                        R2_moved=1;
                        S2=13-i;
                        c2='A';
                        D2=13-(canmove+R2);
                        d2='A';
                  //      printf("aayaaaaa\n");
                    }
                    }
                    if(canmove+R2>12&&R2_moved==0)
                    {
                        if(b[25-(canmove+R2)]==-1)
                        {
                            a[i]--;
                            b[25-(canmove+R2)]=1;
                            b_bar+=1;
                            R2_moved=1;
                            S2=13-i;
                            c2='A';
                            d2='B';
                            D2=(canmove+R2)-12;
                        }
                    }
                }
            }
            for(j=12;j>=0;j--)
            {
                if(b[j]>0)
                {
                    if(j-R1>0&&R1_moved==0)
                    {
                        if(b[j-R1]==-1)
                        {
                            b[j]--;
                            b[j-R1]=1;
                            R1_moved=1;
                            S1=13-j;
                            c1='B';
                            d1='B';
                            D1=13-(j-R1);
                            b_bar-=1;
                        }
                    }
                    if(j-R2>0&&R2_moved==0)
                    {
                        if(b[j-R2]==-1)
                        {
                            b[j]--;
                            b[j-R2]--;
                            R2_moved=1;
                            S2=13-j;
                            D2=13-(j-R2);
                            b_bar-=1;
                            c2='B';
                            d2='B';
                        }
                    }
                }
            }

            for(i=1;i<=12;i++)
            {
                if(a[i]>0)
                {

                    if(R1_moved==0&&R2_moved==0)
                    {   
                        if(i+R1<=12)
                        {
                            if(a[i+R1]>=0)
                            {
                                for(j=1;j>=12;j--)
                                {
                                    if(a[j]>0)
                                    {
                                        if(i+R1==j+R2)
                                        {
                                            a[i+R1]++;
                                            a[j+R2]++;
                                            a[i]--;
                                            a[j]--;
                                            S1=13-(i);
                                            S2=13-j;
                                            D1=13-(i+R1);
                                            D2=13-(j+R2);
                                            R1_moved=1;
                                            c1='A';
                                            c2='A';
                                            d1='A';
                                            d2='A';
                                            R2_moved=1;
                                        }
                                    }
                                }
                            }
                        }
                        if(i+R1>12)
                        {
                            if(b[25-(i+R1)]>=0)
                            {
                                for(j=12;j>=1;j--)
                                {
                                    if(a[j]>0)
                                    {
                                        if(i+R1==j-R2)
                                        {
                                            b[25-(i+R1)]=b[25-(i+R1)]+2;
                                            a[i]--;
                                            a[j]--;
                                            S1=13-i;
                                            c1='A';
                                            c2='B';
                                            S2=13-j;
                                            d1='B';
                                            d2='B';
                                            D2=13-(j-R2);
                                            D1=D2;
                                            R1_moved=1;
                                            R2_moved=1;
                                        }
                                    }
                                }
                            }
                        }
                    }
                
                    if(i+R1<=12&&R1_moved==0)
                    {
                        if(a[i+R1]>0)
                        {
                            a[i]--;
                            a[i+R1]++;
                            R1_moved=1;
                            S1=i;
                            D1=i+R1;
                        }
                        if(a[i]+R1==0&&R1_moved==0)
                        {
                            a[i]--;
                            a[i+R1]++;
                            R1_moved=1;
                            S1=i;
                            D1=i+R1;
                        }
                    }
                    if(i+R2<=12&&R2_moved==0)
                    {
                        if(a[i+R2]>0)
                        {
                            a[i]--;
                            a[i+R2]++;
                            R2_moved=1;
                            S2=i;
                            D2=i+R2;
                        }
                        if(a[i]+R2==0&&R2_moved==0)
                        {
                            a[i]--;
                            a[i+R2]++;
                            R2_moved=1;
                            S2=i;
                            D2=i+R2;
                        }
                    }
                }


            }
            for(j=12;j>=0;j--)
            {
                if(b[j]>0)
                {
                    if(j-R1>0&&R1_moved==0)
                    {
                        if(b[j-R1]>0)
                        {
                            b[j]--;
                            b[j-R1]++;
                            S1=25-j;
                            D1=25-(j-R1);
                            R1_moved=1;
                        }
                    }
                    if(j-R2>0)
                    {
                    if(b[j-R2]>0&&R2_moved==0)
                    {
                        b[j]--;
                        b[j-R2]++;
                        S2=25-j;
                        D2=25-(j-R2);
                        R2_moved=1;
                    }
                    }
            }
            }
            for(j=12;j>=0;j--)
            {
                if(b[j]>0)
                {
                    if(j-R1>0&&R1_moved==0)
                    {
                        if(b[j-R1]==0)
                        {
                            b[j]--;
                            b[j-R1]++;
                            S1=25-j;
                            D1=25-(j-R1);
                            R1_moved=1;
                        }
                    }
                    if(j-R2>0&&R2_moved==0)
                    {
                        if(b[j-R2]==0)
                        {
                            b[j]--;
                            b[j-R2]++;
                            S2=25-j;
                            D2=25-(j-R2);
                            R2_moved=1;
                        }
                    }
                }
            
            }
        
    
    if(S1>0)
        printf("%d->%d\n",S1,D1);
    if(S2>0)
        printf("%d->%d\n",S2,D2);
    if(S1==0&&S2>0)
        printf("Only One Move Possible\n");
    if(S2==0&&S1>0)
        printf("Only One Move Possible\n");
    if(S1==0&&S2==0)
        printf("No Move Possible\n");
    }
    return 0;
}
            



    


