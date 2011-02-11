/***** THERE SEEMS TO BE A PROBLEMO WITH THIS ONE. SAYS "data" AND "next"
 * ARE NOT PART OF THE STRUCT *****/

/* This example can be found on page 114 of Software Systems by J. Vybihal */
#include <stdio.h>
#include <stdlib.h>

struct NODE {
    int data;
    struct NODE *next;
};

int main(void){ /* Add the following integers into a linked list */
    struct NODE *head = NULL, *temp;
    int value;

    printf("Enter integer numbers to the list, Enter zero to quit: ");

#if 0

please check the return value of scanf().  check the manpages if you don't
know what the return values are.  `man scanf'

#endif
    scanf("%d", &value);

    while(value != 0){

#if 0

this is a weird point which you won't understand until later, but:

sizeof() is something evaluated at compile-time, not at run-time.  It is
not a function, it's more like a macro.  It has two ways of operating, it
can take either a type or an expression.  If you give it a type (like
struct NODE), it will replace the sizeof() call with the number of chars
that type occupies, so like "sizeof(struct foo)" or "sizeof(unsigned long
int)" or "sizeof(double *)" or whatever.  If you give it an expression, it
computes the type of that expression, and then replaces the sizeof() call
with the number of chars that type occupies, so like "sizeof(x)" or
"sizeof(*this_is_a_pointer_to_y)" or something.

The point is that you should use the second one, the expr.

Why?

Because then, later, if you decide to change the type of a variable, you
don't have to manually go through every piece of code that used
"sizeof(old_type)".  Instead, you just change the type at the point of
declaration, and that's it.

Also, don't bother casting your malloc()s, and ignore any jokers who tell
you otherwise.  malloc() returns a (void *), which by the C standard, can
be implicitly casted to anything.  If you add the cast, you're cluttering
your code, and giving yourself more things to change later if you need to
change a type somewhere.

For example:

  {
      int x, *p;
      struct foo *s;

      x = 4;
      p = (int *) malloc(sizeof(int) * x);

      s = (struct foo *) malloc(sizeof(struct foo));
  }

Look how many things I have to change if I want to change the "p" array to
use unsigned integers, or if I want to change "s" to a "struct bar"
pointer:

  {
      unsigned int x, *p;                                     // 1
      struct bar *s;                                          // 2

      x = 4;
      p = (unsigned int *) malloc(sizeof(unsigned int) * x);  // 3 + 4

      s = (struct bar *) malloc(sizeof(struct bar));          // 5 + 6
  }

Now imagine REAL software that uses sizeof() for more than malloc()s, and
has tons of these things everywhere.  Horrible.

Instead, do this:

  {
      int x, *p;
      struct foo *s;

      x = 4;
      p = malloc(sizeof(p[0]) * x);

      s = malloc(sizeof(*s));
  }

So much easier to read, and now, you only change the variable
declarations to make those changes!  Hoo-ray!

  {
      unsigned int x, *p;            // 1
      struct bar *s;                 // 2

      x = 4;
      p = malloc(sizeof(p[0]) * x);

      s = malloc(sizeof(*s));
  }

#endif
        temp = (struct NODE *) malloc(sizeof(struct NODE));

#if 0

The problem here is that "temp" is a pointer to a struct, not a struct
itself.  To get at the value referenced by the pointer, you dereference
it, then you can use the "dot" operator to access the "data" field:

  (*temp).data = value;

Thankfully, very smart engineers a long time ago envisioned people
doing this constantly, and created a shorthand for "dereference and
access a field", called "arrow".  This is equivalent:

  temp->data = value;

All this means is "first, dereference temp, then, get me the "data"
field of it".  Very easy.

Anyway, that was your compile error.

#endif
        temp.data = value;

#if 0

Same here, use "temp->next" instead of "temp.next" and you'll be fine.

Also, note that "if the head is NULL, then set the next pointer to
NULL, but if the head is not NULL, then set the next pointer to the
head."  If you read carefully, you can simplify this to just
"temp->next = head" because it doesn't matter whether head is NULL or
not. ;-)

#endif
        if(head == NULL) temp.next = NULL;
        else temp.next = head;

        head = temp;

        printf("Next value: ");
        scanf("%d", &value);
    }

    printf("Dump the contents of the linked list:\n");

#if 0

Braces are a good habit to get in to.  Even if you have a loop or an
if/else that's only one line, wrap it in braces anyway.  They don't
hurt, they make it easier to read, and best of all, if you later decide
to add a debugging or logging statement or something silly (or you just
slip and drop a semicolon in there somewhere), you won't end up with a
bug.

For example:

  int i;
  for (int i = 0; i < N; ++i)
      do_something_really_great_with(i);

Now suppose I add this:

  int i;
  for (i = 0; i < N; ++i)
      fprintf(stderr, "About to do something really great with %d!\n", i);
      do_something_really_great_with(i);

Uh-oh!  Now I loop over all those prints, but I only call
do_something_really_great_with(i) once, at the end, when i == N!  This
compiles fine, and executes, and even prints all your debugging
statements!  But then, it calls that function with N, which is probably
outside the bounds of what you wanted to call it with anyway, so it
breaks!

If only you'd put braces around that one line to begin with, then you'd
have no problem.

#endif
    for (temp=head; temp!=NULL; temp=temp.next)
        printf("Data = %d\n", temp.data);

    return 0;
}

