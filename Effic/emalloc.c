/*
 * This file is part of EffiCientC (https://github.com/Thoq-jar/EffiCientC)
 *
 * Copyright (c) 2024 - Present EffiCientC
 *
 * emalloc.c is a memory allocator for effic
 *
 * EffiCientC is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * Thoq License for more details.
 *
 * You should have received a copy of the Thoq License
 * along with EffiCientC. If not, see
 * <https://raw.githubusercontent.com/Thoq-jar/Thoq-License/main/License>.
 */

#include "effic.h"

typedef struct BlockHeader {
  size_t size;               // size of the block including header
  struct BlockHeader* next;  // pointer to the next free block
  struct BlockHeader* prev;  // pointer to the previous free block
} BlockHeader;

static BlockHeader* free_list = NULL;

void* emalloc(size_t size) {
  BlockHeader* current = free_list;
  BlockHeader* prev = NULL;

  while (current != NULL) {
    if (current->size >= size + sizeof(BlockHeader)) {
      if (prev == NULL) {
        free_list = current->next;
      } else {
        prev->next = current->next;
      }
      BlockHeader* block =
          (BlockHeader*)((uintptr_t)current + sizeof(BlockHeader));
      block->size = current->size - sizeof(BlockHeader);

      return (void*)(block + 1);
    }
    prev = current;
    current = current->next;
  }

  BlockHeader* new_block = (BlockHeader*)sbrk(0);
  if (new_block == (void*)-1) {
    return NULL;
  }

  new_block->size = size + sizeof(BlockHeader);
  new_block->next = free_list;
  new_block->prev =
      NULL;  // initialize prev to NULL since this is the first block
  if (free_list != NULL) {
    free_list->prev =
        new_block;  // link the new block to the existing free list
  }
  free_list = new_block;

  return (void*)(new_block + 1);
}

void efree(void* ptr) {
  BlockHeader* block = (BlockHeader*)((uintptr_t)ptr - sizeof(BlockHeader));

  if (block->next != NULL) {
    block->next->prev = block->prev;
  }
  if (block->prev != NULL) {
    block->prev->next = block->next;
  } else {
    free_list = block->next;
  }
  if (block->next == NULL) {
    free_list = block->prev;
  }
  block = NULL;
  ptr = NULL;
}

void einit(void) {
  free_list = (BlockHeader*)sbrk(0);
  if (free_list == (void*)-1) {
    effic_exit(1);
  }
  free_list->size = 1024 * 8;
  free_list->next = NULL;
  free_list->prev = NULL;
}
