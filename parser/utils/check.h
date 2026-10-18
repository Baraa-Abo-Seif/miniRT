#ifndef CHECK_H
#define CHECK_H

# include <stdbool.h>

#include "../../lib_math/vector/vector.h"
#include "../../lib_math/color/color.h"


#include "../../utils/error.h"

void    check_ratio(double value);
void	check_positive(double value);
void	check_normal(t_vec normal);

#endif