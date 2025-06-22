
// SPDX-License-Identifier: GPL-2.0
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/dma-buf.h>
#include <linux/dma-heap.h>

#include "heap-helpers.h"

void *heap_common_alloc(unsigned long len)
{
    return kzalloc(len, GFP_KERNEL);
}
