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

int main(void) {
  
  return 0;
}

