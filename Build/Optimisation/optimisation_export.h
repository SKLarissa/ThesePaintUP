
#ifndef OPTIMISATION_EXPORT_H
#define OPTIMISATION_EXPORT_H

#ifdef OPTIMISATION_STATIC_DEFINE
#  define OPTIMISATION_EXPORT
#  define OPTIMISATION_NO_EXPORT
#else
#  ifndef OPTIMISATION_EXPORT
#    ifdef Optimisation_EXPORTS
        /* We are building this library */
#      define OPTIMISATION_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define OPTIMISATION_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef OPTIMISATION_NO_EXPORT
#    define OPTIMISATION_NO_EXPORT 
#  endif
#endif

#ifndef OPTIMISATION_DEPRECATED
#  define OPTIMISATION_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef OPTIMISATION_DEPRECATED_EXPORT
#  define OPTIMISATION_DEPRECATED_EXPORT OPTIMISATION_EXPORT OPTIMISATION_DEPRECATED
#endif

#ifndef OPTIMISATION_DEPRECATED_NO_EXPORT
#  define OPTIMISATION_DEPRECATED_NO_EXPORT OPTIMISATION_NO_EXPORT OPTIMISATION_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef OPTIMISATION_NO_DEPRECATED
#    define OPTIMISATION_NO_DEPRECATED
#  endif
#endif

#endif /* OPTIMISATION_EXPORT_H */
