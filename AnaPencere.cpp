#include "AnaPencere.h"
#include "burn.h"
#include "pencereclient.h"

void AnaPencere::slotburn()
{
     burn *b =new burn(this);
     b->exec();
  };

void  AnaPencere::slotclient()
{
       pencereclient  *c= new pencereclient(this);
       c->exec();
 };