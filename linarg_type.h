/*  ----------------------------------------------------------------    */
/*  Filename    : linarg_type.h                                         */
/*  Author      : nekomimi                                              */
/*  Environment : windows11 WSL (Ubuntu22.04 LTS)                       */
/*  ----------------------------------------------------------------    */

#ifndef __LINARG_TYPE_H__
    #define __LINARG_TYPE_H__ 1
    
    // Include standard C libraries
    #include <stdio.h>
    #include <stdlib.h>

    /*  ENUM :: LINARG_TYPE                                             */
    /*  [Discription]                                                   */
    /*      ENUM::LINARG_TYPE is for representing and recording         */
    /*      tensor data types.                                          */
    /*  [Naming convention]                                             */
    /*      element:    LINARG_{TYPE}_{BITS}                            */
    /*      typedef:    LINARG_{NAME}                                   */
    typedef enum{
        LINARG_FLOAT_32,
        LINARG_FLOAT_64,
        LINARG_INT_08,
        LINARG_INT_16,
        LINARG_INT_32,
        LINARG_INT_64
    } LINARG_TYPE;

    /*  Functions - related ENUM::LINARG_TYPE                           */
    /* [INFOMATION]                                                     */
    /*      This field isn't currrentry used. Will be added if needed.  */

    /* WRITE HERE */

#endif //__LINARG_TYPE_H__