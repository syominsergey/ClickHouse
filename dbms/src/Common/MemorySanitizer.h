#pragma once

#define __msan_unpoison(X, Y)
#define __msan_test_shadow(X, Y) (false)
#define __msan_print_shadow(X, Y)
#if defined(__has_feature)
#   if __has_feature(memory_sanitizer)
#       undef __msan_unpoison
#       undef __msan_test_shadow
#       undef __msan_print_shadow
#       include <sanitizer/msan_interface.h>
#   endif
#endif
