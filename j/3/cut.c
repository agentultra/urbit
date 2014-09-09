/* j/3/cut.c
**
** This file is in the public domain.
*/
#include "all.h"


/* functions
*/
  u3_noun
  u3_cqc_cut(
                   u3_atom a,
                   u3_atom b,
                   u3_atom c,
                   u3_atom d)
  {
    if ( u3_ne(u3_co_is_cat(a)) || (a >= 32) ) {
      return u3_cm_bail(c3__fail);
    }
    if ( u3_ne(u3_co_is_cat(b)) ) {
      return 0;
    }
    if ( u3_ne(u3_co_is_cat(c)) ) {
      c = 0x7fffffff;
    }

    {
      c3_g a_g   = a;
      c3_w b_w   = b;
      c3_w c_w   = c;
      c3_w len_w = u3_cr_met(a_g, d);

      if ( (0 == c_w) || (b_w >= len_w) ) {
        return 0;
      }
      if ( b_w + c_w > len_w ) {
        c_w = (len_w - b_w);
      }
      if ( (b_w == 0) && (c_w == len_w) ) {
        return u3k(d);
      }
      else {
        c3_w* sal_w = u3_ca_slaq(a_g, c_w);

        if ( 0 == sal_w ) {
          return u3_cm_bail(c3__fail);
        }
        u3_cr_chop(a_g, b_w, c_w, 0, sal_w, d);

        return u3_ca_malt(sal_w);
      }
    }
  }
  u3_noun
  u3_cwc_cut(
                  u3_noun cor)
  {
    u3_noun a, b, c, d;

    if ( (u3_no == u3_cr_mean(cor, u3_cv_sam_2,  &a,
                                u3_cv_sam_12, &b,
                                u3_cv_sam_13, &c,
                                u3_cv_sam_7,  &d, 0)) ||
         (u3_no == u3ud(a)) ||
         (u3_no == u3ud(b)) ||
         (u3_no == u3ud(c)) ||
         (u3_no == u3ud(d)) )
    {
      return u3_cm_bail(c3__exit);
    } else {
      return u3_cqc_cut(a, b, c, d);
    }
  }
