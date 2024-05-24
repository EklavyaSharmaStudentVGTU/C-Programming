#include <graphics.h>
#include <conio.h>
#include <dos.h>

int
main ()
{
  int gd = DETECT, gm;
  int x, y, i;
  initgraph (&gd, &gm, (char *) "");
  x = getmaxx () / 2;
  y = getmaxx () / 2;

  for (i = 40; i < 200; i++)
	{
	  delay (100);
	  setcolor (i / 10);
	  arc (x, y, 0, 180, i - 10);
	}
  getch ();
  closegraph ();
  return 0;
}
