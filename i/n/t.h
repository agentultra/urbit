/* i/n/t.h
**
** This file is in the public domain.
*/
  /**  Options.
  **/
    /* U3_CPU_DEBUG: activate profiling.
    */
#     define U3_CPU_DEBUG

  /** Data structures.
  **/
    /* u3t_trace: fast execution flags.
    */
      typedef struct _u3t_trace {
        c3_o noc_o;                 //  now executing in nock interpreter
        c3_o glu_o;                 //  now executing in jet glue
        c3_o mal_o;                 //  now executing in allocator
        c3_o far_o;                 //  now executing in fragmentor.
      } u3t_trace;

  /**  Macros.
  **/
#   ifdef U3_CPU_DEBUG
#     define u3t_on(var)  \
        (u3T.var = (u3C.wag_w & u3o_debug_cpu) \
                 ? (c3n == u3T.var) ? c3y : (abort(), 0) \
                 : u3T.var)
#   else
#     define u3t_on(var)
#endif

#   ifdef U3_CPU_DEBUG
#     define u3t_off(var) \
        (u3T.var = (u3C.wag_w & u3o_debug_cpu) \
                 ? (c3y == u3T.var) ? c3n : (abort(), 0) \
                 : u3T.var)
#   else
#     define u3t_off(var)
#endif


  /**  Functions.
  **/
    /* u3t_init(): initialize tracing layer.
    */
      void
      u3t_init(void);

    /* u3t_push(): push on trace stack.
    */
      void
      u3t_push(u3_noun mon);

    /* u3t_mean(): push `[%mean roc]` on trace stack.
    */
      void
      u3t_mean(u3_noun roc);

    /* u3t_drop(): drop from meaning stack.
    */
      void
      u3t_drop(void);

    /* u3t_slog(): print directly.
    */
      void
      u3t_slog(u3_noun hod);

    /* u3t_heck(): profile point.
    */
      void
      u3t_heck(u3_atom cog);

    /* u3t_samp(): sample.
    */
      void
      u3t_samp(void);

    /* u3t_come(): push on profile stack; return yes if active push.  RETAIN.
    */
      c3_o
      u3t_come(u3_noun bat);

    /* u3t_flee(): pop off profile stack.
    */
      void
      u3t_flee(void);

    /* u3t_damp(): print and clear profile data.
    */
      void
      u3t_damp(void);

    /* u3t_boff(): turn profile sampling off.
    */
      void
      u3t_boff(void);

    /* u3t_boot(): turn sampling on.
    */
      void
      u3t_boot(void);


  /** Globals.
  **/
    /* u3_Trace / u3C: global memory control.
    */
      c3_global u3t_trace u3t_Trace;
#     define u3T u3t_Trace

