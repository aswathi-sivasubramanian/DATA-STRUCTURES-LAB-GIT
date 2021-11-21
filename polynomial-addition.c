#include <stdio.h>
#include <stdlib.h>
struct node
{
  int coeff;
  int power;
  struct node *next;
} *tail, *temp, *poly1, *poly2, *poly3 = NULL, *t;
struct node *polyadd (struct node *poly1, struct node *poly2);
struct node *
createnode (int c, int p)
{
  temp = (struct node *) malloc (sizeof (struct node));
  temp->coeff = c;
  temp->power = p;
  temp->next = NULL;
  return temp;
}

struct node *
createpoly (int count, int co[], int po[])
{
  int i;
  struct node *polylink = NULL, *last = NULL;
  for (i = 0; i < count; i++)
    {
      temp = createnode (co[i], po[i]);
      if (polylink == NULL)
	{
	  polylink = last = temp;
	}
      else
	{
	  last->next = temp;
	  last = temp;
	}
    }
  return (polylink);
}

void
display (struct node *first)
{
  temp = first;

  while (first!= NULL)
    {
      printf ("%d ,%d\n", first->coeff, first->power);
      first = first->next;
    }
}

int
main ()
{
  int c1 = 5;
  int ac1[] = { 5, 2, 6, 7, 8 };
  int ap1[] = { 1, 2, 3, 4, 5 };
  int c2 = 5;
  int ac2[] = { 13, 14, 16, 77, 56 };
  int ap2[] = { 1, 2, 988, 4, 6 };

  poly1 = createpoly (c1, ac1, ap1);
  poly2 = createpoly (c2, ac2, ap2);
  printf ("The  first polynomial a is\n");
  display (poly1);
  printf ("The  second polynomial b is\n");
  display (poly2);
  poly3 = polyadd (poly1, poly2);
  printf ("The  result addition polynomial c is\n");
  display (poly3);
  return 0;
}

struct node *
polyadd (struct node *poly1, struct node *poly2)
{
  struct node *p, *q, *res = NULL, *reslast = NULL;
  p = poly1;
  q = poly2;
  while (1)
    {
      if (p == NULL || q == NULL)
	{
	  break;
	}
      if (p->power > q->power)
	{
	  t = createnode (p->coeff, p->power);
	  p = p->next;
	}
      else if (p->power < q->power)
	{
	  t = createnode (q->coeff, q->power);
	  q = q->next;
	}
      else
	{
	  t = createnode (p->coeff + q->coeff, q->power);
	  p = p->next;
	  q = q->next;
	}
      if (res == NULL)
	{
	  res = reslast = t;
	}
      else
	{
	  reslast->next = t;
	  reslast = t;
	}

    }
  while (p != NULL)
    {
      t = createnode (p->coeff, p->power);
      p = p->next;
      if (res == NULL)
	{
	  res = reslast = t;
	}
      else
	{
	  reslast->next = t;
	  reslast = t;
	}
    }
  while (q != NULL)
    {
      t = createnode (q->coeff, q->power);
      q = q->next;
      if (res == NULL)
	{
	  res = reslast = t;
	}
      else
	{
	  reslast->next = t;
	  reslast = t;
	}
    }
  return (res);
}
// The  first polynomial a is
// 5 ,1
// 2 ,2
// 6 ,3
// 7 ,4
// 8 ,5
// The  second polynomial b is
// 14 ,2
// 16 ,988
// 77 ,4
// 56 ,6
// The  result addition polynomial c is
// 18 ,1
// 16 ,2
// 16 ,988
// 77 ,4
// 56 ,6
// 6 ,3
// 7 ,4
// 8 ,5
