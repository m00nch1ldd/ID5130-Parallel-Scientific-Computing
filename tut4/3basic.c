/* OpenMP parallel version of trapezoidal rule */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifdef _OPENMP
#include<omp.h>
#endif

double func(double x)
{
  return (7.0-x*tan(x));
}
double dfunc(double x)
{
    return -(tan(x)+x*pow(1/cos(x),2));
}

// double dudx1(int n, double a, double b, double delx, double der)
// {
//   double h, x, total; 		/* private  */
//   int i;
//   int my_rank = omp_get_thread_num(); /* private  */
//   int thread_count = omp_get_num_threads();
//   int local_n;			
//   double local_a, local_b;	/* private scope  */

//   h = (b-a)/n;			

//   local_n = n/thread_count;	
//   local_a = a + my_rank*local_n*h;
//   local_b = local_a + local_n*h;
  
  
//   total = (func(local_a) + func(local_b))/2.0;
//   for(i = 1; i <= local_n-1; i++) 
//     {
//       x = local_a + i*h;
//       total += func(x);
//     }
//   total = total * h;
//   return der;
// }

int main(int argc, char* argv[])
{
  
  int i;
  double a, b, dx, final_result;
  int n;
  int thread_count = 1;

  if (argc == 2)
    {
      thread_count = strtol(argv[1], NULL, 10);
    }
  else
    {
      printf("\n A command line argument other than name of the executable is required...exiting the program..");
      return 1;
    }

//   n = 124;			/* number of trapezoids.. */
  a = -1.0;			/* shared  */
  b = 1.0;
  dx=0.01;
  n=(int)(b-a)/dx +1;
  double ansol[n],dudx1[n],dudx2[n],dudx3[n],dudx4[n];
  double tabl[n][2];
#pragma omp parallel for num_threads(thread_count)
  for (i=0;i<n-1;i++)
  {
        double x= a+i*dx;
        ansol[i]=dfunc(x);
        dudx1[i]=(func(x+dx)-func(x))/dx;
        dudx2[i]=(func(x)-func(x-dx))/dx;
        dudx3[i]=(func(x+dx)-func(x-dx))/(2*dx);
        dudx4[i]=(func(x-2*dx)-8*func(x-dx)+8*func(x+dx)-func(x+2*dx))/(12*dx);
        tabl[i][1]=dudx1[i];
        tabl[i][2]=ansol[i];
        printf("%lf \n",((dudx1[i]-ansol[i])/ansol[i])*100);
  }

//   printf("\n The area under the curve (1+sin(x)) between 0 to PI is equal to %lf \n\n", final_result);

  return 0;  
}
