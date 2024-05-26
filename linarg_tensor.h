/*  ----------------------------------------------------------------    */
/*  Filename    : linarg_tensor.h                                       */
/*  Author      : nekomimi                                              */
/*  Environment : windows11 WSL (Ubuntu22.04 LTS)                       */
/*  ----------------------------------------------------------------    */

#ifndef __LINARG_TENSOR_H__
    #define __LINARG_TENSOR_H__ 1
    
    //  Include standard C libraries
    #include <stdio.h>
    #include <stdlib.h>
    //  Include to use ENUM::LINARG_TYPE
    #include "linarg_type.h"

    /*  P_TAB :: LINARG_TENSOR_METHOD                                   */
    /*  [Discription]                                                   */
    /*       This struct is used for virtual method pointer table       */
    /*      (mark as "P_TAB") for reducing memory of each instance.     */
    /*       ref:   https://soblin.github.io/technote/books/modern_c_programming/chapter3.html
    /*  [Naming convention]                                             */
    /*          typedef:    LINARG_{CLASSNAME}_METHOD                   */
    /*      struct name:    LINARG_{CLASSNAME}_METHOD_S                 */
    typedef struct LINARG_TENSOR_METHOD_S{
        /*  Method of CLASS::LINARG_TENSOR                              */
        /*  [INFOMATION]                                                */
        /*      Currently, CLASS::LINARG_TENSOR has no methods.         */
        /*      These will be added if needed.                          */

        //  WRITE METHODS HERE IF NEED
    } LINARG_TENSOR_METHOD;

    /*  Pointer table of CLASS::LINARG_TENSOR methods                   */
    extern LINARG_TENSOR_METHOD linarg_tensor_ptab;


    /*  OBJ :: LINARG_TENSOR_FUNC                                       */
    /*  [Discription]                                                   */
    /*       This struct is used for class-object(class-template) for   */
    /*      generating instances.                                       */
    /*       This "template" stores the constructor and methods-P_TAB   */
    /*      of CLASS::LINARG_TENSOR.                                    */
    /*  [Naming convention]                                             */
    /*          typedef:    LINARG_{CLASSNAME}_CLSOBJ                   */
    /*      struct name:    LINARG_{CLASSNAME}_CLSOBJ_S                 */
    typedef struct LINARG_TENSOR_CLSOBJ_S{
        /* Constructor                                                  */
        struct CLS_LINARG_TENSOR *  (*constructor)(int, int *, LINARG_TYPE);
        struct CLS_LINARG_TENSOR *  (*__new)      (struct LINARG_TENSOR_METHOD_S *);
        void                        (*__init)     (struct CLS_LINARG_TENSOR *, int, int *, LINARG_TYPE);

        /*  Methods of CLASS::LINARG_TENSOR                             */
        /*      ref. PTAB::LINARG_TENSOR_METHOD                         */
        LINARG_TENSOR_METHOD   *method;
    } LINARG_TENSOR_CLSOBJ;

    /* Class Object (template) of CLASS::LINARG_TENSOR                  */
    extern LINARG_TENSOR_CLSOBJ linarg_tensor_clsobj;


    /*  CLASS :: LINARG_TENSOR                                          */
    /*  [Discription]                                                   */
    /*      CLASS::LINARG_TENSOR is general tensor class that intended -*/
    /*      to be used as a Vector or Matrix and batches of them.       */
    /*  [Naming convention]                                             */
    /*          typedef:    LINARG_{CLASSNAME}                          */
    /*      struct name:    LINARG_{CLASSNAME}_S                        */
    typedef struct LINARG_TENSOR_S{
        /*  Field of CLASS::LINARG_TENSOR                               */
        void                   *value;
        int                     ndim ;
        int                    *shape;
        LINARG_TYPE             dtype;

        /*  Methods of CLASS::LINARG_TENSOR                             */
        /*      ref. PTAB::LINARG_TENSOR_METHOD                         */
        LINARG_TENSOR_METHOD   *method;
    } LINARG_TENSOR;

    /*  Constructor Functions for CLASS::LINARG_TENSOR                  */
    extern LINARG_TENSOR *  linarg_tensor__constructor(int, int *, LINARG_TYPE);
    extern LINARG_TENSOR *  linarg_tensor__new(LINARG_TENSOR_METHOD *);
    extern void             linarg_tensor__init(LINARG_TENSOR *, int, int *, LINARG_TYPE);
#endif //__LINARG_TENSOR_H__