/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Header for DMA-Heap support
 */

#ifndef _LINUX_DMA_HEAP_H
#define _LINUX_DMA_HEAP_H

#include <linux/device.h>

struct dma_heap;

struct dma_heap_ops {
	void *(*allocate)(struct dma_heap *heap,
			  unsigned long len,
			  unsigned long fd_flags,
			  unsigned long heap_flags);
};

struct dma_heap {
	const char *name;
	const struct dma_heap_ops *ops;
	struct device dev;
};

int dma_heap_add(const char *name, const struct dma_heap_ops *ops);

#endif /* _LINUX_DMA_HEAP_H */
