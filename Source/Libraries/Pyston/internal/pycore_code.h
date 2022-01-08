#ifndef Py_INTERNAL_CODE_H
#define Py_INTERNAL_CODE_H
#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
    PyObject *ptr;  /* Cached pointer (borrowed reference) */
    uint64_t globals_ver;  /* ma_version of global dict */
    uint64_t builtins_ver; /* ma_version of builtin dict */
} _PyOpcache_LoadGlobal;

// This is a special value for the builtins_ver field
// that specifies that the LOAD_GLOBAL hit came from the globals
// and thus the builtins version doesn't matter.
#define LOADGLOBAL_WAS_GLOBAL UINT64_MAX


struct _PyOpcache {
    union {
        _PyOpcache_LoadGlobal lg;
#if PYSTON_SPEEDUPS
        char _data[32];
#endif
    } u;
    char optimized;
#if PYSTON_SPEEDUPS
    char _data2;
#endif
};

/* Private API */
int _PyCode_InitOpcache(PyCodeObject *co);


#ifdef __cplusplus
}
#endif
#endif /* !Py_INTERNAL_CODE_H */
