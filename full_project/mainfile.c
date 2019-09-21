#include <stdio.h>
# include "libftprintf/includes/ft_printf.h"

int main(void)
{
     u_ld                  un;
     long long            exp;
     short                sign_exp;
     t_flag               flgs;
     t_qualfrs            fmt_feature;
     t_float              ldbl;

     fmt_feature.ld = &ldbl;

  // un.d = 1.11897314953572317650212638530309702051690633222946242004403237338917370055229707226164102903365288828535456978074;
    //un.d = 184467440737090.4;
   // un.d = 0.000000000000001189731495357;
    un.d = -31234.14;
    un.d = 0.14;
    un.d = 1887955.9999959284;
    un.d = 1887955.527894;
	un.d = 0.0003626000;
	un.d = LDBL_MIN;
	//un.d = LDBL_MAX;

  	un.d = 0.000000118973149535723176502;
  	un.d = 22.22 ;
    //un.d = 0.00;
    un.d = 0.0;
    //un.d = 10000.1189731495500000059;

   //un.d = 1812.0008118973149535723176502;
    un.d = -LDBL_MIN;
   // un.d = LDBL_MAX;

   long double d = -31234.14;
    d = -0.000001;

    printf("\noriginal_Lf:\n*% 0#30.40Lf*\n\n",d);
	  printf("original_Le:\n*% 030.40Le*\n",d);
    
    char *s ="marina";
    ft_printf("\nINPUT_%s\n",s);   

}

