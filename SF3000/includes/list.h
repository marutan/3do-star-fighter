#ifndef __3do_list_h__
#define __3do_list_h__

#include "types.h"
#include "nodes.h"

typedef struct Link
{
  struct Link *flink;   /* forward (next) link */
  struct Link *blink;   /* backward (prev) link */
} Link;

typedef union ListAnchor
{
  struct                        /* ptr to first node */
  {                             /* anchor for lastnode */
    Link links;
    Link *filler;
  } head;
  struct
  {
    Link *filler;
    Link  links;                /* ptr to lastnode */
  } tail;                       /* anchore for firstnode */
} ListAnchor;

typedef struct List
{
  Node l;                       /* A list is a node itself */
  ListAnchor ListAnchor;        /* Anchor point for list of nodes */
} List, *ListP;



#endif /* __3do_list_h__ */
