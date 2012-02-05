/**  Copyright 2012 Kutty Banerjee <kutty.banerjee@gmail.com> 
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef __qfifo_h__
#define __qfifo_h__

#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
    void** data;
    uint32_t* depth;
    uint32_t maxelements;
    uint32_t put;
    uint32_t get;
    uint32_t cursize;
    uint32_t maxdepth;
} QFifo;

static inline QFifo* exportQFifo(uint32_t maxelements) {
    assert(maxelements);
    QFifo* fifo = calloc(1, sizeof (QFifo));
    assert(fifo);
    *fifo = (QFifo){
        .data = calloc(maxelements, sizeof (void*)),
        .depth = calloc(maxelements, sizeof (uint32_t)),
        .get = 0,
        .put = 0,
        .maxelements = maxelements,
        .cursize = 0,
        .maxdepth = 0
    };
    assert(fifo->data && fifo->depth);
    return fifo;
}

static inline void destroyQFifo(QFifo* fifo) {
    assert(fifo && fifo->data && fifo->depth);
    free(fifo->data);
    free(fifo->depth);
    free(fifo);
}

static inline void put(QFifo* fifo, void* data, uint32_t depth) {
    assert(fifo);
    assert(fifo->cursize < fifo->maxelements);
    assert(fifo->depth);
    fifo->data[fifo->put] = data;
    fifo->depth[fifo->put] = depth;
    fifo->put = (fifo->put + 1) % fifo->maxelements;
    fifo->cursize++;
    if (depth > fifo->maxdepth) {
        fifo->maxdepth = depth;
    }
}

static inline void* get(QFifo* fifo, uint32_t* depth) {
    assert(fifo);
    assert(fifo->cursize);
    assert(fifo->depth);
    assert(depth);
    void* data = fifo->data[fifo->get];
    *depth = fifo->depth[fifo->get];
    fifo->get = (fifo->get + 1) % fifo->maxelements;
    fifo->cursize--;
    return data;
}

static inline void emptyFifo(QFifo* fifo) {
    assert(fifo);
    fifo->put = 0;
    fifo->get = 0;
    fifo->cursize = 0;
    fifo->maxdepth = 0;
}

static inline uint32_t sizeFifo(QFifo* fifo) {
    assert(fifo);
    return fifo->cursize;
}

static inline uint32_t maxDepthFifo(QFifo* fifo) {
    assert(fifo);
    return fifo->maxdepth;
}

#endif //__qfifo_h__
