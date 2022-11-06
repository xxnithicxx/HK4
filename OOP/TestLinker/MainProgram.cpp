#include"Circle.h"
#include"Rectangle.h"
#include"Ellipse.h"

Figure* figMaxArea(Figure* figs[], int nFig)
{
  Figure* figMax = NULL;
  if (nFig > 0)
  {
    figMax = figs[0];
    for (int i =1; i<nFig; i++)
      if (figMax->Area() < figs[i]->Area())
        figMax = figs[i];
  }
  return figMax;
}

int main()
{
  Figure *Figs[] = {new Rectangle(9.3,9.7), new Circle(4.5),
                    new Ellipse(4.2,4.7),  new Ellipse(3.7,7.8)};
  int nFig = sizeof(Figs)/sizeof (Figure*);
  Figure* aFig = figMaxArea(Figs,nFig);
  if (aFig != NULL)
    cout<<aFig->Area() <<endl;
  return 0;
}