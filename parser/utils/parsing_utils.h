#ifndef PARSING_UTILS_H
#define PARSING_UTILS_H


#include <stddef.h>
#include <stdlib.h>
# include <stdbool.h>
#include "../../lib_math/vector/vector.h"
#include "../../lib_math/color/color.h"
#include "../../utils/error.h"
#include "reader.h"

void	free_string_array(char **array);

void    check_ratio(double value);
void	check_positive(double value);
void	check_normal(t_vec normal);



#endif 
