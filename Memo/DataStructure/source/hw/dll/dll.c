//
// FILE : tds.c - Tagged Data Storing Program
//
// This program uses the Doubly-Linked List routines.
//
/* All copyrights reserved by Bokyun Na, bkna@besta.cc */

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "dll.h"


#ifdef TEST
int main (int argc, char *argv[])
#else
int dll_main (int argc, char *argv[])
#endif
{
  /* Initialization  */
  first = last = NULL;

  /* networking & gathering of session data */
  for (;;) {
    fprintf (stderr, "type the proper menu:
i : insert an item
d : delete an item
s : show the list
q : quit
");

    switch (getchar()) {
    case 'i':  {
      DLL *item;

      if (!(item = (DLL *) malloc (sizeof (DLL)))) {
	fprintf (stderr, "Error: DLL malloc in myfunc\n");
	return 0;
      }

      fprintf (stderr, "enter date:");
      scanf ("%s", item->date);
      fprintf (stderr, "      fullpath:");
      scanf ("%s", item->fullpath);
	
      first = dll_insert_sort (item, first);
      break;
    }
    case 'd': {
      DLL item;

      fprintf (stderr, "delete which date:");
      scanf ("%s", item.date);
      dll_delete (item.date);
      break;
    }
    case 's':
      dll_show_list (first);
      break;
    case 'q':
      return 0;
    default:
      fprintf (stderr, "typed wrong choice.\n");
    }
    continue;
  }

  return 0;
}


DLL *dll_insert (DLL *item)
{
  if (last == NULL) {
    last = item;		// first item in list
    return item;
  }
  else last->next = item;

  item->next = NULL;
  item->prev = last;
  last = item;

  return first;
}


DLL *dll_insert_sort (DLL *i, DLL *top)
{
  DLL *old, *p;

  if (last == NULL) {		// first element in list
    i->next = NULL;
    i->prev = NULL;
    last = i;
    return i;
  }

  p = top;
  old = NULL;

  while (p) {
    if (atol(p->date) < atol(i->date)) { // sorting order: "the smaller the closer to first"
      old = p;
      p = p->next;
    }
    else if (atol(p->date) == atol(i->date)) {
      int ret = strcmp (p->fullpath, i->fullpath);
      if (!ret) {
	free (i);
	return first;
      }
      else if (ret < 0) {
	old = p;
	p = p->next;
      }
      else {
 	old = p;
 	p = p->prev;
      }
    }
    else {
      if (p->prev) {
	p->prev->next = i;
	i->next = p;
	i->prev = p->prev;
	p->prev = i;
	return top;
      }
      i->next = p;		// new first element
      i->prev = NULL;
      p->prev = i;
      return i;
    }
  }
  old->next = i;					// put on end
  i->next = NULL;
  i->prev = old ;
  last = i;

  return first;
}


/* Display a directory */

void dll_display (DLL *info)
{
  fprintf (stderr, "%s\n", info->date);
  fprintf (stderr, "%s\n", info->fullpath);
}


// display dll list on the screen 

void dll_show_list (DLL *first)
{
  while (first) {
    dll_display (first);
    first = first->next;		
  }
}


/* Save the list to a disk file */

int dll_store_to_file (DLL *first)
{
  DLL *info = NULL;
  FILE *fp;

  if (!(fp = fopen(".besta.slf", "w+"))) {
    printf("Cannot open File.\n");
    return 1;
  }
  info = first;
  while (info) {
    fwrite (info, sizeof (DLL), 1, fp);
    info = info->next;		// get next element
  }
  fclose (fp);
  return 0;
}


/* Load the list from disk file */

int dll_load_from_file (DLL *first, DLL *last)
{
  DLL *info, *temp = NULL;
  FILE *fp;

  if ((fp = fopen (".besta.slf", "rb")) == NULL) {
    fprintf (stderr, "can't open file\n");
    return 1;
  }

  first = (DLL *) malloc (sizeof (DLL));
  if (!first) {
    fprintf (stderr, "out of memory\n");
    return 1; 
  }

  info = first;
  while (!feof (fp)) {
    if (fread (info, sizeof (DLL), 1, fp) != 1) 
      break;

    /* get memory for next */
    info->next = (DLL *) malloc (sizeof (DLL));
    if (!info->next) {
      fprintf (stderr, "out of memory\n");
      return 0;
    }
    info->prev = temp;
    temp = info;
    info = info->next;

  }

  temp->next = NULL;		// last entry
  last = temp;

  first->prev = NULL;
  fclose (fp);

  return 0;
}


DLL *dll_find (char *date)//, DLL *first)
{
  DLL *info;
  info = first;

  while (info) {
    if (!strcmp (date, info->date))
      return info;
    info = info->next;		// get next DLL list
  }
  return NULL;			// not found
}


void dll_delete (char *date)
{
  DLL *info;

  info = dll_find (date);
  if (info) {

    /* ******* do here any job related the list ******** */

    if (first == info) {
      first = info->next;
      if (first) first->prev = NULL;
      else last = NULL;
    }
    else {
      info->prev->next = info->next;
      if (info != last)
	info->next->prev = info->prev;
      else
	last = info->prev;
    }
    free (info);		// return memory to system
  }
}
