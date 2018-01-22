#ifdef __clang_analyzer__

#define PROPAGATES_ROOT __attribute__((annotate("julia_propagates_root")))
#define NOTSAFEPOINT __attribute__((annotate("julia_not_safepoint")))
#define MAYBE_UNROOTED __attribute__((annotate("julia_maybe_unrooted")))
#define GLOBALLY_ROOTED __attribute__((annotate("julia_globally_rooted")))
#define ROOTING_ARGUMENT __attribute__((annotate("julia_rooting_argument")))
#define ROOTED_ARGUMENT __attribute__((annotate("julia_rooted_argument")))
#define GC_DISABLED __attribute__((annotate("julia_gc_disabled")))
#define ALWAYS_LEAFTYPE __attribute__((annotate("julia_always_leaftype")))
#define ROOTS_TEMPORARILY __attribute__((annotate("julia_temporarily_roots")))
#define REQUIRE_ROOTED_SLOT __attribute__((annotate("julia_require_rooted_slot")))
#ifdef __cplusplus
extern "C" {
#endif
  void JL_GC_PROMISE_ROOTED(void *v);
  void jl_may_leak(uintptr_t);
#ifdef __cplusplus
}
#endif

#else

#define PROPAGATES_ROOT
#define NOTSAFEPOINT
#define MAYBE_UNROOTED
#define GLOBALLY_ROOTED
#define ROOTING_ARGUMENT
#define ROOTED_ARGUMENT
#define GC_DISABLED
#define ALWAYS_LEAFTYPE
#define ROOTS_TEMPORARILY
#define REQUIRE_ROOTED_SLOT
#define JL_GC_PROMISE_ROOTED(x) (void)(x)
#define jl_may_leak(x) (void)(x)

#endif
