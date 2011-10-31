/**  Copyright 2011 Kutty Banerjee <kutty.banerjee@gmail.com> 
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
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>

typedef struct {
  void**     array;
  uint32_t   entries;
  uint32_t   curnext;
  uint32_t   prevnext;
} DependencyStack;

DependencyStack* exportDependencyStack(uint32_t maxentries) {
  DependencyStack* stack = calloc(1, sizeof(DependencyStack));
  assert(stack);
  *stack = (DependencyStack) {
    .array    = calloc(maxentries, sizeof(void*)),
    .entries  = maxentries,
    .curnext  = 0,
    .prevnext = 0
  };
  return stack;
}

void destroyDependencyStack(DependencyStack* stack) {
  assert(stack);
  free(stack->array);
  free(stack);
}

void addCurrent(DependencyStack* stack, void* entry) {
  assert(stack && entry && (stack->curnext < stack->entries));
  stack->array[stack->curnext++] = entry;
}

void* getPrev(DependencyStack* stack) {
  assert(stack && (stack->prevnext < stack->entries));
  return stack->array[stack->prevnext++];
}

void resetCurrent(DependencyStack* stack) {
  assert(stack);
  stack->curnext = 0;
}

void resetPrev(DependencyStack* stack) {
  assert(stack);
  stack->prevnext = 0;
}


int main(void) {
  uint32_t  data[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
  const uint32_t size = sizeof(data) / sizeof(data[0]) ;
  DependencyStack* stack = exportDependencyStack(size);
  
  /** initialize */
  for (uint32_t counter = 0; counter < size; counter++) {
    addCurrent(stack, &data[counter]);
  }
  resetCurrent(stack);

  for (uint32_t counter = 0; counter < size / 2; counter++) {
    assert(*(uint32_t*)getPrev(stack) == (counter * 2));
    assert(*(uint32_t*)getPrev(stack) == (counter * 2) + 1);
    addCurrent(stack, &data[size - counter - 1]);
  }
  
  for (uint32_t counter = 0; counter < size; counter++) {
    printf("array[%d] = %d\n", counter, *(uint32_t*)stack->array[counter]);
  }

  destroyDependencyStack(stack);
  return 0;
}

