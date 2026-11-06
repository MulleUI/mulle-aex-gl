#include <stddef.h>

#include <mulle-aex-gl/blend.h>

#include <stdio.h>


//
// A fragment with mask 0 generates no output (fragment_buffer.h), so blending
// it must leave the destination pixel, alpha included, untouched. The alpha
// store of the subtract equations, and formerly of BEQ_FUNC_ADD too, wrote the
// source alpha instead, which punched transparent holes wherever a masked 2x2
// quad fragment carried a transparent texel.
//
static int   check_masked( blend_eq_t eq, unsigned int src_alpha)
{
   unsigned char   src[4] = { 0, 0, 0, 0 };
   unsigned char   dst[4] = { 16, 32, 48, 255 };
   unsigned char   mask = 0;
   unsigned char   *dstp = dst;
   unsigned char   s0[1], s1[1], s2[1], s3[1];
   unsigned char   d0[1], d1[1], d2[1], d3[1];

   src[3] = (unsigned char) src_alpha;

   blend( 1, &mask,
          &src[0], &src[1], &src[2], &src[3],
          &dstp,
          1, 1, 1, 1,
          eq, eq,
          BF_ONE, BF_ONE,
          BF_ONE_MINUS_SRC_ALPHA, BF_ONE_MINUS_SRC_ALPHA,
          0, 0, 0, 0,
          s0, s1, s2, s3,
          d0, d1, d2, d3);

   if( dst[0] != 16 || dst[1] != 32 || dst[2] != 48 || dst[3] != 255)
   {
      fprintf( stderr,
               "eq %d, src alpha %u: masked fragment changed dst to %u,%u,%u,%u\n",
               (int) eq, src_alpha,
               (unsigned int) dst[0], (unsigned int) dst[1],
               (unsigned int) dst[2], (unsigned int) dst[3]);
      return( 1);
   }

   return( 0);
}


//
// With BF_ONE / BF_ONE the fixed point math is exact: ADD is src + dst,
// SUBTRACT is src - dst and REVERSE_SUBTRACT is dst - src, each clamped to
// 0..255. The per-channel checks pin the equation, and in particular the alpha
// store of REVERSE_SUBTRACT, which used the destination value as its own
// factor instead of the destination weight.
//
static int   check_values( blend_eq_t eq,
                           int src_r, int src_g, int src_b, int src_a,
                           int dst_r, int dst_g, int dst_b, int dst_a,
                           int exp_r, int exp_g, int exp_b, int exp_a)
{
   unsigned char   src[4] = { (unsigned char) src_r, (unsigned char) src_g,
                              (unsigned char) src_b, (unsigned char) src_a };
   unsigned char   dst[4] = { (unsigned char) dst_r, (unsigned char) dst_g,
                              (unsigned char) dst_b, (unsigned char) dst_a };
   unsigned char   mask = 255;
   unsigned char   *dstp = dst;
   unsigned char   s0[1], s1[1], s2[1], s3[1];
   unsigned char   d0[1], d1[1], d2[1], d3[1];

   blend( 1, &mask,
          &src[0], &src[1], &src[2], &src[3],
          &dstp,
          1, 1, 1, 1,
          eq, eq,
          BF_ONE, BF_ONE,
          BF_ONE, BF_ONE,
          0, 0, 0, 0,
          s0, s1, s2, s3,
          d0, d1, d2, d3);

   if( dst[0] != exp_r || dst[1] != exp_g ||
       dst[2] != exp_b || dst[3] != exp_a)
   {
      fprintf( stderr,
               "eq %d: src %d,%d,%d,%d dst %d,%d,%d,%d gave %u,%u,%u,%u, expected %d,%d,%d,%d\n",
               (int) eq, src_r, src_g, src_b, src_a,
               dst_r, dst_g, dst_b, dst_a,
               (unsigned int) dst[0], (unsigned int) dst[1],
               (unsigned int) dst[2], (unsigned int) dst[3],
               exp_r, exp_g, exp_b, exp_a);
      return( 1);
   }

   return( 0);
}


static int   check_unmasked_writes(void)
{
   unsigned char   src[4] = { 0, 0, 0, 255 };
   unsigned char   dst[4] = { 16, 32, 48, 255 };
   unsigned char   mask = 255;
   unsigned char   *dstp = dst;
   unsigned char   s0[1], s1[1], s2[1], s3[1];
   unsigned char   d0[1], d1[1], d2[1], d3[1];

   blend( 1, &mask,
          &src[0], &src[1], &src[2], &src[3],
          &dstp,
          1, 1, 1, 1,
          BEQ_FUNC_ADD, BEQ_FUNC_ADD,
          BF_ONE, BF_ONE,
          BF_ONE_MINUS_SRC_ALPHA, BF_ONE_MINUS_SRC_ALPHA,
          0, 0, 0, 0,
          s0, s1, s2, s3,
          d0, d1, d2, d3);

   /* Control: a fragment that is not masked out must reach the destination. */
   if( dst[0] != 0 || dst[1] != 0 || dst[2] != 0 || dst[3] != 255)
   {
      fprintf( stderr, "unmasked fragment did not blend: %u,%u,%u,%u\n",
               (unsigned int) dst[0], (unsigned int) dst[1],
               (unsigned int) dst[2], (unsigned int) dst[3]);
      return( 1);
   }

   return( 0);
}


int   main( int argc, char *argv[])
{
   static const blend_eq_t   equations[] =
   {
      BEQ_FUNC_ADD,
      BEQ_FUNC_SUBTRACT,
      BEQ_FUNC_REVERSE_SUBTRACT
   };
   static const unsigned int   alphas[] = { 0, 128, 255 };
   size_t                     i, j;

   for( i = 0; i < sizeof( equations) / sizeof( equations[0]); ++i)
      for( j = 0; j < sizeof( alphas) / sizeof( alphas[0]); ++j)
         if( check_masked( equations[i], alphas[j]))
            return( 1);

   if( check_values( BEQ_FUNC_ADD, 10, 20, 30, 40, 1, 2, 3, 4, 11, 22, 33, 44))
      return( 1);
   if( check_values( BEQ_FUNC_SUBTRACT, 200, 150, 100, 50, 50, 20, 10, 10,
                     150, 130, 90, 40))
      return( 1);
   if( check_values( BEQ_FUNC_REVERSE_SUBTRACT, 50, 20, 10, 10, 200, 150, 100, 50,
                     150, 130, 90, 40))
      return( 1);

   if( check_unmasked_writes())
      return( 1);

   printf( "blend masked fragments preserve destination OK\n");
   return( 0);
}
