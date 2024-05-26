/*  ----------------------------------------------------------------    */
/*  Filename    : linarg_tensor.c                                       */
/*  Author      : nekomimi                                              */
/*  Environment : windows11 WSL (Ubuntu22.04 LTS)                       */
/*  ----------------------------------------------------------------    */

//  Include header file
#include "linarg_tensor.h"

/* Create CLASS::LINARG_TENSOR template object                          */
LINARG_TENSOR_METHOD linarg_tensor_ptab = 
    {};
LINARG_TENSOR_CLSOBJ linarg_tensor_clsobj = 
    {linarg_tensor__constructor, linarg_tensor__new, linarg_tensor__init, &linarg_tensor_ptab};


/*  Func :: Tensor.constructor                                          */
/*  [Discription]                                                       */
/*       Class instance is created by constructor by calling __new()    */
/*      and __init() inside the function.                               */
/*       Functions related to generate instance aren't stored in the    */
/*      instance. So, You need to call linarg_tensor_clsobj.__init(...) */
/*      to create instance.                                             */
LINARG_TENSOR * linarg_tensor__constructor(int ndim, int *shape, LINARG_TYPE dtype)
{
    // call "__new()"
    LINARG_TENSOR *instance = linarg_tensor_clsobj.__new(linarg_tensor_clsobj.method);
    // call "__init()"
    linarg_tensor_clsobj.__init(instance, ndim, shape, dtype);
    return instance;
}

/*  Func :: linarg_tensor_clsobj.__new()                                */
/*  [Discription]                                                       */
/*       Class Instance is actually created at __new().                 */
/*       At __new(), allocate a memory area of instance and set methods.*/
LINARG_TENSOR * linarg_tensor__new(LINARG_TENSOR_METHOD *method)
{
    LINARG_TENSOR *instance = (LINARG_TENSOR *)malloc(sizeof(LINARG_TENSOR));
    instance->method = method;

    return instance;
}

/*  Func :: linarg_tensor_clsobj.__init()                               */
/*  [Discription]                                                       */
/*       Class Instance is initialized at __init().                     */
/*       "Initialization" here refers to allocate memory area for data  */
/*      and set arguments to field of instance.                         */
/*       I plan to provide a other function for providing specific      */
/*      initial values of data.                                         */
void linarg_tensor__init(LINARG_TENSOR *self, int ndim, int *shape, LINARG_TYPE dtype)
{
    /*  Calculate number of tensor emelents                             */
    int size = 1;
    for(int i=0; i<ndim; i++){  size *= *(shape+i); }

    /*  Allocate a memory area for storing data according to "dtype".   */
    switch (dtype)
    {
    case LINARG_INT_08:
        self->value = (char *)          malloc(size * 1);
        break;
    case LINARG_INT_16:
        self->value = (int *)           malloc(size * 2);
        break;
    case LINARG_INT_32:
        self->value = (int *)           malloc(size * 4);
        break;
    case LINARG_INT_64:
        self->value = (long long int *) malloc(size * 8);
        break;
    case LINARG_FLOAT_32:
        self->value = (float *)         malloc(size * 4);
        break;
    case LINARG_FLOAT_64:
        self->value = (double *)        malloc(size * 8);
        break;
    default:
        break;
    }
    /*  Initialize other members                                        */
    self->dtype = dtype;
    self->shape = shape;
    self->ndim  = ndim;

    /* Return instance                                                  */
    return self;
}