
// SPDX-License-Identifier: GPL-2.0
#include <linux/device.h>
#include <linux/dma-buf.h>
#include <linux/genalloc.h>
#include <linux/slab.h>
#include <linux/dma-heap.h>

#include "heap-helpers.h"

static void *system_heap_alloc(struct dma_heap *heap, unsigned long len,
                               unsigned long fd_flags, unsigned long heap_flags)
{
    void *vaddr = kmalloc(len, GFP_KERNEL);
    return vaddr;
}

const struct dma_heap_ops system_heap_ops = {
    .allocate = system_heap_alloc,
};
