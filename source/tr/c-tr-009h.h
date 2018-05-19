#pragma once

#ifndef __HE_

#define __HE_
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef struct Tree
{
	char key;
	struct Tree *left, *right;
}TreeNode;


#endif // !__HE_

