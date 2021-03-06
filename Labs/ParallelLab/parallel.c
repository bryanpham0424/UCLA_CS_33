//OpenMP version.  Edit and submit only this file.
/* Enter your details below
 * Name : Bryan Pham
 * UCLA ID : 105-105-100
 * Email : bryan.pham73@gmail.com
 */

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

#include "utils.h"

double work_it_par(long *old, long *new, long *super, long *simple, long *fibonacci) {
  int i, j, k;
  int u, v, w;
  int ton = 0;
  long compute_it, moving_average;
  double pi, pi2, x , y, sum, step = 0.0;
  long dot_product=0;
  long nCirc=0;
  long aggregate=1.0;
  double r=1.0;
  int was_smart = 16;
  /* #pragma omp parallel for
   for(i=0; i<DIM-1;i++)
  {
    super[i] += simple[i];
    //super[i+1] += simple[i+1];
    }*/
  //#pragma omp parallel for reduction(+:dot_product)
  for(i=0; i<DIM-1;i++)
  {
    super[i] += simple[i];
    dot_product += super[i]*simple[i];
    
    moving_average = 0;
    for(ton=i;ton<DIM-1-WINDOW_SIZE;ton++)
    {
      moving_average += simple[ton];
    }
  }

  int a_secret = 5;
  fibonacci[0] = 1;
  fibonacci[1] = 1;
  for(i=2; i<DIM-1;i++)
  {
    fibonacci[i]=fibonacci[i-1]+fibonacci[i-2];
    if(i==3)
    {
      printf("\n A secret is: %d",obfuscate_obfuscate_obfuscate(a_secret));
    }
  }

  step = 1.0 / NUM_STEPS;
  //#pragma omp parallel for private(x) reduction(+:sum)
  for (i=0;i<NUM_STEPS; i++)
  {
    x = (i+0.5)*step;
    sum = sum + 4.0/(1.0+x*x);
  }
  pi = step * sum;
  printf("\n %d trials, Riemann flavored pi is %f \n",NUM_STEPS, pi); 
  //#pragma omp parallel for private(x,y) 
  for(i=0;i<NUM_TRIALS; i++)
  {
    x = (random()%10000000)/10000000.0; 
    y = (random()%10000000)/10000000.0;
    if (( x*x + y*y) <= r*r) {
      nCirc++;
    }
  } 
  pi2 = 4.0 * ((double)nCirc/(double)NUM_TRIALS);
  printf("\n %d trials, Monte-Carlo flavored pi is %f \n",NUM_TRIALS, pi2); 

  /*
  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        compute_it = old[i*DIM*DIM+j*DIM+k] * we_need_the_func();
        aggregate+= compute_it / gimmie_the_func();
      }
    }
  }
  
  printf("AGGR:%ld\n",aggregate);*/
  long temp_new;
  int temp = DIM*DIM;
  int u0, u1, u2, u3, u4, u5, u6, u7, u8, u9;
#pragma omp parallel for private(j,k,u,compute_it,temp_new) reduction(+:aggregate,u0,u1,u2,u3,u4,u5,u6,u7,u8,u9)
  for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
	temp_new = 0;
        //new[i*DIM*DIM+j*DIM+k]=0;
	// for (u=-1; u<=1; u++) {
	//for (v=-1; v<=1; v++) {
	//for (w=-1; w<=1; w++) {
	compute_it = old[i*temp+j*DIM+k] * we_need_the_func();
	aggregate+= compute_it / gimmie_the_func();
	       temp_new+=old[(i+-1)*temp+(j+-1)*DIM+(k+-1)];
	       temp_new+=old[(i+-1)*temp+(j+-1)*DIM+(k)];
	       temp_new+=old[(i+-1)*temp+(j+-1)*DIM+(k+1)];
	       temp_new+=old[(i+-1)*temp+(j)*DIM+(k+-1)];
	       temp_new+=old[(i+-1)*temp+(j)*DIM+(k)];
	       temp_new+=old[(i+-1)*temp+(j)*DIM+(k+1)];
	       temp_new+=old[(i+-1)*temp+(j+1)*DIM+(k+-1)];
	       temp_new+=old[(i+-1)*temp+(j+1)*DIM+(k)];
	       temp_new+=old[(i+-1)*temp+(j+1)*DIM+(k+1)];

	       temp_new+=old[(i)*temp+(j+-1)*DIM+(k+-1)];
               temp_new+=old[(i)*temp+(j+-1)*DIM+(k)];
               temp_new+=old[(i)*temp+(j+-1)*DIM+(k+1)];
               temp_new+=old[(i)*temp+(j)*DIM+(k+-1)];
               temp_new+=old[(i)*temp+(j)*DIM+(k)];
               temp_new+=old[(i)*temp+(j)*DIM+(k+1)];
               temp_new+=old[(i)*temp+(j+1)*DIM+(k+-1)];
               temp_new+=old[(i)*temp+(j+1)*DIM+(k)];
               temp_new+=old[(i)*temp+(j+1)*DIM+(k+1)];

	       temp_new+=old[(i+1)*temp+(j+-1)*DIM+(k+-1)];
               temp_new+=old[(i+1)*temp+(j+-1)*DIM+(k)];
               temp_new+=old[(i+1)*temp+(j+-1)*DIM+(k+1)];
               temp_new+=old[(i+1)*temp+(j)*DIM+(k+-1)];
               temp_new+=old[(i+1)*temp+(j)*DIM+(k)];
               temp_new+=old[(i+1)*temp+(j)*DIM+(k+1)];
               temp_new+=old[(i+1)*temp+(j+1)*DIM+(k+-1)];
               temp_new+=old[(i+1)*temp+(j+1)*DIM+(k)];
               temp_new+=old[(i+1)*temp+(j+1)*DIM+(k+1)];
	       //}
	       //}
	       //}
	       temp_new/=27;
        new[i*temp+j*DIM+k]=temp_new;
	u=(temp_new/100);
       
        if (u>=9) u9++;
	if (u==8) u8++;
	if (u==7) u7++;
	if (u==6) u6++;
	if (u==5) u5++;
	if (u==4) u4++;
	if (u==3) u3++;
	if (u==2) u2++;
	if (u==1) u1++;
	if (u==0) u0++;
        
      }
    }
  }
  printf("AGGR:%ld\n",aggregate);
  
  histogrammy[0]+=u0;
  histogrammy[1]+=u1;
  histogrammy[2]+=u2;
  histogrammy[3]+=u3;
  histogrammy[4]+=u4;
  histogrammy[5]+=u5;
  histogrammy[6]+=u6;
  histogrammy[7]+=u7;
  histogrammy[8]+=u8;
  histogrammy[9]+=u9;

  /*for (i=1; i<DIM-1; i++) {
    for (j=1; j<DIM-1; j++) {
      for (k=1; k<DIM-1; k++) {
        u=(new[i*DIM*DIM+j*DIM+k]/100);
        if (u<=0) u=0;
        if (u>=9) u=9;
        histogrammy[u]++;
      }
    }
    }*/
  return (double) (dot_product+moving_average+pi+pi2);


}
