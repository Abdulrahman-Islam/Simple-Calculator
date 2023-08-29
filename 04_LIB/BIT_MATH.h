#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_



#define SET_BIT(VAL, BIT_NUM) VAL = (VAL|(1<<BIT_NUM))
#define CLEAR_BIT(VAL, BIT_NUM) VAL = (VAL &(~(1<<BIT_NUM)) )
#define TOGGLE_BIT(VAL, BIT_NUM) VAL = (VAL ^(1<<BIT_NUM))
#define GET_BIT(VAL, BIT_NUM) ((VAL & (1<<BIT_NUM)) >> BIT_NUM)



#endif